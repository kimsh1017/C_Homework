#include "DataBase.h"
#include "DataBase_airport.h"
#include "UserData.h"
#include "UserData_airport.h"
#include "Console.h"
#include <iostream>
using namespace std;
#include<string>
#include<vector>

DataBase_airport::DataBase_airport() {
	n = 0;
}
void DataBase_airport::sign_up() {
	cout << "비행기 회원가입 " << endl;
	Users.push_back(UserData_airport());
	Users.back().createUser();
}

bool DataBase_airport::sign_in() {
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

UserData* DataBase_airport::getUser() {
	return &Users[n];
}