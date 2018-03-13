#include"game_zombie.h"
#include"game_player.h"
#include<qmediaplayer.h>
#include<qtimer.h>
gameZombie::gameZombie(QWidget *parent)
	:gamePlayer(parent)
{
	ri = 0;
	attacked = false;
	type = ZombieN;
	speed = 5;
	life = 25;
	power = 5;
	pos_x = 600;
	pos_y = 10;



}

gameZombie::gameZombie(const QString &filename, QWidget *parent)
	:gamePlayer(parent)
{
	boo = 0;
	hasexplode = false;
	bombdie = false;
	ri = 0;
	attacked = false;
	type = ZombieN;
	speed = 5;
	life = 25;
	power = 1;
	defend = 0;
	pos_x = 1500;
	pos_y = 10;
	picture.load(filename);
	m_Movie.setFileName(filename);
	m_Movie.jumpToFrame(0);
	setPixmap(m_Movie.currentPixmap());
	QObject::connect(&m_Movie, SIGNAL(frameChanged(int)), this, SLOT(PixmapUpdate()));

	m_Movie.start();
	
	
	


}
gameZombie::gameZombie(int x, int y, const QString &filename, QWidget *parent)
	:gamePlayer(parent)
{
	boo = 0;
	hasexplode = false;
	bombdie = false;
	pause1 = 0;
	nu = 0;
	pause = 0;
	numb = 0;
	die = 0;
	ri = 0;
	attacked = false;
	type = ZombieN;
	speed = 2;
	life = 40;
	power = 5;
	defend = 0;
	pos_x = x;
	pos_y = y;
	picture.load(filename);
	size_width = picture.width();
	size_height = picture.height();

	 hasStart = false;
	 hasAttack = false;
	 hasDied = false;
	 hasWeak = false;
	 hasChange = false;
	QMovie *newQMovie;
	
	newQMovie = new QMovie;
	newQMovie->setFileName(("Resources\\Zombie3.gif"));
	Gif.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources\\ZombieAttack.gif");
	Gif.push_back(newQMovie);
	
	newQMovie = new QMovie;
	newQMovie->setFileName("Resources\\ZombieDie.gif");
	Gif.push_back(newQMovie);
	newQMovie = new QMovie;
	newQMovie->setFileName("Resources\\BoomDie.gif");
	Gif.push_back(newQMovie);
	
	setMyGif(0);
	timeZombie = startTimer(100);


}
gameZombie::gameZombie(bool play, int x, int y, const QString &filename, QWidget *parent)
	:gamePlayer(parent)
{
	boo = 0;
	hasexplode = false;
	bombdie = false;
	pause1 = 0;
	nu = 0;
	pause = 0;
	numb = 0;
	die = 0;
	ri = 0;
	attacked = false;
	type = ZombieN;
	speed = 2;
	life = 40;
	power = 5;
	defend = 0;
	pos_x = x;
	pos_y = y;
	picture.load(filename);
	size_width = picture.width();
	size_height = picture.height();
	 
	 
	 picture.load(filename);
	 ZombieNormal.setFileName(filename);
	 ZombieNormal.jumpToFrame(0);
	 setPixmap(ZombieNormal.currentPixmap());
	 QObject::connect(&ZombieNormal, SIGNAL(frameChanged(int)), this, SLOT(ZombieNormalUpdate()));
	 ZombieNormal.setSpeed(100);
	 ZombieNormal.start();
	
	
	
	
	timePause = startTimer(100);


}
void gameZombie::playAction()
{
	 m_Movie.setFileName("Resources\\ZombieDie.gif");
	 m_Movie.jumpToFrame(0);
	 setPixmap(m_Movie.currentPixmap());
	 QObject::connect(&m_Movie, SIGNAL(frameChanged(int)), this, SLOT(PixmapUpdate()));

	 m_Movie.start();
	 


}
gameZombie::gameZombie(PlayerType kind, int x, int y, const QString &filename, QWidget *parent)
	:gamePlayer(parent)
{
	 pause = 0;
	 boo = 0;
	 hasexplode = false;
	 bombdie = false;
     play = 0;
	 numb = 0;
	 die = 0;
	 ri = 0;
	 beJump = false;
	 attacked = false;
	 type = kind;
	 speed = 5;
	if(type == BucketZombie)
	{
		life = 50;
		
	}
	else
	{
	 life = 25;
 
	}
	 power = 5;
	 defend = 0;
	 pos_x = x;
	 pos_y = y;
	 picture.load(filename);
	 size_width = picture.width();
	 size_height = picture.height();
	if(type == ZombieN)
	{
	 hasStart = false;
	 hasAttack = false;
	 hasDied = false;
	 hasWeak = false;
	 hasChange = false;
	 QMovie *newQMovie;
	
	 newQMovie = new QMovie;
	 newQMovie->setFileName(("Resources\\Zombie3.gif"));
	 Gif.push_back(newQMovie);

	 newQMovie = new QMovie;
	 newQMovie->setFileName("Resources\\ZombieAttack.gif");
	 Gif.push_back(newQMovie);
	
	 newQMovie = new QMovie;
	 newQMovie->setFileName("Resources\\ZombieDie.gif");
	 Gif.push_back(newQMovie);
	 newQMovie = new QMovie;
	 newQMovie->setFileName("Resources\\BoomDie.gif");
	 Gif.push_back(newQMovie);
	
	 setMyGif(0);
	 timeZombie = startTimer(100);





	}
	if(type == PoleZombie)
	{
	   nj = 0;
	   speed = 10;
	   life = 100;
	   jumpover = false;
	   hasStart = false;
	   hasAttack = false;
	   hasDied = false;
	   hasWeak = false;
	   hasChange = false;
	   jumping = false;
	   jumpequip = false;
	   hasJumping = false;
	   QMovie *newQMovie;
	
	   newQMovie = new QMovie;
	   newQMovie->setFileName(("Resources\\PoleVaultingZombie.gif"));
	   Gif.push_back(newQMovie);

	   newQMovie = new QMovie;
	   newQMovie->setFileName("Resources\\PoleVaultingZombieAttack.gif");
	   Gif.push_back(newQMovie);
	
	   newQMovie = new QMovie;
	   newQMovie->setFileName("Resources\\PoleVaultingZombieJump.gif");
	   Gif.push_back(newQMovie);
	   newQMovie = new QMovie;
	   newQMovie->setFileName("Resources\\PoleVaultingZombieWalk.gif");
	   Gif.push_back(newQMovie);
	   newQMovie = new QMovie;
	   newQMovie->setFileName("Resources\\PoleVaultingZombieAttack.gif");
	   Gif.push_back(newQMovie);
	   Gif.push_back(newQMovie);
	   newQMovie = new QMovie;
	   newQMovie->setFileName("Resources\\PoleVaultingZombieDie.gif");
	   Gif.push_back(newQMovie);
	   newQMovie = new QMovie;
	   newQMovie->setFileName("Resources\\BoomDie.gif");
	   Gif.push_back(newQMovie);
	   setMyGif(0);

	   timePole = startTimer(100);


	}
	if(type == BucketZombie)
	{
		hasStart = false;
		hasAttack = false;
		hasDied = false;
		hasWeak = false;
		hasChange = false;
	    QMovie *newQMovie;
	
	    newQMovie = new QMovie;
	    newQMovie->setFileName(("Resources\\BucketheadZombie.gif"));
	    Gif.push_back(newQMovie);

	    newQMovie = new QMovie;
	    newQMovie->setFileName("Resources\\BucketheadZombieAttack.gif");
	    Gif.push_back(newQMovie);
	
	    newQMovie = new QMovie;
	    newQMovie->setFileName("Resources\\Zombie3.gif");
	    Gif.push_back(newQMovie);
	    newQMovie = new QMovie;
	    newQMovie->setFileName("Resources\\ZombieDie.gif");
	    Gif.push_back(newQMovie);
	    newQMovie = new QMovie;
	    newQMovie->setFileName("Resources\\ZombieAttack.gif");
	    Gif.push_back(newQMovie);
	    newQMovie = new QMovie;
	    newQMovie->setFileName("Resources\\BoomDie.gif");
	    Gif.push_back(newQMovie);
	    setMyGif(0);
	    timeBucket = startTimer(100);
	}
	if(type == OldMan)
	{
	   life = 80;//
	   hasStart = false;
	   hasAttack = false;
	   hasDied = false;
	   hasWeak = false;
	   hasChange = false;
	   hasexplode = false;
	   hasnewspaper = false;
	   QMovie *newQMovie;
	
	   newQMovie = new QMovie;
	   newQMovie->setFileName(("Resources\\HeadWalk1.gif"));
	   Gif.push_back(newQMovie);

	   newQMovie = new QMovie;
	   newQMovie->setFileName("Resources\\HeadAttack1.gif");
	   Gif.push_back(newQMovie);
	
	   newQMovie = new QMovie;
	   newQMovie->setFileName("Resources\\LostNewspaper.gif");
	   Gif.push_back(newQMovie);
	   newQMovie = new QMovie;
	   newQMovie->setFileName("Resources\\HeadWalk0.gif");
	   Gif.push_back(newQMovie);
	   newQMovie = new QMovie;
	   newQMovie->setFileName("Resources\\Die.gif");
	   Gif.push_back(newQMovie);
	   newQMovie = new QMovie;
	   newQMovie->setFileName("Resources\\BoomDie.gif");
	   Gif.push_back(newQMovie);
	   setMyGif(0);
	   timeOld = startTimer(100);







	}

	
	
	



}
void gameZombie::PlayGif()
{
	

		 
		 picture.load("Resources\\BucketheadZombieAttack.gif");
	     movie.setFileName("Resources\\BucketheadZombieAttack.gif");
		 movie.jumpToFrame(0);
	     setPixmap(movie.currentPixmap());
	     QObject::connect(&movie, SIGNAL(frameChanged(int)), this, SLOT(movie_update()));
		  
		 movie.setSpeed(1);
		 movie.start();
		 
		
	 

}
gameZombie::~gameZombie()
{




}

