#pragma once
#include<iostream>
using namespace std;
#include<string>

class Worker {
public:
	int m_id;
	string m_name;
	int m_did; 

	virtual void ShowInfo() = 0;//���麯������ʾ������Ϣ
	virtual string GetPost() = 0;//��ȡ��λ��Ϣ
	virtual string GetDuty() = 0;//��ȡ��λְ��
};