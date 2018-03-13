#include"game_button.h"
//#include"game_window.h"
#include<QMouseEvent>
#include<QGraphicsSceneMouseEvent>
#include<qpainter.h>
#include<qwidget.h>

//#include<QMouseTracking>

gameButton::gameButton(QPixmap button, QPixmap button1,  QObject *parent)
	:QObject(parent)
{
	
	setAcceptHoverEvents(true);
	setFlag(QGraphicsItem::ItemIsFocusable);  
    setFlag(QGraphicsItem::ItemIsMovable);  
//	setAcceptHoverEvents(true);
//	up = false;
	pix_up = new QPixmap("Resources\\button4.png");
	pix_down = new QPixmap("Resources\\button5.png");
	
	setPixmap(*pix_up);
}

/*
�������麯��ʵ��

*/




void gameButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	setFocus();  
    setCursor(Qt::ClosedHandCursor);
	emit clicked();
	QGraphicsItem::mousePressEvent(event);


}
void gameButton::hoverEnterEvent(QGraphicsSceneHoverEvent* event)
{
	
	setPixmap(*pix_down);
	QGraphicsItem::hoverEnterEvent(event);
}
void gameButton::hoverLeaveEvent(QGraphicsSceneHoverEvent* e)
{
	setCursor(Qt::OpenHandCursor); 
	setPixmap(*pix_up);
	QGraphicsItem::hoverLeaveEvent(e);


}



