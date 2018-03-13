#ifndef GAME_SLOT_H
#define GAME_SLOT_H
#include"game_plant.h"
#include"game_player.h"
#include"game_message.h"
#include<QRectF>
#include<QGraphicsPixmapItem>
//���쿨Ƭ�뿨�ۺͲ��Ӽ�����ȴ��
class gameSlot: public gamePlayer
{
	Q_OBJECT;
public:
	gameSlot(QWidget *parent = 0){}
	gameSlot(QPixmap Qcard, QPixmap card1, QPixmap card2, QWidget *parent);
	gameSlot(QPixmap Qcard, QPixmap card1, QPixmap card2, int r, QWidget *parent);
	~gameSlot(){}
public:
	QPixmap card_up;
	QPixmap card_down;
	QPixmap card;
    int px;
	int py;
	int judge;
signals:
	void clicked();
	void press( int);
	void pres();
	void release();
	void clicked(int);
	
public slots:
	void isPressedChange();

public:
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void hoverEnterEvent(QGraphicsSceneHoverEvent* event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
public:
    bool isPressed; 
	int create; //�ж�mouseMoveEvent��״̬����
	int rank; // �жϽ�����Ʒ����ı���
	//
	gamePlant *plant;
	gamePlant *shooter;
};





















#endif