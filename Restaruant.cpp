#include "Restaurant.h"

Restaurant::Restaurant() {
	this->User = NULL;
	schedules = new Schedule_restaurant[7];

	set_date(); // 스케줄에 요일 날짜 설정
	walkInServer = new Walk_in;

	setReservationData();
}
Restaurant::~Restaurant() {
	fstream fout("ReservationRestaurant.txt", ios::out);
	if (!fout) {
		cout << "파일 열기 오류" << endl;
		Sleep(500);
	}
	else {
		for (int i = 0; i < reservationData.size(); i++) {
			fout << "***\n";
			fout << reservationData[i].get_id() << '/';
			fout << reservationData[i].get_date() << '/';
			fout << reservationData[i].get_table_number() << '/';
			fout << reservationData[i].get_people() << '\n';
		}
	}
	fout.close();
	delete[]schedules;
	delete walkInServer;
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

void Restaurant::setReservationData() { // 파일에서 예약 불러오기
	fstream fin("ReservationRestaurant.txt", ios::in);
	string id, temp;
	int date, people, table_number;

	if (!fin) {
		cout << "파일 열기 오류" << endl;
		Sleep(500);
	}
	else {
		while (getline(fin, temp)) {
			if (temp == "***") {
				getline(fin, temp, '/');
				id = temp;

				getline(fin, temp, '/');
				date = stoi(temp);

				getline(fin, temp, '/');
				table_number = stoi(temp);

				getline(fin, temp);
				people = stoi(temp);

				reservationData.push_back(Ticket_restaurant(id, date,table_number,people));
			}
		}
		for (int i = 0; i < reservationData.size(); i++) {
			cout << reservationData[i].get_id() << endl;
			int date = reservationData[i].get_date();
			schedules[date-1].appointment(&reservationData[i]);
		}
	}

	fin.close();
}

void Restaurant::appointment() {
	int date = Console_restaurant::set_date();
	reservationData.push_back(Ticket_restaurant());
	if (date != 0) {
		reservationData.back().set_id(User->get_id());
		reservationData.back().set_date(date);
		schedules[date - 1].appointment(&reservationData.back());
	}
}

void Restaurant::walk_in() {
	walkInServer->running(User);
}

void Restaurant::runServer(newUserData* User) {
	int menu = 0;
	this->User = User; 

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
				if (reservationData.back().get_table_number() != 0) {
					cout << "예약되었습니다" << endl;
					Console_restaurant::clean(1000);
					menu = 5;
				}
				else {
					reservationData.erase(reservationData.end() - 1);
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
	int ticket_number;
	int count = 1;

	for (int i = 0; i < reservationData.size(); i++) {
		if (reservationData[i].get_id() == User->get_id()) {
			cout << count << "번 예약" << endl;
			reservationData[i].showTicket();
			count++;
		}
	}	
	ticket_number = Console_restaurant::set_ticket_number(count-1);//?? count-1?
	count = 0;
	// 받은 정보로 테이블 객체 접근해 취소하기
	if (ticket_number != 0) {
		for (int i = 0; i < reservationData.size(); i++) {
			if (reservationData[i].get_id() == User->get_id()) {
				count++;
				if (count == ticket_number) {
					schedules[reservationData[i].get_date() - 1].cancel(&reservationData[i]);
					reservationData.erase(reservationData.begin() + i);
					cout << "취소되었습니다" << endl;
					Sleep(1000);
					break;
				}
			}
		}
	}
}

void Restaurant::showStat() { // walkin??
	int stat_menu = 0;
	int table_stat[6] = {0,};

	stat_menu = Console_restaurant::set_stat_menu();

	if (stat_menu == 1) { // 고객의 지금까지의 예약 횟수 보여주기
		Console_restaurant::clean(0);
		
		for (int i = 0; i < reservationData.size(); i++) {
			if (reservationData[i].get_id() == User->get_id()) {
				reservationData[i].showTicket();
			}
		}
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
