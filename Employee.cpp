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
		"\t����:" << this->m_name <<
		"\t����:" << this->GetPost() <<
		"\tְ��:" << this->GetDuty() << endl;
}
string Employee::GetPost()
{
	return string("Ա��");
}
string Employee::GetDuty()
{
	return string("������ɾ����ɷ�������");
}