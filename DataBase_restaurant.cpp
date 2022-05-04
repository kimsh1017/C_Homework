#include "DataBase.h"
#include "DataBase_restaurant.h"
#include "UserData.h"
#include "Console.h"
#include <iostream>
using namespace std;
#include<string>
#include<vector>


void DataBase_restaurant::sign_up() {
	cout << "식당 회원가입 " << endl;
	cout << "회원정보를 입력해주세요 >>";

	Console::set_id();
	if (check_id()) {
		cout << "사용이 불가능한 아이디 입니다" << endl;
	}
	else {
		if (start == NULL) {
			start = new UserData_restaurant;
			last = start;
		}
		else {
			last->next = new UserData_restaurant;
			last = last->next;
		}
		last->createUser(Console::get_id());
	}
}