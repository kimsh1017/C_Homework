#include "Schedule_airplane.h"

Schedule_airplane::Schedule_airplane() {
	time = "";

	seats = new Seat[8]; // 3개 비즈니스 5개 이코노미
	set_seat_cost();
}
Schedule_airplane::~Schedule_airplane() {

	delete[]seats;
}
void Schedule_airplane::set_seat_cost() {
	for (int i = 0; i < 8; i++) {
		i < 3 ? seats[i].set_cost_bussiness() : seats[i].set_cost_economy();
	}
}

void Schedule_airplane::setTime(string time) {
	this->time = time;
}

void Schedule_airplane::appointment(Ticket_airport* reservation) {
	int seat_number = -1;
	float cost;

	if (reservation->get_seat_number() != 0) {
		seat_number = reservation->get_seat_number();
		seats[seat_number - 1].appointment(reservation);
	}
	else {
		Console_airport::printDataNow(reservation);

		cost = Console_airport::set_cost();

		while (seat_number == -1) {
			showSeats(cost, reservation);
			seat_number = Console_airport::set_seat_number();

			if (seat_number != 0) {
				if (seats[seat_number - 1].get_cost() > cost) {
					cout << "입력한 예산을 초과하는 좌석입니다" << endl;
					Sleep(500);
					seat_number = -1;
				}
				else {
					if (seats[seat_number - 1].get_id() != "---") {
						cout << "이미 예약된 좌석입니다" << endl;
						Sleep(500);
						seat_number = -1;
					}
					else {
						reservation->set_seat_number(seat_number);
						seats[seat_number - 1].appointment(reservation);
						cout << "예약되었습니다" << endl;
						Sleep(500);
					}
				}
			}
		}
	}
}

void Schedule_airplane::showSeats(float cost, Ticket_airport* appointment_data) {

	Console_airport::printDataNow(appointment_data);
	
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
		if (seats[i].get_id() == "---" && seats[i].get_cost() <= cost) {
			cout << "   가능   |";
		}
		else {
			cout << "   불가   |";
		}
	}
	cout << endl;
}

void Schedule_airplane::cancel(Ticket_airport* cancel_data) {
	int seat_number;
	seat_number = cancel_data->get_seat_number();

	seats[seat_number - 1].cancel();
}

bool Schedule_airplane::checkAppointed(int seat_number) {
	if (seats[seat_number].get_id() != "---") {
		return true;
	}
	else {
		return false;
	}
}
