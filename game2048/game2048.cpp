#include "game2048.h"
//这是getMax函数的实现
int getMax(int a[10][10], int xw, int yw)
{
	int maxnum = 0;
	for (int i = 0; i < yw; i++)
	{
		for (int j = 0; j < xw; j++)
		{
			maxnum = maxnum > a[j][i] ? maxnum : a[j][i];
		}
	}
	//a[0][0] = 100;
	return maxnum;
}

//以下是你们需要完成的
void upmove(int a[10][10], int ROW, int COL)	//左移
{
	for (int col = 1; col < COL; ++col)
	{
		for (int ccol = col; ccol >= 1; --ccol)
		{
			for (int row = 0; row < ROW; ++row)
			{
				//上一个格子为空
				if (a[row][ccol - 1] == 0)
				{
					a[row][ccol - 1] = a[row][ccol];
					a[row][ccol] = 0;
				}
				else
				{
					//合并
					if (a[row][ccol - 1] == a[row][ccol])
					{
						a[row][ccol - 1] *= 2;
						a[row][ccol] = 0;
					}

				}
			}
		}
	}

}

void downmove(int a[10][10], int ROW, int COL)	//右移
{
	for (int col = COL - 2; col >= 0; --col)
	{
		for (int ccol = col; ccol <= COL - 2; ++ccol)
		{
			for (int row = 0; row < ROW; ++row)
			{
				//上一个格子为空
				if (a[row][ccol + 1] == 0)
				{
					a[row][ccol + 1] = a[row][ccol];
					a[row][ccol] = 0;
				}
				else
				{
					//合并
					if (a[row][ccol + 1] == a[row][ccol])
					{
						a[row][ccol + 1] *= 2;
						a[row][ccol] = 0;
					}

				}
			}
		}
	}


}

void leftmove(int a[10][10], int ROW, int COL)		//上移
{
	for (int row = 1; row < ROW; ++row)
	{
		for (int crow = row; crow >= 1; --crow)
		{
			for (int col = 0; col < COL; ++col)
			{
				//上一个格子为空
				if (a[crow - 1][col] == 0)
				{
					a[crow - 1][col] = a[crow][col];
					a[crow][col] = 0;
				}
				else
				{
					//合并
					if (a[crow - 1][col] == a[crow][col])
					{
						a[crow - 1][col] *= 2;
						a[crow][col] = 0;
					}

				}
			}
		}
	}

	
}

void rightmove(int a[10][10], int ROW, int COL)	//下移
{
	for (int row = ROW - 2; row >= 0; --row)
	{
		for (int crow = row; crow < ROW - 1; ++crow)
		{
			for (int col = 0; col < COL; ++col)
			{
				//上一个格子为空
				if (a[crow + 1][col] == 0)
				{
					a[crow + 1][col] = a[crow][col];
					a[crow][col] = 0;
				}
				else
				{
					//合并
					if (a[crow + 1][col] == a[crow][col])
					{
						a[crow + 1][col] *= 2;
						a[crow][col] = 0;
					}

				}
			}
		}
	}

}

bool creatRandNum(int a[10][10], int xw, int yw)	//随机生成数
{
	int x = -1;
	int y = -1;
	int num=0;
	int times = 0;
	int maxTimes = xw * yw;
	int whitch = random(3);
	do
	{
		x = rand() % xw;
		y = rand() % yw;
		++times;
	} while (a[x][y] != 0 && times <= maxTimes);

	if (times >= maxTimes)
	{
		return false;
	}
	else
	{
		if (whitch == 0)
		{
			num = 4;
		}
		else if (whitch)
		{
			num = 2;
		}
		a[x][y] = num;
	}
	return true;
}

int isgameover(int a[10][10], int xw, int yw, bool iscontinue)	//判断游戏是否结束
{
	int const Game_win = 1;
	int const Game_lose = 2;
	int const Game_continue = 3;

	if (!iscontinue)
	{
		for (int i = 0; i < xw; ++i)
		{
			for (int j = 0; j < yw; ++j)
			{
				if (a[i][j] >= 32)
				{
					return Game_win;
					break;
				}
			}
		};
	}

	for (int i = 0; i < xw; ++i)
	{
		for (int j = 0; j < yw - 1; ++j)
		{
			if (!a[i][j] || (a[i][j] == a[i][j + 1]))
			{
				return Game_continue;
				break;
			}
		}
	}
	for (int j = 0; j < yw; ++j)
	{
		for (int i = 0; i < xw - 1; ++i)
		{
			if (!a[i][j] || (a[i][j] == a[i + 1][j]))
			{
				return Game_continue;
				break;
			}
		}
	}


	return Game_lose;
}