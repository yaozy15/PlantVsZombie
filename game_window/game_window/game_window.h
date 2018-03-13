#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H


#include <QtWidgets/QMainWindow>
#include "ui_game_window.h"
#include "game_button.h"
#include"game_controller.h"
#include"game_player.h"
#include"game_screen.h"
#include <QtGui>
#include <qgraphicsitem.h>
#include <qgraphicsscene>  
#include <qgraphicsview>  
#include <qgraphicsitem>  
#include"game_weapon.h"
class game_window : public QMainWindow
{
	Q_OBJECT;

public:
	game_window(QWidget *parent = 0);
	~game_window();

private:
	Ui::game_windowClass ui;
public:
  game_view *client; //本游戏的场景
  gamePlayer*s;
 public slots:
  void endthis();
 
public:
	bool rEnd;

	 
	
};

#endif // GAME_WINDOW_H
