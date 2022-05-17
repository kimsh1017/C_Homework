#include "Apart.h"
#include <iostream>
using namespace std;

Apart::Apart() {
	studyRoom_Date = new StudyRoom_Date[7];
	User = NULL;
}
Apart::~Apart() {
	delete[]studyRoom_Date;
}

void Apart::runserver(UserData* User) {
	this->User = User;
	int menu = 0;

	while (menu != 4) {
		menu = Console_apart::set_menu();

		switch (menu) {
		case 1:
			appointment();
			break;
		case 2:
			cancel();
			break;
		case 3:
			showStat();
			break;
		}
	}
}

void Apart::appointment() {
	int date = 0;
	Ticket_apart* appointment_data;
	date = Console_apart::set_date();

	if (date != 0) {
		appointment_data = new Ticket_apart;
		appointment_data->set_date(date);
		studyRoom_Date[date - 1].appointment(User, appointment_data);
		delete appointment_data;
	}
}
void Apart::cancel() {
	cout << "대충 취소" << endl;
}

void Apart::showStat() {
	cout << "대충 통계" << endl;
}

