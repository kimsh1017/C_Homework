#include "ApartUser.h"

ApartUser::ApartUser()
{
	fstream fin;
	const char* filename = "ApartUser.txt";
	TotalApartId = 1;

	string id, password, temp, apartment_number;

	fin.open(filename, ios::in);

	if (!fin) {
		cout << "���� ���� ���� sign_up" << endl;
	}
	else {
		while (getline(fin, temp)) {
			if (temp == "***") {
				getline(fin, id, '/');
				getline(fin, password, '/');
				getline(fin, apartment_number);

				userData.push_back(newUserData(id, password,apartment_number));
				TotalApartId++;
			}
		}
	}
	fin.close();
}

ApartUser::~ApartUser() {
	const char* filename = "ApartUser.txt";
	fstream fout;
	fout.open(filename, ios::out);

	if (!fout) {
		cout << "���� ���� ����" << endl;
		Sleep(500);
	}
	else {
		for (int i = 0; i < userData.size(); i++) {
			fout << "***\n";
			fout << userData[i].get_id() << '/';
			fout << userData[i].get_password() << '/';
			fout << userData[i].get_apartment_number() << '\n';
		}
	}
	fout.close();
}

void ApartUser::sign_up(string apartment_number) {
	string password;
	if (TotalApartId > 300) {
		cout << "�� �̻� ������ �� �����ϴ� �˼��մϴ�" << endl;
	}
	else {
		cout << apartment_number << "������ ���̵�� " << TotalApartId << "�Դϴ�" << endl;

		password = Console::set_password();
		userData.push_back(newUserData(to_string(TotalApartId), password, apartment_number));

		TotalApartId++;
	}
}

bool ApartUser::check_id(string apartment_number)
{
	for(int i = 0; i < userData.size(); i++){
		if (userData[i].get_apartment_number() == apartment_number) {
			return true;
		}
	}
	return false;
}
