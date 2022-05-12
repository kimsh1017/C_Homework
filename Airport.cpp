#include "Airport.h"
#include "Console_airport.h"

#include "Ticket.h"
#include "Ticket_airport.h"
#include <iostream>
#include <string>
using namespace std;

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

void Airport::sign_in(UserData* User) {
	this->User = User;
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

void Airport::runServer() {
	int menu = 0;
	menu = Console_airport::set_menu();
	while (menu != 4) {
		switch (menu) {
		case 1:
			appointment();
			break;
		case 2:
			cout << "대충 취소" << endl;
			break;
		case 3:
			showStat();
			break;
		}
		menu = Console_airport::set_menu();
	}
	cout << "비행기 예약 시스템을 종료합니다" << endl;
}

void Airport::appointment() {
	int departure, arrival;
	bool round_trip = Console_airport::check_round_trip();

	departure = Console_airport::set_departure();
	arrival = Console_airport::set_arrival();

	if (departure == arrival) {
		cout << "잘못된 입력입니다" << endl;
		cout << "출발지와 도착지는 달라야합니다" << endl;
	}
	else {
		if (round_trip) {
			set_route(departure, arrival);
			set_route(arrival, departure);
		}
		else {
			set_route(departure, arrival);
		}
	}
}

void Airport::set_route(int departure, int arrival) {
	string airport_list[5] = { "인천","김포","제주","김해","대구" };
	appointment_data = new Ticket_airport();
	appointment_data->set_route(departure, arrival);

	cout << airport_list[departure - 1] << "->" << airport_list[arrival - 1] << "행 비행기 " << endl;

	if (arrival > departure) {
		arrival--;
	}
	airplane_list[departure - 1][arrival - 1].appointment(User, appointment_data);
	delete appointment_data;
}

void Airport::showStat() {
	User->showTickets();
}