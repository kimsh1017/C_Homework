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
			Console::clean(0);
			cout << endl;
			cout << "로그인 성공" << endl;
			Sleep(500);

			switch (place_menu) {
			case 1:
				airport->runServer(UserNow);
				UserNow = NULL;
				break;
			case 2:
				restaurant->runServer(UserNow);
				UserNow = NULL;
				break;
			case 3:
				apart->runserver(UserNow);
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
	delete apart; 
}