#include"game_sun.h"
#include<QMouseEvent>
#include<QGraphicsSceneMouseEvent>
#include<qpainter.h>
#include<qwidget.h>
#include<qpixmap.h>
#include<qgraphicsitem.h>
//#include"game_plant.h"
#include<qmouseeventtransition.h>

gameSun::gameSun(QWidget *parent)
	:gamePlayer(parent)
{
	beScreen = false;
	type = PlantWeapon;
	speed = 12;
	life = 10000000;
	power = 5;
	defend = 0;
	

	picture.load("Resources\\Pea.png");


}

gameSun::gameSun(int x, int y, QWidget *parent)
	:gamePlayer(parent)
{
	life = 2;
	beScreen = false;
	sun = 25;
	pos_x = x;
	pos_y = y;
	setPos(x, y);
	picture.load("Resources\\Sun1.png");

	setPixmap(picture);

}
gameSun::gameSun(int count, int x, int y, QWidget *parent)
	:gamePlayer(parent)
{
	life = 2;
	beScreen = false;
	n = count;
	sun = 25;
	pos_x = x;
	pos_y = y;
	setPos(x, y);
	m_Movie.setFileName("Resources\\Sun.gif");
	m_Movie.jumpToFrame(0);
	QObject::connect(&m_Movie, SIGNAL(frameChanged(int)), this, SLOT(PixmapUpdate()));

	s1 = startTimer(100);
	m_Movie.start();
	
}
gameSun::gameSun(bool beIn, int x, int y, QWidget *parent)
	:gamePlayer(parent)
{
	beScreen = beIn;
	n = 100;
	life = 10000;
	sun = 25;
	pos_x = x;
	pos_y = y;
	setPos(x, y);
	m_Movie.setFileName("Resources\\Sun.gif");
	m_Movie.jumpToFrame(0);
	QObject::connect(&m_Movie, SIGNAL(frameChanged(int)), this, SLOT(PixmapUpdate()));

	s2 = startTimer(100);
	m_Movie.start();
	
}
void gameSun::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	setFocus();  
    setCursor(Qt::ClosedHandCursor);
	if(beScreen == false)
	emit click(this);
	if(beScreen == true)
		emit clicked(this);
}


void gameSun::PixmapUpdate()
{


	setPixmap(m_Movie.currentPixmap());

}



void gameSun::timerEvent( QTimerEvent *event )
{
  if(event->timerId() == s2)
  {
	if(beScreen == true)
	{
		if(pos_y < 400)
		pos_y += 5;
		setPos(pos_x, pos_y);

	}
  }
  if(event->timerId() == s1)
  {

	   //setPos(pos_x, pos_y);
	//   if(life <= 0)
	//		delete this;


  }

	




}