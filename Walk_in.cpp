#include "Walk_in.h"

Walk_in::Walk_in() {
	table = new Table[2];
	table[0].set_seat_number(4);
	table[1].set_seat_number(4);
	User = NULL;
}
Walk_in::~Walk_in() {
	delete []table;
}

void Walk_in::running(UserData* User) {
	this->User = User;
	int people = 0;
	int menu = 0;
	Console_restaurant::clean(0);
	cout << endl;

	if (checkTableUser()) { // 이미 식사중
		cout << "지금 식사중입니다" << endl;
		cout << "식사를 종료하시겠습니까? (1:예 / 2: 아니오)>>";
		cin >> menu;

		if (menu == 1) {
			if (table[0].get_id() == User->get_id()) {
				table[0].cancel();
			}
			else {
				table[1].cancel();
			}
		}
	}
	else if (checkListUser()) { //waitingList에 있을 때
		if (waitingList[0] == User->get_id() && checkTableEmpty()) {
			cout << "자리가 생겼습니다" << endl;
			cout << "테이블 청소중.." << endl;
			Sleep(1000);
			showTable();
			seatTable();
			waitingList.pop_front();
		}
		else {
			for (int i = 0; i < waitingList.size(); i++) {
				if (waitingList[i] == User->get_id()) {
					cout << User->get_name() << "님 현재 대기 순번은 " << i + 1 << "번 입니다" << endl;
					Sleep(1000);
				}
			}
		}
	}
	else { // waiting_list에도 없을 때
		people = Console_restaurant::set_walk_in_people();
		cout << endl;

		if (people != 0) {
			if (waitingList.size() != 0) { // 줄 있을때
				cout << "현재 " << waitingList.size() << "팀이 대기중입니다" << endl;
				cout << "대기하시겠습니까? (1:예 / 2: 아니오)>>";
				cin >> menu;

				if (menu == 1) {
					waitingList.push_back(User->get_id());
				}
			}
			else { // 줄 없을때
				if (checkTableEmpty()) {
					showTable();
					seatTable();
				}
				else {
					cout << "현재 가능한 테이블을 모두 사용중입니다" << endl;
					cout << "대기하시겠습니까? (1:예 / 2: 아니오)>>";
					cin >> menu;

					if (menu == 1) {
						waitingList.push_back(User->get_id());
					}
				}
			}
		}
	}
}

bool Walk_in::checkTableUser() {
	for (int i = 0; i < 2; i++) {
		if (User->get_id() == table[i].get_id()) {
			cout << "현재 " << i + 1 << "번 테이블에서 식사중입니다." << endl;
			return true;
		}
	}
	return false;
}

bool Walk_in::checkListUser() {
	for (int i = 0; i < waitingList.size(); i++) {
		if (waitingList[i] == User->get_id()) {
			return true;
		}
	}
	return false;
}

void Walk_in::showTable() {
	Console_restaurant::clean(0);
	cout << endl;
	cout << "   o  o " << "   " << "   o  o" << endl;
	cout << "┌──────┐" << "   " << "┌───────┐" << endl;
	cout << "│1 " << table[0].get_appointed(0) << "│" << "   " << "│ 2 " << table[1].get_appointed(0) << "│" << endl;
	cout << "└──────┘" << "   " << "└───────┘" << endl;
	cout << "   o  o " << "   " << "   o  o" << endl;
}

bool Walk_in::checkTableEmpty() {
	if (table[0].get_id() != "" && table[1].get_id() != "") {
		return false;
	}
	return true;
}

void Walk_in::seatTable() {
	int table_number = 0;
	cout << "앉으실 테이블 번호를 입력해주세요 >>";

	while (table_number == 0) {
		cin >> table_number;

		if (table_number > 2 || table_number < 1) {
			cout << "잘못된 입력입니다" << endl;
			table_number = 0;
		}
		else if (table[table_number - 1].get_id() != "") {
			cout << "앉을 수 없는 자리입니다" << endl;
			table_number = 0;
		}
		else {
			table[table_number - 1].appointment(User);
		}
	}
}