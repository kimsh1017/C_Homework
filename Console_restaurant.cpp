#include "Console_restaurant.h"

int Console_restaurant::set_menu(string name) {
	int menu = 0;

	while (menu == 0) {
		clean(0);
		cout << endl;
		cout << "식당 예매 프로그램에 오신걸 환영합니다" << endl;
		cout << name << "님 환영합니다" << endl;

		cout << endl;
		cout << "1: 예약 / 2: 예약 취소 / 3: 식당 방문 / 4: 통계 / 5: 로그아웃 >>";
		cin >> menu;

		if (menu > 5 || menu < 1) { //예외처리
			menu = 0;
			cout << "잘못된 입력입니다" << endl;
		}
	}
	return menu;
}

int  Console_restaurant::set_date() {
	int date = -1;

	while (date == -1) {
		clean(0);
		cout << endl;
		cout << "날짜를 선택해주세요" << endl;
		cout << "*****5월****************************" << endl;
		cout << "____________________________________" << endl;
		cout << "| 일 | 월 | 화 | 수 | 목 | 금 | 토 |" << endl;
		cout << "------------------------------------" << endl;
		cout << "| 1  | 2  | 3  | 4  | 5  | 6  | 7  |" << endl;
		cout << "------------------------------------" << endl;
		cout << "5월 _일 (돌아가기 : 0)>>";
		cin >> date;

		if (date > 7 || date < 0) { //예외처리
			date = -1;
			cout << "잘못된 입력입니다" << endl;
			Sleep(500);
		}
	}
	return date;
}


int Console_restaurant::set_people(Ticket* appointment_data) {
	int people = -1;
	while (people == -1) {
		clean(0);
		cout << endl;
		cout << "[5월 " << appointment_data->get_date() << "일]" << endl;
		cout << "방문 인원 (돌아가기 : 0)>>";
		cin >> people;
		if (people < 0) {
			cout << "잘못된 입력입니다" << endl;
			people = -1;
			Sleep(500);
		}
		else if (people > 6) {
			cout << "죄송합니다. 저희 가게는 6인 이상 테이블이 존재하지 않습니다" << endl;
			people = -1;
			Sleep(500);
		}
	}
	return people;
}

int Console_restaurant::set_table(Ticket* appointment_data) {
	int table = -1;

	while (table == -1) {
		cout << endl;
		cout << "[5월 " << appointment_data->get_date() << "일]" << endl;
		cout << "\'불가\'라고 쓰인 좌석은 예약할 수 없습니다" << endl;
		cout << "예약하실 좌석의 번호를 입력해주세요 >>";
		cin >> table;

		if (table > 6 || table < 0) {
			table = -1;
			cout << "잘못된 입력입니다" << endl;
		}
	}
	return table;
}

int Console_restaurant::set_ticket_number(int max) {
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

int Console_restaurant::set_stat_menu() {
	int menu = -1;
	while (menu == -1) {
		clean(0);
		cout << endl;
		cout << "1 : 내 예약 현황 보기 / 2 : 테이블별 예약 횟수 보기 (돌아가기 : 0)>>";
		cin >> menu;

		if (menu > 2 || menu < 0) {
			menu = -1;
			cout << "잘못된 입력입니다" << endl;
			Sleep(500);
		}
	}
	return menu;
}

int Console_restaurant::set_walk_in_people() {
	int people = -1;
	while (people == -1) {
		cout << "방문 인원 (돌아가기 : 0)>>";
		cin >> people;
		if (people < 0) {
			cout << "잘못된 입력입니다" << endl;
			people = -1;
			Sleep(500);
		}
		else if (people > 4) {
			cout << "죄송합니다. 5인 이상은 예약 손님만 가능합니다." << endl;
			people = 0;
			Sleep(500);
		}
	}
	return people;
}

void Console_restaurant::clean(int delay) {
	Sleep(delay);
	system("cls");
}

