#include"WorkerManager.h"

WorkerManager::WorkerManager() //构造函数
{
	//文件不存在
	ifstream ifs;
	ifs.open(filepath, ios::in);
	if (!ifs) {
		this->EmpNum = 0;
		this->FileisEmpty = true;
		this->Emp_Array = NULL;
		ifs.close();
		return;
	}
	//文件存在，但是文件内容为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		this->EmpNum = 0;
		this->Emp_Array = NULL;
		this->FileisEmpty = true;
		ifs.close();
		return;
	}
	//文件存在，且不为空
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
	cout << "********** 欢饮使用职工管理系统 *******" << endl;
	cout << "************ 0.退出管理系统 ***********" << endl;
	cout << "************ 1.增加职工信息 ***********" << endl;
	cout << "************ 2.显示职工信息 ***********" << endl;
	cout << "************ 3.删除职工信息 ***********" << endl;
	cout << "************ 4.修改职工信息 ***********" << endl;
	cout << "************ 5.查找职工信息 ***********" << endl;
	cout << "************ 6.按照编号排序 ***********" << endl;
	cout << "************ 7.清空文档信息 ***********" << endl;
	cout << "***************************************" << endl;
}

void WorkerManager::ExitSystem() {
	cout << "再见，欢饮下次使用！" << endl;
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
		case 1: //员工
			worker = new Employee(id, name, did);
			break;
		case 2: //经理
			worker = new Manager(id, name, did);
			break;
		case 3: //老板
			worker = new Boss(id, name, did);
			break;
		default:
			cout << "系统错误" << endl;
			system("pause");
			exit(-1);
			break;
		}
		this->Emp_Array[index++] = worker;
	}
}

void WorkerManager::Emp_Add()
{
	cout << "请输入您需要添加职工的数量:" << endl;
	int num = 0;
	cin >> num;
	//重新开辟内存空间
	Worker** NewSpace = new Worker * [this->EmpNum + num + 4];
	if (this->Emp_Array != NULL) {
		for (int i = 0; i < this->EmpNum; i++) {
			NewSpace[i] = this->Emp_Array[i];
		}
	}
	//添加职工
	int id;
	string name;
	int did;
	for (int j = 0; j < num; j++) {
		cout << "请输入第"<<j + 1<<"员工的ID:" << endl;
		cin >> id;
		//判断ID是否已经存在
		if (this->EmpID_Exist(id)) {//重复了
			cout << "该ID已经被注册" << endl;
			system("pause");
			system("cls");
			return;
		}
		cout << "请输入第" << j + 1 << "员工的姓名:" << endl;
		cin >> name;

		cout << "请输入第" << j + 1 << "员工的部门:" << endl;
		cout << "1.员工" << endl;
		cout << "2.经理" << endl;
		cout << "3.老板" << endl;
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
			cout << "选择错误,请重新添加" << endl;
			continue;
		}
		NewSpace[this->EmpNum+j] = worker;
	}
	//同步更新到文件中
	this->EmpNum +=  num;
	delete[] this->Emp_Array;
	this->Emp_Array = NewSpace;
	this->Emp_Save();
	cout << "添加成功" << endl;
	//文件非空
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
		cout << "当前系统内容为空，请添加员工" << endl;
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
		cout << "当前系统内容为空，不需要删除" << endl;
	}
	else {
		cout << "请输入您想要删除的员工ID:" << endl;
		int id;
		cin >> id;
		int index = this->Get_Index(id);
		if (index == -1) {
			cout << "查无此人" << endl;
		}
		else {
				delete this->Emp_Array[index];
				for (int i = index; i < this->EmpNum - 1; i++) {
					this->Emp_Array[i] = this->Emp_Array[i + 1];
				}
				this->EmpNum--;
				this->Emp_Save();
				cout << "删除成功" << endl;
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
		cout << "当前系统内容为空" << endl;
	}
	else {
		for (int i = 0; i < this->EmpNum; i++) {
			if (this->Emp_Array[i]->m_id == id) {
				this->Emp_Array[i]->ShowInfo();
				return;
			}
		}
		cout << "查无此人" << endl;
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
		cout << "当前系统为空或查无此人" << endl;
	}	
	return;
}

void WorkerManager::Mod_Emp()
{
	cout << "请输入您需要修改员工的ID:" << endl;
	int id;
	cin >> id;
	int index = Get_Index(id);
	if (index == -1) {
		cout << "查无此人" << endl;
	}
	else {
		int nid;
		string name;
		int did;
		cout << "请输入ID为" << id << "员工的修改ID" << endl;
		cin >> nid;
		cout << "请输入ID为" << id << "员工的修改姓名" << endl;
		cin >> name;
		cout << "请输入ID为" << id << "员工的修改岗位" << endl;
		cout << "1.员工" << endl;
		cout << "2.经理" << endl;
		cout << "3.老板" << endl;
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
			cout << "您的输入有误" << endl;
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
	cout << "请选择您的查找方式:" << endl;
	cout << "1.通过ID查找" << endl;
	cout << "2.通过姓名查找" << endl;
	int select;
	cin >> select;
	if (select == 1) {
		cout << "请输入查找ID:" << endl;
		int id;
		cin >> id;
		Find_Emp(id);
	}
	else if(select==2) {
		cout << "请输入查找姓名:" << endl;
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
		cout << "当前系统内容为空" << endl;
	}
	else {
		cout << "请选择排序方式" << endl;
		cout << "1.按ID号升序排序" << endl;
		cout << "2.按ID号降序排序" << endl;
		int select;
		cin >> select;
		if (select == 1) {//升序
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
		else if (select == 2) {//降序
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
			cout << "输入错误" << endl;
		}
	}
	system("pause");
	system("cls");
	return;
}

void WorkerManager::Clear_Emp()
{
	if (this->FileisEmpty) {
		cout << "当前系统内容为空" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "1.确认清空系统内容" << endl;
	cout << "2.返回主页面" << endl;
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
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
	return;
}

WorkerManager::~WorkerManager()//析构函数
{
	if (this->Emp_Array != NULL) {
		for (int i = 0; i < this->EmpNum; i++) {
			delete this->Emp_Array[i];
		}
	}
	delete[] this->Emp_Array;
	this->Emp_Array = NULL;
}