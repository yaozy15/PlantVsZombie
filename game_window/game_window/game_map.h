#ifndef GAME_MAP_H
#define GAME_MAP_H

#include<qwidget.h>
typedef struct gameBlock
{
public:
	int block_line;
	int block_list;


}Block;
 //判断和储存植物的横纵坐标
class gameLawn: public QObject
{
	Q_OBJECT
public:
	gameLawn(QWidget *parent = 0);
	~gameLawn(){}
public:
	int line;   //第几行
	int row;    //第几列
	int zombie_line;
	int zombie_row;
    static int PlantOccupied[10][10];  //判断该格子是否已种上了植物
	static int ZombieOccupied[10][10];
	bool PlantExist;  //判断该格子中是否有植物
	bool ZombieExist;
	int x[100];  //记录豌豆射手横坐标
	int y[100];  //记录豌豆射手纵坐标
	int x1[100]; //记录向日葵横坐标
	int y1[100];//记录向日葵的纵坐标
	int x2[100]; //记录双发射手的横坐标
	int y2[100];  //记录双发射手的纵坐标
	int x3[100]; //记录机枪射手的横坐标
	int y3[100]; //记录机枪射手的纵坐标
public:
	Block find_block(int x, int y);
	bool equal(Block a, Block b);
public slots:
	void judgePlant(int x, int y );//判断该坐标所在格子有没有植物
	void judgeZombie(int x, int y);




};

































#endif