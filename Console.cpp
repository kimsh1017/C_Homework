#include "Console.h"
#include <iostream>
#include <string>
using namespace std;

string Console::id = "";
string Console::password = "";
int Console::place_menu = 0;
int Console::login_menu = 0;

void Console::set_id() {
	cout << "ID >>";
	cin >> id;
}
string Console::get_id() {
	return id;
}

void Console::set_password() {
	cout << "��й�ȣ >>";
	cin >> password;
}
string Console::get_password() {
	return password;
}


void Console::set_place_menu() {
	place_menu = 0;
	while (place_menu == 0) {
		cout << "���� ���α׷��� �����ϼ���" << endl;
		cout << "1: ����� ���� / 2: �Ĵ� ���� / 3: ������ ���� / 4: ����>>";
		cin >> place_menu;

		if (place_menu > 4 || place_menu < 1) {
			cout << "�߸��� �Է��Դϴ�" << endl;
			place_menu = 0;
		}
	}
}

void Console::set_login_menu() {
	login_menu = 0;
	cout << "ȯ���մϴ�" << endl;
	while (login_menu == 0) {
		cout << "1: �α��� / 2: ȸ�� ����>>";
		cin >> login_menu;

		if (login_menu > 2 || login_menu < 1) {
			cout << "�߸��� �Է��Դϴ�" << endl;
			login_menu = 0;
		}
	}
}

int Console::get_login_menu() {
	return login_menu;
}
int Console::get_place_menu() {
	return place_menu;
}
