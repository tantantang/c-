#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
#define MAX 1000
//设计联系人结构体
struct Person
{
	//姓名
	string m_Name;
	//性别 1.男 2.女
	int m_Sex;
	//年龄
	int m_Age;
	//电话
	string m_Phone;
	//住址
	string m_Addr;
};
//设计通讯录结构体
struct Addressbooks
{
	//通讯录保存的联系人数组
	struct Person personArray[MAX];
	//记录通讯录中当前人个数
	int m_Size;
};
//添加联系人
void addPerson(struct Addressbooks*abs)
{
	//判断是否已满通讯录
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return ;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//性别
		cout << "请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2--女" << endl;
		int sex=0;
		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		//年龄
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//电话
		cout << "请输入电话号码" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//住址
		cout << "请输入住址" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		//更新通讯录
		abs->m_Size += 1;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}
//显示联系人信息
void showPerson(struct Addressbooks *abs)
{
	//如果人数为0 提示记录为空
	if (abs->m_Size == 0)
		cout << "当前记录为空" << endl;
	else
	{
		int i = 0;
		for (i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex==1?"男":"女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age<< "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "地址：" << abs->personArray[i].m_Addr<< endl;
		}
		system("pause");
		system("cls");//清屏
	}
}
//检测是否存在 若存在返回该联系人地址 不存在返回-1
int isExist(struct Addressbooks*abs, string name)
{
	int i = 0;
	for (i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)//c++string字符串可以直接比较 可以理解为string为数据类型 name为数组名
			return i;//返回下标
	}
			return -1;
	
}
//删除指定联系人
void deletePerson(struct Addressbooks*abs)
{
	cout << "请输入要删除联系人的姓名:" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);//1找到了 -1没找到
	if (ret != -1)//进行删除操作
	{
		int i = 0;
		for (i = ret; i < abs->m_Size; i++)
		{
			//数据迁移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//查找指点的联系人
void findPerson(struct Addressbooks*abs)
{
	cout << "输入查找人的姓名" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs,name);//abs为指针
	if (ret != -1)//找到联系人
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << abs->personArray[ret].m_Sex << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age <<"\t";
		cout << "电话：" << abs->personArray[ret].m_Phone<<"\t";
		cout << "地址：" << abs->personArray[ret].m_Addr<< endl;

	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void showMenu()
{
	cout << "************************" << endl;
	cout << "***** 1.添加联系人 *****" << endl;
	cout << "***** 2.显示联系人 *****" << endl;
	cout << "***** 3.删除联系人 *****" << endl;
	cout << "***** 4.查找联系人 *****" << endl;
	cout << "***** 5.修改联系人 *****" << endl; 
	cout << "***** 6.清空联系人 *****" << endl;
	cout << "***** 0.退出通讯录 *****" << endl;
	cout << "************************" << endl;

}

int main()
{
	//创建通讯录结构体变量
	struct Addressbooks abs;
	//初始化个数
	abs.m_Size = 0;

	int select = 0;
	while (1)
	{
	showMenu();//菜单界面
	cin >> select;
	switch (select)
	{
	    case 1://1.添加联系人
			addPerson(&abs);//址传递 改变实参
			break;
		case 2://2.显示联系人
			showPerson(&abs);
			break;
		case 3://3.删除联系人
			deletePerson(&abs);
			break;
		case 4://4.查找联系人
			findPerson(&abs);
			break;
		case 5://5.修改联系人
			break;
		case 6://6.清空联系人
			break;
		case 0://0.退出通讯录
			cout << "欢迎下次使用" << endl;
			return 0;
			break;
		default:
			break;


	 }
	}
	system("pause");
	return 0;
}