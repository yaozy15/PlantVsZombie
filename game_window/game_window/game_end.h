#ifndef GAME_END_H
#define GAME_END_H

#include <QtGui>
#include <qgraphicsitem.h>
#include <qgraphicsscene>  
#include <qgraphicsview>  
#include <qgraphicsitem>  
#include<qpushbutton.h>
#include<QRectF>
#include<QGraphicsPixmapItem>
//结束按钮
class gameEnd:public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT;
public:
	gameEnd(QGraphicsItem *parent = 0){setAcceptHoverEvents(true);}
     gameEnd(QPixmap button, QPixmap button1, QObject *parent = 0);
	~gameEnd(){}
signals:
	void clicked();
public:
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void hoverEnterEvent(QGraphicsSceneHoverEvent* event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event);

public:

	QPixmap *pix_up;  //开始按钮
	QPixmap *pix_down;//结束按钮
	





};


//gameButton start_button



#endif