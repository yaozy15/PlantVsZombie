#include"game_end.h"
//#include"game_window.h"
#include<QMouseEvent>
#include<QGraphicsSceneMouseEvent>
#include<qpainter.h>
#include<qwidget.h>









gameEnd::gameEnd(QPixmap button, QPixmap button1,  QObject *parent)
	:QObject(parent)
{
	
	setAcceptHoverEvents(true);
	setFlag(QGraphicsItem::ItemIsFocusable);  
    setFlag(QGraphicsItem::ItemIsMovable);  

	pix_up = new QPixmap("Resources\\withdraw.jpg");
	pix_down = new QPixmap("Resources\\withdraw_fade.jpg");
	
	setPixmap(*pix_up);
}

/*
将两个虚函数实现

*/




void gameEnd::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	setFocus();  
    setCursor(Qt::ClosedHandCursor);
	emit clicked();
	QGraphicsItem::mousePressEvent(event);


}
void gameEnd::hoverEnterEvent(QGraphicsSceneHoverEvent* event)
{
	
	setPixmap(*pix_down);

	QGraphicsItem::hoverEnterEvent(event);
}
void gameEnd::hoverLeaveEvent(QGraphicsSceneHoverEvent* e)
{
	setCursor(Qt::OpenHandCursor); 
	setPixmap(*pix_up);
	QGraphicsItem::hoverLeaveEvent(e);


}