#include"game_screen.h"
#include"game_button.h"
#include"game_window.h"

gameScreen::gameScreen(QPixmap window, QObject *parent)
	:QObject(parent)
{
	
	begin_screen = new QPixmap(window);
	setPixmap(*begin_screen);


}

/*
将两个虚函数实现

*/
QRectF gameScreen::boundingRect() const 
{ 

   return QRectF(0, 0,begin_screen->width(),begin_screen->height());
 
} 


void gameScreen::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget) 
{ 
	
        painter->drawPixmap(boundingRect().topLeft(), *begin_screen);
   

} 
