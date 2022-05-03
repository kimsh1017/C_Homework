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
	cout << "비밀번호 >>";
	password = Console::get_string();

	for (int i = 0; i < Users.size(); i++) {
		if (Users[i].checkData(id, password)) {
			check = true;
			break;
		}
	}

	if (check) {
		cout << "로그인 성공 환영합니다" << endl;
	}
	else {
		cout << " 로그인 실패 " << endl;
	}
}
void DataBase::sign_up(int menu) {
	cout << "회원가입";
	Users.push_back(UserData());
	Users.back().createUser();
}