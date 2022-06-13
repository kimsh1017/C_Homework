#include "RestaurantUser.h"

RestaurantUser::RestaurantUser()
{
	fstream fin;
	const char* filename = "RestaurantUser.txt";
	string id, password, temp, age_string , name;

	fin.open(filename, ios::in);

	if (!fin) {
		cout << "파일 열기 오류 sign_up" << endl;
	}
	else {
		while (getline(fin, temp)) {
			if (temp == "***") {
				getline(fin, id, '/');
				getline(fin, password, '/');
				getline(fin, age_string,'/');
				getline(fin, name);

				userData.push_back(newUserData(id, password, stoi(age_string),name));
			}
		}
	}
	fin.close();
}

RestaurantUser::~RestaurantUser() {
	const char* filename = "RestaurantUser.txt";
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
			fout << userData[i].get_age() << '/';
			fout << userData[i].get_name() << '\n';
		}
	}
	fout.close();
}