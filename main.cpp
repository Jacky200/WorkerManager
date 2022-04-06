#include<iostream>
using namespace std;
#include"WorkerManager.h"
int main() {
	WorkerManager wm;
	while (true)
	{
		wm.show_Menu();
		int choice;
		cout << "请输入您的选择:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: //退出系统
			wm.ExitSystem();
			break;
		case 1: //添加职工
			wm.Emp_Add();
			break;
		case 2: //显示员工
			wm.Show_Emp();
			break;
		case 3://删除员工（根据ID号）
			wm.Del_Emp();
			break;
		case 4: //修改员工
			wm.Mod_Emp();
			break;
		case 5: //查找职工信息
			wm.Emp_Find();
			break;
		case 6://按照编号进行排序
			wm.Sort_Emp();
			break;
		case 7: //清空文档内容
			wm.Clear_Emp();
			break;
		default:
			cout << "您输入有误！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}