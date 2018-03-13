#ifndef GAME_CAR_H
#define GAME_CAR_H

#include"game_player.h"
//小车的类
class gameCar: public gamePlayer
{
	Q_OBJECT;
public:
	gameCar(QWidget *parent);
	gameCar(int x, int y, QWidget *parent);
	~gameCar(){}
public:
	//实现gif帧数的更换
	void PixmapUpdate()
	{

		setPixmap(m_Movie.currentPixmap());

	}
	void timerEvent( QTimerEvent *event );
public:
	bool drive; //判断是否开车
};























#endif