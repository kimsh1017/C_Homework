#include "System.h"
#include "Login.h"
#include <iostream>
using namespace std;
#include<string>

void System::get_menu() {
	cout << "프로그램 선택" << endl;
	cout << "1: 비행기 예약 / 2: 식당 예약 / 3: 독서실 예약>>";
	cin >> menu;
}
void System::running() {
	login = new Login();
	login->ui?
	delete login;
}