#include "Airport.h"

Airport::Airport() {
	User = NULL;
	airplane_list = new Airplane * [5];
	appointment_data = NULL;
	
	for (int i = 0; i < 5; i++) { // 비행기 목록 만들기
		airplane_list[i] = new Airplane[4];
	}
	setAirplaneDeparture(); //출발지 설정
	setAirplaneArrival(); // 도착지 설정
}
Airport::~Airport() {
	for (int i = 0; i < 5; i++) {
		delete []airplane_list[i];
	}
	delete []airplane_list;
}

void Airport::setAirplaneDeparture() {
	string airport_list[5] = { "인천","김포","제주","김해","대구" };
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			airplane_list[i][j].setDeparture(airport_list[i]);
		}
	}
}

void Airport::setAirplaneArrival() {
	string airport_list[5] = { "인천","김포","제주","김해","대구" };
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

void Airport::show_airplane_list() { // 디버깅용 출발 도착 출력
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
	cout << "비행기 예약 시스템을 종료합니다" << endl;
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
			cout << "잘못된 입력입니다" << endl;
			cout << "출발지와 도착지는 달라야합니다" << endl;
			Sleep(500);
			system("cls");
		}
		else if (round_trip) {
			cancelCheck = User->get_tickets_size();

			set_route(departure, arrival);
			if (cancelCheck != User->get_tickets_size()) { //첫번째 예약 실행시에만
				set_route(arrival, departure);
			}
		}
		else {
			set_route(departure, arrival);
		}
	}
}

void Airport::set_route(int departure, int arrival) {
	string airport_list[5] = { "인천","김포","제주","김해","대구" };

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

		cout << "취소되었습니다" << endl;
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
		cout << "마일리지 : " << User->get_mileage() << "km" << endl;
	}
	else { // 총 예약 현황은?
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
		cout << "예약된 좌석 수" << endl;
		for (int i = 0; i < 8; i++) {
			cout << i + 1 << "번 좌석 : " << seat_stat[i] << "회" << endl;
		}
		cout << endl;
		cout << "총 예약된 이코노미 좌석 수 : " << economy << endl;
		cout << "총 예약된 비즈니스 좌석 수 : " << bussiness << endl;
	}

	while (menu != 0) {
		cout << "돌아가기 : 0 >>";
		cin >> menu;
		if (menu != 0) {
			menu = 1;
		}
	}
}