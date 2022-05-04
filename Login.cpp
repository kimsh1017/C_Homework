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
	LoginDataBase[0] = new DataBase_airport;
	LoginDataBase[1] = new DataBase_restaurant; 
	LoginDataBase[2] = new DataBase_apart;
}

void Login::sign_up(int place) {
	LoginDataBase[place - 1]->sign_up();
}
bool Login::sign_in(int place) {
	if (LoginDataBase[place - 1]->sign_in()) {
		User = LoginDataBase[place - 1]->getUser();
		return true;
	}
	else {
		return false;
	}
}

UserData* Login::getUser() {
	return User;
}