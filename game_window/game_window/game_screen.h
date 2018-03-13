#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H
#include <QtGui>
#include <qgraphicsitem.h>
#include <qgraphicsscene>  
#include <qgraphicsview>  
#include <qgraphicsitem>  
#include<qpushbutton.h>
#include<QRectF>
#include<QGraphicsPixmapItem>
//游戏场景物件的类
class gameScreen:public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT;
public:
	 gameScreen(){}
     gameScreen(QPixmap button, QObject *parent = 0);
	~gameScreen(){ }
public:
     QRectF boundingRect()const;
	 void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
public:

	QPixmap *begin_screen;  //开始按钮
signals:
	void zombieAttack();
	




};












#endif