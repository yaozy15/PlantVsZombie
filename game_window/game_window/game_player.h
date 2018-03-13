#ifndef GAME_PLAYER
#define GAME_PLAYER
#include <QtGui>
#include <qgraphicsitem.h>
#include <qgraphicsscene>  
#include <qgraphicsview>  
#include <qgraphicsitem>  
#include<qpushbutton.h>
#include<QRectF>
#include<QGraphicsPixmapItem>
#include"game_gif.h"
#include<qmovie.h>
//enum PlayerType{sunPlant, attackPlant, defendPlant, repeater, Cherry, Zombie, PlantWeapon, BucketZombie, PoleZombie}; 
enum PlayerType{ZombieN,  BucketZombie,PoleZombie, OldMan,  sunPlant, attackPlant, defendPlant, repeater, Cherry, PlantWeapon, GatlingPea, SunShine }; 
class gamePlayer: public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT;
public:
	gamePlayer(QWidget *parent = 0);
	~gamePlayer();
public:
	int life;          //人物的生命值
	int power;         //人物的攻击力
    int defend;     //人物的防御值
	int speed;         // 人物的速度
public:
	 PlayerType type;   //人物种类
    gameGif  *cartoon;        //人物的效果
	QPixmap picture;       //人物载入的照片
	QMovie m_Movie;  //用于gif播放
	QMovie movie;   //用于gif播放

public:
	int pos_x;        //横坐标
	int pos_y;        //纵坐标
	int pos_line;            //第几行
	int pos_row;            //第几列
    int size_width;    //图片宽
    int size_height;   //图片高
//public:
//virtual void timerEvent(QTimerEvent *event);
	
		

};
































#endif