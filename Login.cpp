#include "Login.h"

int UserData_apart::study_room_id_total = 1;

Login::Login() {
	LoginDataBase = new DataBase[3]; // 유저 정보 데이터베이스 1.비행기 2.식당 3.독서실
	User = NULL;
}
Login::~Login() {
	delete []LoginDataBase;
}

void Login::sign_up(int place) { //나중에 로직 수정 필요
	string id;

	Console::clean(0);
	cout << endl;
	cout << " [회원가입] " << endl;
	cout << " 회원 정보를 입력해주세요" << endl;
	cout << endl;

	if (place == 3) { //아파트일 경우 세대수 입력 받기
		id = Console::set_apartment_number();
		
		if (LoginDataBase[place - 1].check_id(id)) {
			cout << "이미 가입된 호수 입니다" << endl;
			User = NULL;
			Sleep(500);
		}
		else {
			User = new UserData_apart; //생성자에서 static 증가
			LoginDataBase[place - 1].sign_up(User, id); // id는 UserData에서 구현
		}
	}
	else {
		id = Console::set_id();

		if (LoginDataBase[place - 1].check_id(id)) { // 아이디 중복 체크
			cout << "사용이 불가능한 아이디 입니다" << endl;
			Sleep(500);
			User = NULL;
		}
		else {
			switch (place) {
			case 1: // 항공사 회원가입
				User = new UserData_airport;
				LoginDataBase[place - 1].sign_up(User, id);
				break;
			case 2: // 식당 회원가입
				User = new UserData_restaurant;
				LoginDataBase[place - 1].sign_up(User, id);
				break;
			}
		}
	}
}
void Login::sign_in(int place) {
	Console::clean(0);
	cout << endl;
	cout << " [로그인] " << endl;
	cout << endl;

	string id = Console::set_id();
	string password = Console::set_password();
	User = LoginDataBase[place - 1].sign_in(id,password);
}

UserData* Login::sign_in_or_up(int place) {
	int login_menu;
	printGreetMessage(place);

	login_menu = Console::set_login_menu();

	if (login_menu == 1) { // 1. 로그인
		sign_in(place);
	}
	else if(login_menu == 2) { // 2. 회원가입
		sign_up(place);
	}
	return User;
}

void Login::printGreetMessage(int place) {
	Console::clean(300);
	cout << endl;

	switch (place) {
	case 1:
		cout << "비행기 예매 프로그램에 오신걸 환영합니다" << endl;
		break;
	case 2:
		cout << "식당 예약 프로그램에 오신걸 환영합니다" << endl;
		break;
	case 3:
		cout << "독서실 예약 프로그램에 오신걸 환영합니다" << endl;
		break;
	}

}
