#include "DataBase.h"
#include "DataBase_restaurant.h"
#include "UserData.h"
#include "Console.h"
#include <iostream>
using namespace std;
#include<string>
#include<vector>

DataBase_restaurant::DataBase_restaurant() {
	n = 0;
}
void DataBase_restaurant::sign_up() {
	cout << "식당 회원가입 " << endl;
	Users.push_back(UserData_restaurant());
	Users.back().createUser();
}

bool DataBase_restaurant::sign_in() {
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

UserData* DataBase_restaurant::getUser() {
	return &Users[n];
}