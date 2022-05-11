#include "Login.h"
#include "Console.h"

#include "DataBase.h"

#include "UserData.h"
#include "UserData_airport.h"
#include "UserData_apart.h"
#include "UserData_restaurant.h"

#include <iostream>
using namespace std;
#include <string>


Login::Login() {
	LoginDataBase = new DataBase[3]; // 유저 데이터베이스 1.비행기 2.식당 3.독서실
	User = NULL;
}
Login::~Login() {
	delete []LoginDataBase;
}

void Login::sign_up(int place) {
	cout << "회원가입 " << endl;
	cout << "회원 정보를 입력해주세요" << endl;

	Console::set_id(); 
	if (LoginDataBase[place-1].check_id()) { // 아이디 중복 체크
		cout << "사용이 불가능한 아이디 입니다" << endl;
		User = NULL;
	}
	else {
		switch (place) {
		case 1: // 항공사 회원가입
			User = new UserData_airport;
			LoginDataBase[place - 1].sign_up(User);
			break;
		case 2: // 식당 회원가입
			User = new UserData_restaurant;
			LoginDataBase[place - 1].sign_up(User);
			break;
		case 3: // 독서실 회원가입
			User = new UserData_apart;
			LoginDataBase[place - 1].sign_up(User);
			break;
		}
	}
}
void Login::sign_in(int place) {
	Console::set_id();
	Console::set_password();
	User = LoginDataBase[place - 1].sign_in(Console::get_id(),Console::get_password());
}

UserData* Login::sign_in_or_up(int place) {
	Console::set_login_menu();

	if (Console::get_login_menu() == 1) { // 로그인
		sign_in(place);
	}
	else { // 회원가입
		sign_up(place);
	}
	return User;
}

