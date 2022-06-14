#include "Console_airport.h"

void Console_airport::clean(int delay) {
	Sleep(delay);
	system("cls");
}
int Console_airport::set_menu(string name) {
	int menu = 0;

	while (menu == 0) {
		clean(0);
		cout << endl;
		cout << "����� ���� �ý��ۿ� ���Ű� ȯ���մϴ�" << endl;
		cout << name<< "�� ȯ���մϴ�" << endl;

		cout << endl;
		cout << "1: ���� / 2: ���� ��� / 3: ��� / 4: �α׾ƿ� >>";
		cin >> menu;

		if (menu > 4 || menu < 1) { //����ó��
			menu = 0;
			cout << "�߸��� �Է��Դϴ�" << endl;
		}
	}
	return menu;
}

int  Console_airport::set_date(Ticket_airport* appointment_data) {
	int date = -1;

	while (date == -1) {
		clean(0);
		cout << endl;
		printDataNow(appointment_data);
		cout << "��¥�� �������ּ���" << endl;
		cout << "*****5��****************************" << endl;
		cout << "____________________________________" << endl;
		cout << "| �� | �� | ȭ | �� | �� | �� | �� |" << endl;
		cout << "------------------------------------" << endl;
		cout << "| 1  | 2  | 3  | 4  | 5  | 6  | 7  |" << endl;
		cout << "------------------------------------" << endl;
		cout << "5�� _�� (���ư��� : 0) >>";
		cin >> date;

		if (date > 7 || date < 0) { //����ó��
			date = -1;
			cout << "�߸��� �Է��Դϴ�" << endl;
			Sleep(500);
			system("cls");
		}
	}
	return date;
}

int Console_airport::set_departure() {
	int place = -1;
	
	while (place == -1) {
		string airport_list[5] = { "��õ","����","����","����","�뱸" };
		cout << endl;
		cout << "������� �������� �������ּ���" << endl;
		for (int i = 0; i < 5; i++) {
			cout << i + 1 << " : " << airport_list[i] << "����" << endl;
		}
		cout << "(���ư��� : 0)" << endl;
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
	int place = -1;

	while (place == -1) {
		cout << "������>>";
		cin >> place;

		if (place > 5 || place < 0) {
			cout << "�߸��� �Է��Դϴ�" << endl;
			place = -1;
		}
	}
	return place;
}

int Console_airport::set_time(Ticket_airport* appointment_data) {
	int time = -1;

	while (time == -1) {
		clean(0);
		printDataNow(appointment_data);
		cout << "�ð��븦 �Է����ּ���" << endl;
		cout << "1: 07�� / 2: 12�� / 3: 17�� /(0: ���ư���)>>";
		cin >> time;

		if (time > 3 || time < 0) {
			cout << "�߸��� �Է��Դϴ�" << endl;
			Sleep(500);
			time = -1;
		}
	}
	return time;
}

int Console_airport::set_seat_number() {
	int seat_number = -1;
	while (seat_number == -1) {
		cout << endl;
		cout << "������ ���ϴ� �ڸ��� �Է����ּ��� (���ư��� : 0)>>";
		cin >> seat_number;

		if (seat_number > 8 || seat_number < 0) {
			cout << "�߸��� �Է��Դϴ�" << endl;
			seat_number = -1;
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
	clean(0);
	temp == 1 ? cout << "�պ� ����" << endl : cout << "�� ����" << endl;
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
		cout << endl;
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

int Console_airport::set_stat_menu() {
	int stat_menu = 0;
	while (stat_menu == 0) {
		clean(0);
		cout << endl;
		cout << "1 : �� ���� ��Ȳ ���� / 2 : �¼��� ���� ��Ȳ ���� >>";
		cin >> stat_menu;

		if (stat_menu > 2 || stat_menu < 1) {
			stat_menu = 0;
			cout << "�߸��� �Է��Դϴ�" << endl;
			Sleep(500);
		}
	}
	return stat_menu;
}

void Console_airport::printDataNow(Ticket_airport* appointment_data) {
	int departure,arrival,date, time;
	string string_time;
	string airport_list[5] = { "��õ","����","����","����","�뱸" };

	departure = appointment_data->get_departure();
	arrival = appointment_data->get_arrival();
	date = appointment_data->get_date();
	time = appointment_data->get_time();


	switch (time) {
	case 1:
		string_time = "07��";
		break;
	case 2:
		string_time = "12��";
		break;
	case 3:
		string_time = "17��";
		break;
	}

	clean(0);

	if (date == 0) {
		cout << endl;
		cout << "[" << airport_list[departure - 1] << "->" << airport_list[arrival - 1] << "�� ����� ]" << endl;
	}
	else if (time == 0) {
		cout << endl;
		cout << "5�� " << date << "�� " << endl;
		cout << "[" << airport_list[departure - 1] << "->" << airport_list[arrival - 1] << "�� ����� ]" << endl;
	}
	else {
		cout << endl;
		cout << "5�� " << date << "�� " << string_time << endl;
		cout << "[" << airport_list[departure - 1] << "->" << airport_list[arrival - 1] << "�� ����� ]" << endl;
	}
	cout <<  endl;
}