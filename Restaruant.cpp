#include "Restaurant.h"
#include "Console_restaurant.h"
#include "UserData_restaurant.h"

#include <iostream>
#include <string>
#include "Ticket.h"
using namespace std;

int Console_restaurant::menu = 0;
int Console_restaurant::date = 0;
int Console_restaurant::people = 0;
int Console_restaurant::table = 0;
int Console_restaurant::ticket_number = 0;

void Restaurant::set_date() {
	schedules[0].setDate("5�� 1�� �Ͽ���");
	schedules[1].setDate("5�� 2�� ������");
	schedules[2].setDate("5�� 3�� ȭ����");
	schedules[3].setDate("5�� 4�� ������");
	schedules[4].setDate("5�� 5�� �����");
	schedules[5].setDate("5�� 6�� �ݿ���");
	schedules[6].setDate("5�� 7�� �����");
}

Restaurant::Restaurant() {
	this->User = NULL;
	schedules = new Schedule_restaurant[7];
	set_date();
}
void Restaurant::sign_in(UserData* User) {
	this->User = User;
}

void Restaurant::appointment() {
	Console_restaurant::set_date(); // ����ó��
	schedules[Console_restaurant::get_date() - 1].appointment(User);
}

void Restaurant::walk_in() {
	int walk_in_menu = 0;
	if (walk_in_queue.empty()) {
		cout << "���̺��� �����ֽ��ϴ�. �ٷ� �Ļ��Ͻðڽ��ϱ�?" << endl;
		cout << "�� : 1 / �ƴϿ� : 2" << endl;
		cin >> walk_in_menu;
		if (walk_in_menu == 1) {
			add_queue();
		}
	}
	else if (User->get_id() == walk_in_queue.front()) {
		// �� �Ļ� ����Ǽ� �Ļ� ���� ������ ��?
		int walk_in_menu = 0;
		cout << "�Ļ縦 �����Ͻðڽ��ϱ�?" << endl;
		cout << "�� : 1 / �ƴϿ� : 2" << endl;
		cin >> walk_in_menu;
		if (walk_in_menu == 1) {
			walk_in_queue.pop();
		}
	}
	else {
		int walk_in_menu = 0;
		cout << "����" << walk_in_queue.size() << "���� ������Դϴ�" << endl;
		cout << "����Ͻðڽ��ϱ�?" << endl;
		cout << "�� : 1 / �ƴϿ� : 2" << endl;
		cin >> walk_in_menu;
		if (walk_in_menu == 1) {
			add_queue();
		}
	}
}

void Restaurant::open() {
	Console_restaurant::set_menu();
	while (Console_restaurant::get_menu() != 5) {
		switch (Console_restaurant::get_menu()) {
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
			break;
		case 5:
			cout << "�α׾ƿ� �մϴ�" << endl;
			break;
		}
		Console_restaurant::set_menu();
	}
}

void Restaurant::cancel() {
	// User ���� ���̺� ���� �޾ƿ���
	// ���� ������ ���̺� ��ü ������ ����ϱ�
	Ticket* ticket = NULL;

	User->showTickets();
	Console_restaurant::set_ticket_number();

	ticket = User->getTicket(Console_restaurant::get_ticket_number());
	if (ticket != NULL) {
		schedules[ticket->get_date() - 1].cancel(ticket->get_table_number());
	}
	User->cancel(Console_restaurant::get_ticket_number());
}

void Restaurant::add_queue() {
	walk_in_queue.push(User->get_id());
}
