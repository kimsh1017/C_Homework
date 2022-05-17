#include "StudyRoom_Date.h"
#include <iostream>
using namespace std;

StudyRoom_Date::StudyRoom_Date() {
	schedules = new Schedule_StudyRoom[14];
}
StudyRoom_Date::~StudyRoom_Date() {
	delete[]schedules;
}

void StudyRoom_Date::appointment(UserData* User, Ticket_apart* appointment_data) {
	int time;
	int total_time = User->getTotalTime(appointment_data->get_date());

	if ( total_time >= 4) {
		cout << "하루 최대 예약 시간은 4시간 입니다" << endl;
	}
	else {
		time = Console_apart::set_time(total_time); // 시간 중복 예외처리
		if (time != 0) {
			appointment_data->set_time(time);
			schedules[time - 9].appointment(User, appointment_data);
		}
	}
}
void StudyRoom_Date::cancel(Ticket* cancel_data) {
	int time;
	time = cancel_data->get_time();
	schedules[time - 9].cancel(cancel_data);
}
int StudyRoom_Date::check_seat(int seat_number) {
	int result = 0;
	for (int i = 0; i < 14; i++) {
		if (schedules[i].checkAppointed(seat_number) == false) result++;
	}
	return result;
}

int StudyRoom_Date::check_gender(string gender) {
	int result = 0;
	for (int i = 0; i < 14; i++) {
		result += schedules[i].checkGender(gender);
	}
	return result;
}