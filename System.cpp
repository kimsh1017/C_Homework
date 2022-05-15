#include "System.h"
#include "UserData.h"
#include "Login.h"
#include "Console.h"

#include "Restaurant.h"
#include "Apart.h"

#include <iostream>
#include<string>
using namespace std;

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
				airport->sign_in(UserNow);
				airport->runServer();
				UserNow = NULL;
				break;
			case 2:
				restaurant->sign_in(UserNow);
				restaurant->runServer();
				UserNow = NULL;
				break;
			case 3:
				cout << "독서실 로그인 성공" << endl;
				UserNow = NULL;
				break;
			}
		}

		cout << endl;
		cout << "====================================" << endl;
		place_menu = Console::set_place_menu();
	}
	cout << "프로그램을 종료합니다" << endl;
	delete login;
	delete restaurant;
	delete airport;
}