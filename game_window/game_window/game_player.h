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
	int life;          //���������ֵ
	int power;         //����Ĺ�����
    int defend;     //����ķ���ֵ
	int speed;         // ������ٶ�
public:
	 PlayerType type;   //��������
    gameGif  *cartoon;        //�����Ч��
	QPixmap picture;       //�����������Ƭ
	QMovie m_Movie;  //����gif����
	QMovie movie;   //����gif����

public:
	int pos_x;        //������
	int pos_y;        //������
	int pos_line;            //�ڼ���
	int pos_row;            //�ڼ���
    int size_width;    //ͼƬ��
    int size_height;   //ͼƬ��
//public:
//virtual void timerEvent(QTimerEvent *event);
	
		

};
































#endif