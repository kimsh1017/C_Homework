#include "Ticket_airport.h"


Ticket_airport::Ticket_airport(string id ,int departure, int arrival,string name) {
	this->id = id;
	this->departure = departure;
	this->arrival = arrival;
	this->name = name;
	time = 0;
	date = 0;
	seat_number = 0;
}

Ticket_airport::Ticket_airport(string id, int departure, int arrival, int date, int time, int seat_number)
{
	this->id = id;
	this->departure = departure;
	this->arrival = arrival;
	this->date = date;
	this->time = time;
	this->seat_number = seat_number;
}

void Ticket_airport::set_route(int departure, int arrival) {
	this->departure = departure;
	this->arrival = arrival;
}
void Ticket_airport::set_time(int time) {
	this->time = time;
}
void Ticket_airport::set_seat_number(int seat_number) {
	this->seat_number = seat_number;
}
void Ticket_airport::showTicket() {
	string airport_list[5] = { "인천","김포","제주","김해","대구" };
	string string_time;

	switch (time) {
	case 1:
		string_time = "07시";
		break;
	case 2:
		string_time = "12시";
		break;
	case 3:
		string_time = "17시";
		break;
	case 0:
		string_time = "";
		break;
	}

	cout << " --------------------------------" << endl;
	cout << "| 5월 " << this->date << "일 " << string_time << "    ";
	cout << "[" << airport_list[departure - 1] << "->" << airport_list[arrival - 1] << "]   |" << endl;
	cout << "|                                |" << endl;
	if (seat_number < 3) {
		cout << "| 비즈니스 클래스  " << seat_number << "번 좌석      |" << endl;
	}
	else {
		cout <<"| 이코노미 클래스  " << seat_number << "번 좌석      |" << endl;
	}
	cout << " --------------------------------" << endl;
	
}

int Ticket_airport::get_departure() {
	return departure;
}
int Ticket_airport::get_arrival() {
	return arrival;
}
int Ticket_airport::get_time() {
	return time;
}
int Ticket_airport::get_seat_number() {
	return seat_number;
}
