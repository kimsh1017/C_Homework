#include "DataBase.h"

DataBase::DataBase() {
}

newUserData* DataBase::sign_in(string id,string password) {
	string temp, fileId, filePassword,string_age;
	fout.open(filename, ios::out | ios::app);
	fin.open(filename, ios::in);

	if (!fout || !fin) {
		cout << "���� ���� ����" << endl;
		fin.close();
		fout.close();
		return NULL;
	}

	while (getline(fin, temp)) {
		if (temp == "***") {
			getline(fin, fileId, '/');
			getline(fin, filePassword, '/');
			getline(fin, string_age, '/');

			if (id == fileId && password == filePassword) {
				cout << "���� �α��� ����" << endl;
				fin.close();
				fout.close();
				return new newUserData(id, password, stoi(string_age));
			}
		}
	}
	cout << "�α��ο� �����߽��ϴ�" << endl;
	Sleep(500);
	fin.close();
	fout.close();
	return NULL;
}

void DataBase::sign_up(string id) {
	string password;
	int age;

	fout.open(filename, ios::out | ios::app);
	fin.open(filename, ios::in);

	if (!fout || !fin) {
		cout << "���� ���� ���� sign_up" << endl;
		fin.close();
		fout.close();
	}
	else {
		password = Console::set_password();
		age = Console::set_age();
		fout << "***\n";
		fout << id << '/' << password << '/' << age << '\n';

		fin.close();
		fout.close();
	}
}

bool DataBase::check_id(string id) {
	string temp, fileId;
	fout.open(filename, ios::out | ios::app);
	fin.open(filename, ios::in);

	if (!fout || !fin) {
		cout << "���� ���� ���� check_id" << endl;
		fin.close();
		fout.close();
		return NULL;
	}
	while (getline(fin, temp)) {
		if (temp == "***") {
			getline(fin, fileId, '/');

			if (id == fileId) {
				cout << "�ߺ��Ǵ� ���̵� ����" << endl;
				fin.close();
				fout.close();
				return true;
			}
		}
	}
	fin.close();
	fout.close();
	return false;
}

