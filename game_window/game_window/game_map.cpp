#include"game_map.h"

int gameLawn::PlantOccupied[10][10] = { 0 };
int gameLawn::ZombieOccupied[10][10] = { 0 };
gameLawn::gameLawn(QWidget *parent)
	:PlantExist(true)
{







}






void gameLawn::judgePlant(int x, int y )
{

	if(x > 998 || x < 227 || y < 56 || y > 582)
	{
		PlantExist = false;
        

	}
	else
	{
		//exist = true;
	//	row = (x - 250) / 78;
	//	line = (y - 80) / 102;
		line = ((double)(y) + 35- 78.0)/96.0;
		
		row = ((double)(x) + 30 - 244)/86.0;
		
		if(PlantOccupied[line][row] == 0)
		{
		  PlantExist = true;


		}
		PlantOccupied[line][row] = 1;

	}



}

void gameLawn::judgeZombie(int x, int y)
{
	if(x > 998 || x < 250 || y < 71 || y > 568)
	{
		ZombieExist = false;
        

	}
	else
	{
		//exist = true;
		zombie_row = (x - 250) / 78;
		zombie_line = (y - 80) / 102;
		if(ZombieOccupied[zombie_line][zombie_row] == 0)
		{
		  ZombieExist = true;


		}
		ZombieOccupied[zombie_line][zombie_row] = 1;

	}




}

bool gameLawn::equal(Block a, Block b)
{

	if(a.block_line == b.block_line && a.block_list == b.block_list)
	{
		return true;
	}
	else
	{
		return false;


	}




}


Block gameLawn::find_block(int x, int y)
{
	Block block;
	if(x > 998 || x < 227 || y < 56 || y > 582)
	{
		//ZombieExist = false;
        block.block_line = -2;
		block.block_list = -2;

	}
	else
	{
		//exist = true;
		block.block_list = (x - 250) / 78;
		block.block_line = (y - 80) / 102;
		

	}

	return block;

}