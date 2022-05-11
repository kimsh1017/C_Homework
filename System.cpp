#include "System.h"
#include "UserData.h"
#include "Login.h"
#include "Console.h"

#include "Restaurant.h"

#include <iostream>
using namespace std;
#include<string>


System::System() {
	login = new Login;
	UserNow = NULL;
	restaurant = new Restaurant;
}
void System::running() {
	int place_menu;

	place_menu = Console::set_place_menu(); 
	while (place_menu != 4) {
		// �α��� �Ǵ� ȸ������
		UserNow = login->sign_in_or_up(place_menu);

		// �α��� ������
		while (UserNow != NULL) {
			switch (place_menu) {
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
		place_menu = Console::set_place_menu();
	}
	cout << "���α׷��� �����մϴ�" << endl;
	delete login;
	delete restaurant;
}