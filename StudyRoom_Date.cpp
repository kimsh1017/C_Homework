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
		time = Console_apart::set_time(total_time);
		if (time != 0) {
			appointment_data->set_time(time);
			schedules[time - 9].appointment(User, appointment_data);
		}
	}
}