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
	int sun;   //������
	public slots:
		void PixmapUpdate(); //gif֡�ĸ���
public: 
	int n;
	bool beScreen;  //�Ƿ�Ϊ��Ļ���µ�̫��
	int s1;  //ֲ���������ļ�ʱ��
	int s2;



};








#endif