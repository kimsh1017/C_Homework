#include "Console_apart.h"

int Console_apart::set_menu() {
	int menu = 0;

	while (menu == 0) {
		cout << endl;
		cout << "=========================" << endl;
		cout << "독서실 시스템에 오신걸 환영합니다" << endl;
		cout << "1: 예약 / 2: 예약 취소 / 3: 통계 보기 / 4: 로그아웃 >>";
		cin >> menu;

		if (menu > 5 || menu < 1) { //예외처리
			menu = 0;
			cout << "잘못된 입력입니다" << endl;
		}
	}
	return menu;
}

int  Console_apart::set_date() {
	int date = -1;

	cout << "====================================" << endl;
	while (date == -1) {
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
		}
	}
	return date;
}

int Console_apart::set_time(int total_time) {
	int time = -1;

	cout << "=============================================================" << endl;
	cout << "예약하실 시간을 입력해주세요." << endl;
	cout << "영업시간: 09시 ~ 23시 , 세대당 하루 최대 4시간 예약 가능합니다" << endl;
	cout << endl;
	while (time == -1) {
		cout << "현재 " << total_time << "시간 예약중" << endl;
		cout << "한 번에 1시간씩 예약 가능합니다" << endl;
		cout << endl;
		cout << "입실 시간 (돌아가기 : 0)>>";
		cin >> time;

		if ((time < 9 || time> 22 ) && (time != 0)) {
			cout << "잘못된 입력입니다. 영업시간: 09시 ~23시" << endl;
			time = -1;
		}
	}
	return time;
}

string Console_apart::set_name() {
	string name;
	cout << "예약자의 이름을 입력해주세요>>";
	cin >> name;
	return name;
}
string Console_apart::set_gender() {
	string gender = "";

	while (gender == "") {
		cout << "예약자의 성별을 입력해주세요 (남/여) >>";
		cin >> gender;

		if (gender != "남" && gender != "여") {
			cout << "잘못된 입력입니다" << endl;
			gender = "";
		}
	}
	return gender;
}
int Console_apart::set_seat_number() {
	int n = -1;
	while (n == -1) {
		cout << "예약하실 좌석 번호를 입력해주세요 (돌아가기 0) >>";
		cin >> n;

		if (n > 225 || n < 0) {
			cout << "잘못된 입력입니다" << endl;
			n = -1;
		}
	}
	return n;
}

int Console_apart::set_age() {
	int age = 0;
	while (age == 0) {
		cout << "나이 >>";
		cin >> age;
		if (age < 0) {
			cout << "잘못된 입력입니다" << endl;
			age = 0;
		}
	}
	return age;
}

int Console_apart::set_ticket_number(int tickets_size) {
	int ticket_number = -1;
	while (ticket_number == -1) {
		cout << "취소하고 싶은 예약의 번호를 입력하세요 (돌아가기 : 0)>>";
		cin >> ticket_number;
		if (ticket_number > tickets_size || ticket_number < 0) {
			ticket_number = -1;
			cout << "잘못된 입력입니다" << endl;
		}
	}
	return ticket_number;
}

int Console_apart::set_stat_menu() {
	int menu = -1;
	while (menu == -1) {
		cout << "1: 내 예약 현황 보기 / 2: 전체 예약 통계 보기 (돌아가기 : 0)>>";
		cin >> menu;
		if (menu > 2 || menu < 0) {
			cout << "잘못된 입력입니다" << endl;
			menu = -1;
		}
	}
	return menu;
}

int Console_apart::set_stat_detail() {
	int menu = -1;

	while (menu == -1) {
		cout << "1 : 좌석별 예매 현황 보기 / 2 : 성별 예약 횟수 보기 (돌아가기 : 0)>>";
		cin >> menu;
		if (menu > 2 || menu < 0) {
			cout << "잘못된 입력입니다" << endl;
			menu = -1;
		}	
	}
	return menu;
}

void Console_apart::clean(int delay) {
	Sleep(delay);
	system("cls");
}
