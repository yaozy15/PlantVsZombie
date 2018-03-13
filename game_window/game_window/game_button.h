#ifndef GAME_BUTTON_H
#define GAME_BUTTON_H

#include <QtGui>
#include <qgraphicsitem.h>
#include <qgraphicsscene>  
#include <qgraphicsview>  
#include <qgraphicsitem>  
#include<qpushbutton.h>
#include<QRectF>
#include<QGraphicsPixmapItem>
//��ʼ��ť
class gameButton:public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT;
public:
	gameButton(QGraphicsItem *parent = 0){setAcceptHoverEvents(true);}
     gameButton(QPixmap button, QPixmap button1, QObject *parent = 0);
	~gameButton()
	{
	  delete pix_up;
	  delete pix_down;
	}
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