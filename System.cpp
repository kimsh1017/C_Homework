#include "System.h"
#include "Login.h"
#include <iostream>
using namespace std;
#include<string>

void System::get_menu() {
	cout << "���α׷� ����" << endl;
	cout << "1: ����� ���� / 2: �Ĵ� ���� / 3: ������ ����>>";
	cin >> menu;
}
void System::running() {
	login = new Login();
	login->ui?
	delete login;
}