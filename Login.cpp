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
	LoginDataBase = new DataBase[3];
	User = NULL;
}
Login::~Login() {
	delete []LoginDataBase;
}

void Login::sign_up(int place) {
	switch (place) {
	case 1: // 항공사 회원가입
		LoginDataBase[place - 1].sign_up(new UserData_airport);
		break;
	case 2: // 식당 회원가입
		LoginDataBase[place - 1].sign_up(new UserData_restaurant);
		break;
	case 3: // 독서실 회원가입
		LoginDataBase[place - 1].sign_up(new UserData_apart);
		break;
	}
}
UserData* Login::sign_in(int place) {
	Console::set_id();
	Console::set_password();
	return LoginDataBase[place - 1].sign_in(Console::get_id(),Console::get_password());
}

UserData* Login::sign_in_or_up(int place) {
	Console::set_login_menu();

	if (Console::get_login_menu() == 1) { // 로그인
		return sign_in(place);
	}
	else { // 회원가입
		sign_up(place);
		return NULL;
	}
}

