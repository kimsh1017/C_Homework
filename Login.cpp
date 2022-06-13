#include "Login.h"

Login::Login() {
	LoginDataBase[0] = new AirportUser;
	LoginDataBase[1] = new RestaurantUser;
	LoginDataBase[2] = new ApartUser;
	// ���� ���� �����ͺ��̽� 1.����� 2.�Ĵ� 3.������
	User = NULL;
}
Login::~Login() {
	for (int i = 0; i < 3; i++) {
		delete LoginDataBase[i];
	}
}

void Login::sign_up(int place) {
	string id;

	Console::clean(0);
	cout << endl;
	cout << " [ȸ������] " << endl;
	cout << " ȸ�� ������ �Է����ּ���" << endl;
	cout << endl;

	if (place == 3) { //����Ʈ�� ��� ����� �Է� �ޱ�
		id = Console::set_apartment_number();
		
		if (LoginDataBase[place - 1]->check_id(id)) {
			cout << "�̹� ���Ե� ȣ�� �Դϴ�" << endl;
			Sleep(500);
		}
		else {
			LoginDataBase[place - 1]->sign_up(id); // id�� UserData���� ����
			
			Console::clean(0);
			cout << "ȸ�����Կ� �����߽��ϴ�" << endl;
			Sleep(1000);
		}
	}
	else {
		id = Console::set_id();

		if (LoginDataBase[place - 1]->check_id(id)) { // ���̵� �ߺ� üũ
			cout << "����� �Ұ����� ���̵� �Դϴ�" << endl;
			Sleep(500);
		}
		else {
			switch (place) {
			case 1: // �װ��� ȸ������
				LoginDataBase[place - 1]->sign_up(id);

				Console::clean(0);
				cout << "ȸ�����Կ� �����߽��ϴ�" << endl;
				Sleep(1000);
				break;
			case 2: // �Ĵ� ȸ������
				LoginDataBase[place - 1]->sign_up(id);

				Console::clean(0);
				cout << "ȸ�����Կ� �����߽��ϴ�" << endl;
				Sleep(1000);
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
	User = LoginDataBase[place - 1]->sign_in(id,password);
}

newUserData* Login::sign_in_or_up(int place) {
	User = NULL;
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
	Console::clean(0);
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
