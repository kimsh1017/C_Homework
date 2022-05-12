#include "Airport.h"
#include "Console_airport.h"

Airport::Airport() {
	User = NULL;
	airplane_list = new Airplane * [5];
	
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
	string airport_list[5] = { "1번공항","2번공항","3번공항","4번공항","5번공항" };
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			airplane_list[i][j].setDeparture(airport_list[i]);
		}
	}
}

void Airport::setAirplaneArrival() {
	string airport_list[5] = { "1번공항","2번공항","3번공항","4번공항","5번공항" };
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

void Airport::show_airplane_list() {
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
			cout << "대충 예약" << endl;
			break;
		case 2:
			cout << "대충 취소" << endl;
			break;
		case 3:
			cout << "대충 통계" << endl;
			break;
		}
		menu = Console_airport::set_menu();
	}
	cout << "비행기 예약 시스템을 종료합니다" << endl;
}