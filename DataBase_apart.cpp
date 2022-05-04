#include "DataBase.h"
#include "DataBase_apart.h"
#include "UserData.h"
#include "Console.h"
#include <iostream>
using namespace std;
#include<string>
#include<vector>

DataBase_apart::DataBase_apart() {
	n = 0;
}

void DataBase_apart::sign_up() {
	cout << "독서실 회원가입 " << endl;
	Users.push_back(UserData_apart());
	Users.back().createUser();
}

bool DataBase_apart::sign_in() {
	string id;
	string password;
	cout << "id >>";
	cin >> id;
	cout << "password >>";
	cin >> password;
	for (int i = 0; i < Users.size(); i++) {
		if (Users[i].checkData(id, password)) {
			n = i;
			return true;
		}
	}
	return false;
}

UserData* DataBase_apart::getUser() {
	return &Users[n];
}