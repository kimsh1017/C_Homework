#include "Console_apart.h"

int Console_apart::set_menu() {
	int menu = 0;

	while (menu == 0) {
		cout << endl;
		cout << "=========================" << endl;
		cout << "������ �ý��ۿ� ���Ű� ȯ���մϴ�" << endl;
		cout << "1: ���� / 2: ���� ��� / 3: ��� ���� / 4: �α׾ƿ� >>";
		cin >> menu;

		if (menu > 5 || menu < 1) { //����ó��
			menu = 0;
			cout << "�߸��� �Է��Դϴ�" << endl;
		}
	}
	return menu;
}

int  Console_apart::set_date() {
	int date = -1;

	cout << "====================================" << endl;
	while (date == -1) {
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
		}
	}
	return date;
}

int Console_apart::set_time(int total_time) {
	int time = -1;

	cout << "=============================================================" << endl;
	cout << "�����Ͻ� �ð��� �Է����ּ���." << endl;
	cout << "�����ð�: 09�� ~ 23�� , ����� �Ϸ� �ִ� 4�ð� ���� �����մϴ�" << endl;
	cout << endl;
	while (time == -1) {
		cout << "���� " << total_time << "�ð� ������" << endl;
		cout << "�� ���� 1�ð��� ���� �����մϴ�" << endl;
		cout << endl;
		cout << "�Խ� �ð� (���ư��� : 0)>>";
		cin >> time;

		if ((time < 9 || time> 22 ) && (time != 0)) {
			cout << "�߸��� �Է��Դϴ�. �����ð�: 09�� ~23��" << endl;
			time = -1;
		}
	}
	return time;
}

string Console_apart::set_name() {
	string name;
	cout << "�������� �̸��� �Է����ּ���>>";
	cin >> name;
	return name;
}
string Console_apart::set_gender() {
	string gender = "";

	while (gender == "") {
		cout << "�������� ������ �Է����ּ��� (��/��) >>";
		cin >> gender;

		if (gender != "��" && gender != "��") {
			cout << "�߸��� �Է��Դϴ�" << endl;
			gender = "";
		}
	}
	return gender;
}
int Console_apart::set_seat_number() {
	int n = -1;
	while (n == -1) {
		cout << "�����Ͻ� �¼� ��ȣ�� �Է����ּ��� (���ư��� 0) >>";
		cin >> n;

		if (n > 225 || n < 0) {
			cout << "�߸��� �Է��Դϴ�" << endl;
			n = -1;
		}
	}
	return n;
}

int Console_apart::set_age() {
	int age = 0;
	while (age == 0) {
		cout << "���� >>";
		cin >> age;
		if (age < 0) {
			cout << "�߸��� �Է��Դϴ�" << endl;
			age = 0;
		}
	}
	return age;
}

int Console_apart::set_ticket_number(int tickets_size) {
	int ticket_number = -1;
	while (ticket_number == -1) {
		cout << "����ϰ� ���� ������ ��ȣ�� �Է��ϼ��� (���ư��� : 0)>>";
		cin >> ticket_number;
		if (ticket_number > tickets_size || ticket_number < 0) {
			ticket_number = -1;
			cout << "�߸��� �Է��Դϴ�" << endl;
		}
	}
	return ticket_number;
}

int Console_apart::set_stat_menu() {
	int menu = -1;
	while (menu == -1) {
		cout << "1: �� ���� ��Ȳ ���� / 2: ��ü ���� ��� ���� (���ư��� : 0)>>";
		cin >> menu;
		if (menu > 2 || menu < 0) {
			cout << "�߸��� �Է��Դϴ�" << endl;
			menu = -1;
		}
	}
	return menu;
}

int Console_apart::set_stat_detail() {
	int menu = -1;

	while (menu == -1) {
		cout << "1 : �¼��� ���� ��Ȳ ���� / 2 : ���� ���� Ƚ�� ���� (���ư��� : 0)>>";
		cin >> menu;
		if (menu > 2 || menu < 0) {
			cout << "�߸��� �Է��Դϴ�" << endl;
			menu = -1;
		}	
	}
	return menu;
}

void Console_apart::clean(int delay) {
	Sleep(delay);
	system("cls");
}
