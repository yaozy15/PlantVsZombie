#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H


#include <QtGui>
#include <qgraphicsitem.h>
#include <qgraphicsscene>  
#include <qgraphicsview>  
#include <qgraphicsitem>  
#include"game_button.h"
#include"game_screen.h"
//#include"game_gif.h"
#include"game_player.h"
#include"game_zombie.h"
#include"game_plant.h"
#include"game_slot.h"
#include"game_map.h"
#include"game_weapon.h"
#include"game_clear.h"
#include"game_sun.h"
#include<qvector.h>
#include<vector>
#include<qset.h>
#include"game_end.h"
#include"game_car.h"
 //用来加载场景切换场景加载僵尸与植物
class game_view: public QGraphicsView
{

	Q_OBJECT;

public:
	game_view(QWidget *parent = 0);
	~game_view(){}
public:
	gameCar *car[6]; //小车
	QTimer *timer;
	gameButton *begin; //开始按钮
	gameEnd *end;        //结束按钮
	QGraphicsScene *scene; //主要场景
	QGraphicsScene *scene_begin; //结束场景
	gameScreen *start;    //表示游戏的地图
	gameScreen *progress;
	QGraphicsView *viewer; //主要的view
	gamePlayer *player;
	gameZombie *zombie[5];
	gamePlant *Plant[10];  // 植物种类
	gamePlant *Plant2[10]; //植物阴影
	int l1[100]; //记录植物行数
	int r1[100]; //记录植物列数 
	gamePlant *p;
	QVector<gameZombie*> Zombie;  //用Vector数组
	QVector<gamePlant*> QPlant;   //用来记录所有植物；
	QVector<gamePlant*>QCherry;  //用来记录樱桃炸弹
	QVector<gameSun*>QSun; //用来记录太阳
	QVector<gameSun*>BSun; 
    gamePlant *temp;
	gamePlant *flower[15]; 
	gameWeapon *Bullet[15];  //子弹数组
	QVector<gameWeapon*>pea_bullet; //用来记录子弹
	QVector<gameWeapon*>set;
	gameSun *Sun[15];
	gameSun *sun;
	gameSun *screen_sun;  //屏幕落下的太阳
	gameSlot *card_plant;    //卡片管理
	gameSlot *card_plant1;
	gameSlot *shover;  //铲子
	gameSlot *card[10]; 
	gameSlot *repeat;
	gameSlot *card_shadow[10];
	gameSlot *card_pic[10];
	gameSlot *card_plant2;
	gameLawn *center_map;   //地图管理器
	gameWeapon *bull;   //攻击的子弹
	gameWeapon *bull1;
	gameClear *clean; //铲子
	gameSlot *clear;
	QVector<int> numZombie; //用来记录角标
	QVector<int> numPlant;
	QVector<int> numBullet;
	QVector<int>killZombie;//记录被干掉的僵尸
	QVector<int>killPlant; //记录被干掉的植物
	QVector<int>shadowRecord[10];
	QMovie *Gif;
	QSet<int>number;
	gameZombie *zom; 
	gameZombie *zom1;
	gameZombie *zom2;
	gameScreen *cardselect; // 卡槽 
	int high;  //控制出现僵尸的纵坐标
	static int num;
	int n1; //记录向日葵
	int fade_high[10];  //冷却条的高度
	int plant_high[10]; //植物的高度
	int n;
	int n2; //记录土豆
	int n3;
	int n4;
	int n5;
	int ID;
	int id;
	int iD;
	int iDsun;  //对于屏幕下落太阳的计时器
	int Shadow[8];
	int SunNum;
	int heightRecord;
	static int PlantNumber;
	int record_shadow[10];
	int maplist[7];  //僵尸纵坐标的数组
	int carStart; //小车 
	QTimer *sT;  //铲子
	QGraphicsTextItem *TextSun; //记录阳光数
	QGraphicsTextItem *TextRepeat; //个卡牌消耗的阳光数
	gameZombie *zt;
	QTimer *timer_move;
	int sunNumber;
	int screenSun; //屏幕落下的太阳计时器
	int showSunNum;   //记录现在的阳光数
	void timerEvent( QTimerEvent *event );
	int iDTest;
	int iDWin; //  僵尸胜利的计时器
	int iDstart; //开始动画的计时器
	int rg;
	gamePlant *tempPlant;
	bool End;
	gameScreen *e;
	gameScreen *e1;
	gameScreen *ZombieWin; //僵尸胜利的动画
	gameZombie *zom3;
	gameScreen *gameprogress;
	gameScreen *part;
	gameZombie *zom4;
	int zombiekill;
	int z1 ;
	int z2;
	int z3;
	gameScreen *crator; //樱桃炸弹留下的坑

void paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
   painter.drawPixmap(0,0,this->width(),this->height(),QPixmap("Resources\\Surface.png"));
}
signals:
   void check(int, int);
public slots:
	void move_to_screen();  
	void createBullet(int );
	void createBomb(int );
	void createMoreBullet(int );
	void createZombie();
	void makeCard(int );
	void createSun(int, gamePlant*);
	void attack();
	void damageVector(gamePlant*);
	void damageVectorCherry(gamePlant*);
	void damageVector1(gameZombie*);
	void damageVector2(gameWeapon*);
	void showSun(gameSun*);
	void getShover();
	void getMousePlace();
	void clearPlant();
	void mouseback();
	void makeFade(int );
	void makeScreenSun(gameSun*);
	void make_plant(int i);
	void getMousePlant();
	void createMaxBullet(int );
	void endScreen()
	{
		QPixmap star, button, button_p;
	star.load("Resources\\Surface.png");
	button.load("Resources\\button2.png");
	button_p.load("Resources\\fade2.png");
	e = new gameScreen(QPixmap("Resources\\PrepareGrowPlants.png"), this);//
	e1 = new gameScreen(QPixmap("Resources\\LargeWave.gif"), this);
	setFixedSize(star.size());

	

	scene_begin = new QGraphicsScene(this);
	
	start = new gameScreen(star, this);
	
	scene_begin->setSceneRect(0, 0, star.width(), star.height());
	int x = star.height();       
	
	
	scene_begin->setItemIndexMethod(QGraphicsScene::NoIndex);

	begin = new gameButton(button, button_p, this);
	viewer->setScene(scene_begin);
	viewer->resize(star.width(), star.height());
	viewer->setCacheMode(QGraphicsView::CacheBackground);
	viewer->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

	
    scene_begin->addItem(start);

	begin->setPos(470, 50);       //开始按钮
	scene_begin->addItem(begin);

	for(int i = 0; i < 6; i++)
	card[i]->setZValue(88);
		
	}
	
};































#endif