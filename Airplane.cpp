#include "Airplane.h"


Airplane::Airplane() {
	departure = "";
	arrival = "";
	airplane_date = new Airplane_date[7];
}
Airplane::~Airplane() {
	delete []airplane_date;
}

void Airplane::setDeparture(string departure) {
	this->departure = departure;
}
void Airplane::setArrival(string arrival) {
	this->arrival = arrival;
}
string Airplane::getDeparture() {
	return departure;
}
string Airplane::getArrival() {
	return arrival;
}
void Airplane::setDate() {
	airplane_date[0].setDate("5월 1일 일요일");
	airplane_date[1].setDate("5월 2일 월요일");
	airplane_date[2].setDate("5월 3일 화요일");			
	airplane_date[3].setDate("5월 4일 수요일");
	airplane_date[4].setDate("5월 5일 목요일");
	airplane_date[5].setDate("5월 6일 금요일");
	airplane_date[6].setDate("5월 7일 토요일");
}

void Airplane::appointment(Ticket_airport* reservation) {
	int date;

	if (reservation->get_seat_number() != 0) { // 이미 완성된 예약
		date = reservation->get_date();
		airplane_date[date - 1].appointment(reservation);
	}
	else {
		date = Console_airport::set_date(reservation);
		if (date != 0) {
			reservation->set_date(date);
			airplane_date[date - 1].appointment(reservation);
		}
	}
}

void Airplane::cancel(Ticket_airport* cancel_data) {
	int date = cancel_data->get_date();
	airplane_date[date - 1].cancel(cancel_data);
}

int Airplane::checkAppointed(int seat_number) {
	int result = 0;
	for (int i = 0; i < 7; i++) {
		result += airplane_date[i].checkAppointed(seat_number);
	}
	return result;
}
