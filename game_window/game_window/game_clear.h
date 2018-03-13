#ifndef GAME_CLEAR_H
#define GAME_CLEAR_H

#include<qwidget.h>
#include"game_player.h"
#include"game_message.h"
#include<qobject.h>
#include<QRectF>
#include<QGraphicsPixmapItem>
class gameClear: public gamePlayer
{
public:
	gameClear(QWidget *parent = 0);
	~gameClear(){}
public:
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
public:
	int judge;
	int judgePlant;
	QTimer *timer;
signals:
	void pre();

};



































#endif