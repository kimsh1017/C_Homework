#include "Seat_StudyRoom.h"

Seat_StudyRoom::Seat_StudyRoom() {
	name = "";
	gender = "";
}
void Seat_StudyRoom::appointment(UserData* User, Ticket_apart* appointment_data) {
	name = appointment_data->get_name();
	gender = appointment_data->get_gender();

	User->appointment(appointment_data);

	cout << appointment_data->get_name() << "님 예약되었습니다" << endl;
	Sleep(1000);
}
bool Seat_StudyRoom::checkSeat() { 
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
void Seat_StudyRoom::cancel() {
	name = "";
	gender = "";
}