#include"WorkerManager.h"

WorkerManager::WorkerManager() //���캯��
{
	//�ļ�������
	ifstream ifs;
	ifs.open(filepath, ios::in);
	if (!ifs) {
		this->EmpNum = 0;
		this->FileisEmpty = true;
		this->Emp_Array = NULL;
		ifs.close();
		return;
	}
	//�ļ����ڣ������ļ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		this->EmpNum = 0;
		this->Emp_Array = NULL;
		this->FileisEmpty = true;
		ifs.close();
		return;
	}
	//�ļ����ڣ��Ҳ�Ϊ��
	int num = this->File_Num();
	this->EmpNum = num;
	this->File_Emp(num);
	this->FileisEmpty = false;
	ifs.close();
	return;
}

void WorkerManager::show_Menu()
{
	cout << "***************************************" << endl;
	cout << "********** ����ʹ��ְ������ϵͳ *******" << endl;
	cout << "************ 0.�˳�����ϵͳ ***********" << endl;
	cout << "************ 1.����ְ����Ϣ ***********" << endl;
	cout << "************ 2.��ʾְ����Ϣ ***********" << endl;
	cout << "************ 3.ɾ��ְ����Ϣ ***********" << endl;
	cout << "************ 4.�޸�ְ����Ϣ ***********" << endl;
	cout << "************ 5.����ְ����Ϣ ***********" << endl;
	cout << "************ 6.���ձ������ ***********" << endl;
	cout << "************ 7.����ĵ���Ϣ ***********" << endl;
	cout << "***************************************" << endl;
}

