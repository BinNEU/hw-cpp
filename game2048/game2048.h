#pragma once
#ifndef SQUARD_H
#define SQUARD_H
#include<cstdlib>
#define random(x) (rand()%(x))		//ʹ��random(x)����[0,x)�������

// ���������ƶ�

void leftmove(int a[10][10], int ROW, int COL);
void rightmove(int a[10][10], int ROW, int COL);
void upmove(int a[10][10], int ROW, int COL);
void downmove(int a[10][10], int ROW, int COL);

bool creatRandNum(int a[10][10], int xw, int yw);	//���������
int getMax(int a[10][10], int xw, int yw);			//��ȡ�����
int isgameover(int a[10][10], int xw, int yw, bool iscontinue);		//�ж��Ƿ�ҵ�

#endif
