#include "Login.h"

int UserData_apart::study_room_id_total = 1;

Login::Login() {
	LoginDataBase = new DataBase[3]; // ���� ���� �����ͺ��̽� 1.����� 2.�Ĵ� 3.������
	User = NULL;
}
Login::~Login() {
	delete []LoginDataBase;
}

void Login::sign_up(int place) { //���߿� ���� ���� �ʿ�
	string id;

	Console::clean(0);
	cout << endl;
	cout << " [ȸ������] " << endl;
	cout << " ȸ�� ������ �Է����ּ���" << endl;
	cout << endl;

	if (place == 3) { //����Ʈ�� ��� ����� �Է� �ޱ�
		id = Console::set_apartment_number();
		
		if (LoginDataBase[place - 1].check_id(id)) {
			cout << "�̹� ���Ե� ȣ�� �Դϴ�" << endl;
			User = NULL;
			Sleep(500);
		}
		else {
			User = new UserData_apart; //�����ڿ��� static ����
			LoginDataBase[place - 1].sign_up(User, id); // id�� UserData���� ����
		}
	}
	else {
		id = Console::set_id();

		if (LoginDataBase[place - 1].check_id(id)) { // ���̵� �ߺ� üũ
			cout << "����� �Ұ����� ���̵� �Դϴ�" << endl;
			Sleep(500);
			User = NULL;
		}
		else {
			switch (place) {
			case 1: // �װ��� ȸ������
				User = new UserData_airport;
				LoginDataBase[place - 1].sign_up(User, id);
				break;
			case 2: // �Ĵ� ȸ������
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
	cout << " [�α���] " << endl;
	cout << endl;

	string id = Console::set_id();
	string password = Console::set_password();
	User = LoginDataBase[place - 1].sign_in(id,password);
}

UserData* Login::sign_in_or_up(int place) {
	int login_menu;
	printGreetMessage(place);

	login_menu = Console::set_login_menu();

	if (login_menu == 1) { // 1. �α���
		sign_in(place);
	}
	else if(login_menu == 2) { // 2. ȸ������
		sign_up(place);
	}
	return User;
}

void Login::printGreetMessage(int place) {
	Console::clean(300);
	cout << endl;

	switch (place) {
	case 1:
		cout << "����� ���� ���α׷��� ���Ű� ȯ���մϴ�" << endl;
		break;
	case 2:
		cout << "�Ĵ� ���� ���α׷��� ���Ű� ȯ���մϴ�" << endl;
		break;
	case 3:
		cout << "������ ���� ���α׷��� ���Ű� ȯ���մϴ�" << endl;
		break;
	}

}
