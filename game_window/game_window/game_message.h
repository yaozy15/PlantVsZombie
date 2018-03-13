#ifndef GAME_MESSAGE_H
#define GAME_MESSAGE_H
/*
消息处理器

*/
#include"game_button.h"
#include"game_screen.h"
//#include"game_gif.h"
#include"game_player.h"
#include"game_zombie.h"
class gameMessage: public QObject
{
	Q_OBJECT
public:
	gameMessage(QWidget *parent);
	~gameMessage(){}
public:
	int bool_begin;
	int bool_battle;
	int bool_graphics1;
	int bool_graphics2;
	public slots:
		void bool_begin_change()
		{
			bool_begin = 1;

		}
		void bool_battle_change()
		{
			bool_battle = 1;

		}




};












#endif