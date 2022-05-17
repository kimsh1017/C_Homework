#include "Schedule_StudyRoom.h"
#include <iostream>
using namespace std;

#include "Seat_StudyRoom.h"

Schedule_StudyRoom::Schedule_StudyRoom() {
	seats = new Seat_StudyRoom * [15];
	for (int i = 0; i < 15; i++) {
		seats[i] = new Seat_StudyRoom[15];
	}
}
Schedule_StudyRoom::~Schedule_StudyRoom() {
	for (int i = 0; i < 15; i++) {
		delete[]seats[i];
	}
	delete[]seats;
}

void Schedule_StudyRoom::appointment(UserData* User, Ticket_apart* appointment_data) {
	string gender;
	string name;
	int age = 0;
	int seat_number = 0;

	age = Console_apart::set_age();
	if (age <= 13) {
		cout << endl;
		cout << "13세 이하는 예약이 불가능합니다" << endl;
	}
	else {
		gender = Console_apart::set_gender();
		name = Console_apart::set_name();

		showSeats(gender); // 좌석 보여주기
		seat_number = Console_apart::set_seat_number();

		if (seat_number != 0) {
			if (checkSeat(seat_number, gender) == false) {
				cout << "예약이 불가능한 좌석입니다" << endl;
			}
			else {
				appointment_data->set_name(name);
				appointment_data->set_gender(gender);
				appointment_data->set_seat_number(seat_number);

				if (seat_number % 15 == 0) {
					seats[seat_number / 15 - 1][14].appointment(User, appointment_data);
				}
				else {
					seats[seat_number / 15][seat_number % 15 - 1].appointment(User, appointment_data);
				}
			}
		}
	}
}

void Schedule_StudyRoom::showSeats(string gender) { // sector 나누기? 1~9
	int n = 1;
	int nn = 1;
	for (int i = 0; i < 15; i++) {
		cout << "──────┬";
	}
	cout << endl;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			cout << left << " " << setw(3) << n;
			if (checkSeat(n, gender)) {
				cout << "□│";
			}
			else {
				cout << "■│";
			}
			n++;
		}
		cout << endl;
		for (int j = 0; j < 15; j++) {
			cout << "──────┤";
		}
		cout << endl;
	}
}

bool Schedule_StudyRoom::checkSeat(int seat_number, string gender) {
	int row, column;
	if (seat_number % 15 == 0) {
		row = seat_number / 15 - 1;
		column = 14;
	}
	else {
		row = seat_number / 15;
		column = seat_number % 15 - 1;
	}

	if (seats[row][column].checkSeat() == false) {
		return false;
	}
	else { // 인덱스 예외처리
		if (row != 0 && seats[row - 1][column].get_gender() == gender) return false;
		if (row != 14 && seats[row + 1][column].get_gender() == gender) return false;
		if (column != 0 && seats[row][column-1].get_gender() == gender) return false;
		if (column != 14 && seats[row][column+1].get_gender() == gender) return false;
		return true;
	}
}

void Schedule_StudyRoom::cancel(Ticket* cancel_data) {
	int seat_number;
	seat_number = cancel_data->get_seat_number();

	if (seat_number % 15 == 0) {
		seats[seat_number / 15 - 1][14].cancel();
	}
	else {
		seats[seat_number / 15][seat_number % 15 - 1].cancel();
	}
}

bool Schedule_StudyRoom::checkAppointed(int seat_number) {
	if (seat_number % 15 == 0) {
		return seats[seat_number / 15 - 1][14].checkSeat();
	}
	else {
		return seats[seat_number / 15][seat_number % 15 - 1].checkSeat();
	}
}
int Schedule_StudyRoom::checkGender(string gender) {
	int result = 0;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (seats[i][j].get_gender() == gender) result++;
		}
	}
	return result;
}