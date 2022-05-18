#include "StudyRoom_Date.h"

StudyRoom_Date::StudyRoom_Date() {
	schedules = new Schedule_StudyRoom[14];
}
StudyRoom_Date::~StudyRoom_Date() {
	delete[]schedules;
}

void StudyRoom_Date::appointment(UserData* User, Ticket_apart* appointment_data) {
	int time;
	int total_time = User->getTotalTime(appointment_data->get_date());
	Ticket* data;

	if ( total_time >= 4) {
		cout << "�Ϸ� �ִ� ���� �ð��� 4�ð� �Դϴ�" << endl;
	}
	else {
		time = Console_apart::set_time(total_time); 

		for (int i = 0; i < User->get_tickets_size(); i++) {// �ð� �ߺ� ����ó��
			data = User->getTicket(i + 1);
			if (appointment_data->get_date() == data->get_date() &&
				time == data->get_time()) {
				cout << "�� �ð��� �̹� ������ �¼��� �ֽ��ϴ�" << endl;
				time = 0;
				break;
			}
		}
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