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
		"\t����:" << this->m_name <<
		"\t����:" << this->GetPost() <<
		"\tְ��:" << this->GetDuty() << endl;
}
string Manager::GetPost()
{
	return string("����");
}
string Manager::GetDuty()
{
	return string("����ϰ��ɷ������񣬲��·������Ա��");
}