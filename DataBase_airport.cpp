#include "DataBase.h"
#include "DataBase_airport.h"
#include "UserData.h"
#include "UserData_airport.h"
#include "Console.h"
#include <iostream>
using namespace std;
#include<string>
#include<vector>

void DataBase_airport::sign_up() {
	cout << "항공사 회원가입 " << endl;
	cout << "회원 정보를 입력해주세요" << endl;


	Console::set_id();
	if (check_id()) {
		cout << "사용이 불가능한 아이디 입니다" << endl;
	}
	else {
		if (start == NULL) {
			start = new UserData_airport;
			last = start;
		}
		else {
			last->next = new UserData_airport;
			last = last->next;
		}
		last->createUser(Console::get_id());
	}
}