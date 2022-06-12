#include "ApartUser.h"

ApartUser::ApartUser()
{
	string temp;
	filename = "ApartUser.txt";
	TotalApartId = 1;

	fout.open(filename, ios::out | ios::app);
	fin.open(filename, ios::in);

	while (getline(fin, temp)) {
		if (temp == "***") {
			TotalApartId++;
		}
	}
	fin.close();
	fout.close();
}

void ApartUser::sign_up(string apartment_number) {
	cout << apartment_number << "세대의 아이디는 " << TotalApartId << "입니다";
	
	string id = to_string(TotalApartId);
	string password;
	int age;

	fout.open(filename, ios::out | ios::app);
	fin.open(filename, ios::in);

	if (!fout || !fin) {
		cout << "파일 열기 오류 sign_up" << endl;
		fin.close();
		fout.close();
	}
	else {
		password = Console::set_password();
		age = Console::set_age();
		fout << "***\n";
		fout << id << '/' << password << '/' << age << '/' << apartment_number << '\n';

		fin.close();
		fout.close();
	}

	TotalApartId++;
}

bool ApartUser::check_id(string apartment_number)
{
	string temp, fileNumber;
	fout.open(filename, ios::out | ios::app);
	fin.open(filename, ios::in);

	if (!fout || !fin) {
		cout << "파일 열기 오류 check_id" << endl;
		fin.close();
		fout.close();
		return NULL;
	}
	while (getline(fin, temp)) {
		if (temp == "***") {
			getline(fin, temp, '/');
			getline(fin, temp, '/');
			getline(fin, temp, '/');
			getline(fin, fileNumber);

			if (fileNumber == apartment_number) {
				cout << "중복되는 호수가 존재합니다" << endl;
				fin.close();
				fout.close();
				return true;
			}
		}
	}
	fin.close();
	fout.close();
	return false;
}
