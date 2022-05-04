#include "Login.h"
#include "Console.h"

#include "DataBase.h"
#include "DataBase_airport.h"
#include "DataBase_apart.h"
#include "DataBase_restaurant.h"

#include <iostream>
using namespace std;
#include <string>
#include <vector>


Login::Login() {
	LoginDataBase = new DataBase*[3];
	LoginDataBase[0] = new DataBase_airport;
	LoginDataBase[1] = new DataBase_restaurant; 
	LoginDataBase[2] = new DataBase_apart;
	User = NULL;
}
Login::~Login() {
	for (int i = 0; i < 3; i++) {
		delete LoginDataBase[i];
	}
	delete []LoginDataBase;
}

void Login::sign_up(int place) {
	LoginDataBase[place - 1]->sign_up();
}
UserData* Login::sign_in(int place) {
	Console::set_id();
	Console::set_password();

	cout << "회원정보를 등록해주세요" << endl;
	return LoginDataBase[place - 1]->sign_in(Console::get_id(),Console::get_password());
}

