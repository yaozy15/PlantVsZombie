#ifndef GAME_ZOMBIE_H
#define GAME_ZOMBIE_H
#include"game_player.h"
#include"game_gif.h"
#include"game_map.h"
#include<qpixmap.h>
//用来生成僵尸
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
	bool attacked; //判断是否攻击
	bool beJump;   //判断是否跳跃
	int  ri;
	int play;
	int die;
	int pause; // 僵尸走路的状态
	int pause1;
	int nu;
	int timeZombie; //普通僵尸的计时器
	int timeBucket; //铁桶僵尸的计时器
	int numb;
	int timePole; //撑杆跳僵尸计时器
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
	bool hasStart; //僵尸是否移动
	bool hasAttack;//僵尸是否进攻
	bool hasDied; //僵尸是否被干掉
	bool hasWeak;// 僵尸是否被打到残血
	bool hasChange; //僵尸是否暴走
	bool jumping;  // 僵尸起跳了吗
	bool jumpequip;
	bool hasJumping;
	int nj;
	bool jumpover;  //撑杆跳僵尸是否已经跳跃过
	bool hasJumped;
	bool bombdie;   //   僵尸是否被炸死
	int boo; 
	bool hasexplode; //是否爆炸
	bool hasnewspaper; //是否报纸僵尸还拿着报纸
	int pe;
	int timeOld; //报纸僵尸的计时器
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