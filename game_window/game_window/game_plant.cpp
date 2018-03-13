#include"game_plant.h"
#include<qmediaplayer.h>
int gamePlant::pea_num = 0;
gamePlant::gamePlant(QWidget* parent)
//	:QMyObject(parent)
{
	type = sunPlant;
	threatened = false;
}
gamePlant::gamePlant(PlayerType kind, const QString &filename, QWidget *parent)
	:gamePlayer(parent)
{
	bombr = 0;
	explosion = false;
	explode = false;
	bomb = false;
	regist = 0;
	regist1 = 0;
	regist2 = 0;
	type = kind;
	threatened = false;
	speed = 5;
	if(type == defendPlant)
	{
	life = 400;
	cost = 50;
	}
	else if(type == attackPlant)
	{
		life = 100;
		cost = 100;
	}
	else
	{
		life = 100;
		cost = 50;
	}
	power = 5;
	defend = 0;
	pos_x = 100;
	pos_y = 0;
	picture.load(filename);
	size_width = picture.width();
	size_height = picture.height();
	m_Movie.setFileName(filename);
	m_Movie.jumpToFrame(0);
	setPixmap(m_Movie.currentPixmap());
	startTimer(100);
	QObject::connect(&m_Movie, SIGNAL(frameChanged(int)), this, SLOT(PixmapUpdate()));

	m_Movie.start();


}
gamePlant::gamePlant(const QString &filename, int x, int y,  QWidget *parent)
	:gamePlayer(parent)
{
	bombr = 0;
	explosion = false;
	explode = false;
	bomb = false;
	regist = 0;
	regist1 = 0;
	regist2 = 0;
	type = sunPlant;
	threatened = false;
	speed = 5;
	if(type == defendPlant)
	{
	life = 400;
	cost = 50;
	}
	else if(type == attackPlant)
	{
		life = 100;
		cost = 100;
	}
	else
	{
		life = 100;
		cost = 50;
	}
	power = 5;
	defend = 0;
	pos_x = x;
	pos_y = y;
	picture.load(filename);
	size_width = picture.width();
	size_height = picture.height();
	m_Movie.setFileName(filename);
	m_Movie.jumpToFrame(0);
	setPixmap(m_Movie.currentPixmap());
	//startTimer(100);
	QObject::connect(&m_Movie, SIGNAL(frameChanged(int)), this, SLOT(PixmapUpdate()));
	m_Movie.start();
		startTimer(100);

}
gamePlant::gamePlant(int n, PlayerType kind, const QString &filename, int x, int y,  QWidget *parent)
	:gamePlayer(parent)
{
	bombr = 0;
	explosion = false;
	explode = false;
	bomb = false;
	regist = 0;
	regist1 = 0;
	regist2 = 0;
	count = n;
	type = kind;
	threatened = false;
	speed = 5;
	if(type == defendPlant)
	{
	life = 400;
	cost = 50;
	}
	else if(type == attackPlant)
	{
		life = 100;
		cost = 100;
	}
	else if(type == repeater)
	{
		life = 100;
		cost = 150;
	}
	else if(type == GatlingPea)
	{
		life = 100;
		cost = 200;
	}
	else  
	{
		life = 100;
		cost = 50;

	}
	power = 5;
	defend = 0;
	pos_x = x;
	pos_y = y;

	picture.load(filename);
	size_width = picture.width();
	size_height = picture.height();
	m_Movie.setFileName(filename);
	m_Movie.jumpToFrame(0);
	setPixmap(m_Movie.currentPixmap());
	//startTimer(100);
	QObject::connect(&m_Movie, SIGNAL(frameChanged(int)), this, SLOT(PixmapUpdate()));
	m_Movie.start();
//	if(type == attackPlant)
		startTimer(100);

}
gamePlant::gamePlant(int n, PlayerType kind, const QString &filename, int x, int y)
{
	reg = 0;
	regis = 0;
	showS = false;
	forceDestroy = false;
	sunN = 0;
	bombr = 0;
	explosion = false;
	explode = false;
	bomb = false;
	regist = 0;
	regist1 = 0;
	regist2 = 0;
	count = n;
	type = kind;
	threatened = false;
	speed = 5;
	if(type == defendPlant)
	{
	life = 400;
	cost = 50;
	}
	else if(type == attackPlant)
	{
		life = 100;
		cost = 100;
	}
	else
	{
		life = 100;
		cost = 50;
	}
	power = 5;
	defend = 0;
	pos_x = x;
	pos_y = y;
	hasSun = false;
	

	QMovie *newQMovie;

	newQMovie = new QMovie;
	newQMovie->setFileName(("Resources\\s3.gif"));
	Gif.push_back(newQMovie);
	newQMovie = new QMovie;
	newQMovie->setFileName("Resources\\SunFlower2.gif");
	Gifs.push_back(newQMovie);
	
	if(type == sunPlant)
	{
    m_Movie.setFileName(filename);
	m_Movie.jumpToFrame(0);
	setPixmap(m_Movie.currentPixmap());
	//startTimer(100);
	QObject::connect(&m_Movie, SIGNAL(frameChanged(int)), this, SLOT(PixmapSUpdate()));
	m_Movie.start();
	}
	
	
	
	picture.load(filename);
	size_width = picture.width();
	size_height = picture.height();

	startTimer(100);

}
gamePlant::gamePlant(PlayerType kind, const QString &filename)
{
	bombr = 0;
	explosion = false;
	explode = false;
	bomb = false;
	regist1 = 0;
	regist2 = 0;
	type = kind;
	threatened = false;
	speed = 5;
	if(type == defendPlant)
	{
	life = 400;
	cost = 50;
	}
	else if(type == attackPlant)
	{
		life = 100;
		cost = 100;
	}
	else if(type == GatlingPea)
	{
		life = 100;
		cost = 200;


	}
	else if(type == Cherry)
	{
		life = 100;
		cost = 150;

	}
	else if(type == repeater)
	{
		life = 100;
		cost = 150;

	}
	else
	{
		life = 100;
		cost = 50;
	}
	power = 5;
	defend = 0;
	pos_x = 100;
	pos_y = 0;
	picture.load(filename);
	size_width = picture.width();
	size_height = picture.height();
	m_Movie.setFileName(filename);
	m_Movie.jumpToFrame(0);
	setPixmap(m_Movie.currentPixmap());
	QObject::connect(&m_Movie, SIGNAL(frameChanged(int)), this, SLOT(PixmapUpdate()));

	startTimer(100);
	m_Movie.start();



}
void gamePlant::setLife(int n)
{
	life = n;


}
void gamePlant::killLife(int n)
{

	life -= n;
}
int gamePlant::getLife()
{
	return life;

}
void gamePlant::setSunPrice(int n)
{
	sunPrice += n;

}
int gamePlant::getSunPrice()
{

	return sunPrice;

}

