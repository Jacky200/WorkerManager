#include<iostream>
using namespace std;
#include"WorkerManager.h"
int main() {
	WorkerManager wm;
	while (true)
	{
		wm.show_Menu();
		int choice;
		cout << "����������ѡ��:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: //�˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1: //���ְ��
			wm.Emp_Add();
			break;
		case 2: //��ʾԱ��
			wm.Show_Emp();
			break;
		case 3://ɾ��Ա��������ID�ţ�
			wm.Del_Emp();
			break;
		case 4: //�޸�Ա��
			wm.Mod_Emp();
			break;
		case 5: //����ְ����Ϣ
			wm.Emp_Find();
			break;
		case 6://���ձ�Ž�������
			wm.Sort_Emp();
			break;
		case 7: //����ĵ�����
			wm.Clear_Emp();
			break;
		default:
			cout << "����������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}