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
	int ticket_number = 0;
	Ticket* cancel_data;
	int date;

	User->showTickets();
	ticket_number = Console_apart::set_ticket_number(User->get_tickets_size());
	if (ticket_number != 0) {
		cancel_data = User->getTicket(ticket_number);
		date = cancel_data->get_date();
		studyRoom_Date[date - 1].cancel(cancel_data);
		User->cancel(ticket_number);
	}
}

void Apart::showStat() {
	int menu, seat_number;
	int result = 0;

	menu = Console_apart::set_stat_menu();

	if (menu == 1) {
		User->showTickets();
	}
	else if (menu == 2) {
		cout << endl;
		menu = Console_apart::set_stat_detail();

		if (menu == 1) {
			seat_number = Console_apart::set_seat_number();
			if (seat_number != 0) {
				for (int i = 0; i < 7; i++) {
					result += studyRoom_Date[i].check_seat(seat_number);
				}
				cout << seat_number << "¹ø ÁÂ¼®Àº ÃÑ" << result << "¹ø ¿¹¾àµÆ½À´Ï´Ù" << endl;
			}
		}
		else if (menu == 2) {
			for (int i = 0; i < 7; i++) {
				result += studyRoom_Date[i].check_gender("³²");
			}
			cout << "ÃÑ ¿¹¾à¼ö " << endl;
			cout << "³² : " << result << "   ";

			result = 0;
			for (int i = 0; i < 7; i++) {
				result += studyRoom_Date[i].check_gender("¿©");
			}
			cout << "¿© : " << result << endl;
		}
	}
}

