#include<iostream>
#include<string>
#define MAX 2000
using namespace std;
//�漰��ϵ�˵Ľṹ��
struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	int m_Phone;
	string m_Addr;
};
//�漰ͨѶ¼�ṹ��
struct Addressbooks
{
	//ͨѶ¼�б������ϵ������
	struct Person personArray[MAX];
	//ͨѶ¼�е�ǰ��ϵ�˸���
	int m_Size;
};
//��ʾ�˵�
void showMenu()
{
	cout << "1�������ϵ��" << endl;
	cout << "2����ʾ��ϵ��" << endl;
	cout << "3��ɾ����ϵ��" << endl;
	cout << "4��������ϵ��" << endl;
	cout << "5���޸���ϵ��" << endl;
	cout << "6�������ϵ��" << endl;
	cout << "0���˿���ϵ��" << endl;
}
//�����ϵ��
void addPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�Ƿ�������
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼���ˡ��޷��������";
		return ;
	}
	else
	{
		string name;
		cout << "����������";
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//�Ա�
		int sex = 0;
		while (true)
		{
		cout << "�������Ա�:" << endl;
		cout << "1---��" << endl;
		cout << "2-----Ů" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "�������� ���������룡" << endl;
	}
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		
		cout << "��������ϵ�绰" << endl;
		int tel = 0;
		cin >> tel;
		abs->personArray[abs->m_Size].m_Phone = tel;
		
		cout << "�������ַ" << endl;
		string addr;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;

		abs->m_Size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}
//��ʾ��ϵ��
void showPerson(Addressbooks* abs)
{
	//���������Ϊ0����ʾ
	if (abs->m_Size == 0)
	{
		cout << "��ǰ�� ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name << endl;
			cout << "���䣺" << abs->personArray[i].m_Age<< endl;
			cout << "�ձ�" << (abs->personArray[i].m_Sex==1 ?"��":"Ů")<< endl;
			cout << "�绰��" << abs->personArray[i].m_Phone<< endl;
			cout << "��ַ��" << abs->personArray[i].m_Addr<< endl;
		}

	}
		system("pause");
		system("cls");
}
//�����ϵ���Ƿ����
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;

		}
		else {
			return -1;
		}
	}
}
//ɾ����Ա
void deletePerson(Addressbooks* abs)
{
	cout << "������Ҫɾ������ϵ������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "δ�鵽" << endl;
	}
	else
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
		system("pause");
		system("cls");
	}
}
//������ϵ��
void findPerson(Addressbooks* abs)
{
	cout << "����Ҫ���ҵ���1" << endl;
	string name;
	cin >> name;
	int t = isExist(abs, name);
	if (t == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		cout << "����:" << abs->personArray[t].m_Name << endl;
		cout << "����:" << abs->personArray[t].m_Age << endl;
		cout << "�Ա�:" << abs->personArray[t].m_Sex << endl;
		cout << "�绰:" << abs->personArray[t].m_Phone << endl;
		cout << "��ַ:" << abs->personArray[t].m_Addr << endl;
	}
	cout << "���ҳɹ�" << endl;
	system("pause");
	system("cls");
}
//�޸���ϵ������
void modify(Addressbooks* abs)
{
	cout << "������Ҫ�޸ĵ�����" << endl;
	string name;
	cin >> name;
	int lt = isExist(abs, name);
	if (lt == -1)
	{
		cout << "�Ҳ�������" << endl;
	}
	else
	{
		abs->personArray[lt].m_Name = name;
	}
	cout << "�޸����" << endl;
	system("pause");
	system("cls");
}
//�����ϵ��
void clearPerson(Addressbooks* abs)
{
	cout << "��ʼ�����ϵ��" << endl;
	abs->m_Size = 0;
	cout << "������" << endl;
	system("pause");
	system("cls");
}
int main()
{
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_Size = 0;

	while (true)
	{

	showMenu();
	int select = 0;
	cin >> select;
	switch (select)
	{
	case 1:
		addPerson(&abs);
		break;

	case 2:
		showPerson(&abs);
		break;
	case 3:
		deletePerson(&abs);
	
		break;
	case 4:
		findPerson(&abs);
		break;
	case 5:
		modify(&abs);
		break;
	case 6:
		clearPerson(&abs);
		break;
	case 0:
		cout << "��ӭ�´�ʹ��" << endl;
		system("pause");
		return 0;
		break;
	}

	}

}
