#include "Console_restaurant.h"

int Console_restaurant::set_menu(string name) {
	int menu = 0;

	while (menu == 0) {
		clean(0);
		cout << endl;
		cout << "�Ĵ� ���� ���α׷��� ���Ű� ȯ���մϴ�" << endl;
		cout << name << "�� ȯ���մϴ�" << endl;

		cout << endl;
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
	int date = -1;

	while (date == -1) {
		clean(0);
		cout << endl;
		cout << "��¥�� �������ּ���" << endl;
		cout << "*****5��****************************" << endl;
		cout << "____________________________________" << endl;
		cout << "| �� | �� | ȭ | �� | �� | �� | �� |" << endl;
		cout << "------------------------------------" << endl;
		cout << "| 1  | 2  | 3  | 4  | 5  | 6  | 7  |" << endl;
		cout << "------------------------------------" << endl;
		cout << "5�� _�� (���ư��� : 0)>>";
		cin >> date;

		if (date > 7 || date < 0) { //����ó��
			date = -1;
			cout << "�߸��� �Է��Դϴ�" << endl;
			Sleep(500);
		}
	}
	return date;
}


int Console_restaurant::set_people(Ticket* appointment_data) {
	int people = -1;
	while (people == -1) {
		clean(0);
		cout << endl;
		cout << "[5�� " << appointment_data->get_date() << "��]" << endl;
		cout << "�湮 �ο� (���ư��� : 0)>>";
		cin >> people;
		if (people < 0) {
			cout << "�߸��� �Է��Դϴ�" << endl;
			people = -1;
			Sleep(500);
		}
		else if (people > 6) {
			cout << "�˼��մϴ�. ���� ���Դ� 6�� �̻� ���̺��� �������� �ʽ��ϴ�" << endl;
			people = -1;
			Sleep(500);
		}
	}
	return people;
}

int Console_restaurant::set_table(Ticket* appointment_data) {
	int table = -1;

	while (table == -1) {
		cout << endl;
		cout << "[5�� " << appointment_data->get_date() << "��]" << endl;
		cout << "\'�Ұ�\'��� ���� �¼��� ������ �� �����ϴ�" << endl;
		cout << "�����Ͻ� �¼��� ��ȣ�� �Է����ּ��� >>";
		cin >> table;

		if (table > 6 || table < 0) {
			table = -1;
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
		clean(0);
		cout << endl;
		cout << "1 : �� ���� ��Ȳ ���� / 2 : ���̺� ���� Ƚ�� ���� (���ư��� : 0)>>";
		cin >> menu;

		if (menu > 2 || menu < 0) {
			menu = -1;
			cout << "�߸��� �Է��Դϴ�" << endl;
			Sleep(500);
		}
	}
	return menu;
}

int Console_restaurant::set_walk_in_people() {
	int people = -1;
	while (people == -1) {
		cout << "�湮 �ο� (���ư��� : 0)>>";
		cin >> people;
		if (people < 0) {
			cout << "�߸��� �Է��Դϴ�" << endl;
			people = -1;
			Sleep(500);
		}
		else if (people > 4) {
			cout << "�˼��մϴ�. 5�� �̻��� ���� �մԸ� �����մϴ�." << endl;
			people = 0;
			Sleep(500);
		}
	}
	return people;
}

void Console_restaurant::clean(int delay) {
	Sleep(delay);
	system("cls");
}

