#ifndef GAME_ZOMBIE_H
#define GAME_ZOMBIE_H
#include"game_player.h"
#include"game_gif.h"
#include"game_map.h"
#include<qpixmap.h>
//�������ɽ�ʬ
class gameZombie:public gamePlayer
{
	Q_OBJECT;
public:
	gameZombie(QWidget *parent);
	gameZombie(const QString &filename, QWidget *parent);
	gameZombie(int x, int y, const QString &filename, QWidget *parent);
	gameZombie(bool play, int x, int y, const QString &filename, QWidget *parent);
	gameZombie(PlayerType kind, int x, int y, const QString &filename, QWidget *parent);
	~gameZombie();
public:

	void setLife(int qlife)
	{

		life = qlife;

	}
	void killLife(int damage)
	{
		life -= damage;

	}
	public slots:
		void PixmapUpdate();
		void movie_update();
		void destroy();
public:
	void timerEvent( QTimerEvent *event );
	void playGif(const QString &filename);
signals:
	void damageZombie(gameZombie*);
public:
	bool attacked; //�ж��Ƿ񹥻�
	bool beJump;   //�ж��Ƿ���Ծ
	int  ri;
	int play;
	int die;
	int pause; // ��ʬ��·��״̬
	int pause1;
	int nu;
	int timeZombie; //��ͨ��ʬ�ļ�ʱ��
	int timeBucket; //��Ͱ��ʬ�ļ�ʱ��
	int numb;
	int timePole; //�Ÿ�����ʬ��ʱ��
	int timePause;
	QMovie ZombieMove;
	QMovie ZombieNormal;
	QMovie ZombieDie;
	QMovie ZombieEat;
	QMovie ZombieBucket;
	QTimer *time_die;
	QMovie PoleMovie;
	QVector<QMovie*>Gif;
	int GifNumber;
	QLabel *zo;
	QMovie *newMovie;
	bool hasStart; //��ʬ�Ƿ��ƶ�
	bool hasAttack;//��ʬ�Ƿ����
	bool hasDied; //��ʬ�Ƿ񱻸ɵ�
	bool hasWeak;// ��ʬ�Ƿ񱻴򵽲�Ѫ
	bool hasChange; //��ʬ�Ƿ���
	bool jumping;  // ��ʬ��������
	bool jumpequip;
	bool hasJumping;
	int nj;
	bool jumpover;  //�Ÿ�����ʬ�Ƿ��Ѿ���Ծ��
	bool hasJumped;
	bool bombdie;   //   ��ʬ�Ƿ�ը��
	int boo; 
	bool hasexplode; //�Ƿ�ը
	bool hasnewspaper; //�Ƿ�ֽ��ʬ�����ű�ֽ
	int pe;
	int timeOld; //��ֽ��ʬ�ļ�ʱ��
public:
	void PlayGif();
	public slots:
	void playAction();
	void ZombieMove_update()
	{
		setPixmap(ZombieMove.currentPixmap());

	}
	void ZombieBucket_update()
	{
		if(life > 25)
		setPixmap(ZombieBucket.currentPixmap());


	}
	void PoleZombieUpdate()
	{
		setPixmap(PoleMovie.currentPixmap());

	}
	void ZombieNormalUpdate()
	{
	      
		setPixmap(ZombieNormal.currentPixmap());

	}
	void ZombieDieUpdate()
	{

		setPixmap(ZombieDie.currentPixmap());

	}
	void ZombieEatUpdate()
	{
			
		pause1 ++;

			
		if(pause1 >= 30)
		{
			pause1 = 0;
			setPixmap(ZombieEat.currentPixmap());

		}

	}
	void judgeMovie()
	{
		//hide();
		//play = 1;

	}
	void setnewPixmap(int i)
	{
			//hide();
		setPixmap(Gif[GifNumber]->currentPixmap());

	}
	void  setMyGif(int i)
	{
		for (const auto &i : Gif)
		{
			i->stop();
		}
		GifNumber = i;
		Gif[i]->jumpToFrame(0);
		connect(Gif[i], SIGNAL(frameChanged(int)), this, SLOT(setnewPixmap(int)));
		Gif[i]->start();
	}
};


























#endif