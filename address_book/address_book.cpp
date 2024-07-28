#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#define MAX 1000
using namespace std;

void showmenu()
{
	cout << "************************" << endl;
	cout << "*****1�������ϵ��******" << endl;
	cout << "*****2����ʾ��ϵ��******" << endl;
	cout << "*****3��ɾ����ϵ��******" << endl;
	cout << "*****4��������ϵ��******" << endl;
	cout << "*****5���޸���ϵ��******" << endl;
	cout << "*****6�������ϵ��******" << endl;
	cout << "*****0���˳�ͨѶ¼******" << endl;
	cout << "************************" << endl;
}

struct person
{
	string name;
	int sex;//1�� 2Ů
	int age;
	string phone;
	string address;
};
struct addressbooks
{
	struct person personarray[MAX];
	int size;
};

void addperson(addressbooks * abs)
{
	//�ж�MAX
	if (abs->size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		string name;
		cout << "����������" << endl;
		cin >> name;
		for (int i = 0; i < MAX; i++)
		{
			if (name == abs->personarray[i].name) 
			{ 
				cout << "�Ѿ���ӹ�����ϵ��" << endl; 
				system("pause");
				system("cls");
				return;
			}
		}
		abs->personarray[abs->size].name = name;

		cout << "�����Ա�" << endl;
		cout << "1--��\n2--Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[abs->size].sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		cout << "�������䣺" << endl;
		int age;
		while (true)
		{
			cin >> age;
			if (age <= 135 && age >= 0)
			{
				abs->personarray[abs->size].age = age;
				break;
			}
			cout << "������������������" << endl;			
		}
		cout << "������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personarray[abs->size].phone = phone;
		cout << "�����ͥסַ��" << endl;
		string addr;
		cin >> addr;
		abs->personarray[abs->size].address = addr;
		abs->size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}
void showperson(addressbooks* abs)
{
	if (abs->size == 0)cout << "��ǰ��¼Ϊ��" << endl;
	else
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout << "������" << abs->personarray[i].name << "\t";
			cout << "�Ա�" << (abs->personarray[i].sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personarray[i].age << "\t";
			cout << "�绰��" << abs->personarray[i].phone << "\t";
			cout << "סַ��" << abs->personarray[i].address << "\n\n";
		}
	}
	system("pause");
	system("cls");
}
int isexist(addressbooks * abs,string name)
{
	for (int i = 0; i < abs->size; i++)
	{
		if (abs->personarray[i].name == name)return i;
	}
	return -1;
}
void deleteperson(addressbooks * abs)
{
	cout << "������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		for(int i=ret;i<abs->size;i++)
		{ 
			abs->personarray[i] = abs->personarray[i + 1];
		}
		abs->size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else { cout << "���޴���" << endl; }
	system("pause");
	system("cls");
}
void findperson(addressbooks* abs)
{
	cout << "��Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->personarray[ret].name << endl;
		cout << "�Ա�" << (abs->personarray[ret].sex == 1 ? "��" : "Ů") << endl;
		cout << "���䣺" << abs->personarray[ret].age << endl;
		cout << "�绰��" << abs->personarray[ret].phone << endl;
		cout << "סַ��" << abs->personarray[ret].address << endl;
		system("pause");
		system("cls");
	}
	else { cout << "���޴���" << endl; }
	system("pause");
	system("cls");
}
void modifyperson(addressbooks* abs)
{
	cout << "�����������޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personarray[ret].name = name;

		cout << "�����Ա�" << endl;
		cout << "1--��\n2--Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[ret].sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		cout << "�������䣺" << endl;
		int age;
		while (true)
		{
			cin >> age;
			if (age <= 120 && age >= 0)
			{
				abs->personarray[ret].age = age;
				break;
			}
			cout << "������������������" << endl;			
		}
		cout << "������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personarray[ret].phone = phone;
		cout << "�����ͥסַ��" << endl;
		string addr;
		cin >> addr;
		abs->personarray[ret].address = addr;
		cout << "�޸ĳɹ�" << endl;
	}
	else {cout << "���޴���" << endl;}
	system("pause");
	system("cls");
}
void clearperson(addressbooks* abs)
{
	abs->size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}

int main()
{
	addressbooks abs;
	abs.size = 0;
	int select = 0;

	while (true)
	{
	showmenu();
	cin >> select;
	if (select > 6 || select < 0)cout << "������0-6" << endl;
	switch (select)
	{
	case 1://�����ϵ��
		addperson(&abs);
		break;
	case 2://��ʾ��ϵ��
		showperson(&abs);
		break;
	case 3://ɾ����ϵ��
		deleteperson(&abs);
		break;
	case 4://������ϵ��
		findperson(&abs);
		break;
	case 5://�޸���ϵ��
		modifyperson(&abs);
		break;
	case 6://�����ϵ��
		clearperson(&abs);
		break;
	case 0://�˳�ͨѶ¼
		cout << "��ӭ�´�ʹ��" << endl;
		return 0;
		break;
	}
	system("cls");
		}
	return 0;
	}