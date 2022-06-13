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
	string airport_list[5] = { "��õ","����","����","����","�뱸" };
	string string_time;

	switch (time) {
	case 1:
		string_time = "07��";
		break;
	case 2:
		string_time = "12��";
		break;
	case 3:
		string_time = "17��";
		break;
	case 0:
		string_time = "";
		break;
	}

	cout << " --------------------------------" << endl;
	cout << "| 5�� " << this->date << "�� " << string_time << "    ";
	cout << "[" << airport_list[departure - 1] << "->" << airport_list[arrival - 1] << "]   |" << endl;
	cout << "|                                |" << endl;
	if (seat_number < 3) {
		cout << "| ����Ͻ� Ŭ����  " << seat_number << "�� �¼�      |" << endl;
	}
	else {
		cout <<"| ���ڳ�� Ŭ����  " << seat_number << "�� �¼�      |" << endl;
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
