#include "Console.h"

string Console::set_id() {
	string id;
	cout << "ID >>";
	cin >> id;
	return id;
}

string Console::set_password() {
	string password;

	cout << "��й�ȣ >>";
	cin >> password;
	return password;
}


int Console::set_place_menu() {
	int place_menu = 0;
	while (place_menu == 0) {
		cout << "���� ���α׷��� �����ϼ���" << endl;
		cout << "1: ����� ���� / 2: �Ĵ� ���� / 3: ������ ���� / 4: ����>>";
		cin >> place_menu;

		if (place_menu > 4 || place_menu < 1) {
			cout << "�߸��� �Է��Դϴ�" << endl;
			place_menu = 0;
		}
	}
	return place_menu;
}

int Console::set_login_menu() {
	int login_menu = 0;
	cout << "ȯ���մϴ�" << endl;
	while (login_menu == 0) {
		cout << "1: �α��� / 2: ȸ�� ����>>";
		cin >> login_menu;

		if (login_menu > 2 || login_menu < 1) {
			cout << "�߸��� �Է��Դϴ�" << endl;
			login_menu = 0;
		}
	}
	return login_menu;
}

