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
 //�������س����л��������ؽ�ʬ��ֲ��
class game_view: public QGraphicsView
{

	Q_OBJECT;

public:
	game_view(QWidget *parent = 0);
	~game_view(){}
public:
	gameCar *car[6]; //С��
	QTimer *timer;
	gameButton *begin; //��ʼ��ť
	gameEnd *end;        //������ť
	QGraphicsScene *scene; //��Ҫ����
	QGraphicsScene *scene_begin; //��������
	gameScreen *start;    //��ʾ��Ϸ�ĵ�ͼ
	gameScreen *progress;
	QGraphicsView *viewer; //��Ҫ��view
	gamePlayer *player;
	gameZombie *zombie[5];
	gamePlant *Plant[10];  // ֲ������
	gamePlant *Plant2[10]; //ֲ����Ӱ
	int l1[100]; //��¼ֲ������
	int r1[100]; //��¼ֲ������ 
	gamePlant *p;
	QVector<gameZombie*> Zombie;  //��Vector����
	QVector<gamePlant*> QPlant;   //������¼����ֲ�
	QVector<gamePlant*>QCherry;  //������¼ӣ��ը��
	QVector<gameSun*>QSun; //������¼̫��
	QVector<gameSun*>BSun; 
    gamePlant *temp;
	gamePlant *flower[15]; 
	gameWeapon *Bullet[15];  //�ӵ�����
	QVector<gameWeapon*>pea_bullet; //������¼�ӵ�
	QVector<gameWeapon*>set;
	gameSun *Sun[15];
	gameSun *sun;
	gameSun *screen_sun;  //��Ļ���µ�̫��
	gameSlot *card_plant;    //��Ƭ����
	gameSlot *card_plant1;
	gameSlot *shover;  //����
	gameSlot *card[10]; 
	gameSlot *repeat;
	gameSlot *card_shadow[10];
	gameSlot *card_pic[10];
	gameSlot *card_plant2;
	gameLawn *center_map;   //��ͼ������
	gameWeapon *bull;   //�������ӵ�
	gameWeapon *bull1;
	gameClear *clean; //����
	gameSlot *clear;
	QVector<int> numZombie; //������¼�Ǳ�
	QVector<int> numPlant;
	QVector<int> numBullet;
	QVector<int>killZombie;//��¼���ɵ��Ľ�ʬ
	QVector<int>killPlant; //��¼���ɵ���ֲ��
	QVector<int>shadowRecord[10];
	QMovie *Gif;
	QSet<int>number;
	gameZombie *zom; 
	gameZombie *zom1;
	gameZombie *zom2;
	gameScreen *cardselect; // ���� 
	int high;  //���Ƴ��ֽ�ʬ��������
	static int num;
	int n1; //��¼���տ�
	int fade_high[10];  //��ȴ���ĸ߶�
	int plant_high[10]; //ֲ��ĸ߶�
	int n;
	int n2; //��¼����
	int n3;
	int n4;
	int n5;
	int ID;
	int id;
	int iD;
	int iDsun;  //������Ļ����̫���ļ�ʱ��
	int Shadow[8];
	int SunNum;
	int heightRecord;
	static int PlantNumber;
	int record_shadow[10];
	int maplist[7];  //��ʬ�����������
	int carStart; //С�� 
	QTimer *sT;  //����
	QGraphicsTextItem *TextSun; //��¼������
	QGraphicsTextItem *TextRepeat; //���������ĵ�������
	gameZombie *zt;
	QTimer *timer_move;
	int sunNumber;
	int screenSun; //��Ļ���µ�̫����ʱ��
	int showSunNum;   //��¼���ڵ�������
	void timerEvent( QTimerEvent *event );
	int iDTest;
	int iDWin; //  ��ʬʤ���ļ�ʱ��
	int iDstart; //��ʼ�����ļ�ʱ��
	int rg;
	gamePlant *tempPlant;
	bool End;
	gameScreen *e;
	gameScreen *e1;
	gameScreen *ZombieWin; //��ʬʤ���Ķ���
	gameZombie *zom3;
	gameScreen *gameprogress;
	gameScreen *part;
	gameZombie *zom4;
	int zombiekill;
	int z1 ;
	int z2;
	int z3;
	gameScreen *crator; //ӣ��ը�����µĿ�

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

	begin->setPos(470, 50);       //��ʼ��ť
	scene_begin->addItem(begin);

	for(int i = 0; i < 6; i++)
	card[i]->setZValue(88);
		
	}
	
};































#endif