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
//������ť
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

	QPixmap *pix_up;  //��ʼ��ť
	QPixmap *pix_down;//������ť
	





};


//gameButton start_button



#endif