#include "Console_restaurant.h"
#include <iostream>
#include <string>
using namespace std;

void Console_restaurant::set_menu() {
	menu = 0;

	while (menu == 0) {
		cout << endl;
		cout << "=========================" << endl;
		cout << "�Ĵ� ���� �ý��ۿ� ���Ű� ȯ���մϴ�" << endl;
		cout << "1: ���� / 2: ���� ��� / 3: �Ĵ� �湮 / 4: ��� / 5: �α׾ƿ� >>";
		cin >> menu;

		if (menu > 5 || menu < 1) { //����ó��
			menu = 0;
			cout << "�߸��� �Է��Դϴ�" << endl;
		}
	}
}

int Console_restaurant::get_menu() {
	return menu;
}

void Console_restaurant::set_date() {
	date = 0;

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
}

int Console_restaurant::get_date() {
	return date;
}


void Console_restaurant::set_people() {
	cout << "�湮 �ο� >>";
	cin >> people;
}

int Console_restaurant::get_people() {
	return people;
}

void Console_restaurant::set_table() {
	table = 0;

	while (table == 0) {
		cout << "\'�Ұ�\'��� ���� �¼��� ������ �� �����ϴ�" << endl;
		cout << "�����Ͻ� �¼��� ��ȣ�� �Է����ּ��� >>";
		cin >> table;

		if (table > 7 || table < 1) {
			table = 0;
			cout << "�߸��� �Է��Դϴ�" << endl;
		}
	}
}

int Console_restaurant::get_table() {
	return table;
}

void Console_restaurant::set_ticket_number() {
	cout << "����ϰ� ���� ���� ��ȣ�� �Է��ϼ��� (���ư��� : 0 )>>";
	cin >> ticket_number;
}
int Console_restaurant::get_ticket_number() {
	return ticket_number;
}
