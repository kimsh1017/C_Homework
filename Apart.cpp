#include "Apart.h"


Apart::Apart() {
	studyRoom_Date = new StudyRoom_Date[7];
	User = NULL;

	setReservationData();
}
Apart::~Apart() {
	fstream fout("ReservationApart.txt", ios::out);
	if (!fout) {
		cout << "파일 열기 오류" << endl;
		Sleep(500);
	}
	else {
		for (int i = 0; i < reservationData.size(); i++) {
			fout << "***\n";
			fout << reservationData[i].get_id() << '/';
			fout << reservationData[i].get_name() << '/';
			fout << reservationData[i].get_date() << '/';
			fout << reservationData[i].get_time() << '/';
			fout << reservationData[i].get_seat_number() << '/';
			fout << reservationData[i].get_gender() << '\n';
		}
	}
	fout.close();
	delete[]studyRoom_Date;
}
void Apart::setReservationData() {
	fstream fin("ReservationApart.txt", ios::in);
	string temp,id,name,gender;
	int date, time, seat_number;

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
				name = temp;

				getline(fin, temp, '/');
				date = stoi(temp);

				getline(fin, temp, '/');
				time = stoi(temp);

				getline(fin, temp, '/');
				seat_number = stoi(temp);

				getline(fin, temp);
				gender = temp;

				reservationData.push_back(Ticket_apart(id, name, date, time, seat_number, gender));
			}
		}
		for (int i = 0; i < reservationData.size(); i++) {
			int date = reservationData[i].get_date();
			studyRoom_Date[date - 1].appointment(&reservationData[i]);
		}
	}
	fin.close();
}

void Apart::runserver(newUserData* User) {
	this->User = User;
	int menu = 0;

	while (menu != 4) { // menu 5 = 로그아웃
		menu = Console_apart::set_menu();

		switch (menu) {
		case 1:
			appointment();
			if (reservationData.back().get_seat_number() != 0){
				cout << "예약되었습니다" << endl;
				Sleep(1000);
				menu = 4;
			}
			else {
				reservationData.erase(reservationData.end() - 1);
			}
			break;
		case 2:
			cancel();
			break;
		case 3:
			showStat();
			break;
		}
	}
}

void Apart::appointment() {
	int date = 0;
	date = Console_apart::set_date();
	reservationData.push_back(Ticket_apart());

	if (date != 0) {
		reservationData.back().set_id(User->get_id());
		reservationData.back().set_date(date);
		studyRoom_Date[date - 1].appointment(&reservationData.back());
	}
}
void Apart::cancel() {
	int ticket_number = 0;
	int date;
	int count = 1;

	cout << endl;
	for (int i = 0; i < reservationData.size(); i++) {
		if (reservationData[i].get_id() == User->get_id()) {
			cout << count << "번 예약" << endl;
			reservationData[i].showTicket();
			count++;
		}
	}
	ticket_number = Console_apart::set_ticket_number(reservationData.size());
	count = 0;
	
	if (ticket_number != 0) {
		for (int i = 0; i < reservationData.size(); i++) {
			if (reservationData[i].get_id() == User->get_id()) {
				count++;
				if (count == ticket_number) {
					date = reservationData[i].get_date();
					studyRoom_Date[date - 1].cancel(&reservationData[i]);
					reservationData.erase(reservationData.begin() + i);
					cout << "취소되었습니다" << endl;
					Sleep(1000);
				}
			}
		}
	}
}

void Apart::showStat() {
	int menu = 0;
	int seat_number = 0;
	int result = 0;

	menu = Console_apart::set_stat_menu();

	if (menu == 1) {
		for (int i = 0; i < reservationData.size(); i++) {
			if (reservationData[i].get_id() == User->get_id()) {
				reservationData[i].showTicket();
			}
		}

		while (menu != 0) {
			cout << "돌아가기 : 0 >>";
			cin >> menu;
		}
	}
	else if (menu == 2) {
		cout << endl;
		menu = Console_apart::set_stat_detail();

		if (menu == 1) {
			seat_number = Console_apart::set_seat_stat_number();
			if (seat_number != 0) {
				for (int i = 0; i < 7; i++) {
					result += studyRoom_Date[i].check_seat(seat_number);
				}
				Console_apart::clean(0);
				cout << endl;
				cout << seat_number << "번 좌석은 총" << result << "번 예약됐습니다" << endl;
				cout << endl;
			}
		}
		else if (menu == 2) {
			for (int i = 0; i < 7; i++) {
				result += studyRoom_Date[i].check_gender("남");
			}

			Console_apart::clean(0);
			cout << endl;
			cout << "총 예약수 " << endl;
			cout << "남 : " << result << "   ";

			result = 0;
			for (int i = 0; i < 7; i++) {
				result += studyRoom_Date[i].check_gender("여");
			}
			cout << "여 : " << result << endl;
			cout << endl;
		}

		while (menu != 0) {
			cout << "돌아가기 : 0 >>";
			cin >> menu;
		}
	}
}

