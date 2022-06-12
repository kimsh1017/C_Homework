#include "Console.h"

void moveCursor(int x, int y) { // Ŀ�� �����̴� �����Լ�
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

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

	clean(0);
	cout << endl;

	while (place_menu == 0) {
		cout << "���� ���α׷��� �����ϼ���" << endl;
		cout << "1: ����� ���� / 2: �Ĵ� ���� / 3: ������ ���� / 4: ����>>";
		cin >> place_menu;

		if (place_menu > 4 || place_menu < 1) {
			cout << "�߸��� �Է��Դϴ�" << endl;
			place_menu = 0;
			clean(500);
			cout << endl;
		}
	}
	return place_menu;
}

int Console::set_login_menu() {
	int login_menu = -1;
	while (login_menu == -1) {
		cout << "1: �α��� / 2: ȸ�� ���� / 0: ���ư���>>";
		cin >> login_menu;

		if (login_menu > 2 || login_menu < 0) {
			cout << "�߸��� �Է��Դϴ�" << endl;
			login_menu = -1;
		}
	}
	return login_menu;
}

string Console::set_apartment_number() {
	string apartment_number = "";
	
	cout << "���븦 �Է����ּ��� : 101�� ___ȣ >>";
	cout << "(101~999������ ���ڷ� �Է����ּ���)" << endl;
	moveCursor(28, 4);
	cin >> apartment_number;

	return apartment_number;
}

void Console::clean(int delay) {
	Sleep(delay);
	system("cls");
}

int Console::set_age() {
	int age;
	cout << "���� >>";
	cin >> age;
	return age;
}


