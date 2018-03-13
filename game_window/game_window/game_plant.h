#ifndef GAME_PLANT_H
#define GAME_PLANT_H

#include"game_player.h"
#include<qpixmap.h>
#include"game_weapon.h"
#include<qstring.h>
//��������ֲ��
class gamePlant: public gamePlayer
{
	Q_OBJECT;
public:
	gamePlant(QWidget *parent = 0);
	gamePlant(PlayerType kind, const QString &filename, QWidget *parent);
	gamePlant(const QString &filename, int x, int y,  QWidget *parent);
	gamePlant(int n, PlayerType kind, const QString &filename, int x, int y,  QWidget *parent); //
	gamePlant(int n, PlayerType kind, const QString &filename, int x, int y);
	gamePlant(PlayerType kind, const QString&filename);
	~gamePlant(){}
signals:
	void needWeapon( int );
	void needMoreWeapon( int );
	void needSun(int, gamePlant*);
	void damage(gamePlant*);
	void damageCherry(gamePlant*);
	void needBomb(int);
	void needMaxWeapon(int);
public:
	int sunPrice;
	bool threatened;
	int regist;
	int regist1;
	gameWeapon *pea;  //�㶹����
	static int pea_num;
	int count;
	int iDPlant;
	int iPlant;
	int cost;  // ֲ��Ļ���
	int iDCherry;  //ӣ��ը�����ź�
	bool bomb;  //ӣ��ը���Ƿ�ը
	bool explode; //�Ƿ�ը
	bool explosion;
	int bombr;
	int regist2;
	QVector<QMovie*>Gif;  //�������е�gif
	QVector<QMovie*>Gifs;
	int GifNumber;
	int GifNumbers;
	bool hasSun;
	bool forceDestroy;
	QGraphicsPixmapItem *sunshine;
	QMovie sh;
	bool showS;
	int sunN;
	int regis;
	int reg;
public:
	void setLife(int);
	void killLife(int);
	int getLife();
	void setSunPrice(int);
	int getSunPrice();
	void timerEvent( QTimerEvent *event );
	gameWeapon *createWeapon();
	gameWeapon *t;
	QGraphicsPixmapItem shine;
	
	void  setMyGif(int i)
	{
			
		GifNumber = i;
		if(type == sunPlant)
		Gif[i]->jumpToFrame(0);
		
		connect(Gif[i], SIGNAL(frameChanged(int)), this, SLOT(setnewPixmap(int)));
		Gif[i]->start();
	}
	void  setMyGifs(int i)
	{
		  
		GifNumbers = i;
		if(type == sunPlant)
		Gifs[i]->jumpToFrame((this->Gif[0])->currentFrameNumber());
		
		connect(Gifs[i], SIGNAL(frameChanged(int)), this, SLOT(setnewPixmaps(int)));
		Gifs[i]->start();
	}
public slots:
	void PixmapUpdate();
	void PixmapSUpdate()
	{

		setPixmap(m_Movie.currentPixmap());
		sh.jumpToFrame(m_Movie.currentFrameNumber());
		shine.setPixmap(sh.currentPixmap());
	}
	void setnewPixmap(int i)
	{
		setPixmap(Gif[GifNumber]->currentPixmap());

	}
	void setnewPixmaps(int i)
	{
			
	    setPixmap(Gifs[GifNumbers]->currentPixmap());

	}

};


























#endif