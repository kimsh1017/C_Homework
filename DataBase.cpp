#include "DataBase.h"
#include "UserData.h"
#include "Console.h"
#include <iostream>
using namespace std;
#include<string>
#include<vector>

void DataBase::sign_in() {
	bool check = false;

	cout << "ID >>";
	id = Console::get_string();
	cout << "��й�ȣ >>";
	password = Console::get_string();

	for (int i = 0; i < Users.size(); i++) {
		if (Users[i].checkData(id, password)) {
			check = true;
			break;
		}
	}

	if (check) {
		cout << "�α��� ���� ȯ���մϴ�" << endl;
	}
	else {
		cout << " �α��� ���� " << endl;
	}
}
void DataBase::sign_up(int menu) {
	cout << "ȸ������";
	Users.push_back(UserData());
	Users.back().createUser();
}