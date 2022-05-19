#include "Airport.h"

Airport::Airport() {
	User = NULL;
	airplane_list = new Airplane * [5];
	appointment_data = NULL;
	
	for (int i = 0; i < 5; i++) { // ����� ��� �����
		airplane_list[i] = new Airplane[4];
	}
	setAirplaneDeparture(); //����� ����
	setAirplaneArrival(); // ������ ����
}
Airport::~Airport() {
	for (int i = 0; i < 5; i++) {
		delete []airplane_list[i];
	}
	delete []airplane_list;
}

void Airport::setAirplaneDeparture() {
	string airport_list[5] = { "��õ","����","����","����","�뱸" };
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			airplane_list[i][j].setDeparture(airport_list[i]);
		}
	}
}

void Airport::setAirplaneArrival() {
	string airport_list[5] = { "��õ","����","����","����","�뱸" };
	int temp;

	for (int i = 0; i < 5; i++) {
		temp = 0;
		for (int j = 0; j < 4; j++) {
			if (temp == i) { temp++; }
			airplane_list[i][j].setArrival(airport_list[temp]);
			temp++;
		}
	}
}

void Airport::show_airplane_list() { // ������ ��� ���� ���
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			cout << airplane_list[i][j].getDeparture() << "->" << airplane_list[i][j].getArrival() << endl;
		}
		cout << "======================" << endl;
	}
}

void Airport::runServer(UserData* User) {
	this->User = User;
	int menu = 0;

	Sleep(500);
	menu = Console_airport::set_menu(User->get_name());

	while (menu != 4) {
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
		menu = Console_airport::set_menu(User->get_name());
	}
	cout << "����� ���� �ý����� �����մϴ�" << endl;
}

void Airport::appointment() {
	int departure = 0;
	int arrival = 0;
	int cancelCheck = 0;
	bool round_trip = Console_airport::check_round_trip();

	departure = Console_airport::set_departure();
	if (departure != 0) {
		arrival = Console_airport::set_arrival();
	}
	if (arrival != 0) {
		if (departure == arrival) {
			cout << endl;
			cout << "�߸��� �Է��Դϴ�" << endl;
			cout << "������� �������� �޶���մϴ�" << endl;
			Sleep(500);
			system("cls");
		}
		else if (round_trip) {
			cancelCheck = User->get_tickets_size();

			set_route(departure, arrival);
			if (cancelCheck != User->get_tickets_size()) { //ù��° ���� ����ÿ���
				set_route(arrival, departure);
			}
		}
		else {
			set_route(departure, arrival);
		}
	}
}

void Airport::set_route(int departure, int arrival) {
	string airport_list[5] = { "��õ","����","����","����","�뱸" };

	appointment_data = new Ticket_airport;
	appointment_data->set_route(departure, arrival);

	if (arrival > departure) {
		arrival--;
	}
	airplane_list[departure - 1][arrival - 1].appointment(User, appointment_data);
	delete appointment_data;
}

void Airport::cancel() {
	int ticket_number, departure , arrival;
	Ticket* cancel_data = NULL;

	User->showTickets();
	ticket_number = Console_airport::set_ticket_number(User->get_tickets_size());

	if (ticket_number != 0) {
		cancel_data = User->getTicket(ticket_number);
		departure = cancel_data->get_departure();
		arrival = cancel_data->get_arrival();

		if (arrival > departure) arrival--;

		airplane_list[departure-1][arrival-1].cancel(cancel_data);
		User->cancel(ticket_number);

		cout << "��ҵǾ����ϴ�" << endl;
		Sleep(1000);
	}
}

void Airport::showStat() {
	int menu;
	int economy = 0;
	int bussiness = 0;
	int seat_stat[8] = {0,};

	menu = Console_airport::set_stat_menu();
	if (menu == 1) {
		User->showTickets();
		cout << endl;
		cout << "���ϸ��� : " << User->get_mileage() << "km" << endl;
	}
	else { // �� ���� ��Ȳ��?
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 4; k++) {
					seat_stat[i] += airplane_list[j][k].checkAppointed(i);
				}	
			}
		}
		for (int i = 0; i < 8; i++) {
			if (i < 3) bussiness += seat_stat[i];
			else economy += seat_stat[i];
		}

		system("cls");
		cout << endl;
		cout << "����� �¼� ��" << endl;
		for (int i = 0; i < 8; i++) {
			cout << i + 1 << "�� �¼� : " << seat_stat[i] << "ȸ" << endl;
		}
		cout << endl;
		cout << "�� ����� ���ڳ�� �¼� �� : " << economy << endl;
		cout << "�� ����� ����Ͻ� �¼� �� : " << bussiness << endl;
	}

	while (menu != 0) {
		cout << "���ư��� : 0 >>";
		cin >> menu;
		if (menu != 0) {
			menu = 1;
		}
	}
}