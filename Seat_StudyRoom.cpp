#include "Seat_StudyRoom.h"

Seat_StudyRoom::Seat_StudyRoom() {
	id = "";
	gender = "";
}
void Seat_StudyRoom::appointment(Ticket_apart* reservation) {
	id = reservation->get_id();
	gender = reservation->get_gender();
}
bool Seat_StudyRoom::checkSeat() { 
	if (id == "" && gender == "") {
		return true;
	}
	else {
		return false;
	}
}
string Seat_StudyRoom::get_gender() {
	return gender;
}
string Seat_StudyRoom::get_id() {
	return id;
}
void Seat_StudyRoom::cancel() {
	id = "";
	gender = "";
}