#include "Seat_StudyRoom.h"
#include <iostream>
using namespace std;

Seat_StudyRoom::Seat_StudyRoom() {
	name = "";
	gender = "";
}
void Seat_StudyRoom::appointment(UserData* User, Ticket_apart* appointment_data) {
	name = appointment_data->get_name();
	gender = appointment_data->get_gender();

	User->appointment(appointment_data);
}
bool Seat_StudyRoom::checkSeat() { // 여기 예외처리 고민
	if (name == "" && gender == "") {
		return true;
	}
	else {
		return false;
	}
}
string Seat_StudyRoom::get_gender() {
	return gender;
}
string Seat_StudyRoom::get_name() {
	return name;
}