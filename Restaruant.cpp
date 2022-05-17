#include "Restaurant.h"
#include "Console_restaurant.h"
#include "UserData_restaurant.h"

#include <iostream>
#include <string>
#include "Ticket_restaurant.h"
using namespace std;

Restaurant::Restaurant() {
	this->User = NULL;
	schedules = new Schedule_restaurant[7];
	walk_in_table = "";

	set_date(); // �����ٿ� ���� ��¥ ����
}
Restaurant::~Restaurant() {
	delete[]schedules;
}

void Restaurant::set_date() { // ���� ��¥ ����
	schedules[0].setDate("5�� 1�� �Ͽ���");
	schedules[1].setDate("5�� 2�� ������");
	schedules[2].setDate("5�� 3�� ȭ����");
	schedules[3].setDate("5�� 4�� ������");
	schedules[4].setDate("5�� 5�� �����");
	schedules[5].setDate("5�� 6�� �ݿ���");
	schedules[6].setDate("5�� 7�� �����");
}


void Restaurant::sign_in(UserData* User) { //�α��ε� ���� ���� �޾ƿ���
	this->User = User;
}

void Restaurant::appointment() {
	int date = Console_restaurant::set_date();

	appointment_data = new Ticket_restaurant;
	appointment_data->set_date(date);
	schedules[date - 1].appointment(User,appointment_data);
}

void Restaurant::walk_in() { // walk-in ���� 
	int walk_in_menu = 0;

	if (User->get_id() == walk_in_table) { // ���̺� ������ ������? or walk_in ��ü ����?
		cout << "���� �Ļ����Դϴ�" << endl;
		cout << "�Ļ縦 �����Ͻðڽ��ϱ�?" << endl;
		cout << "�� : 1 / �ƴϿ� : 2" << endl;
		cin >> walk_in_menu;
		if (walk_in_menu == 1) {
			walk_in_table = "";
		}
	}
	else {
		if (walk_in_queue.empty()) {
			if (walk_in_table == "") {
				cout << "���̺��� �����ֽ��ϴ�. �ٷ� �Ļ��Ͻðڽ��ϱ�?" << endl;
				cout << "�� : 1 / �ƴϿ� : 2" << endl;
				cin >> walk_in_menu;
				if (walk_in_menu == 1) {
					walk_in_table = User->get_id();
				}
			}
			else {
				cout << "��� ���̺��� �Ļ� ���Դϴ�" << endl;
				cout << "����Ͻðڽ��ϱ�?" << endl;
				cout << "�� : 1 / �ƴϿ� : 2" << endl;
				cin >> walk_in_menu;
				if (walk_in_menu == 1) {
					add_queue();
				}
			}
		}

		else if (User->get_id() == walk_in_queue.front()) {
			// �� �Ļ� ����Ǽ� �Ļ� ���� ������ ��?
			if (walk_in_table == "") {
				cout << "���̺� �ڸ��� ������ϴ�. �ٷ� �Ļ��Ͻðڽ��ϱ�?" << endl;
				cout << "�� : 1 / �ƴϿ� : 2" << endl;
				cin >> walk_in_menu;
				if (walk_in_menu == 1) {
					walk_in_table = walk_in_queue.front();
					walk_in_queue.pop_front();
				}
			}
			else {
				cout << "���� �������� 1�� �Դϴ�" << endl;
			}
		}
		else {
			for (int i = 1; i < walk_in_queue.size(); i++) {
				if (User->get_id() == walk_in_queue[i]) {
					cout << "���� ��� ��ȣ��" << i+1 << "�� �Դϴ�" << endl;
					walk_in_menu = 1;
				}
			}
			if (walk_in_menu == 0) {
				cout << "����" << walk_in_queue.size() << "���� ������Դϴ�" << endl;
				cout << "����Ͻðڽ��ϱ�?" << endl;
				cout << "�� : 1 / �ƴϿ� : 2 >>" << endl;
				cin >> walk_in_menu;

				if (walk_in_menu == 1) {
					add_queue();
				}
			}
		}
	}
}

void Restaurant::runServer(UserData* User) {
	int menu;
	this->User = User;

	menu = Console_restaurant::set_menu();
	while (menu!= 5) {  //menu 5 = �α׾ƿ�
		switch (menu) {
		case 1:
			if (User->get_age() <= 7) {
				cout << "7�� ���� ������ �Ƶ��� ������ �Ұ����մϴ�." << endl;
			}
			else {
				appointment();
			}
			break;
		case 2:
			cancel();
			break;
		case 3: 
			walk_in();
			break;
		case 4:
			showStat();
			break;
		}
		menu = Console_restaurant::set_menu();
	}
}

void Restaurant::cancel() {
	Ticket* ticket = NULL;
	int ticket_number;

	// User ���� ���̺� ���� �޾ƿ���
	User->showTickets();
	ticket_number = Console_restaurant::set_ticket_number(User->get_tickets_size());
	ticket = User->getTicket(ticket_number);

	// ���� ������ ���̺� ��ü ������ ����ϱ�
	if (ticket != NULL) {
		schedules[ticket->get_date() - 1].cancel(ticket->get_table_number());
		User->cancel(ticket_number);
	}
}

void Restaurant::add_queue() {
	walk_in_queue.push_back(User->get_id());
}

void Restaurant::showStat() {
	// ���� ��� �����ִ� �Լ�

	int stat_menu = 0;
	int table_stat[6] = { 0, };
	while (stat_menu == 0) {
		cout << "1 : �� ���� ��Ȳ ���� / 2 : ���̺� ���� Ƚ�� ���� >>";
		cin >> stat_menu;

		if (stat_menu > 2 || stat_menu < 1) {
			stat_menu = 0;
			cout << "�߸��� �Է��Դϴ�" << endl;
		}
	}

	if (stat_menu == 1) { // ���� ���ݱ����� ���� Ƚ�� �����ֱ�
		User->showTickets();
	}
	else { // ���̺� ����� Ƚ�� �����ֱ�
		for (int i = 0; i < 6; i++) {
			table_stat[i] = 0;
		}


		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 6; j++) {
				if (schedules[i].checkTable(j+1)) {
					table_stat[j]++;
				}
			}
		}

		for (int i = 0; i < 6; i++) {
			cout << i+1 << "�� ���̺� ���� Ƚ�� : " << table_stat[i] << endl;
		}
	}
}
