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

	set_date(); // �����ٿ� ���� ��¥ ����
	walkInServer = new Walk_in;
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

void Restaurant::walk_in() {
	walkInServer->running(User);
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

void Restaurant::showStat() {
	int stat_menu = 0;
	int table_stat[6] = {0,};

	stat_menu = Console_restaurant::set_stat_menu();

	if (stat_menu == 1) { // ���� ���ݱ����� ���� Ƚ�� �����ֱ�
		User->showTickets();
	}
	else if (stat_menu == 2) { // ���̺� ����� Ƚ�� �����ֱ�

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
