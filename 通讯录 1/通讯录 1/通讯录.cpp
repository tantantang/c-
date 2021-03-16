#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
#define MAX 1000
//�����ϵ�˽ṹ��
struct Person
{
	//����
	string m_Name;
	//�Ա� 1.�� 2.Ů
	int m_Sex;
	//����
	int m_Age;
	//�绰
	string m_Phone;
	//סַ
	string m_Addr;
};
//���ͨѶ¼�ṹ��
struct Addressbooks
{
	//ͨѶ¼�������ϵ������
	struct Person personArray[MAX];
	//��¼ͨѶ¼�е�ǰ�˸���
	int m_Size;
};
//�����ϵ��
void addPerson(struct Addressbooks*abs)
{
	//�ж��Ƿ�����ͨѶ¼
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return ;
	}
	else
	{
		//����
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2--Ů" << endl;
		int sex=0;
		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		//����
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//�绰
		cout << "������绰����" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//סַ
		cout << "������סַ" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		//����ͨѶ¼
		abs->m_Size += 1;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}
//��ʾ��ϵ����Ϣ
void showPerson(struct Addressbooks *abs)
{
	//�������Ϊ0 ��ʾ��¼Ϊ��
	if (abs->m_Size == 0)
		cout << "��ǰ��¼Ϊ��" << endl;
	else
	{
		int i = 0;
		for (i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex==1?"��":"Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_Age<< "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "��ַ��" << abs->personArray[i].m_Addr<< endl;
		}
		system("pause");
		system("cls");//����
	}
}
//����Ƿ���� �����ڷ��ظ���ϵ�˵�ַ �����ڷ���-1
int isExist(struct Addressbooks*abs, string name)
{
	int i = 0;
	for (i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)//c++string�ַ�������ֱ�ӱȽ� �������ΪstringΪ�������� nameΪ������
			return i;//�����±�
	}
			return -1;
	
}
//ɾ��ָ����ϵ��
void deletePerson(struct Addressbooks*abs)
{
	cout << "������Ҫɾ����ϵ�˵�����:" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);//1�ҵ��� -1û�ҵ�
	if (ret != -1)//����ɾ������
	{
		int i = 0;
		for (i = ret; i < abs->m_Size; i++)
		{
			//����Ǩ��
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//����ָ�����ϵ��
void findPerson(struct Addressbooks*abs)
{
	cout << "��������˵�����" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs,name);//absΪָ��
	if (ret != -1)//�ҵ���ϵ��
	{
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << abs->personArray[ret].m_Sex << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age <<"\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone<<"\t";
		cout << "��ַ��" << abs->personArray[ret].m_Addr<< endl;

	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
void showMenu()
{
	cout << "************************" << endl;
	cout << "***** 1.�����ϵ�� *****" << endl;
	cout << "***** 2.��ʾ��ϵ�� *****" << endl;
	cout << "***** 3.ɾ����ϵ�� *****" << endl;
	cout << "***** 4.������ϵ�� *****" << endl;
	cout << "***** 5.�޸���ϵ�� *****" << endl; 
	cout << "***** 6.�����ϵ�� *****" << endl;
	cout << "***** 0.�˳�ͨѶ¼ *****" << endl;
	cout << "************************" << endl;

}

int main()
{
	//����ͨѶ¼�ṹ�����
	struct Addressbooks abs;
	//��ʼ������
	abs.m_Size = 0;

	int select = 0;
	while (1)
	{
	showMenu();//�˵�����
	cin >> select;
	switch (select)
	{
	    case 1://1.�����ϵ��
			addPerson(&abs);//ַ���� �ı�ʵ��
			break;
		case 2://2.��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://3.ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4://4.������ϵ��
			findPerson(&abs);
			break;
		case 5://5.�޸���ϵ��
			break;
		case 6://6.�����ϵ��
			break;
		case 0://0.�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			return 0;
			break;
		default:
			break;


	 }
	}
	system("pause");
	return 0;
}