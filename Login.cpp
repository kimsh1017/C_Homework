#include "Login.h"
#include "Console.h"

#include <iostream>
using namespace std;
#include <string>
#include <vector>


Login::Login() {
	LoginDataBase = new DataBase[3];
	LoginDataBase[0] = DataBase_airport();
	LoginDataBase[1] = DataBase_restaurant();
	LoginDataBase[2] = DataBase_apart();
}

void Login::get_menu() {
	cout << "프로그램 선택" << endl;
	cout << "1: 비행기 예약 / 2: 식당 예약 / 3: 독서실 예약>>";
	cin >> menu;
}
UserData Login::getUser() {
	cout << "1: 로그인 / 2: 회원가입 >>";
	cin >> sign;

	if (sign == 0) {
		LoginDataBase[menu].sign_in();
	}
	else {
		LoginDataBase[menu].sign_up();
	}
}