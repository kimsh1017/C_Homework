#include "System.h"
#include "UserData.h"
#include "Login.h"
#include "Console.h"
#include <iostream>
using namespace std;
#include<string>

System::System() {
	login = new Login;
	UserNow = NULL;
}
void System::running() {
	Console::set_place_menu(); 

	while (Console::get_place_menu() != 4) {
		UserNow = NULL;
		Console::set_login_menu();

		if (Console::get_login_menu() == 1) { // �α��� sign_in
			UserNow = login->sign_in(Console::get_place_menu());
		}
		else { // ȸ������ sign_up
			login->sign_up(Console::get_place_menu());
		}

		
		if (UserNow != NULL) {
			cout << "�α��� ����" << endl;
			UserNow->showData();
		}

		Console::set_place_menu();
	}
	cout << "���α׷��� �����մϴ�" << endl;
	delete login;
}