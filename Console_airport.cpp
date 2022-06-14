#include "Console_airport.h"

void Console_airport::clean(int delay) {
	Sleep(delay);
	system("cls");
}
int Console_airport::set_menu(string name) {
	int menu = 0;

	while (menu == 0) {
		clean(0);
		cout << endl;
		cout << "비행기 예매 시스템에 오신걸 환영합니다" << endl;
		cout << name<< "님 환영합니다" << endl;

		cout << endl;
		cout << "1: 예약 / 2: 예약 취소 / 3: 통계 / 4: 로그아웃 >>";
		cin >> menu;

		if (menu > 4 || menu < 1) { //예외처리
			menu = 0;
			cout << "잘못된 입력입니다" << endl;
		}
	}
	return menu;
}

int  Console_airport::set_date(Ticket_airport* appointment_data) {
	int date = -1;

	while (date == -1) {
		clean(0);
		cout << endl;
		printDataNow(appointment_data);
		cout << "날짜를 선택해주세요" << endl;
		cout << "*****5월****************************" << endl;
		cout << "____________________________________" << endl;
		cout << "| 일 | 월 | 화 | 수 | 목 | 금 | 토 |" << endl;
		cout << "------------------------------------" << endl;
		cout << "| 1  | 2  | 3  | 4  | 5  | 6  | 7  |" << endl;
		cout << "------------------------------------" << endl;
		cout << "5월 _일 (돌아가기 : 0) >>";
		cin >> date;

		if (date > 7 || date < 0) { //예외처리
			date = -1;
			cout << "잘못된 입력입니다" << endl;
			Sleep(500);
			system("cls");
		}
	}
	return date;
}

int Console_airport::set_departure() {
	int place = -1;
	
	while (place == -1) {
		string airport_list[5] = { "인천","김포","제주","김해","대구" };
		cout << endl;
		cout << "출발지와 도착지를 선택해주세요" << endl;
		for (int i = 0; i < 5; i++) {
			cout << i + 1 << " : " << airport_list[i] << "공항" << endl;
		}
		cout << "(돌아가기 : 0)" << endl;
		cout << "출발지>>";
		cin >> place;

		if (place > 5 || place < 0) {
			cout << "잘못된 입력입니다" << endl;
			place = 0;
		}
	}
	return place;
}

int Console_airport::set_arrival() {
	int place = -1;

	while (place == -1) {
		cout << "도착지>>";
		cin >> place;

		if (place > 5 || place < 0) {
			cout << "잘못된 입력입니다" << endl;
			place = -1;
		}
	}
	return place;
}

int Console_airport::set_time(Ticket_airport* appointment_data) {
	int time = -1;

	while (time == -1) {
		clean(0);
		printDataNow(appointment_data);
		cout << "시간대를 입력해주세요" << endl;
		cout << "1: 07시 / 2: 12시 / 3: 17시 /(0: 돌아가기)>>";
		cin >> time;

		if (time > 3 || time < 0) {
			cout << "잘못된 입력입니다" << endl;
			Sleep(500);
			time = -1;
		}
	}
	return time;
}

int Console_airport::set_seat_number() {
	int seat_number = -1;
	while (seat_number == -1) {
		cout << endl;
		cout << "예약을 원하는 자리를 입력해주세요 (돌아가기 : 0)>>";
		cin >> seat_number;

		if (seat_number > 8 || seat_number < 0) {
			cout << "잘못된 입력입니다" << endl;
			seat_number = -1;
		}
	}
	return seat_number;
}

bool Console_airport::check_round_trip() {
	int temp = 0;
	cout << endl;

	while (temp == 0) {
		cout << "1: 왕복 / 2: 편도 >>";
		cin >> temp;

		if (temp > 2 || temp < 0) {
			temp = 0;
		}
	}
	clean(0);
	temp == 1 ? cout << "왕복 예약" << endl : cout << "편도 예약" << endl;
	return temp==1 ? true : false;
}

int Console_airport::set_ticket_number(int max) {
	int ticket_number = -1;
	while (ticket_number == -1) {
		cout << "취소하고 싶은 예약 번호를 입력하세요 (돌아가기 : 0 )>>";
		cin >> ticket_number;

		if (ticket_number < 0 || ticket_number > max) {
			cout << "잘못된 입력입니다" << endl;
			ticket_number = -1;
		}
	}
	return ticket_number;
}

float Console_airport::set_cost() {
	int menu = 0;
	float cost = 0;

	while (menu == 0) {
		cout << endl;
		cout << "1. 가격 상한선 설정하기 / 2. 모든 좌석 보기 >>";
		cin >> menu;
		if (menu > 2 || menu < 0) {
			menu = 0;
			cout << "잘못된 입력입니다" << endl;
		}
	}
	
	if (menu == 2) {
		cost = 11;
	}
	while (cost == 0) {
		cout << " 가격 : __만 원 이하 >>";
		cin >> cost;

		if (cost < 0) {
			cout << "잘못된 입력입니다" << endl;
		}
	}
	return cost;
}

int Console_airport::set_stat_menu() {
	int stat_menu = 0;
	while (stat_menu == 0) {
		clean(0);
		cout << endl;
		cout << "1 : 내 예약 현황 보기 / 2 : 좌석별 예약 현황 보기 >>";
		cin >> stat_menu;

		if (stat_menu > 2 || stat_menu < 1) {
			stat_menu = 0;
			cout << "잘못된 입력입니다" << endl;
			Sleep(500);
		}
	}
	return stat_menu;
}

void Console_airport::printDataNow(Ticket_airport* appointment_data) {
	int departure,arrival,date, time;
	string string_time;
	string airport_list[5] = { "인천","김포","제주","김해","대구" };

	departure = appointment_data->get_departure();
	arrival = appointment_data->get_arrival();
	date = appointment_data->get_date();
	time = appointment_data->get_time();


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
	}

	clean(0);

	if (date == 0) {
		cout << endl;
		cout << "[" << airport_list[departure - 1] << "->" << airport_list[arrival - 1] << "행 비행기 ]" << endl;
	}
	else if (time == 0) {
		cout << endl;
		cout << "5월 " << date << "일 " << endl;
		cout << "[" << airport_list[departure - 1] << "->" << airport_list[arrival - 1] << "행 비행기 ]" << endl;
	}
	else {
		cout << endl;
		cout << "5월 " << date << "일 " << string_time << endl;
		cout << "[" << airport_list[departure - 1] << "->" << airport_list[arrival - 1] << "행 비행기 ]" << endl;
	}
	cout <<  endl;
}