void gamePlant::PixmapUpdate()
{


	setPixmap(m_Movie.currentPixmap());
	
}

void gamePlant::timerEvent( QTimerEvent *event )
{
	pos_line = ((double)(pos_y) + 35- 78.0)/96.0;
		
	pos_row = ((double)(pos_x) + 30 - 244)/86.0;


	regist++;
	regist1 ++;
	regist2 ++;
	if(threatened == true)
		life -= 5;
	if(type == attackPlant)
	{
	if(regist % 25 == 1)
	{
    
	if(regist > 25)
		regist -= 25;
	pea_num++;
	emit needWeapon(count);
	}

	
	}
	else if(type == sunPlant)
	{
	 
	
		 regis ++;
	  if(reg <= 100)
		 reg ++;

	if(regis >= 100)
	{
		regis -= 100;
	   
	    emit needSun(count, this);
	}

	else
		hasSun = false;
	}
	else if(type == repeater)
	{
	if(regist1 > 25)
		regist1 -= 25;
	if(regist1 %50 == 1)
	emit needMoreWeapon(count);
	if(regist1 %50 == 5)
	emit needMoreWeapon(count);
	}
	else if(type == GatlingPea)
	{
	if(regist2 > 25)
		regist2 -= 25;
	if(regist2 %5 == 1)
	emit needMaxWeapon(count);
	
	}
	
	if(life <= 100 && type == defendPlant && life >= 50)
	{
		m_Movie.setFileName("Resources\\WallNut1.gif");
		m_Movie.jumpToFrame(0);
		setPixmap(m_Movie.currentPixmap());
	
		QObject::connect(&m_Movie, SIGNAL(frameChanged(int)), this, SLOT(PixmapUpdate()));
	    m_Movie.start();


	}
	if(type == defendPlant && life <  50)
	{
		m_Movie.setFileName("Resources\\Wallnut_cracked2.gif");
		m_Movie.jumpToFrame(0);
		setPixmap(m_Movie.currentPixmap());
	
		QObject::connect(&m_Movie, SIGNAL(frameChanged(int)), this, SLOT(PixmapUpdate()));
	
	    m_Movie.start();
	

	}
	if(type == Cherry)
	{
		emit needBomb(count);

	
		if(explode == true)
		{
			if(explosion == false)
			{
					m_Movie.setFileName("Resources\\Boom.gif");
					m_Movie.jumpToFrame(0);
					setPixmap(m_Movie.currentPixmap());
	
					QObject::connect(&m_Movie, SIGNAL(frameChanged(int)), this, SLOT(PixmapUpdate()));

				
					 m_Movie.start();

					 explosion = true;
			}
			setPos(pos_x -30, pos_y - 50);
		

		}
		QMediaPlayer *music;
		if(explosion == true)
		{
			if(bombr < 50)
			bombr++;
			//delete this;
			
			music = new QMediaPlayer(this);
			music->setMedia(QUrl::fromLocalFile("Resources\\cherrybomb.mp3"));
			music->setVolume(100);
			music->play();
			if(bombr >= 50)
			{
			    hide();
				delete music;
				pos_x = -100;
				pos_y = -100;
			}
		}
	
		

	}
	if(life <= 0 && type != Cherry)
	{
	
	emit damage(this);
		

	}
	if(forceDestroy == true)
	{
		sunN ++;
		if(sunN > 50)
			delete this;

	}

}

gameWeapon* gamePlant::createWeapon()
{

	gameWeapon *t = new gameWeapon(pos_x, pos_y);
	return t;

}