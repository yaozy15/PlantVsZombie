#ifndef GAME_MAP_H
#define GAME_MAP_H

#include<qwidget.h>
typedef struct gameBlock
{
public:
	int block_line;
	int block_list;


}Block;
 //�жϺʹ���ֲ��ĺ�������
class gameLawn: public QObject
{
	Q_OBJECT
public:
	gameLawn(QWidget *parent = 0);
	~gameLawn(){}
public:
	int line;   //�ڼ���
	int row;    //�ڼ���
	int zombie_line;
	int zombie_row;
    static int PlantOccupied[10][10];  //�жϸø����Ƿ���������ֲ��
	static int ZombieOccupied[10][10];
	bool PlantExist;  //�жϸø������Ƿ���ֲ��
	bool ZombieExist;
	int x[100];  //��¼�㶹���ֺ�����
	int y[100];  //��¼�㶹����������
	int x1[100]; //��¼���տ�������
	int y1[100];//��¼���տ���������
	int x2[100]; //��¼˫�����ֵĺ�����
	int y2[100];  //��¼˫�����ֵ�������
	int x3[100]; //��¼��ǹ���ֵĺ�����
	int y3[100]; //��¼��ǹ���ֵ�������
public:
	Block find_block(int x, int y);
	bool equal(Block a, Block b);
public slots:
	void judgePlant(int x, int y );//�жϸ��������ڸ�����û��ֲ��
	void judgeZombie(int x, int y);




};

































#endif