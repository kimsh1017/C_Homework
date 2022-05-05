#include "System.h"
#include "UserData.h"
#include "Login.h"
#include "Console.h"
#include <iostream>
using namespace std;
#include<string>

string Console::id = "";
string Console::password = "";
int Console::place_menu = 0;
int Console::login_menu = 0;


System::System() {
	login = new Login;
	UserNow = NULL;
}
void System::running() {
	Console::set_place_menu(); 

	while (Console::get_place_menu() != 4) {
		// 로그인 또는 회원가입
		UserNow = NULL;
		UserNow = login->sign_in_or_up(Console::get_place_menu());

		// 로그인 성공시
		if (UserNow != NULL) {
			cout << "로그인 성공" << endl;
			UserNow->showData();
		}

		cout << endl;
		cout << "====================================" << endl;
		Console::set_place_menu();
	}
	cout << "프로그램을 종료합니다" << endl;
	delete login;
}