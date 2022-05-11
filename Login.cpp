#include "Login.h"
#include "Console.h"

#include "DataBase.h"

#include "UserData.h"
#include "UserData_airport.h"
#include "UserData_apart.h"
#include "UserData_restaurant.h"

#include <iostream>
using namespace std;
#include <string>


Login::Login() {
	LoginDataBase = new DataBase[3]; // ���� �����ͺ��̽� 1.����� 2.�Ĵ� 3.������
	User = NULL;
}
Login::~Login() {
	delete []LoginDataBase;
}

void Login::sign_up(int place) {
	cout << "ȸ������ " << endl;
	cout << "ȸ�� ������ �Է����ּ���" << endl;

	Console::set_id(); 
	if (LoginDataBase[place-1].check_id()) { // ���̵� �ߺ� üũ
		cout << "����� �Ұ����� ���̵� �Դϴ�" << endl;
		User = NULL;
	}
	else {
		switch (place) {
		case 1: // �װ��� ȸ������
			User = new UserData_airport;
			LoginDataBase[place - 1].sign_up(User);
			break;
		case 2: // �Ĵ� ȸ������
			User = new UserData_restaurant;
			LoginDataBase[place - 1].sign_up(User);
			break;
		case 3: // ������ ȸ������
			User = new UserData_apart;
			LoginDataBase[place - 1].sign_up(User);
			break;
		}
	}
}
void Login::sign_in(int place) {
	Console::set_id();
	Console::set_password();
	User = LoginDataBase[place - 1].sign_in(Console::get_id(),Console::get_password());
}

UserData* Login::sign_in_or_up(int place) {
	Console::set_login_menu();

	if (Console::get_login_menu() == 1) { // �α���
		sign_in(place);
	}
	else { // ȸ������
		sign_up(place);
	}
	return User;
}