void gameZombie::PixmapUpdate()
{


  setPixmap(m_Movie.currentPixmap());

}
void gameZombie::movie_update()
{

	//hide();
	setPixmap(movie.currentPixmap());
	
}

 void gameZombie::timerEvent( QTimerEvent *event )
 {
	if(event->timerId() == timeZombie)
	{

	if(attacked == false && bombdie == false)
	{
	 if(pause == 0)
	 {
		speed = 8;
		pos_x -= speed;
	    pause++;
	 }
	 if(pause >= 1)
	 {
	   pause++;

	 }
	 if(pause >= 7)
	 {

		 pause = 0;
	 }
	 setPos(pos_x, pos_y);
	 if(hasAttack == true && hasDied == false)
	 {

		 setMyGif(0);
		 hasStart = true;
		 hasAttack = false;

	 }
	 }
	 if(attacked == true)
	 {
		speed = 0;
	    setPos(pos_x, pos_y);
//	    setMyGif(1);

	 }
	 
	  if(speed == 0  && bombdie == false && life > 0 )
	  {
		 if(hasAttack == false)
		 {

			 setMyGif(1);
			 hasAttack = true;

		 }
	  }
	 
	
	 
     if(life < 8 && bombdie == false)
	 {
		  if(hasDied == false)
		 {

			 setMyGif(2);
			 hasDied = true;

		 }


	 }
	 if(bombdie == true)
	 {
		 boo++;
		if(hasexplode == false)
		{
			 setMyGif(3);
			 hasexplode = true;
			 setPos(pos_x -120, pos_y - 80);
			 speed = 0;
		 }
		 if(boo > 8)
		 {
			 
			 life = 0;
			
		 }



	 }
	 if(life <= 0)
	 {
	 emit damageZombie(this);
	 // delete this;
	 }
	}



	if(event->timerId() == timeBucket)
	{
	 if(attacked == false && bombdie == false)
	 {
	 //hasStart = false;
	 if(pause == 0)
	 {
	 speed = 8;
     pos_x -= speed;
	 pause++;
	 }
	 if(pause >= 1)
	 {
	 pause++;
	 }
	 if(pause >= 7)
		 pause = 0;
	 setPos(pos_x, pos_y);
	  if(hasAttack == true && hasDied == false )
	  {
	  setMyGif(0);
	  hasStart = true;
	  hasAttack = false;
	  }
	 }
	 if(attacked == true)
	 {
	   speed = 0;
	   setPos(pos_x, pos_y);
//	    setMyGif(1);

	 }

	  if(speed == 0 && life > 20 && bombdie == false )
	  {
		  if(hasAttack == false)
		 {

			 setMyGif(1);
			 hasAttack = true;

		 }
	  }
	  if(speed == 0 && life < 20 && life > 0 && bombdie == false)
	  {

		 if(hasChange == false)
		 {

			 setMyGif(4);
			 hasChange = true;

		 }


	  }
	 if( life > 8 && life <= 25 && speed > 0&&bombdie == false)
	 {
		if(hasWeak == false)
		{
			setMyGif(2);
			hasWeak = true;
		}
		 

	 }
	 
     if(life < 8 && bombdie == false)
	 {
		  if(hasDied == false)
		 {

			 setMyGif(3);
			 hasDied = true;

		 }


	 }
	 if(bombdie == true)
	 {
		 boo++;
		if(hasexplode == false)
		{
			 setMyGif(5);
			 hasexplode = true;
			 setPos(pos_x -120, pos_y - 80);
			 speed = 0;
		 }
		 if(boo > 8)
		 {
			 
			 life = 0;
			
		 }



	 }
	 if(life <= 0)
	 {
	 emit damageZombie(this);
	 // delete this;
	  
	 }
	}



	if(event->timerId() == timePole)
	{
		pe = 0;
	 if(attacked == false )
	 {
	// speed = 10;
		if(speed == 0)
		{
			if(jumping == true)
				speed = 5;
			if(jumping == false)
				speed = 10;

		}
	
		pos_x -= speed;
		setPos(pos_x, pos_y);
	    if(hasChange == true)
	    {
	      if(jumpover == false)
	      {
	         if(hasStart == false && hasChange == true)
	         {
	           setMyGif(3);
	           hasChange = false;
	          }
	       }
	  
	      hasStart = true;
	      hasChange = false;
	    }
	 }
	 if(attacked == true)
	 {
	   
	     speed = 0;
	     setPos(pos_x, pos_y);
//	    setMyGif(1);

	 }
	 QMediaPlayer *music = new QMediaPlayer(this);
	  if(jumping == true && jumpequip == true && jumpover == false && attacked == false)
	  {
		  nj ++;
		  	//music = new QMediaPlayer(this);
			music->setMedia(QUrl::fromLocalFile("Resources\\polevault.mp3"));
			music->setVolume(100);
			music->play();
		  if(hasAttack == false)
		 {
			 speed = 1;
			 setMyGif(2);
			 hasAttack = true;

		 }
		  if(nj > 8)
		  {
			  delete music;
			  jumpequip = false;
			  jumpover = true;
		  }
		//jumpequip = false;
	  }
	  if(jumping == true && jumpequip == false && jumpover == true && attacked == false)
	  {
		  pos_x -= 150;
		  setPos(pos_x, pos_y);
		  jumpover = false;
		  if(hasJumping == false)
		 {

			 setMyGif(3);
			 hasJumping = true;

		 }


	  }
	   if(jumping == true && jumpequip == false && jumpover == false && attacked == false)
	  {
		 speed = 5;
		  if(hasJumped == false)
		 {
			 speed = 5;
			 setMyGif(3);
			 hasJumped = true;

		 }


	  }
	  if(speed == 0 && life > 0 && attacked == true)
	  {

		 if(hasChange == false)
		 {

			 setMyGif(4);
			 hasChange = true;

		 }


	  }
	 if(bombdie == true)
	 {
		 boo++;
		if(hasexplode == false)
		{
			 setMyGif(5);
			 hasexplode = true;
			 setPos(pos_x -120, pos_y - 80);
			 speed = 0;
		 }
		 if(boo > 8)
		 {
			 
			 life = 0;
			
		 }



	 }

	 if(life <= 0)
	 {
		 pe++;
	   if(hasDied == false)
		 {

			 setMyGif(5);
			 hasDied = true;

		 }
	  if(pe > 100);
	  {
	 emit damageZombie(this);
	 
	  }
	  
	 }


	}
	if(event->timerId() == timeOld)
	{
	 if(attacked == false && bombdie == false)
	 {
	 if(pause == 0)
	 {
	 speed = 8;
     pos_x -= speed;
	 pause++;
	 }
	 if(pause >= 1)
	 {
	 pause++;
	 }
	 if(pause >= 7)
		 pause = 0;
	 setPos(pos_x, pos_y);
	  if(hasAttack == true && hasDied == false )
	  {
	  setMyGif(0);
	  hasStart = true;
	  hasAttack = false;
	  }
	 }

	 if(attacked == true)
	 {
	   speed = 0;
	   setPos(pos_x, pos_y);

	 }

	 if(speed == 0 && life > 40 && bombdie == false )
	 {
		  if(hasAttack == false)
		 {

			 setMyGif(1);
			 hasAttack = true;

		 }
	  }
	  
	  if(speed == 0 && life < 30 && life > 0 && bombdie == false)
	  {

		 if(hasChange == false)
		 {

			 setMyGif(3);
			 hasChange = true;

		 }


	  }
	  QMediaPlayer *music1 = new QMediaPlayer(this);
	  if(life <=  40 && life > 30)
	  {
		  if(hasnewspaper == false)
		 {
			music1 = new QMediaPlayer(this);
			music1->setMedia(QUrl::fromLocalFile("Resources\\newspaper_rarrgh2.mp3"));
			music1->setVolume(100);
			music1->play();
			 setMyGif(2);
			 hasnewspaper = true;

		 }


	  }
	 if( life > 8 && life < 30 && speed > 0&&bombdie == false)
	 {
		 delete music1;
		if(hasWeak == false)
		{
			setMyGif(3);
			hasWeak = true;
		}
		 

	 }
	 
     if(life < 8 && bombdie == false)
	 {
		  if(hasDied == false)
		 {

			 setMyGif(4);
			 hasDied = true;

		 }


	 }
	 QMediaPlayer *music;
	 if(bombdie == true)
	 {
		 boo++;
		if(hasexplode == false)
		{
			 setMyGif(5);
			 hasexplode = true;
			 setPos(pos_x -120, pos_y - 80);
			 speed = 0;
			 music = new QMediaPlayer(this);
			 music->setMedia(QUrl::fromLocalFile("Resources\\cherrybomb.mp3"));
			 music->setVolume(100);
			 music->play();
		 }
		 if(boo > 4)
		 {
			 delete music;
			 life = 0;
			
		 }



	 }
	 if(life <= 0)
	 {
	  emit damageZombie(this);
	 // delete this;
	  
	 }
	 }
	if(event->timerId() == timePause)
	{

		speed = 0;
		setPos(pos_x, pos_y);
	}
 }

void gameZombie::destroy()
{

	delete this;

}

void gameZombie::playGif(const QString &filename)
{

	
	  m_Movie.setFileName(filename);
	  m_Movie.jumpToFrame(0);
	  setPixmap(m_Movie.currentPixmap());
		
		
	  QObject::connect(&m_Movie, SIGNAL(frameChanged(int)), this, SLOT(PixmapUpdate()));
      m_Movie.setSpeed(1);
	  m_Movie.start();



}




