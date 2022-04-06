#include"Manager.h"

Manager::Manager(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_did = did;
}
void Manager::ShowInfo()
{
	cout << "ID:" << this->m_id <<
		"\t姓名:" << this->m_name <<
		"\t部门:" << this->GetPost() <<
		"\t职责:" << this->GetDuty() << endl;
}
string Manager::GetPost()
{
	return string("经理");
}
string Manager::GetDuty()
{
	return string("完成老板派发的任务，并下发任务给员工");
}