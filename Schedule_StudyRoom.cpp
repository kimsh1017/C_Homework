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
	int seat_number = 0;

	gender = Console_apart::set_gender();
	name = Console_apart::set_name();

	showSeats(gender);
	seat_number = Console_apart::set_seat_number(); // 여기 이후로 수정

	if (seat_number != 0) {
		if (seat_number % 15 == 0) {
			if (seats[seat_number / 15 - 1][14].checkSeat()) {
				appointment_data->set_name(name);
				appointment_data->set_gender(gender);
				appointment_data->set_seat_number(seat_number);
				seats[seat_number / 15 - 1][14].appointment(User,appointment_data);
			}
			else {
				cout << "예약이 불가능한 좌석입니다" << endl;
			}
		}
		else {
			if (seats[seat_number / 15][seat_number%15 -1].checkSeat()) {
				appointment_data->set_name(name);
				appointment_data->set_gender(gender);
				appointment_data->set_seat_number(seat_number);
				seats[seat_number / 15][seat_number%15 -1].appointment(User,appointment_data);
			}
			else {
				cout << "예약이 불가능한 좌석입니다" << endl;
			}
		}
	}
}

void Schedule_StudyRoom::showSeats(string gender) {
	int n = 1;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			cout << n << " |";
			n++;
		}
		cout << endl;
		n = 1;
		for (int j = 0; j < 15; j++) {
			if (checkSeat(n,gender)) {
				cout << "가능|";
			}
			else {
				cout << "불가|";
			}
			n++;
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
		cout << "이미 예약된 좌석입니다" << endl;
		return false;
	}
	else { // 인덱스 예외처리
		if (row == 0) {
			if (column == 0) {
				if (seats[row + 1][column].get_gender() == gender) return false;
				if (seats[row][column + 1].get_gender() == gender) return false;
			}
			else if (column == 14) {
				if (seats[row + 1][column].get_gender() == gender) return false;
				if (seats[row][column - 1].get_gender() == gender) return false;
			}
			else {
				if (seats[row + 1][column].get_gender() == gender) return false;
				if (seats[row][column + 1].get_gender() == gender) return false;
				if (seats[row][column - 1].get_gender() == gender) return false;
			}
		}
		if (row == 14) {
			if (column == 0) {
				if (seats[row - 1][column].get_gender() == gender) return false;
				if (seats[row][column + 1].get_gender() == gender) return false;
			}
			else if (column == 14) {
				if (seats[row - 1][column].get_gender() == gender) return false;
				if (seats[row][column - 1].get_gender() == gender) return false;
			}
			else {
				if (seats[row - 1][column].get_gender() == gender) return false;
				if (seats[row][column + 1].get_gender() == gender) return false;
				if (seats[row][column - 1].get_gender() == gender) return false;
			}
		}
		else {
			if (column == 0) {
				if (seats[row - 1][column].get_gender() == gender) return false;
				if (seats[row + 1][column].get_gender() == gender) return false;
				if (seats[row][column + 1].get_gender() == gender) return false;
			}
			if (column == 14) {
				if (seats[row - 1][column].get_gender() == gender) return false;
				if (seats[row + 1][column].get_gender() == gender) return false;
				if (seats[row][column - 1].get_gender() == gender) return false;
			}
			else {
				if (seats[row - 1][column].get_gender() == gender) return false;
				if (seats[row + 1][column].get_gender() == gender) return false;
				if (seats[row][column - 1].get_gender() == gender) return false;
				if (seats[row][column + 1].get_gender() == gender) return false;
			}
		}
		return true;
	}
}