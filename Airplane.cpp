#include "Airplane.h"
#include "Console_airport.h"

#include "Ticket.h"
#include "Ticket_airport.h"
#include <iostream>
#include <string>
using namespace std;

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
	airplane_date[0].setDate("5�� 1�� �Ͽ���");
	airplane_date[1].setDate("5�� 2�� ������");
	airplane_date[2].setDate("5�� 3�� ȭ����");
	airplane_date[3].setDate("5�� 4�� ������");
	airplane_date[4].setDate("5�� 5�� �����");
	airplane_date[5].setDate("5�� 6�� �ݿ���");
	airplane_date[6].setDate("5�� 7�� �����");
}

void Airplane::appointment(UserData* User, Ticket_airport* appointment_data) {
	int date;

	date = Console_airport::set_date();
	appointment_data->set_date(date);
	airplane_date[date - 1].appointment(User,appointment_data);
}