void WorkerManager::ExitSystem() {
	cout << "�ټ��������´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

int WorkerManager::File_Num()
{
	int id;
	string name;
	int did;
	int count = 0;
	fstream ifs;
	ifs.open(filepath, ios::in);
	while (ifs >> id && ifs >> name && ifs >> did) {
		count++;
	}
	ifs.close();
	return count;
}

void WorkerManager::File_Emp(int n)
{
	this->Emp_Array = new Worker * [n+4];
	fstream ifs;
	int id;
	string name;
	int did;
	int index = 0;
	ifs.open(filepath, ios::in);
	while (ifs >> id && ifs >> name && ifs >> did) {
		Worker* worker = NULL;
		switch (did)
		{
		case 1: //Ա��
			worker = new Employee(id, name, did);
			break;
		case 2: //����
			worker = new Manager(id, name, did);
			break;
		case 3: //�ϰ�
			worker = new Boss(id, name, did);
			break;
		default:
			cout << "ϵͳ����" << endl;
			system("pause");
			exit(-1);
			break;
		}
		this->Emp_Array[index++] = worker;
	}
}

void WorkerManager::Emp_Add()
{
	cout << "����������Ҫ���ְ��������:" << endl;
	int num = 0;
	cin >> num;
	//���¿����ڴ�ռ�
	Worker** NewSpace = new Worker * [this->EmpNum + num + 4];
	if (this->Emp_Array != NULL) {
		for (int i = 0; i < this->EmpNum; i++) {
			NewSpace[i] = this->Emp_Array[i];
		}
	}
	//���ְ��
	int id;
	string name;
	int did;
	for (int j = 0; j < num; j++) {
		cout << "�������"<<j + 1<<"Ա����ID:" << endl;
		cin >> id;
		//�ж�ID�Ƿ��Ѿ�����
		if (this->EmpID_Exist(id)) {//�ظ���
			cout << "��ID�Ѿ���ע��" << endl;
			system("pause");
			system("cls");
			return;
		}
		cout << "�������" << j + 1 << "Ա��������:" << endl;
		cin >> name;

		cout << "�������" << j + 1 << "Ա���Ĳ���:" << endl;
		cout << "1.Ա��" << endl;
		cout << "2.����" << endl;
		cout << "3.�ϰ�" << endl;
		cin >> did;
		Worker* worker = NULL;
		switch (did) {
		case 1:
			worker = new Employee(id, name, did);
			break;
		case 2:
			worker = new Manager(id, name, did);
			break;
		case 3:
			worker = new Boss(id, name, did);
			break;
		default:
			cout << "ѡ�����,���������" << endl;
			continue;
		}
		NewSpace[this->EmpNum+j] = worker;
	}
	//ͬ�����µ��ļ���
	this->EmpNum +=  num;
	delete[] this->Emp_Array;
	this->Emp_Array = NewSpace;
	this->Emp_Save();
	cout << "��ӳɹ�" << endl;
	//�ļ��ǿ�
	this->FileisEmpty = false;
	system("pause");
	system("cls");
	
}

void WorkerManager::Emp_Save()
{
	ofstream ofs;
	ofs.open(filepath, ios::out|ios::trunc);

	for (int i = 0; i < this->EmpNum; i++) {
		ofs << this->Emp_Array[i]->m_id << " "
			<< this->Emp_Array[i]->m_name << " "
			<< this->Emp_Array[i]->m_did << endl;
	}
	ofs.close();
}

bool WorkerManager::EmpID_Exist(int id)
{
	if (this->Emp_Array != NULL) {
		for (int i = 0; i < this->EmpNum; i++) {
			if (id == this->Emp_Array[i]->m_id) {
				return true;
			}
		}
	}
	return false;
}

void WorkerManager::Show_Emp()
{
	if (this->Emp_Array == NULL || this->EmpNum==0) {
		cout << "��ǰϵͳ����Ϊ�գ������Ա��" << endl;
	}
	else {
		for (int i = 0; i < this->EmpNum; i++) {
			this->Emp_Array[i]->ShowInfo();
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Del_Emp()
{
	if (this->Emp_Array==NULL) {
		cout << "��ǰϵͳ����Ϊ�գ�����Ҫɾ��" << endl;
	}
	else {
		cout << "����������Ҫɾ����Ա��ID:" << endl;
		int id;
		cin >> id;
		int index = this->Get_Index(id);
		if (index == -1) {
			cout << "���޴���" << endl;
		}
		else {
				delete this->Emp_Array[index];
				for (int i = index; i < this->EmpNum - 1; i++) {
					this->Emp_Array[i] = this->Emp_Array[i + 1];
				}
				this->EmpNum--;
				this->Emp_Save();
				cout << "ɾ���ɹ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

int WorkerManager::Get_Index(int id)
{
	for (int i = 0; i < this->EmpNum; i++) {
		if (this->Emp_Array[i]->m_id == id) {
			return i;
		}
	}
	return -1;
}

void WorkerManager::Find_Emp(int id)
{
	if (this->Emp_Array == NULL || this->EmpNum == 0) {
		cout << "��ǰϵͳ����Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < this->EmpNum; i++) {
			if (this->Emp_Array[i]->m_id == id) {
				this->Emp_Array[i]->ShowInfo();
				return;
			}
		}
		cout << "���޴���" << endl;
		return;
	}
}

void WorkerManager::FindByName_Emp(string name)
{
	int flag = false;
	if (this->Emp_Array == NULL || this->EmpNum == 0) {
		flag = true;
	}
	else {
		for (int i = 0; i < this->EmpNum; i++) {
			if (this->Emp_Array[i]->m_name == name) {
				this->Emp_Array[i]->ShowInfo();
			}
		}
	}
	if (flag) {
		cout << "��ǰϵͳΪ�ջ���޴���" << endl;
	}	
	return;
}

void WorkerManager::Mod_Emp()
{
	cout << "����������Ҫ�޸�Ա����ID:" << endl;
	int id;
	cin >> id;
	int index = Get_Index(id);
	if (index == -1) {
		cout << "���޴���" << endl;
	}
	else {
		int nid;
		string name;
		int did;
		cout << "������IDΪ" << id << "Ա�����޸�ID" << endl;
		cin >> nid;
		cout << "������IDΪ" << id << "Ա�����޸�����" << endl;
		cin >> name;
		cout << "������IDΪ" << id << "Ա�����޸ĸ�λ" << endl;
		cout << "1.Ա��" << endl;
		cout << "2.����" << endl;
		cout << "3.�ϰ�" << endl;
		cin >> did;
		Worker* worker = NULL;
		switch (did)
		{
		case 1:
			worker = new Employee(nid, name, did);
			break;
		case 2:
			worker = new Manager(nid, name, did);
			break;
		case 3:
			worker = new Boss(nid, name, did);
			break;
		default:
			cout << "������������" << endl;
			break;
		}
		this->Emp_Array[index] = worker;
		this->Emp_Save();
	}
	system("pause");
	system("cls");
}

void WorkerManager::Emp_Find()
{
	cout << "��ѡ�����Ĳ��ҷ�ʽ:" << endl;
	cout << "1.ͨ��ID����" << endl;
	cout << "2.ͨ����������" << endl;
	int select;
	cin >> select;
	if (select == 1) {
		cout << "���������ID:" << endl;
		int id;
		cin >> id;
		Find_Emp(id);
	}
	else if(select==2) {
		cout << "�������������:" << endl;
		string name;
		cin >> name;
		FindByName_Emp(name);
	}
	system("pause");
	system("cls");
	return;
}

void WorkerManager::Sort_Emp()
{
	if (this->FileisEmpty) {
		cout << "��ǰϵͳ����Ϊ��" << endl;
	}
	else {
		cout << "��ѡ������ʽ" << endl;
		cout << "1.��ID����������" << endl;
		cout << "2.��ID�Ž�������" << endl;
		int select;
		cin >> select;
		if (select == 1) {//����
			int min = 0;
			for (int i = 0; i < this->EmpNum-1; i++) {
				min = i;
				for (int j = i + 1; j < this->EmpNum; j++) {
					if (this->Emp_Array[min]->m_id > this->Emp_Array[j]->m_id) {
						Worker* temp = this->Emp_Array[min];
						this->Emp_Array[min] = this->Emp_Array[j];
						this->Emp_Array[j] = temp;
					}
				}
			}
			this->Emp_Save();
		}
		else if (select == 2) {//����
			int max = 0;
			for (int i = 0; i < this->EmpNum - 1; i++) {
				max = i;
				for (int j = i + 1; j < this->EmpNum; j++) {
					if (this->Emp_Array[max]->m_id < this->Emp_Array[j]->m_id) {
						Worker* temp = this->Emp_Array[max];
						this->Emp_Array[max] = this->Emp_Array[j];
						this->Emp_Array[j] = temp;
					}
				}
			}
			this->Emp_Save();
		}
		else {
			cout << "�������" << endl;
		}
	}
	system("pause");
	system("cls");
	return;
}

void WorkerManager::Clear_Emp()
{
	if (this->FileisEmpty) {
		cout << "��ǰϵͳ����Ϊ��" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "1.ȷ�����ϵͳ����" << endl;
	cout << "2.������ҳ��" << endl;
	int select;
	cin >> select;
	if (select == 1) {
		ofstream ofs;
		ofs.open(filepath, ios::trunc);
		ofs.close();
		delete[] this->Emp_Array;
		this->EmpNum = 0;
		this->FileisEmpty = true;
	}
	else if (select != 1 && select!=2) {
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
	return;
}

WorkerManager::~WorkerManager()//��������
{
	if (this->Emp_Array != NULL) {
		for (int i = 0; i < this->EmpNum; i++) {
			delete this->Emp_Array[i];
		}
	}
	delete[] this->Emp_Array;
	this->Emp_Array = NULL;
}