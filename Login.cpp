#include "Login.h"
#include "UserData.h"
#include "Console.h"

#include <iostream>
using namespace std;
#include <string>
#include <vector>


void Login::sign_up() {
	int menu;
	
	cin >> menu;
	dataBase[menu].sign_up(menu);
}

void Login::sign_in(){
	int menu;
	cout << "프로그램 선택" << endl;
	cout << "1: 비행기 예약 / 2: 식당 예약 / 3: 독서실 예약>>";
	cin >> menu;
	dataBase[menu].sign_in();
}