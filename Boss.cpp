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
		"\t����:" << this->m_name <<
		"\t����:" << this->GetPost() <<
		"\tְ��:" << this->GetDuty() << endl;
}
string Boss::GetPost()
{
	return string("�ϰ�");
}
string Boss::GetDuty()
{
	return string("��ɹ�˾��������");
}