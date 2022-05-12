#include "Airplane.h"

Airplane::Airplane() {
	departure = "";
	arrival = "";
	schedules = new Schedule_airplane[7];
}
Airplane::~Airplane() {
	delete []schedules;
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
	schedules[0].setDate("5월 1일 일요일");
	schedules[1].setDate("5월 2일 월요일");
	schedules[2].setDate("5월 3일 화요일");
	schedules[3].setDate("5월 4일 수요일");
	schedules[4].setDate("5월 5일 목요일");
	schedules[5].setDate("5월 6일 금요일");
	schedules[6].setDate("5월 7일 토요일");
}