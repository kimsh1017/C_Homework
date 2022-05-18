#include "Console_restaurant.h"
#include <iostream>
#include <string>
using namespace std;

int Console_restaurant::set_menu() {
	int menu = 0;

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
	return menu;
}

int  Console_restaurant::set_date() {
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


int Console_restaurant::set_people() {
	int people;
	cout << "�湮 �ο� >>";
	cin >> people;

	return people;
}

int Console_restaurant::set_table() {
	int table = 0;

	while (table == 0) {
		cout << "\'�Ұ�\'��� ���� �¼��� ������ �� �����ϴ�" << endl;
		cout << "�����Ͻ� �¼��� ��ȣ�� �Է����ּ��� >>";
		cin >> table;

		if (table > 7 || table < 1) {
			table = 0;
			cout << "�߸��� �Է��Դϴ�" << endl;
		}
	}
	return table;
}

int Console_restaurant::set_ticket_number(int max) {
	int ticket_number = -1;
	while (ticket_number == -1) {
		cout << "����ϰ� ���� ���� ��ȣ�� �Է��ϼ��� (���ư��� : 0 )>>";
		cin >> ticket_number;

		if (ticket_number < 0 || ticket_number > max) {
			cout << "�߸��� �Է��Դϴ�" << endl;
			ticket_number = -1;
		}
	}
	return ticket_number;
}

int Console_restaurant::set_stat_menu() {
	int menu = -1;
	while (menu == -1) {
		cout << "1 : �� ���� ��Ȳ ���� / 2 : ���̺� ���� Ƚ�� ���� (���ư��� : 0)>>";
		cin >> menu;

		if (menu > 2 || menu < 1) {
			menu = -1;
			cout << "�߸��� �Է��Դϴ�" << endl;
		}
	}
	return menu;
}
