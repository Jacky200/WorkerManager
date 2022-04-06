#include"Employee.h"


Employee::Employee(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_did = did;
}
void Employee::ShowInfo()
{
	cout << "ID:" << this->m_id <<
		"\t姓名:" << this->m_name <<
		"\t部门:" << this->GetPost() <<
		"\t职责:" << this->GetDuty() << endl;
}
string Employee::GetPost()
{
	return string("员工");
}
string Employee::GetDuty()
{
	return string("负责完成经理派发的任务");
}