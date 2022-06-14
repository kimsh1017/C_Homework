#include "ApartUser.h"

ApartUser::ApartUser()
{
	fstream fin;
	const char* filename = "ApartUser.txt";
	TotalApartId = 1;

	string id, password, temp, apartment_number;

	fin.open(filename, ios::in);

	if (!fin) {
		cout << "파일 열기 오류 sign_up" << endl;
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
		cout << "파일 열기 오류" << endl;
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
		cout << "더 이상 가입할 수 없습니다 죄송합니다" << endl;
	}
	else {
		cout << apartment_number << "세대의 아이디는 " << TotalApartId << "입니다" << endl;

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
