#include"game_weapon.h"
int gameWeapon::num = 0;
gameWeapon::gameWeapon(QWidget *parent)
	:gamePlayer(parent)
{
	
	type = PlantWeapon;
	speed = 12;
	life = 10000000;
	power = 5;
	defend = 0;
	collision = false;
	startTimer(100);
//	numChange();
//	pos_x = 0;
//	pos_y = 0;
	setPos(pos_x , pos_y);
	picture.load("Resources\\Pea.png");
	setPixmap(picture);

}

gameWeapon::gameWeapon(int x, int y, QWidget *parent)
	:gamePlayer(parent)
{
	
	type = PlantWeapon;
	speed = 50;
	life = 10000000;
	power = 5;
	defend = 0;
	collision = false;
	pos_x = x;
	pos_y = y;
	startTimer(100);
//	setPos(x, y);
	picture.load("Resources\\Pea.png");
	setPixmap(picture);
	//emit press();
}







void gameWeapon::timerEvent( QTimerEvent *event )
{

	if(life > 0)
	{
	num++;
	pos_x += 25;
	setPos(pos_x + speed, pos_y);
	}
	if(life <= 0)
	{
		emit damageBullet(this);
		delete this;

	}

}

void gameWeapon::emitBullet()
{
	startTimer(1000);



}