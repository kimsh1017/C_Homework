#include "Console_restaurant.h"
#include <iostream>
#include <string>
using namespace std;

void Console_restaurant::set_menu() {
	cout << endl;
	cout << "=========================" << endl;
	cout << "�Ĵ� ���� �ý��ۿ� ���Ű� ȯ���մϴ�" << endl;
	cout << "1: ���� / 2: ���� ��� / 3: �Ĵ� �湮 / 4: ��� / 5: �α׾ƿ� >>";
	cin >> menu;
}

int Console_restaurant::get_menu() {
	return menu;
}

void Console_restaurant::set_date() {
	cout << "��¥�� �������ּ���" << endl;
	cout << "*****5��****************************" << endl;
	cout << "____________________________________" << endl;
	cout << "| �� | �� | ȭ | �� | �� | �� | �� |" << endl;
	cout << "------------------------------------" << endl;
	cout << "| 1  | 2  | 3  | 4  | 5  | 6  | 7  |" << endl;
	cout << "------------------------------------" << endl;
	cout << "5�� _�� >>";
	cin >> date;
}

int Console_restaurant::get_date() {
	return date;
}


void Console_restaurant::set_people() {
	cout << "�湮 �ο� >>";
	cin >> people;
}

int Console_restaurant::get_people() {
	return people;
}