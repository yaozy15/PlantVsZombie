#include"game_car.h"


gameCar::gameCar(QWidget *parent)
	:gamePlayer(parent)
{
	

	speed = 5;
	life = 25;
	power = 5;
	



}
gameCar::gameCar(int x, int y, QWidget *parent)
	:gamePlayer(parent)
{
	drive = false;
	pos_x = x;
	pos_y = y;
    picture.load("Resources\\LawnMower.gif");
	m_Movie.setFileName("Resources\\LawnMower.gif");
	m_Movie.jumpToFrame(0);
	setPixmap(m_Movie.currentPixmap());
	QObject::connect(&m_Movie, SIGNAL(frameChanged(int)), this, SLOT(PixmapUpdate()));

	m_Movie.start();
	startTimer(100);



}

 void gameCar::timerEvent( QTimerEvent *event )
 {

	 if(drive == true)
	 {
		 pos_x += 20;
		 setPos(pos_x, pos_y);


	 }
	 if(pos_x > 1200)
		 delete this;



 }




