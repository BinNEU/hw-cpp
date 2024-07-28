#pragma once
#ifndef SQUARD_H
#define SQUARD_H
#include<cstdlib>
#define random(x) (rand()%(x))		//使用random(x)生成[0,x)的随机数

// 上下左右移动

void leftmove(int a[10][10], int ROW, int COL);
void rightmove(int a[10][10], int ROW, int COL);
void upmove(int a[10][10], int ROW, int COL);
void downmove(int a[10][10], int ROW, int COL);

bool creatRandNum(int a[10][10], int xw, int yw);	//随机生成数
int getMax(int a[10][10], int xw, int yw);			//获取最高数
int isgameover(int a[10][10], int xw, int yw, bool iscontinue);		//判断是否挂掉

#endif
