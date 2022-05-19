#include "Restaurant.h"

Restaurant::Restaurant() {
	this->User = NULL;
	schedules = new Schedule_restaurant[7];

	set_date(); // 스케줄에 요일 날짜 설정
	walkInServer = new Walk_in;
}
Restaurant::~Restaurant() {
	delete[]schedules;
}

void Restaurant::set_date() { // 요일 날짜 설정
	schedules[0].setDate("5월 1일 일요일");
	schedules[1].setDate("5월 2일 월요일");
	schedules[2].setDate("5월 3일 화요일");
	schedules[3].setDate("5월 4일 수요일");
	schedules[4].setDate("5월 5일 목요일");
	schedules[5].setDate("5월 6일 금요일");
	schedules[6].setDate("5월 7일 토요일");
}

void Restaurant::appointment() {
	int date = Console_restaurant::set_date();

	if (date != 0) {
		appointment_data = new Ticket_restaurant;
		appointment_data->set_date(date);
		schedules[date - 1].appointment(User, appointment_data);
	}
}

void Restaurant::walk_in() {
	walkInServer->running(User);
}

void Restaurant::runServer(UserData* User) {
	int menu = 0;
	this->User = User;
	int check_appointed = User->get_tickets_size(); // 현재까지 예약 수

	while (menu != 5) {  //menu 5 = 로그아웃
		menu = Console_restaurant::set_menu(User->get_name());
		switch (menu) {
		case 1:
			if (User->get_age() <= 7) {
				cout << "7세 이하 미취학 아동은 예약이 불가능합니다." << endl;
				Sleep(1000);
			}
			else {
				appointment();
				if (User->get_tickets_size() != check_appointed) {
					menu = 5;
				}
			}
			break;
		case 2:
			cancel();
			break;
		case 3: 
			walk_in();
			break;
		case 4:
			showStat();
			break;
		}
	}
}

void Restaurant::cancel() {
	Ticket* ticket = NULL;
	int ticket_number;

	// User 에서 테이블 정보 받아오기
	User->showTickets();
	ticket_number = Console_restaurant::set_ticket_number(User->get_tickets_size());
	ticket = User->getTicket(ticket_number);

	// 받은 정보로 테이블 객체 접근해 취소하기
	if (ticket != NULL) {
		schedules[ticket->get_date() - 1].cancel(ticket->get_table_number());
		User->cancel(ticket_number);
	}
}

void Restaurant::showStat() {
	int stat_menu = 0;
	int table_stat[6] = {0,};

	stat_menu = Console_restaurant::set_stat_menu();

	if (stat_menu == 1) { // 고객의 지금까지의 예약 횟수 보여주기
		Console_restaurant::clean(0);
		User->showTickets();
		while (stat_menu != 0) {
			cout << "돌아가기 : 0 >>";
			cin >> stat_menu;
		}

	}
	else if (stat_menu == 2) { // 테이블별 예약된 횟수 보여주기
		Console_restaurant::clean(0);
		cout << endl;
		cout << "[ 5월 1일 ~ 7일 식당 예약 현황 ]" << endl;
		cout << endl;
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 6; j++) {
				if (schedules[i].checkTable(j+1)) {
					table_stat[j]++;
				}
			}
		}

		for (int i = 0; i < 6; i++) {
			cout << i+1 << "번 테이블 예약 횟수 : " << table_stat[i] << endl;
		}
		cout << endl;
		while (stat_menu != 0) {
			cout << "돌아가기 : 0 >>";
			cin >> stat_menu;
		}
	}
}
