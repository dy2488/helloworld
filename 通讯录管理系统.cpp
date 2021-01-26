#include<iostream>
#include<string>
#define MAX 2000
using namespace std;
//涉及联系人的结构体
struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	int m_Phone;
	string m_Addr;
};
//涉及通讯录结构体
struct Addressbooks
{
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];
	//通讯录中当前联系人个数
	int m_Size;
};
//显示菜单
void showMenu()
{
	cout << "1、添加联系人" << endl;
	cout << "2、显示联系人" << endl;
	cout << "3、删除联系人" << endl;
	cout << "4、查找联系人" << endl;
	cout << "5、修改联系人" << endl;
	cout << "6、清空联系人" << endl;
	cout << "0、退空联系人" << endl;
}
//添加联系人
void addPerson(Addressbooks* abs)
{
	//判断通讯录是否已满。
	if (abs->m_Size == MAX)
	{
		cout << "通讯录满了。无法继续添加";
		return ;
	}
	else
	{
		string name;
		cout << "请输入姓名";
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//性别
		int sex = 0;
		while (true)
		{
		cout << "请输入性别:" << endl;
		cout << "1---男" << endl;
		cout << "2-----女" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误 请重新输入！" << endl;
	}
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		
		cout << "请输入联系电话" << endl;
		int tel = 0;
		cin >> tel;
		abs->personArray[abs->m_Size].m_Phone = tel;
		
		cout << "请输入地址" << endl;
		string addr;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;

		abs->m_Size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}
//显示联系人
void showPerson(Addressbooks* abs)
{
	//如果人数不为0才显示
	if (abs->m_Size == 0)
	{
		cout << "当前的 记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << endl;
			cout << "年龄：" << abs->personArray[i].m_Age<< endl;
			cout << "姓别：" << (abs->personArray[i].m_Sex==1 ?"男":"女")<< endl;
			cout << "电话：" << abs->personArray[i].m_Phone<< endl;
			cout << "地址：" << abs->personArray[i].m_Addr<< endl;
		}

	}
		system("pause");
		system("cls");
}
//检查联系人是否存在
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
//删除人员
void deletePerson(Addressbooks* abs)
{
	cout << "请输入要删除的联系人姓名" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "未查到" << endl;
	}
	else
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功" << endl;
		system("pause");
		system("cls");
	}
}
//查找联系人
void findPerson(Addressbooks* abs)
{
	cout << "输入要查找的人1" << endl;
	string name;
	cin >> name;
	int t = isExist(abs, name);
	if (t == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		cout << "姓名:" << abs->personArray[t].m_Name << endl;
		cout << "年龄:" << abs->personArray[t].m_Age << endl;
		cout << "性别:" << abs->personArray[t].m_Sex << endl;
		cout << "电话:" << abs->personArray[t].m_Phone << endl;
		cout << "地址:" << abs->personArray[t].m_Addr << endl;
	}
	cout << "查找成功" << endl;
	system("pause");
	system("cls");
}
//修改联系人姓名
void modify(Addressbooks* abs)
{
	cout << "请输入要修改的姓名" << endl;
	string name;
	cin >> name;
	int lt = isExist(abs, name);
	if (lt == -1)
	{
		cout << "找不到此人" << endl;
	}
	else
	{
		abs->personArray[lt].m_Name = name;
	}
	cout << "修改完成" << endl;
	system("pause");
	system("cls");
}
//清空联系人
void clearPerson(Addressbooks* abs)
{
	cout << "开始清空联系人" << endl;
	abs->m_Size = 0;
	cout << "清除完毕" << endl;
	system("pause");
	system("cls");
}
int main()
{
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中当前人员个数
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
		cout << "欢迎下次使用" << endl;
		system("pause");
		return 0;
		break;
	}

	}

}
