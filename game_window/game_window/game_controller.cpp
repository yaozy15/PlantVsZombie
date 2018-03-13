#include"game_controller.h"
#include<qmediaplayer.h>
#include"game_slot.h"
#include<qevent.h>
#include<QMouseEvent>
#include<qgraphicsview.h>
#include<QGraphicsSceneMouseEvent>
#include<qtimer.h>
#include<QTime>
int game_view::num = 0;
int game_view::PlantNumber = 0;
//该函数为构造函数用来加载开始界面与一些重要数据的初始化
game_view::game_view(QWidget *parent)
{
	QMediaPlayer music;
	music.setMedia(QUrl::fromLocalFile("Resources\\UraniwaNi.mp3"));
	music.setVolume(100);
	music.play();
	z1 = 0;
	z2 = 0;
	z3 = 0;
	zombiekill = 0;
	rg = 0;
	End = false;
	SunNum = 0;
	screenSun = 0;
	showSunNum = 100;
	heightRecord = 0;
	for(int i = 0; i < 10; i++)
	{
	record_shadow[i] = 0;
	if(i == 4)
    	fade_high[i] = 68;
	fade_high[i] = 71;
	plant_high[i] = 0;
	}
	maplist[0] = 50;
	maplist[1] = 144;
	maplist[2] = 250;
	maplist[3] = 340;
	maplist[4] = 440;
	maplist[5] = 144;
	high = 0;
	sunNumber  = 0;
	n = 0;
	n1 = 0;
	n2 = 0;
	n3 = 0;
	n4 = 0;
	n5 = 0;
	TextSun = new QGraphicsTextItem;
	TextRepeat = new QGraphicsTextItem;
	clean = new gameClear(this);  //
	QPixmap a1, a2, a3;
	a1.load("Resources\\flowercard.png");
	a2.load("Resources\\flowercard.png");
	a3.load("Resources\\s3.gif");

	card[0] = new gameSlot(a3, a1, a2, 0, this);
	a1.load("Resources\\Peashootercard.gif");
	a2.load("Resources\\Peashootercard.gif");
	a3.load("Resources\\Peashooter.gif");

	card[1] = new gameSlot(a3, a1, a2, 1, this);
	a1.load("Resources\\WallNutCard.gif");
	a2.load("Resources\\WallNutCard.gif");
	a3.load("Resources\\WallNut.gif");
	card[2] = new gameSlot(a3, a1, a2, 2, this);
	a1.load("Resources\\Card.png");
	a2.load("Resources\\Card.png");
	a3.load("Resources\\Repeater.gif");
	card[3] = new gameSlot(a3, a1, a2, 3, this);
	a1.load("Resources\\Card.png");
	a2.load("Resources\\Card.png");
	a3.load("Resources\\0.gif");
	card[4] = new gameSlot(a3, a1, a2, 4, this);
	a1.load("Resources\\Card.png");
	a2.load("Resources\\Card.png");
	a3.load("Resources\\GatlingPea.gif");
	card[5] = new gameSlot(a3, a1, a2, 5, this);
	card[3]->setScale(0.5);
	card[4]->setScale(0.5);
	card[5]->setScale(0.5);
	a1.load("Resources\\01.gif");
	a2.load("Resources\\01.gif");
	a3.load("Resources\\01.gif");
	repeat = new gameSlot(a1, a1, a1, -100, this);
	repeat->setScale(0.5);
	Plant[1] = new gamePlant(attackPlant, "Resources\\Peashooter.gif");
	Plant2[1] = new gamePlant(attackPlant, "Resources\\Peashooter.gif");
	Plant2[1]->setOpacity(0.6);
	Plant[0] = new gamePlant(sunPlant, "Resources\\s3.gif");
	Plant2[0] = new gamePlant(sunPlant, "Resources\\s3.gif");
	Plant2[0]->setOpacity(0.6);
	Plant[2] = new gamePlant(defendPlant, "Resources\\WallNut.gif");
	Plant2[2] = new gamePlant(defendPlant, "Resources\\WallNut.gif");
	Plant2[2]->setOpacity(0.6);
	Plant[3] =  new gamePlant(repeater, "Resources\\Repeater.gif");
	Plant2[3] =  new gamePlant(repeater, "Resources\\Repeater.gif");
	Plant2[3]->setOpacity(0.6);
	Plant[4] = new gamePlant(Cherry, "Resources\\0.gif");
	Plant2[4] = new gamePlant(Cherry, "Resources\\0.gif");
	Plant2[4]->setOpacity(0.6);
	Plant[5] = new gamePlant(GatlingPea, "Resources\\GatlingPea.gif");
	Plant2[5] = new gamePlant(GatlingPea, "Resources\\GatlingPea.gif");
	Plant2[5]->setOpacity(0.6);
	a1.load("Resources\\ShovelBack.png");
	a2.load("Resources\\ShovelBack.png");
	a3.load("Resources\\ShovelBack.png");
	shover = new gameSlot(a1, a1, a1, -1, this);
	a1.load("Resources\\Shovel.png");
	clear = new gameSlot(a1, a1, a1, -2, this);
	QPixmap star, button, button_p;
	star.load("Resources\\Surface.png");
	button.load("Resources\\button2.png");
	button_p.load("Resources\\fade2.png");
	e = new gameScreen(QPixmap("Resources\\PrepareGrowPlants.png"), this);//
	e1 = new gameScreen(QPixmap("Resources\\LargeWave.gif"), this);
	setFixedSize(star.size());
	scene = new QGraphicsScene(this);

	scene_begin = new QGraphicsScene(this);
	viewer = new QGraphicsView(this);
	start = new gameScreen(star, this);
	scene->setSceneRect(0, 0, star.width(), star.height());

	int x = star.height();        //900
	
	scene->setItemIndexMethod(QGraphicsScene::NoIndex);
	scene_begin->setItemIndexMethod(QGraphicsScene::NoIndex);

	begin = new gameButton(button, button_p, this);
	viewer->setScene(scene);

	viewer->resize(star.width(), star.height());
	viewer->setCacheMode(QGraphicsView::CacheBackground);
	viewer->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

	scene->addItem(start);


	begin->setPos(470, 50);       //开始按钮
	scene->addItem(begin);

	
	QTime tim= QTime::currentTime();
  
	qsrand(NULL);

}
 //该函数主要是用来加载战斗画面
