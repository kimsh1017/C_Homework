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
	cout << "���α׷� ����" << endl;
	cout << "1: ����� ���� / 2: �Ĵ� ���� / 3: ������ ����>>";
	cin >> menu;
}
UserData Login::getUser() {
	cout << "1: �α��� / 2: ȸ������ >>";
	cin >> sign;

	if (sign == 0) {
		LoginDataBase[menu].sign_in();
	}
	else {
		LoginDataBase[menu].sign_up();
	}
}