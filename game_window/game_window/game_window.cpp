#include "game_window.h"
#include<qpainter.h>
#include<QEvent>
#include<QResizeEvent>
#include"game_controller.h"
#include<qpixmap.h>
#include"game_button.h"
#include"game_screen.h"
#include <qscrollbar>  
#include"game_player.h"
#include"game_zombie.h"
#include"game_weapon.h"
game_window::game_window(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setMouseTracking(true);
	rEnd = false;
	client = new game_view(this);
	client->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setCentralWidget(client);  //��Ϊ���ؼ�
	QObject::connect(client->begin, SIGNAL(clicked()), client, SLOT(move_to_screen()));  //��ʼ��ť��Ϣ��Ӧ
	//����6�����Ӷ�Ϊ�ɿ�Ƭǣ������ֲ�����Ӧ
	QObject::connect(client->card[0], SIGNAL(press(int )), client, SLOT(makeCard(int )));
	QObject::connect(client->card[1], SIGNAL(press(int )), client, SLOT(makeCard(int )));
	QObject::connect(client->card[2], SIGNAL(press(int )), client, SLOT(makeCard(int )));
	QObject::connect(client->card[3], SIGNAL(press(int )), client, SLOT(makeCard(int )));
	QObject::connect(client->card[4], SIGNAL(press(int )), client, SLOT(makeCard(int )));
	QObject::connect(client->card[5], SIGNAL(press(int )), client, SLOT(makeCard(int )));
	//��������Ϊ���ӵ���Ϣ��Ӧ
	QObject::connect(client->clear, SIGNAL(clicked()), client, SLOT(getShover()));
	QObject::connect(client->clear, SIGNAL(pres()), client, SLOT(clearPlant()));
	QObject::connect(client->clear, SIGNAL(release()), client, SLOT(mouseback()));
   

	
}

game_window::~game_window()
{
	delete client;
}


void game_window::endthis()
{

	client = new game_view(this);


}

//	QObject::connect(client->card[0], SIGNAL(clicked(int )), client, SLOT(makeFade(int )));