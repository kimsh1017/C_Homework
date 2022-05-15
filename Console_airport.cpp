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
		string airport_list[5] = { "��õ","����","����","����","�뱸" };
		cout << "======================" << endl;
		cout << "������� �������ּ���" << endl;
		for (int i = 0; i < 5; i++) {
			cout << i + 1 << " : " << airport_list[i] << "����" << endl;
		}
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
		cout << "�������� �������ּ���" << endl;
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
		cout << "������ ���ϴ� �ڸ��� �Է����ּ��� >>";
		cin >> seat_number;

		if (seat_number > 8 || seat_number < 0) {
			cout << "�߸��� �Է��Դϴ�" << endl;
			seat_number = 0;
		}
	}
	return seat_number;
}

bool Console_airport::check_round_trip() {
	int temp = 0;
	cout << endl;

	while (temp == 0) {
		cout << "1: �պ� / 2: �� >>";
		cin >> temp;

		if (temp > 2 || temp < 0) {
			temp = 0;
		}
	}
	return temp==1 ? true : false;
}

int Console_airport::set_ticket_number(int max) {
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

float Console_airport::set_cost() {
	int menu = 0;
	float cost = 0;
	while (menu == 0) {
		cout << "1. ���� ���Ѽ� �����ϱ� / 2. ��� �¼� ���� >>";
		cin >> menu;
		if (menu > 2 || menu < 0) {
			menu = 0;
			cout << "�߸��� �Է��Դϴ�" << endl;
		}
	}
	
	if (menu == 2) {
		cost = 11;
	}
	while (cost == 0) {
		cout << " ���� : __�� �� ���� >>";
		cin >> cost;

		if (cost < 0) {
			cout << "�߸��� �Է��Դϴ�" << endl;
		}
	}
	return cost;
}