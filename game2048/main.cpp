#include "game2048.h"
#include <iostream>
#include<time.h> 
#include<stdlib.h>
using namespace std;
int main()
{
	srand((int)time(0));
	char ctrl;
	int squard[10][10];				//��Ϸ���� squard[x][y]
	int xwidth = 4, ywidth = 4;		//�����С
	bool gameContinue = false;		//ʤ������Ϸ�Ƿ����

	//�����ʼ��
	for (int i = 0; i < xwidth; i++)
	{
		for (int j = 0; j < ywidth; j++)
		{
			squard[i][j] = 0;
		}
	}

	while (true)
	{
		//���������
		creatRandNum(squard, xwidth, ywidth);

		//�����Ϸ�������
		cout << "\n\n\n\n\n\n\n\n\n\n\n";
		for (int i = 0; i < ywidth; i++)
		{
			cout << "	";
			for (int j = 0; j < xwidth; j++)
			{
				cout << squard[j][i] << "	";
			}
			cout << endl << endl;
		}
		cout << "\n\n\n\n\n\n";

		//��������ﵽ2048��ʤ��
		if (isgameover(squard, xwidth, ywidth, gameContinue) == 1)
		{
			cout << "You win! continue(c), restart(r), quit(q)" << endl;
			while (true)
			{
				cin >> ctrl;
				if (ctrl == 'c')	//������Ϸ
				{
					gameContinue = true;
					break;
				}
				else if (ctrl == 'r')	//����һ��
				{
					//������Ϸ����
					for (int i = 0; i < ywidth; i++)
					{
						for (int j = 0; j < xwidth; j++)
						{
							squard[j][i] = 0;
						}
					}
					creatRandNum(squard, xwidth, ywidth);

					//�����Ϸ�������
					cout << "\n\n\n\n\n\n\n\n\n\n\n";
					for (int i = 0; i < ywidth; i++)
					{
						cout << "	";
						for (int j = 0; j < xwidth; j++)
						{
							cout << squard[j][i] << "	";
						}
						cout << endl << endl;
					}
					cout << "\n\n\n\n\n\n";
					break;
				}
				else if (ctrl == 'q')	//�˳�
				{
					return 0;
				}
				else
				{
					cout << "Command error, please reenter" << endl;
				}
			}
		}

		//���޷�����������Ϸ����
		if (isgameover(squard, xwidth, ywidth, gameContinue) == 2)
		{
			while (true)
			{
				cout << "You lost, restart��(y/n)" << endl;
				cin >> ctrl;
				if (ctrl == 'n')
				{
					return 0;
				}
				if (ctrl == 'y')
				{
					for (int i = 0; i < xwidth; i++)
					{
						for (int j = 0; j < ywidth; j++)
						{
							squard[i][j] = 0;
						}
					}
					break;
				}
			}
		}

		//�������
		cout << "Input wasd to control, or quit(q)" << "\n\n\n\n\n\n";
		while (true)
		{
			cin >> ctrl;
			if (ctrl == 'w')
			{
				upmove(squard, xwidth, ywidth);
				break;
			}
			else if (ctrl == 'a')
			{
				leftmove(squard, xwidth, ywidth);
				break;
			}
			else if (ctrl == 's')
			{
				downmove(squard, xwidth, ywidth);
				break;
			}
			else if (ctrl == 'd')
			{
				rightmove(squard, xwidth, ywidth);
				break;
			}
			else if (ctrl == 'q')
			{
				cout << "Really quit��(y/n)" << endl;
				cin >> ctrl;
				if (ctrl == 'y')
				{
					return 0;
				}
			}
			else
			{
				cout << "Command error, please reenter" << endl;
			}
		}


	}

}

