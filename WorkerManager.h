#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"
#include<fstream>
#include<cstdlib>
#define filepath "employee.txt"

class WorkerManager {
public:
	WorkerManager(); //���캯��
	~WorkerManager(); //��������

	//�˵���ʾ����
	void show_Menu();

	//�˳�ϵͳ����
	void ExitSystem();

	//�ж��ļ��Ƿ�Ϊ��
	bool FileisEmpty = true;
	//��ǰְ����
	int EmpNum = 0;
	//���Ա����ָ������
	Worker** Emp_Array = NULL;
	//�ж��Ƿ��������ظ�ID
	bool EmpID_Exist(int id);
	//��ȡ�ļ���ְ��������
	int File_Num();

	//���ļ��е�ְ����ȡ���ڴ���
	void File_Emp(int n);

	//���ְ����
	void Emp_Add();

	//������Ϣ���ļ�
	void Emp_Save();

	//��ʾ�ļ������е�Ա��
	void Show_Emp();

	//����ID�Ž���ɾ��Ա��
	void Del_Emp();

	//����ID��ȡԱ�����ڴ�Ա������ָ�������
	int Get_Index(int id);

	//����ID����Ա��
	void Find_Emp(int id);

	//������������Ա��
	void FindByName_Emp(string name);

	//�޸�Ա����Ϣ
	void Mod_Emp();

	//����ְ����Ϣ
	void Emp_Find();

	//���ձ�Ž�������
	void Sort_Emp();
	//����ĵ�����
	void Clear_Emp();

};