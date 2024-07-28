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
	cout << "*****1、添加联系人******" << endl;
	cout << "*****2、显示联系人******" << endl;
	cout << "*****3、删除联系人******" << endl;
	cout << "*****4、查找联系人******" << endl;
	cout << "*****5、修改联系人******" << endl;
	cout << "*****6、清空联系人******" << endl;
	cout << "*****0、退出通讯录******" << endl;
	cout << "************************" << endl;
}

struct person
{
	string name;
	int sex;//1男 2女
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
	//判断MAX
	if (abs->size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		string name;
		cout << "输入姓名：" << endl;
		cin >> name;
		for (int i = 0; i < MAX; i++)
		{
			if (name == abs->personarray[i].name) 
			{ 
				cout << "已经添加过该联系人" << endl; 
				system("pause");
				system("cls");
				return;
			}
		}
		abs->personarray[abs->size].name = name;

		cout << "输入性别：" << endl;
		cout << "1--男\n2--女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[abs->size].sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		cout << "输入年龄：" << endl;
		int age;
		while (true)
		{
			cin >> age;
			if (age <= 135 && age >= 0)
			{
				abs->personarray[abs->size].age = age;
				break;
			}
			cout << "输入有误，请重新输入" << endl;			
		}
		cout << "输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personarray[abs->size].phone = phone;
		cout << "输入家庭住址：" << endl;
		string addr;
		cin >> addr;
		abs->personarray[abs->size].address = addr;
		abs->size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}
void showperson(addressbooks* abs)
{
	if (abs->size == 0)cout << "当前记录为空" << endl;
	else
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout << "姓名：" << abs->personarray[i].name << "\t";
			cout << "性别：" << (abs->personarray[i].sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personarray[i].age << "\t";
			cout << "电话：" << abs->personarray[i].phone << "\t";
			cout << "住址：" << abs->personarray[i].address << "\n\n";
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
	cout << "输入您要删除的联系人" << endl;
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
		cout << "删除成功" << endl;
	}
	else { cout << "查无此人" << endl; }
	system("pause");
	system("cls");
}
void findperson(addressbooks* abs)
{
	cout << "你要查找的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personarray[ret].name << endl;
		cout << "性别：" << (abs->personarray[ret].sex == 1 ? "男" : "女") << endl;
		cout << "年龄：" << abs->personarray[ret].age << endl;
		cout << "电话：" << abs->personarray[ret].phone << endl;
		cout << "住址：" << abs->personarray[ret].address << endl;
		system("pause");
		system("cls");
	}
	else { cout << "查无此人" << endl; }
	system("pause");
	system("cls");
}
void modifyperson(addressbooks* abs)
{
	cout << "请输入你想修改的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "输入姓名：" << endl;
		cin >> name;
		abs->personarray[ret].name = name;

		cout << "输入性别：" << endl;
		cout << "1--男\n2--女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[ret].sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		cout << "输入年龄：" << endl;
		int age;
		while (true)
		{
			cin >> age;
			if (age <= 120 && age >= 0)
			{
				abs->personarray[ret].age = age;
				break;
			}
			cout << "输入有误，请重新输入" << endl;			
		}
		cout << "输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personarray[ret].phone = phone;
		cout << "输入家庭住址：" << endl;
		string addr;
		cin >> addr;
		abs->personarray[ret].address = addr;
		cout << "修改成功" << endl;
	}
	else {cout << "查无此人" << endl;}
	system("pause");
	system("cls");
}
void clearperson(addressbooks* abs)
{
	abs->size = 0;
	cout << "通讯录已清空" << endl;
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
	if (select > 6 || select < 0)cout << "请输入0-6" << endl;
	switch (select)
	{
	case 1://添加联系人
		addperson(&abs);
		break;
	case 2://显示联系人
		showperson(&abs);
		break;
	case 3://删除联系人
		deleteperson(&abs);
		break;
	case 4://查找联系人
		findperson(&abs);
		break;
	case 5://修改联系人
		modifyperson(&abs);
		break;
	case 6://清空联系人
		clearperson(&abs);
		break;
	case 0://退出通讯录
		cout << "欢迎下次使用" << endl;
		return 0;
		break;
	}
	system("cls");
		}
	return 0;
	}