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
	cout << "���α׷� ����" << endl;
	cout << "1: ����� ���� / 2: �Ĵ� ���� / 3: ������ ����>>";
	cin >> menu;
	dataBase[menu].sign_in();
}