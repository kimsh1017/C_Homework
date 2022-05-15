#include "Schedule_airplane.h"
#include "Console_airport.h"

#include "Ticket.h"
#include "Ticket_airport.h"
#include <iostream>
#include <string>
using namespace std;

Schedule_airplane::Schedule_airplane() {
	time = "";

	seats = new Seat[8]; // 3개 비즈니스 5개 이코노미
	set_seat_cost();
}
Schedule_airplane::~Schedule_airplane() {

	delete[]seats;
}
void Schedule_airplane::set_seat_cost() { //이거 걍 합칠까
	for (int i = 0; i < 8; i++) {
		i < 3 ? seats[i].set_cost_bussiness() : seats[i].set_cost_economy();
	}
}

void Schedule_airplane::setTime(string time) {
	this->time = time;
}

void Schedule_airplane::appointment(UserData* User,Ticket_airport* appointment_data) {
	int seat_number;
	float cost;

	cost = Console_airport::set_cost();

	showSeats(cost);
	seat_number = Console_airport::set_seat_number();

	if (seats[seat_number - 1].get_cost() <= cost) {
		if (seats[seat_number - 1].get_name() != "---") {
			cout << "이미 예약된 좌석입니다" << endl;
		}
		else {
			appointment_data->set_seat_number(seat_number);
			seats[seat_number - 1].appointment(User);
			User->appointment(appointment_data);
		}
	}
	else {
		cout << "입력한 예산을 초과하는 좌석입니다" << endl;
	}
}

void Schedule_airplane::showSeats(float cost) {

	cout << "===========================" << endl;
	
	for (int i = 0; i < 8; i++) {
		cout << " "<< i + 1 << "번 좌석 " << "|";
	}
	cout << endl;

	for (int i = 0; i < 8; i++) {
		if (i<3) cout <<" 비즈니스 " << "|";
		else cout << " 이코노미 " << "|";
	}
	cout << endl;

	for (int i = 0; i < 8; i++) {
		if(i<3)cout << "  "<< seats[i].get_cost() << "만원  |";
		else cout << "  " << seats[i].get_cost() << " 만원  |";
	}
	cout << endl;

	for (int i = 0; i < 8; i++) {
		if (seats[i].get_name() == "---" && seats[i].get_cost() <= cost) {
			cout << "   가능   |";
		}
		else {
			cout << "   불가   |";
		}
	}
	cout << endl;
}

void Schedule_airplane::cancel(Ticket* cancel_data) {
	int seat_number;
	seat_number = cancel_data->get_seat_number();

	seats[seat_number - 1].cancel();
}
