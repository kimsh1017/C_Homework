#include "System.h"

System::System() {
	login = new Login;
	UserNow = NULL;

	restaurant = new Restaurant;
	apart = new Apart;
	airport = new Airport;
}
void System::running() {
	int place_menu;

	place_menu = Console::set_place_menu(); 
	while (place_menu != 4) {
		// 로그인 또는 회원가입
		UserNow = login->sign_in_or_up(place_menu);

		// 로그인 성공시
		if (UserNow != NULL) {
			switch (place_menu) {
			case 1:
				airport->runServer(UserNow);
				cout << "로그인 성공" << endl;
				UserNow = NULL;
				break;
			case 2:
				restaurant->runServer(UserNow);
				cout << "로그인 성공" << endl;
				cout << UserNow->get_id() << " " << UserNow->get_age() << endl;
				UserNow = NULL;
				break;
			case 3:
				//apart->runserver(user);
				cout << "로그인 성공" << endl;
				cout << UserNow->get_id() << " " << UserNow->get_age() << endl;
				UserNow = NULL;
				break;
			}
		}

		cout << endl;
		place_menu = Console::set_place_menu();
	}
	cout << "프로그램을 종료합니다" << endl;
	delete login;
	delete restaurant;
	delete airport;
}