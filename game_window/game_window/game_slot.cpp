#include"game_slot.h"
#include<QMouseEvent>
#include<QGraphicsSceneMouseEvent>
#include<qpainter.h>
#include<qwidget.h>
#include<qpixmap.h>
#include<qgraphicsitem.h>
#include"game_plant.h"
#include<qmouseeventtransition.h>


gameSlot::gameSlot(QPixmap Qcard, QPixmap card1, QPixmap card2, QWidget *parent)
	:isPressed(false), create(0)
{
	
	setAcceptHoverEvents(true);
	setFlag(QGraphicsItem::ItemIsFocusable);  
    setFlag(QGraphicsItem::ItemIsMovable);  
	card_up = card1;
	card_down = card2;
	card = Qcard;
	setPixmap(card1);
	


}
gameSlot::gameSlot(QPixmap Qcard, QPixmap card1, QPixmap card2, int r,  QWidget *parent)
	:isPressed(false), create(0)
{
	judge = 0;
	setAcceptHoverEvents(true);
	setFlag(QGraphicsItem::ItemIsFocusable);  
    setFlag(QGraphicsItem::ItemIsMovable);  
	card_up = card1;
	card_down = card2;
	card = Qcard;
	setPixmap(card1);
	rank = r;


}
void gameSlot::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	setFocus();  
    setCursor(Qt::ClosedHandCursor);
	isPressed = true;
	create = 1;
	if(rank == -2)
	{
		if(judge == 0 && event->button() == Qt::LeftButton)
		{
		emit clicked();
		QGraphicsItem::mousePressEvent(event);
		}
		else if(judge == 1 && event->button() == Qt::LeftButton)
		{
		emit pres();
		QGraphicsItem::mousePressEvent(event);

		}
		else if(event->button() == Qt::RightButton)
		{
			
			emit release();
			QGraphicsItem::mousePressEvent(event);
		}

	}





}
void gameSlot::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	setFocus();  
    setCursor(Qt::ClosedHandCursor);
	isPressed = false;
	create = 3;

	
	if(rank >= 0)
	{
	  emit press( rank);
	  emit clicked(rank);
	}

	QGraphicsItem::mouseReleaseEvent(event);

}
void gameSlot::hoverEnterEvent(QGraphicsSceneHoverEvent* event)
{
	
	setPixmap(card_down);
	QGraphicsItem::hoverEnterEvent(event);
}
void gameSlot::hoverLeaveEvent(QGraphicsSceneHoverEvent* e)
{
	setCursor(Qt::OpenHandCursor); 
	setPixmap(card_up);
	QGraphicsItem::hoverLeaveEvent(e);


}
void gameSlot::isPressedChange()
{

	isPressed = !isPressed;


}

void gameSlot::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	

		
   if(isPressed == true)
   {
	create = 2;
	if(rank >= 0);
	emit press( rank);

   }

	




}