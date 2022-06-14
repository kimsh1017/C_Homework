#include "StudyRoom_Date.h"

StudyRoom_Date::StudyRoom_Date() {
	schedules = new Schedule_StudyRoom[14];
}
StudyRoom_Date::~StudyRoom_Date() {
	delete[]schedules;
}

void StudyRoom_Date::appointment(Ticket_apart* reservation) {
	int time;
	if (reservation->get_seat_number() != 0) {
		time = reservation->get_time();
		schedules[time - 9].appointment(reservation);
	}
	else {
		time = set_time(reservation);

		if (time != 0) {
			reservation->set_time(time);
			schedules[time - 9].appointment(reservation);
		}
	}
}

void StudyRoom_Date::cancel(Ticket_apart* cancel_data) {
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

int StudyRoom_Date::set_time(Ticket_apart* reservation) {
	int time = -1;
	int totalTime = 0;

	for (int i = 0; i < 14; i++) {
		if (schedules[i].checkId(reservation->get_id())) {
			totalTime++;
		}
	}

	if (totalTime >= 4) {
		Console_apart::clean(0);
		cout << endl;

		cout << "5월 " << reservation->get_date() << "일 ]" << endl;
		cout << "이미 4시간 예약이 완료됐습니다" << endl;
		Sleep(1000);
		time = 0;
	}
	else {
		while (time == -1) {
			Console_apart::clean(0);
			cout << endl;

			cout << "예약하실 시간을 입력해주세요." << endl;
			cout << "영업시간: 09시 ~ 23시 , 세대당 하루 최대 4시간 예약 가능합니다" << endl;
			cout << endl;
			cout << "[ 5월 " << reservation->get_date() << "일]" << endl;
			cout << "현재 " << totalTime << "시간 예약중" << endl;
			cout << "한 번에 1시간씩 예약 가능합니다" << endl;
			cout << endl;

			cout << "입실 시간 (돌아가기 : 0)>>";
			cin >> time;

			if (time != 0) {
				if (time < 9 || time> 22) {
					cout << "잘못된 입력입니다. 영업시간: 09시 ~23시" << endl;
					time = -1;
					Sleep(500);
				}
				else if (schedules[time - 9].checkId(reservation->get_id())) {
					cout << "이 시간에 이미 예약한 좌석이 있습니다" << endl;
					time = -1;
					Sleep(500);
				}
			}
		}
	}
	return time;
}