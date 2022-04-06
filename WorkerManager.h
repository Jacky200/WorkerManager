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
	WorkerManager(); //构造函数
	~WorkerManager(); //析构函数

	//菜单显示函数
	void show_Menu();

	//退出系统程序
	void ExitSystem();

	//判断文件是否为空
	bool FileisEmpty = true;
	//当前职工数
	int EmpNum = 0;
	//存放员工的指针数组
	Worker** Emp_Array = NULL;
	//判断是否输入了重复ID
	bool EmpID_Exist(int id);
	//读取文件中职工的人数
	int File_Num();

	//将文件中的职工读取到内存中
	void File_Emp(int n);

	//添加职工到
	void Emp_Add();

	//保存信息到文件
	void Emp_Save();

	//显示文件中所有的员工
	void Show_Emp();

	//根据ID号进行删除员工
	void Del_Emp();

	//根据ID获取员工在内存员工数组指针的索引
	int Get_Index(int id);

	//根据ID查找员工
	void Find_Emp(int id);

	//根据姓名查找员工
	void FindByName_Emp(string name);

	//修改员工信息
	void Mod_Emp();

	//查找职工信息
	void Emp_Find();

	//按照编号进行排序
	void Sort_Emp();
	//清空文档内容
	void Clear_Emp();

};