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
		// �α��� �Ǵ� ȸ������
		UserNow = login->sign_in_or_up(place_menu);

		// �α��� ������
		if (UserNow != NULL) {
			switch (place_menu) {
			case 1:
				airport->runServer(UserNow);
				cout << "�α��� ����" << endl;
				UserNow = NULL;
				break;
			case 2:
				restaurant->runServer(UserNow);
				cout << "�α��� ����" << endl;
				cout << UserNow->get_id() << " " << UserNow->get_age() << endl;
				UserNow = NULL;
				break;
			case 3:
				//apart->runserver(user);
				cout << "�α��� ����" << endl;
				cout << UserNow->get_id() << " " << UserNow->get_age() << endl;
				UserNow = NULL;
				break;
			}
		}

		cout << endl;
		place_menu = Console::set_place_menu();
	}
	cout << "���α׷��� �����մϴ�" << endl;
	delete login;
	delete restaurant;
	delete airport;
}