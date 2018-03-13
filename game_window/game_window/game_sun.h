#ifndef GAME_SUN_H
#define GAME_SUN_H

#include"game_player.h"
#include<qwidget.h>
#include<QGraphicsPixmapItem>
//#include"game_plant.h"
#include <QtGui>
#include <qgraphicsitem.h>
#include <qgraphicsscene>  
#include <qgraphicsview>  
#include <qgraphicsitem>  
class  gameSun: public gamePlayer
{
	Q_OBJECT;
public:
	gameSun(QWidget *parent = 0);
	gameSun(int x, int y, QWidget *parent = 0);
	gameSun(int count, int x, int y, QWidget *parent = 0);
	gameSun(bool beIn, int x, int y, QWidget *parent = 0);
	~gameSun(){}

signals:
	void click(gameSun*);
	void clicked(gameSun *);
public:
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void timerEvent( QTimerEvent *event );
public:
	int sun;   //阳光数
	public slots:
		void PixmapUpdate(); //gif帧的更新
public: 
	int n;
	bool beScreen;  //是否为屏幕落下的太阳
	int s1;  //植物产生阳光的计时器
	int s2;



};








#endif