void game_view::move_to_screen()
{
 
	viewer->setScene(scene);
	QPixmap play_screen;
	play_screen.load("Resources\\background1.jpg");
	scene->setSceneRect(0, 0, play_screen.width(), play_screen.height());
	start = new gameScreen(play_screen, this);
	QPixmap cardSelect;
	cardSelect.load("Resources\\card_select.jpg");
	cardselect = new gameScreen(cardSelect, this);
	cardselect->setPos(0, 0);
	scene->setSceneRect(0, 0, play_screen.width(), play_screen.height());
	scene->addItem(start);
	clear->setPos(446, 0);
	card[0]->setPos(75, 10);
	card[1]->setPos(124,10);
	card[2]->setPos(173, 10);
	card[3]->setPos(222, 10);
	card[4]->setPos(272, 10);
	card[5]->setPos(322, 10);
	repeat->setPos(228, 23);
	shover->setPos(446, 0);
	QFont font("Helvetica");
	
	font.setPixelSize(25);
	TextSun->setFont(font);
    TextSun->setPlainText(QString::number(100));

	TextSun->setPos(15, 51);
	TextSun->setDefaultTextColor(QColor(0, 0, 0));
	TextSun->setZValue(1000);

	QFont font1("Helvetica");
	
	font1.setPixelSize(15);
	TextRepeat->setFont(font1);
    TextRepeat->setPlainText(QString::number(150));
	TextRepeat->setPos(228, 58);
	TextRepeat->setDefaultTextColor(QColor(0, 0, 0));
	scene->addItem(cardselect);
	scene->addItem(card[0]);
	scene->addItem(card[1]);
	scene->addItem(card[2]);
	scene->addItem(card[3]);
	scene->addItem(card[4]);
	scene->addItem(card[5]);
	scene->addItem(shover);
	scene->addItem(clear);
	scene->addItem(TextSun);
	scene->addItem(repeat);
	scene->addItem(TextRepeat);
	QPixmap a3;
	a3.load("Resources\\0.gif");
	repeat = new gameSlot(a3, a3, a3, -11, this);
	repeat->setScale(0.5);
	repeat->setPos(268, 23);

	scene->addItem(repeat);
	font1.setPixelSize(15);
	TextRepeat = new QGraphicsTextItem;
	TextRepeat->setFont(font1);
    TextRepeat->setPlainText(QString::number(150));
	TextRepeat->setPos(278, 58);
	TextRepeat->setDefaultTextColor(QColor(0, 0, 0));
	
	scene->addItem(TextRepeat);
	a3.load("Resources\\011.gif");
	repeat = new gameSlot(a3, a3, a3, -12, this);
	repeat->setScale(0.5);
	repeat->setPos(328, 23);

	scene->addItem(repeat);
	font1.setPixelSize(15);
	TextRepeat = new QGraphicsTextItem;
	TextRepeat->setFont(font1);
    TextRepeat->setPlainText(QString::number(200));
	TextRepeat->setPos(328, 58);
	TextRepeat->setDefaultTextColor(QColor(0, 0, 0));
	scene->addItem(TextRepeat);
	center_map = new gameLawn(this);
	QPixmap button, button_p;
	button.load("Resources\\Button.png");
	button_p.load("Resources\\Button.png");
	end = new gameEnd(button, button, this);
	gameprogress = new gameScreen(QPixmap("Resources\\FlagMeterEmpty.png"), this);
	part = new gameScreen(QPixmap("Resources\\partial.png"), this);
	end->setPos(600, 0);
	scene->addItem(end);

	QObject::connect(end, SIGNAL(clicked()), this, SLOT(endScreen()));

	for(int i = 0; i < 5; i++)
	{
	car[i] = new gameCar(200, maplist[i] + 80, this);
	car[i]->setPos(200, maplist[i] + 80);
	scene->addItem(car[i]);

	}
	QMediaPlayer *music = new QMediaPlayer(this);
	music->setMedia(QUrl::fromLocalFile("Resources\\UraniwaNi.mp3"));
	music->setVolume(50);
	music->play();
	


	
	id = startTimer(20);
	iDsun = startTimer(10000); 
	iDWin = startTimer(100);
	iDstart = startTimer(20);
	carStart = startTimer(20);
	
	
}
//用来生成冷却条
void game_view::makeFade(int i )
{

	QPixmap shadowPicture(49, 71);
	shadowPicture.fill(Qt::black);
	card_shadow[i] = new gameSlot(shadowPicture, shadowPicture, shadowPicture, -3, this);
	card_shadow[i]->setPixmap(shadowPicture);
	card_shadow[i]->setPos(75 + 49 * i, 10);
	card_shadow[i]->setOpacity(0.6);
	card_pic[i] = new gameSlot(shadowPicture, shadowPicture, shadowPicture, -3, this);
if(showSunNum >= Plant[i]->cost)
{
	if(shadowRecord[i].size() == 0)
	{

	shadowRecord[i].push_back(i);
	scene->addItem(card_shadow[i]);
	QFont font("Helvetica");
	

	Shadow[i] = startTimer(100);
	showSunNum -= Plant[i]->cost;
	TextSun->setPlainText(QString::number(showSunNum));//


	TextSun->setPos(15, 51);
	TextSun->setDefaultTextColor(QColor(0, 0, 0));
	TextSun->setZValue(1000);

	}
}

}
//从卡片中拖拽出植物，生成新的植物
void game_view::makeCard(int i)
{
if(showSunNum >=  Plant[i]->cost)
{
	QPoint a = mapFromGlobal(cursor().pos());
	if(card[i]->create != 3)
	{
		Plant[i]->setPos(a);
		card[i]->plant = Plant[i];
		card[i]->plant->setPos(a);
		QPoint a1 = mapFromGlobal(cursor().pos());
		int k2 = ((double)(a1.ry()) + 35- 78.0)/96.0;
		int l2 = k2 * 96 + 78 + 30;
		int k3 = ((double)(a1.rx()) + 30 - 244)/86.0;
		int r3 = k3 * 86 + 250 - 10;
		Plant2[i]->setPos(r3, l2);
		scene->addItem(Plant2[i]);
		scene->addItem(card[i]->plant);
	}
	if(card[i]->create == 2)
	{
		Plant[i]->setPos(a);
	    card[i]->plant = Plant[i];
	    card[i]->plant->setPos(a);
		card[i]->plant->setVisible(true);
		Plant2[i]->setVisible(true);
	}
	if(card[i]->create == 3)
	{
		Plant[i]->setPos(a);
	    card[i]->plant = Plant[i];
	    card[i]->plant->setPos(a);
		
		QPoint b = mapFromGlobal(cursor().pos());

		center_map->judgePlant(b.rx(), b.ry());
		if(center_map->PlantExist == true)
		{

		int k = ((double)(b.ry()) + 35- 78.0)/96.0;
		int l = k * 96 + 78 + 30;
		int k1 = ((double)(b.rx()) + 30 - 244)/86.0;
		int r = k1 * 86 + 250 - 10;
		card[i]->plant->setVisible(false);
		Plant2[i]->setVisible(false);
		gamePlant *p;
		PlantNumber ++;
		if(i == 0)
		{
		  n1++;
          p = new gamePlant(n1, sunPlant, "Resources\\s3.gif", r , l);
		  center_map->x1[n1] = r;
          center_map->y1[n1] = l;
		  QPlant.push_back(p);
		  connect(p, SIGNAL(needSun(int, gamePlant*)), this, SLOT(createSun(int, gamePlant*)));
		}
		if(i == 1)
		{
			num++;
            p = new gamePlant(num, attackPlant, "Resources\\Peashooter.gif", r , l,  this);

		    center_map->x[num] = r;
            center_map->y[num] = l;
			QPlant.push_back(p);
		    connect(p, SIGNAL(needWeapon(int )), this, SLOT(createBullet(int )));
		}
		if(i == 2)
		{
			n2++;
			p = new gamePlant(n2, defendPlant, "Resources\\WallNut.gif", r , l,  this);
			QPlant.push_back(p);
		}
		if(i == 3)
		{
			n3++;
			p = new gamePlant(n3, repeater, "Resources\\Repeater.gif", r , l,  this);
			QPlant.push_back(p);
			center_map->x2[n3] = r;
            center_map->y2[n3] = l;
		    
			 connect(p, SIGNAL(needMoreWeapon(int )), this, SLOT(createMoreBullet(int )));


		}
		if(i == 4)
		{
			n4++;
			p = new gamePlant(n4, Cherry, "Resources\\CherryBomb.gif", r  , l );
		    QCherry.push_back(p);
			center_map->PlantOccupied[k][k1] = 0;
			connect(p, SIGNAL(needBomb(int )), this, SLOT(createBomb(int )));



		}
		if(i == 5)
		{
			n5++;
			p = new gamePlant(n5, GatlingPea, "Resources\\GatlingPea.gif", r , l,  this);
			QPlant.push_back(p);
			center_map->x3[n5] = r;
            center_map->y3[n5] = l;
		    
			 connect(p, SIGNAL(needMaxWeapon(int )), this, SLOT(createMaxBullet(int )));


		}
	    p->pos_x = r;  //
		p->pos_y = l;  //
		
		p->setPos(r, l);

		if(QPlant.size() >= 1)
		{
			l1[QPlant.size() - 1] = k;
			r1[QPlant.size() - 1] = k1;
		}

		


		QFont font("Helvetica");
	
		font.setPixelSize(25);
		TextSun->setFont(font);
	    showSunNum -= Plant[i]->cost;
		TextSun->setPlainText(QString::number(showSunNum));


		TextSun->setPos(15, 51);
		TextSun->setDefaultTextColor(QColor(0, 0, 0));
	
	    TextSun->setZValue(1000);
		scene->addItem(p); //
	  
		card[i]->create = 5;
		center_map->PlantExist = false;
	    QPixmap shadowPicture(49, 71);
		shadowPicture.fill(Qt::black);
		card_shadow[i] = new gameSlot(shadowPicture, shadowPicture, shadowPicture, -3, this);
		card_shadow[i]->setPixmap(shadowPicture);
		card_shadow[i]->setPos(75 + 49 * i, 10);
		card_shadow[i]->setOpacity(0.6);
		card_pic[i] = new gameSlot(shadowPicture, shadowPicture, shadowPicture, -3, this);
		
		if(shadowRecord[i].size() == 0)
		{
		shadowRecord[i].push_back(i);
		scene->addItem(card_shadow[i]);
		QFont font("Helvetica");
	
	
		Shadow[i] = startTimer(100);
		showSunNum -= Plant[i]->cost;
		
		}
		
	    }
		
	
		else
		{
			card[i]->plant->setVisible(false);
		}
	}

}

	 
}
//用来让铲子跟随鼠标的移动
void game_view::make_plant(int i)
{
	QPoint a = mapFromGlobal(cursor().pos());
	if(card[i]->judge == 0 && card[i]->rank >= 0)
	{
		sT = new QTimer(this);
		sT->setInterval(100);
		QObject::connect(sT, SIGNAL(timeout()), this, SLOT(getMousePlace()));
		sT->start();
		card[i]->judge = 1;
		tempPlant = new gamePlant(sunPlant, "Resources\\s3.gif"); 

	}

}
//获取鼠标的位置
void game_view::getMousePlant()
{
	QPoint b = QCursor::pos();
	QPoint a = mapFromGlobal(b);
	tempPlant->setPos(a);
	QPixmap s;
	scene->addItem(tempPlant);

}
 //铲子信号的中转站
