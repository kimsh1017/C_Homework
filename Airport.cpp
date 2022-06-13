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

	setReservation();
}
Airport::~Airport() {
	fstream fout("ReservationAirport.txt", ios::out);
	if (!fout) {
		cout << "���� ���� ����" << endl;
		Sleep(500);
	}
	else {
		for (int i = 0; i < reservationData.size(); i++) {
			fout << "***\n";
			fout << reservationData[i].get_id() << '/';
			fout << reservationData[i].get_departure() << '/';
			fout << reservationData[i].get_arrival() << '/';
			fout << reservationData[i].get_date() << '/';
			fout << reservationData[i].get_time() << '/';
			fout << reservationData[i].get_seat_number() << '\n';
		}
	}
	fout.close();

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

void Airport::setReservation() {
	fstream fin("ReservationAirport.txt", ios::in);
	string id, temp;
	int departure, arrival, time, date, seat_number;

	if (!fin) {
		cout << "���� ���� ����" << endl;
		Sleep(500);
	}
	else {
		while (getline(fin, temp)) {
			if (temp == "***") {
				getline(fin, temp, '/');
				id = temp;

				getline(fin, temp, '/');
				departure = stoi(temp);

				getline(fin, temp, '/');
				arrival = stoi(temp);

				getline(fin, temp, '/');
				date = stoi(temp);

				getline(fin, temp, '/');
				time = stoi(temp);

				getline(fin, temp);
				seat_number = stoi(temp);

				reservationData.push_back(Ticket_airport(id, departure, arrival, date, time, seat_number));
			}
		}
	}

	for (int i = 0; i < reservationData.size(); i++) {
		int departure, arrival;
		departure = reservationData[i].get_departure();
		arrival = reservationData[i].get_arrival();

		if (arrival > departure) arrival--;
		airplane_list[departure - 1][arrival - 1].appointment(&reservationData[i]);
	}
	fin.close();
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

void Airport::runServer(newUserData* User) {
	this->User = User;
	int menu = 0;
	int check_appointed = reservationData.size(); // ������� ���� ��

	while (menu != 4) {
		// 1. ���� 2. ��� 3. ��� 4. �α׾ƿ�
		menu = Console_airport::set_menu(User->get_name());

		switch (menu) {
		case 1:
			appointment();
			if (reservationData.size() != check_appointed) { // ���� ������
				menu = 4; // �α׾ƿ�
			}
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
			set_route(departure, arrival);
			if (reservationData.back().get_seat_number() != 0) { //ù��° ���� ����ÿ���
				set_route(arrival, departure);
			}
		}
		else {
			set_route(departure, arrival);
		}

		if (reservationData.back().get_seat_number() == 0) {
			cout << "���� ���" << endl;
			Sleep(500);
			reservationData.erase(reservationData.end() - 1);
		}
	}
}

void Airport::set_route(int departure, int arrival) {
	reservationData.push_back(Ticket_airport(User->get_id(),departure,arrival,User->get_name()));

	if (arrival > departure) {
		arrival--;
	}
	airplane_list[departure - 1][arrival - 1].appointment(&reservationData.back());
}

void Airport::cancel() {
	int ticket_number, departure , arrival;
	int count = 1;
	Ticket_airport* cancel_data = NULL;
	
	for (int i = 0; i < reservationData.size(); i++) {
		if (User->get_id() == reservationData[i].get_id()) {
			cout << count << "�� ����" << endl;
			reservationData[i].showTicket();
			count++;
		}
	}
	count = 0;
	ticket_number = Console_airport::set_ticket_number(reservationData.size());

	if (ticket_number != 0) {
		for (int i = 0; i < reservationData.size(); i++) {
			if (User->get_id() == reservationData[i].get_id()) {
				count++;
				if (count == ticket_number) {
					ticket_number = i;
					break;
				}
			}
		}

		cancel_data = &reservationData[ticket_number];
		departure = cancel_data->get_departure();
		arrival = cancel_data->get_arrival();

		if (arrival > departure) arrival--;

		airplane_list[departure-1][arrival-1].cancel(cancel_data);
		reservationData.erase(reservationData.begin() + ticket_number);

		cout << "��ҵǾ����ϴ�" << endl;
		Sleep(1000);
	}
}

void Airport::showStat() {
	int menu;
	int economy = 0;
	int bussiness = 0;
	int seat_stat[8] = {0,};
	int mileage = 0;

	menu = Console_airport::set_stat_menu();
	if (menu == 1) {
		for (int i = 0; i < reservationData.size(); i++) {
			if (User->get_id() == reservationData[i].get_id()) {
				reservationData[i].showTicket();
				mileage += 100;
			}
		}
		cout << endl;
		cout << "���ϸ��� : " << mileage << "km" << endl;
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