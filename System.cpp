#include "System.h"
#include "UserData.h"
#include "Login.h"
#include "Console.h"

#include "Restaurant.h"

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
	restaurant = new Restaurant;
}
void System::running() {
	Console::set_place_menu(); 

	while (Console::get_place_menu() != 4) {
		// �α��� �Ǵ� ȸ������
		UserNow = login->sign_in_or_up(Console::get_place_menu());

		// �α��� ������
		while (UserNow != NULL) {
			switch (Console::get_place_menu()) {
			case 1:
				cout << "����� ���� �α��� ����" << endl;
				UserNow = NULL;
				break;
			case 2:
				restaurant->sign_in(UserNow);
				restaurant->open();
				UserNow = NULL;
				break;
			case 3:
				cout << "������ �α��� ����" << endl;
				UserNow = NULL;
				break;
			}
		}

		cout << endl;
		cout << "====================================" << endl;
		Console::set_place_menu();
	}
	cout << "���α׷��� �����մϴ�" << endl;
	delete login;
}