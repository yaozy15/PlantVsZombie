#include"game_clear.h"
#include<QGraphicsSceneMouseEvent>
#include<qevent.h>
#include<QMouseEvent>
#include<qobject.h>

#include<qpoint.h>
gameClear::gameClear(QWidget *parent)
{
	judge = 0;
	judgePlant;
	QPixmap a;
	a.load("Resources\\Shovel.png");
	setPixmap(a);







}







void gameClear::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	

	
	
			
			QGraphicsItem::mousePressEvent(event);
		


}