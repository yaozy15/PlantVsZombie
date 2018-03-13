#ifndef GAME_WEAPON_H
#define GAME_WEAPON_H

#include"game_player.h"
#include<qwidget.h>
#include<QGraphicsPixmapItem>
#include <QtGui>
#include <qgraphicsitem.h>
#include <qgraphicsscene>  
#include <qgraphicsview>  
#include <qgraphicsitem>  

//�������ɵ�ҩ����
class gameWeapon: public gamePlayer
{
	Q_OBJECT;
public:
	gameWeapon(QWidget *parent = 0);
	gameWeapon(int x, int y, QWidget *parent = 0);
	~gameWeapon(){}
public:
	bool collision;  //����������ײ
	static int num;
signals:
	void press();
	void damageBullet(gameWeapon*);
public:
	void emitBullet( );
	void timerEvent( QTimerEvent *event );
	void numChange();
	


};




























#endif