#include "Console_airport.h"
#include <iostream>
#include <string>
using namespace std;

int Console_airport::set_menu() {
	int menu = 0;

	while (menu == 0) {
		cout << endl;
		cout << "=========================" << endl;
		cout << "����� ���� �ý��ۿ� ���Ű� ȯ���մϴ�" << endl;
		cout << "1: ���� / 2: ���� ��� / 3: ��� / 4: �α׾ƿ� >>";
		cin >> menu;

		if (menu > 4 || menu < 1) { //����ó��
			menu = 0;
			cout << "�߸��� �Է��Դϴ�" << endl;
		}
	}
	return menu;
}

int  Console_airport::set_date() {
	int date = 0;

	while (date == 0) {
		cout << "��¥�� �������ּ���" << endl;
		cout << "*****5��****************************" << endl;
		cout << "____________________________________" << endl;
		cout << "| �� | �� | ȭ | �� | �� | �� | �� |" << endl;
		cout << "------------------------------------" << endl;
		cout << "| 1  | 2  | 3  | 4  | 5  | 6  | 7  |" << endl;
		cout << "------------------------------------" << endl;
		cout << "5�� _�� >>";
		cin >> date;

		if (date > 7 || date < 1) { //����ó��
			date = 0;
			cout << "�߸��� �Է��Դϴ�" << endl;
		}
	}
	return date;
}