#include "System.h"
#include "UserData.h"
#include "Login.h"
#include <iostream>
using namespace std;
#include<string>

System::System() {
	place_menu = -1;
	sign_menu = -1;
	login = new Login;
}

void System::get_place() {
	cout << "���α׷� ����" << endl;
	cout << "1: ����� ���� / 2: �Ĵ� ���� / 3: ������ ���� / 4: ����>>";
	cin >> place_menu;
}
void System::get_sign() {
	cout << "ȯ���մϴ�" << endl;
	cout << "1: �α��� / 2: ȸ�� ����>>";
	cin >> sign_menu;
}

void System::running() {
	get_place();
	while (place_menu != 4) {
		get_sign();
		if (sign_menu == 1) {
			if (login->sign_in(place_menu)) {
				UserNow = login->getUser();
				cout << "ȯ���մϴ�" << endl;
				UserNow->showData();
			}
			else {
				cout << "������ �ùٸ��� �ʽ��ϴ�" << endl;
			}
		}
		else {
			login->sign_up(place_menu);
		}
		get_place();
	}
}