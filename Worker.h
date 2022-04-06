#pragma once
#include<iostream>
using namespace std;
#include<string>

class Worker {
public:
	int m_id;
	string m_name;
	int m_did; 

	virtual void ShowInfo() = 0;//纯虚函数，显示个人信息
	virtual string GetPost() = 0;//获取岗位信息
	virtual string GetDuty() = 0;//获取岗位职责
};