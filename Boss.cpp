#include"Boss.h"

Boss::Boss(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_did = did;
}
void Boss::ShowInfo()
{
	cout << "ID:" << this->m_id <<
		"\t姓名:" << this->m_name <<
		"\t部门:" << this->GetPost() <<
		"\t职责:" << this->GetDuty() << endl;
}
string Boss::GetPost()
{
	return string("老板");
}
string Boss::GetDuty()
{
	return string("完成公司所有任务");
}