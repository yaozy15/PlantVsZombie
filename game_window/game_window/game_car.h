#ifndef GAME_CAR_H
#define GAME_CAR_H

#include"game_player.h"
//С������
class gameCar: public gamePlayer
{
	Q_OBJECT;
public:
	gameCar(QWidget *parent);
	gameCar(int x, int y, QWidget *parent);
	~gameCar(){}
public:
	//ʵ��gif֡���ĸ���
	void PixmapUpdate()
	{

		setPixmap(m_Movie.currentPixmap());

	}
	void timerEvent( QTimerEvent *event );
public:
	bool drive; //�ж��Ƿ񿪳�
};























#endif