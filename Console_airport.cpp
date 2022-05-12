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

int Console_airport::set_departure() {
	int place = 0;
	
	while (place == 0) {
		cout << "======================" << endl;
		cout << "������� �������ּ���" << endl;
		cout << "1: 1�� ����" << endl;
		cout << "2: 2������" << endl;
		cout << "3: 3������" << endl;
		cout << "4: 4������" << endl;
		cout << "5: 5������" << endl;
		cout << "�����>>";
		cin >> place;

		if (place > 5 || place < 0) {
			cout << "�߸��� �Է��Դϴ�" << endl;
			place = 0;
		}
	}
	return place;
}

int Console_airport::set_arrival() {
	int place = 0;

	while (place == 0) {
		cout << "======================" << endl;
		cout << "�������� �������ּ���" << endl;
		cout << "1: 1�� ����" << endl;
		cout << "2: 2������" << endl;
		cout << "3: 3������" << endl;
		cout << "4: 4������" << endl;
		cout << "5: 5������" << endl;
		cout << "������>>";
		cin >> place;

		if (place > 5 || place < 0) {
			cout << "�߸��� �Է��Դϴ�" << endl;
			place = 0;
		}
	}
	return place;
}

int Console_airport::set_time() {
	int time = 0;
	while (time == 0) {
		cout << "�ð��븦 �Է����ּ���" << endl;
		cout << "1: 07�� / 2: 12�� / 3: 17�� >>";
		cin >> time;

		if (time > 3 || time < 0) {
			cout << "�߸��� �Է��Դϴ�" << endl;
			time = 0;
		}
	}
	return time;
}

int Console_airport::set_seat_number() {
	int seat_number = 0;
	while (seat_number == 0) {
		cout << "������ ���ϴ� �ڸ��� �Է����ּ��� >>" << endl;
		cin >> seat_number;

		if (seat_number > 8 || seat_number < 0) {
			cout << "�߸��� �Է��Դϴ�" << endl;
			seat_number = 0;
		}
	}
	return seat_number;
}

int Console_airport::set_seat_type() {
	int seat_type = 0;
	while (seat_type == 0) {
		cout << "�¼� ����� �������ּ��� 1: ���ڳ�� / 2: ����Ͻ�>>" << endl;
		cin >> seat_type;

		if (seat_type > 2 || seat_type < 0) {
			cout << "�߸��� �Է��Դϴ�" << endl;
			seat_type = 0;
		}
	}
	return seat_type;
}