void game_view::getShover()
{
	QPoint a = mapFromGlobal(cursor().pos());
	if(clear->judge == 0 && clear->rank <= -2)
	{
		
		sT = new QTimer(this);
		sT->setInterval(100);
		QObject::connect(sT, SIGNAL(timeout()), this, SLOT(getMousePlace()));
		sT->start();
		clear->judge = 1;


	}




}
//用铲子铲除植物
void game_view::clearPlant()
{
	
	QPoint a = mapFromGlobal(cursor().pos());
	int x = a.rx();
	int y = a.ry();
	int l = ((double)(a.ry()) + 35- 78.0)/96.0;
		
	int r = ((double)(a.rx()) + 30 - 244)/86.0;
	
	for(int i = 0; i < QPlant.size(); i++)
	{
	 if(QPlant[i] != nullptr)
	 {
		
	  
		if(x > QPlant[i]->pos_x - 20 && x < QPlant[i]->pos_x + QPlant[i]->size_width && y > QPlant[i]->pos_y && y < QPlant[i]->pos_y + QPlant[i]->size_height)
		{
			
			QPlant[i]->life = 0;
			
			QObject::connect(QPlant[i], SIGNAL(damage(gamePlant*)), this, SLOT(damageVector(gamePlant*)));//
			center_map->PlantOccupied[l][r] = 0;
			break;

		}
	 }


	}

}
//铲子回到原来的位置
void game_view::mouseback()
{

	sT->deleteLater();
	clear->setPos(446, 0);
	clear->judge = 0;


}
void game_view::getMousePlace()
{
	
	QPoint b = QCursor::pos();
	QPoint a = mapFromGlobal(b);
	clear->setPos(a);
	QPixmap s;
	s.load("Resources\\Shovel.png");
	clear->setPixmap(s);
	

}
//豌豆射手发射子弹
void game_view::createBullet( int i)
{

		for(int j = 0; j < Zombie.size(); j++)
		{
		if(Zombie[j] != nullptr)
		{
		
			bull = new gameWeapon(center_map->x[i],center_map->y[i], this);

			bull->setPos(center_map->x[i] + 20, center_map->y[i]);
		
	    if((bull->pos_y > Zombie[j]->pos_y) && (bull->pos_y < Zombie[j]->pos_y + Zombie[j]->size_height) && Zombie[j]->pos_x > bull->pos_x - 10 &&Zombie[j]->pos_x < 900)
		{
			pea_bullet.push_back(bull);
		
			scene->addItem(bull);
	    }
		else
			delete bull;
		}
		}
	 
}
//樱桃炸弹产生爆炸效果
void game_view::createBomb(int i)
{

	if(QCherry.size() >= 1)
	{
	crator = new gameScreen(QPixmap("Resources\\crater1.png"), this);
	crator->setPos(QCherry[QCherry.size() - 1]->pos_x, QCherry[QCherry.size() - 1]->pos_y);
	scene->addItem(crator);
	QCherry[QCherry.size() - 1]->explode = true;

	
	}
 
	for(int j = 0; j < Zombie.size(); j++)
	{
		
		if(Zombie[j]->pos_x > QCherry[QCherry.size() - 1]->pos_x - 80 && Zombie[j]->pos_x < QCherry[QCherry.size() - 1]->pos_x + 80 && Zombie[j]->pos_y > QCherry[QCherry.size() - 1]->pos_y - 80 && Zombie[j]->pos_y < QCherry[QCherry.size() - 1]->pos_y + 80)
		{
			zombiekill++;
			Zombie[j]->bombdie = true;
			QObject::connect(Zombie[i], SIGNAL(damageZombie(gameZombie*)), this, SLOT(damageVector1(gameZombie*)));//

		}
		

	}
	
}
//双发射手发出子弹
void game_view::createMoreBullet( int i)
{


	 
	for(int j = 0; j < Zombie.size(); j++)
		{
		if(Zombie[j] != nullptr)
		{
		
		bull = new gameWeapon(center_map->x2[i],center_map->y2[i], this);

		bull->setPos(center_map->x2[i] + 20, center_map->y2[i]);
		
	    if((bull->pos_y > Zombie[j]->pos_y) && (bull->pos_y < Zombie[j]->pos_y + Zombie[j]->size_height) && Zombie[j]->pos_x > bull->pos_x - 10 && Zombie[j]->pos_x < 900 )
		{
		pea_bullet.push_back(bull);
		
		scene->addItem(bull);
	    }
		else
			delete bull;
		}
		}
		
	 

	 
}
//机枪射手发出子弹
void game_view::createMaxBullet( int i)
{


	 
	for(int j = 0; j < Zombie.size(); j++)
		{
		if(Zombie[j] != nullptr)
		{
		
		bull = new gameWeapon(center_map->x3[i],center_map->y3[i] + 10, this);

		bull->setPos(center_map->x3[i] + 20, center_map->y3[i] + 10);
		
	    if((bull->pos_y > Zombie[j]->pos_y) && (bull->pos_y < Zombie[j]->pos_y + Zombie[j]->size_height) && Zombie[j]->pos_x > bull->pos_x - 10 && Zombie[j]->pos_x < 900 )
		{
		pea_bullet.push_back(bull);
		
		scene->addItem(bull);
	    }
		else
			delete bull;
		}
		}
		
	 

	 
}
//向日葵产生太阳
void game_view::createSun(int i, gamePlant* t)
{


	sun = new gameSun(i, center_map->x1[i] + 130 ,center_map->y1[i] , this);
	sun->setPos(center_map->x1[i] + 40 ,center_map->y1[i]);
	sun->pos_x = center_map->x1[i];
	sun->pos_y = center_map->y1[i];
	QSun.push_back(sun);

	scene->addItem(sun);

	
	QObject::connect(sun, SIGNAL(click(gameSun*)), this, SLOT(showSun(gameSun*)));




}
//太阳点击后消失
void game_view::showSun(gameSun *t)
{


	QString a = TextSun->toPlainText();
	int num = a.toInt();
	num += 25;
    TextSun->setPlainText(QString::number(num));
	 scene->addItem(TextSun);

	 showSunNum = num;
	 QSun[QSun.size() - 1]->life = 0;
	 delete t;
	
	 
}
//大屏幕落下太阳
void game_view::makeScreenSun(gameSun* t)
{
	QString a = TextSun->toPlainText();
	int num = a.toInt();
	num += 25;
    TextSun->setPlainText(QString::number(num));
	showSunNum = num;
	 scene->addItem(TextSun);
	delete t;



}
void game_view::createZombie()
{

	startTimer(100);
	
}
void game_view::timerEvent( QTimerEvent *event )
{

if(event->timerId() == id)
{
	
	if(high > 493)
		high = high - 495;
	n++;
	
	
	if(n % 50 == 1)
	{
	if(n > 50)
		n = n - 50;
	if(Zombie.size() < 5 )
	{
	
	
    int f1 = qrand() % 5 ;
	int f2 = qrand() % 5;
	int f3 = qrand() % 5;
	
	zom = new gameZombie(BucketZombie, 1200, maplist[f1], "Resources\\Zombie3.gif", this);
	z1++;
	zom1 = new gameZombie(ZombieN, 1200, maplist[f2], "Resources\\Zombie3.gif", this);
	z2++;
	if(z3 <= 1)
	zom3 = new gameZombie(PoleZombie, 1300, 250 + 20, "Resources\\PoleVaultingZombie.gif", this);
	z3++;
	zom4 = new gameZombie(OldMan, 1300, 144 + 90, "Resources\\HeadWalk1.gif", this);
	
	center_map->judgeZombie(zom->pos_x, zom->pos_y);
	Zombie.push_back(zom);
	Zombie[Zombie.size() - 1]->setPos(Zombie[Zombie.size() - 1]->pos_x, Zombie[Zombie.size() - 1]->pos_y);
    scene->addItem(Zombie[Zombie.size() - 1]);
	center_map->judgeZombie(zom1->pos_x, zom1->pos_y);
	Zombie.push_back(zom1);
	Zombie[Zombie.size() - 1]->setPos(Zombie[Zombie.size() - 1]->pos_x, Zombie[Zombie.size() - 1]->pos_y);
    scene->addItem(Zombie[Zombie.size() - 1]);
	if(z3 <= 1)
	{
	Zombie.push_back(zom3);
	Zombie[Zombie.size() - 1]->setPos(Zombie[Zombie.size() - 1]->pos_x, Zombie[Zombie.size() - 1]->pos_y);
     scene->addItem(Zombie[Zombie.size() - 1]);
	}
	Zombie.push_back(zom4);
	Zombie[Zombie.size() - 1]->setPos(Zombie[Zombie.size() - 1]->pos_x, Zombie[Zombie.size() - 1]->pos_y);
    scene->addItem(Zombie[Zombie.size() - 1]);
	}
	
	}
	
	QVector<gameWeapon*>::iterator it = pea_bullet.begin();
	QVector<gameZombie*>::iterator its = Zombie.begin();
	int n1 = Zombie.size();
	int n2 = pea_bullet.size();
	int s = 0;
	int n3 = QPlant.size();
	QVector<int>p;
	//以下语句用来判断僵尸是否与子弹或植物相遇
	if(n1 > 0)
	{
	
	for(int i = 0; i < Zombie.size(); i++)
	{
	 if(Zombie[i] != nullptr)
	 {
		for(int j = 0; j < pea_bullet.size(); j++)
		{
		if(pea_bullet[j] != nullptr)
		{
			if((pea_bullet[j]->pos_x > Zombie[i]->pos_x) && (pea_bullet[j]->pos_y > Zombie[i]->pos_y) && (pea_bullet[j]->pos_x < Zombie[i]->pos_x + Zombie[i]->size_width) && (pea_bullet[j]->pos_y < Zombie[i]->pos_y + Zombie[i]->size_height))
			{
				Zombie[i]->life -= 5;
			
				
				numBullet.push_back(j);
				p.push_back(j);
			
			
			    if(Zombie[i]->life <= 0)
				{
				    
					zombiekill++;
					Zombie[i]->attacked = false;
				
					QObject::connect(Zombie[i], SIGNAL(damageZombie(gameZombie*)), this, SLOT(damageVector1(gameZombie*)));
					killZombie.push_back(i);
					
				}
				delete pea_bullet[j];
               
			 

			}
		}
		}
	 }

     	if(Zombie[i] != nullptr)
	    {
		if(Zombie[i]->type != PoleZombie)
		{
		for(int j = 0; j < QPlant.size(); j++)
		{
		if(QPlant[j] != nullptr && Zombie[i] != nullptr )
		{
			if(QPlant[j]->life <= 0)
			{
					
					center_map->PlantOccupied[l1[j]][r1[j]] = 0;
					
					QObject::connect(QPlant[j], SIGNAL(damage(gamePlant*)), this, SLOT(damageVector(gamePlant*)));
				 QPlant[j]->threatened = false;//
				 Zombie[i]->attacked = false;
				

			}
			//else if(Zombie[i]->attacked == false)
			//	QPlant[j]->threatened = false;
			if(QPlant[j] != nullptr)
			{
			if((QPlant[j]->pos_y < Zombie[i]->pos_y + Zombie[i]->size_height/2) && (Zombie[i]->pos_y + Zombie[i]->size_height/2 < QPlant[j]->pos_y + QPlant[j]->size_height)&&(Zombie[i]->pos_x < QPlant[j]->pos_x + QPlant[j]->size_width - 70 )&&(Zombie[i]->pos_x > QPlant[j]->pos_x - 20))
			{
			      
					
					
				    if(QPlant[j]->life > 0)
					{
				
					numZombie.push_back(i);
					numPlant.push_back(j);
				 	int xl = Zombie[i]->pos_x;
					int yl = Zombie[i]->pos_y;
					

					Zombie[i]->attacked = true;
				
					
					QPlant[j]->threatened = true;
				
				
				
					
					}
			       

				
				if(QPlant[j]->life <= 0)
				{
					
					int x1 = numZombie[numZombie.size() - 1];
					int y1 = numPlant[numPlant.size() - 1];
					
					center_map->PlantOccupied[QPlant[y1]->pos_line][QPlant[y1]->pos_row] = 0;
					
				    QPlant[j]->threatened = false;
					Zombie[i]->attacked = false;
					Zombie[i]->hasStart = false;
				    Zombie[i]->hasAttack = false;

				}
				
			}
			}
		
			else if(Zombie[i]->attacked == false)
				QPlant[j]->threatened = false;
			
		
		//else
          // Zombie[i]->attacked = false;
			
		
	}
		else if(Zombie[i] == nullptr)
		{
        Zombie[i]->attacked = false;
		QPlant[j]->threatened = false;
		}
	
		}
		}
		else if(Zombie[i]->type == PoleZombie)
		{
        for(int k = 0; k < QPlant.size(); k++)
		{
		if(QPlant[k] != nullptr && Zombie[i] != nullptr )
		{
			if(QPlant[k]->life <= 0)
			{
					
					center_map->PlantOccupied[l1[k]][r1[k]] = 0;
					Zombie[i]->attacked = false;
					Zombie[i]->hasStart = false;
				    Zombie[i]->hasAttack = false;

			}
		//	else 
		//		QPlant[j]->threatened = false;
		if(Zombie[i]->jumping == false)
		{
			if((Zombie[i]->pos_x < QPlant[k]->pos_x + QPlant[k]->size_width - 180 )&&(Zombie[i]->pos_x > QPlant[k]->pos_x - 130)&&(QPlant[k]->pos_y + QPlant[k]->size_height >= Zombie[i]->pos_y + 65)&& (QPlant[k]->pos_y  < Zombie[i]->pos_y + 130 ) )
			{
			   
					Zombie[i]->jumping = true;
	                Zombie[i]->jumpequip = true;
			    
				
			}
		
		}
		else if(Zombie[i]->jumping == true &&   Zombie[i]->jumpequip == false && Zombie[i]->jumpover == false)
		{
         if(Zombie[i]->pos_x  > QPlant[k]->pos_x - 135)
		 {
			 if((Zombie[i]->pos_x < QPlant[k]->pos_x + QPlant[k]->size_width -190 ))
			{
				    if(QPlant[k]->life > 0)
					{
			
					numZombie.push_back(i);
					numPlant.push_back(k);
				 	int xl = Zombie[i]->pos_x;
					int yl = Zombie[i]->pos_y;
					

					Zombie[i]->attacked = true;
				
					
					QPlant[k]->threatened = true;

				
				
					
					}
			       

				
				if(QPlant[k]->life <= 0)
				{
					
					int x1 = numZombie[numZombie.size() - 1];
					int y1 = numPlant[numPlant.size() - 1];
				
					center_map->PlantOccupied[QPlant[y1]->pos_line][QPlant[y1]->pos_row] = 0;
					
				    QPlant[k]->threatened = false;
					Zombie[i]->attacked = false;
					Zombie[i]->hasStart = false;
				    Zombie[i]->hasAttack = false;

				}
				
			}
		 }
		 else if(Zombie[i]->attacked == false)
		 QPlant[k]->threatened = false;




		}
	
			
		
	}
	}








		}
    // else
        // Zombie[i]->attacked = false;
		}
		}

		}
		}
		 
	
	
	
	
	

	

	 


	
	
	if(event->timerId() == iDTest)
	{

    if(zombiekill == 0)
	{
		gameprogress->setPos(400, 450);
		scene->addItem(gameprogress);


	}
	if(Zombie.size() == 1)
	{
		part->setPos(400, 450);
		scene->addItem(part);

	}


	}
	//以下6个语句用来产生冷却条
  if(event->timerId() == Shadow[0])
  {
	  record_shadow[0]++;
	  fade_high[0] -= record_shadow[0]/4;
	 
	  QPixmap shadowPicture1(49, 71);
	  shadowPicture1.fill(Qt::black);
	  QPixmap shadowPicture(49, fade_high[0]);
	  shadowPicture.fill(Qt::black);
	  card_shadow[0]->setPixmap(shadowPicture);
	  card_shadow[0]->setPos(75, 10);
	  card_shadow[0]->setOpacity(0.6);
	  card_pic[0]->setPixmap(shadowPicture1);
	  card_pic[0]->setPos(75 + 49 * 0, 10);
	  card_pic[0]->setOpacity(0.6);
	  scene->addItem(card_shadow[0]);
	 scene->addItem(card_pic[0]);
	  if(fade_high[0] <= 0 )
	  {
		  record_shadow[0] = 0;
		  fade_high[0] = 71;
		 // hide();
		  delete card_pic[0];
		  //hide();
		  shadowRecord[0].pop_back();
		  killTimer(Shadow[0]);

	  }



  }
  if(event->timerId() == Shadow[1])
  {
	  record_shadow[1]++;
	  fade_high[1] -= record_shadow[1]/4;
	 
	 QPixmap shadowPicture1(49, 71);
	shadowPicture1.fill(Qt::black);
	  QPixmap shadowPicture(49, fade_high[1]);
	  shadowPicture.fill(Qt::black);
	  //card_shadow[0] = new gameSlot(shadowPicture, shadowPicture, shadowPicture, -3, this);
	  card_shadow[1]->setPixmap(shadowPicture);
	  card_shadow[1]->setPos(75 + 49 * 1, 10);
	  card_shadow[1]->setOpacity(0.6);
	  
//	  card_pic[0] = new gameSlot(shadowPicture1, shadowPicture1, shadowPicture1, -3, this);
	  card_pic[1]->setPixmap(shadowPicture1);
	  card_pic[1]->setPos(75 + 49 * 1, 10);
	  card_pic[1]->setOpacity(0.6);
	  scene->addItem(card_shadow[1]);
	 scene->addItem(card_pic[1]);
	  if(fade_high[1] <= 0 )
	  {
		  record_shadow[1] = 0;
		  fade_high[1] = 71;
		 // hide();
		  delete card_pic[1];
		  //hide();
		  shadowRecord[1].pop_back();
		  killTimer(Shadow[1]);

	  }



  }
  if(event->timerId() == Shadow[2])
  {
	  record_shadow[2]++;
	  fade_high[2] -= record_shadow[2]/4;
	 
	 QPixmap shadowPicture1(49, 71);
	 shadowPicture1.fill(Qt::black);
	  QPixmap shadowPicture(49, fade_high[2]);
	  shadowPicture.fill(Qt::black);
	  //card_shadow[0] = new gameSlot(shadowPicture, shadowPicture, shadowPicture, -3, this);
	  card_shadow[2]->setPixmap(shadowPicture);
	  card_shadow[2]->setPos(75 + 49 * 2, 10);
	  card_shadow[2]->setOpacity(0.6);
	  
//	  card_pic[0] = new gameSlot(shadowPicture1, shadowPicture1, shadowPicture1, -3, this);
	  card_pic[2]->setPixmap(shadowPicture1);
	  card_pic[2]->setPos(75 + 49 * 2, 10);
	  card_pic[2]->setOpacity(0.6);
	  scene->addItem(card_shadow[2]);
	 scene->addItem(card_pic[2]);
	  if(fade_high[2] <= 0 )
	  {
		  record_shadow[2] = 0;
		  fade_high[2] = 71;
		 // hide();
		  delete card_pic[2];
		  //hide();
		  shadowRecord[2].pop_back();
		  killTimer(Shadow[2]);

	  }



  }
  if(event->timerId() == Shadow[3])
  {
	  record_shadow[3]++;
	  fade_high[3] -= record_shadow[3]/4;
	 
	 QPixmap shadowPicture1(49, 71);
	 shadowPicture1.fill(Qt::black);
	  QPixmap shadowPicture(49, fade_high[3]);
	  shadowPicture.fill(Qt::black);
	  //card_shadow[0] = new gameSlot(shadowPicture, shadowPicture, shadowPicture, -3, this);
	  card_shadow[3]->setPixmap(shadowPicture);
	  card_shadow[3]->setPos(75 + 49 * 3, 10);
	  card_shadow[3]->setOpacity(0.6);
	  
//	  card_pic[0] = new gameSlot(shadowPicture1, shadowPicture1, shadowPicture1, -3, this);
	  card_pic[3]->setPixmap(shadowPicture1);
	  card_pic[3]->setPos(75 + 49 * 3, 10);
	  card_pic[3]->setOpacity(0.6);
	  scene->addItem(card_shadow[3]);
	 scene->addItem(card_pic[3]);
	  if(fade_high[3] <= 0 )
	  {
		  record_shadow[3] = 0;
		  fade_high[3] = 71;
		 // hide();
		  delete card_pic[3];
		  //hide();
		  shadowRecord[3].pop_back();
		  killTimer(Shadow[3]);

	  }



  }
  if(event->timerId() == Shadow[4])
  {
	  record_shadow[4]++;
	  fade_high[4] -= record_shadow[4]/4;
	 
	  QPixmap shadowPicture1(52, 70);
	  shadowPicture1.fill(Qt::black);
	  QPixmap shadowPicture(52, fade_high[4]);
	  shadowPicture.fill(Qt::black);
	  //card_shadow[0] = new gameSlot(shadowPicture, shadowPicture, shadowPicture, -3, this);
	  card_shadow[4]->setPixmap(shadowPicture);
	  card_shadow[4]->setPos(75 + 49 * 4, 10);
	  card_shadow[4]->setOpacity(0.6);
	  
//	  card_pic[0] = new gameSlot(shadowPicture1, shadowPicture1, shadowPicture1, -3, this);
	  card_pic[4]->setPixmap(shadowPicture1);
	  card_pic[4]->setPos(75 + 49 * 4, 10);
	  card_pic[4]->setOpacity(0.6);
	  scene->addItem(card_shadow[4]);
	  scene->addItem(card_pic[4]);
	  if(fade_high[4] <= 0 )
	  {
		  record_shadow[4] = 0;
		  fade_high[4] = 71;
		 // hide();
		  delete card_pic[4];
		  //hide();
		  shadowRecord[4].pop_back();
		  killTimer(Shadow[4]);

	  }



  }
  if(event->timerId() == Shadow[5])
  {
	  record_shadow[5]++;
	  fade_high[5] -= record_shadow[5]/4;
	 
	  QPixmap shadowPicture1(52, 70);
	  shadowPicture1.fill(Qt::black);
	  QPixmap shadowPicture(52, fade_high[5]);
	  shadowPicture.fill(Qt::black);
	  card_shadow[5]->setPixmap(shadowPicture);
	  card_shadow[5]->setPos(75 + 49 * 5, 10);
	  card_shadow[5]->setOpacity(0.6);
	  card_pic[5]->setPixmap(shadowPicture1);
	  card_pic[5]->setPos(75 + 49 * 5, 10);
	  card_pic[5]->setOpacity(0.6);
	  scene->addItem(card_shadow[5]);
	  scene->addItem(card_pic[5]);
	  if(fade_high[5] <= 0 )
	  {
		  record_shadow[5] = 0;
		  fade_high[5] = 71;
		  delete card_pic[5];
		  shadowRecord[5].pop_back();
		  killTimer(Shadow[5]);

	  }



  }
  //用来产生落下的太阳
  if(event->timerId() == iDsun)
  {
	  screen_sun = new gameSun(true, 400, 0, this);

	  BSun.push_back(screen_sun);
	  scene->addItem(screen_sun);
	  QObject::connect(screen_sun, SIGNAL(clicked(gameSun* )), this, SLOT(makeScreenSun(gameSun* )));
  }
    if(event->timerId() == iDWin)
	{
		for(int i = 0; i < Zombie.size(); i++)
		{
			if(Zombie[i] != nullptr)
			{
			 if(Zombie[i]->life > 0)
			 {
				if(Zombie[i]->pos_x < 60)
				{
					gameScreen *e = new gameScreen(QPixmap("Resources\\ZombiesWon.png"), this);
					e->setPos(200, 80);
					scene->addItem(e);
					break;


				}
			 }

			}


		}


	}
	//开场动画
	if(event->timerId() == iDstart)
	{
		rg++;
		if(rg <= 100)
		{
		
		e->setOpacity(0.01 * rg);
		e->setPos(400, 100);
		scene->addItem(e);
		}
		if(rg > 100 && rg <= 200)
		{
		e->setOpacity(0.01 * (200 - rg));
		e->setPos(400, 100);
		scene->addItem(e);
		}
		if(rg > 200 && rg <= 300)
		{

			e1->setOpacity(0.01 * (rg - 200));
			e1->setPos(400, 100);
		    scene->addItem(e1);

		}
		if(rg > 300)
		{
			e1->setOpacity(0.01 * (400 - rg));
			e1->setPos(400, 100);
		    scene->addItem(e1);
			if(rg == 400)
				killTimer(iDstart);


		}
		



	}
	int zline;
	//判断小车是否移动
	if(event->timerId() == carStart)
	{

		for(int i = 0; i < Zombie.size(); i++)
		{
			if(Zombie[i] == nullptr)
				continue;
			else
			{
				for(int j = 0; j < 5; j++)
				{
					if(Zombie[i]->type == PoleZombie)
					zline = ((double)(Zombie[i]->pos_y + 30) + 35 - 78.0)/96.0 + 1;
					else
                    zline = ((double)(Zombie[i]->pos_y + 30) + 35 - 78.0)/96.0;
					if(Zombie[i]->pos_x < 280 &&zline == j )
					{
						car[j]->drive = true;

					}
				}
			}





		}
		for(int k = 0; k < 5; k++)
		{
			if(car[k]->drive == true)
			{
				for(int i = 0; i < Zombie.size(); i++)
				{
					if(Zombie[i] == nullptr)
				    continue;
					else
					{
						int zzline = ((double)(Zombie[i]->pos_y + 65) + 35- 78.0)/96.0;
						if(Zombie[i]->pos_x < car[k]->pos_x + 50 && Zombie[i]->pos_x > car[k]->pos_x && zzline == k )
						{
							
							Zombie[i]->life = 0;
							QObject::connect(Zombie[i], SIGNAL(damageZombie(gameZombie*)), this, SLOT(damageVector1(gameZombie*)));//

						}
					}




				}
			}
		}



	}
}


void game_view::attack()
{
	
	QVector<gamePlant*>::iterator itp = QPlant.begin();
	int x1 = numZombie[numZombie.size() - 1];
	int y1 = numPlant[numPlant.size() - 1];
	Zombie[x1]->speed = 0;
	QPlant[y1]->life -= Zombie[x1]->power;
	if(QPlant[y1]->life <= 0)
	{
		delete QPlant[y1];
		
		killPlant.push_back(y1);
		number.insert(y1);
	
		Zombie[x1]->speed = 5;
		
	
	}
	
}
//将死去植物去除
void game_view::damageVector(gamePlant* t)
{

	QPlant.removeAll(t);
	delete t;

}
void game_view::damageVectorCherry(gamePlant* t)
{
	
	QCherry.removeAll(t);
	delete t;
}
//将死去僵尸去除
void game_view::damageVector1(gameZombie* t)
{
	Zombie.removeAll(t);
	delete t;

}
void game_view::damageVector2(gameWeapon* t)
{

	pea_bullet.removeAll(t);
}


