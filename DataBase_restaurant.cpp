#include "DataBase.h"
#include "DataBase_restaurant.h"
#include "UserData.h"
#include "Console.h"
#include <iostream>
using namespace std;
#include<string>
#include<vector>


void DataBase_restaurant::sign_up() {
	cout << "�Ĵ� ȸ������ " << endl;
	cout << "���̵� �Է��ϼ��� >>";
	cin >> id;
	if (check_id()) {
		cout << "����� �Ұ����� ���̵� �Դϴ�" << endl;
	}
	else {
		if (start == NULL) {
			start = new UserData_restaurant;
			last = start;
		}
		else {
			last->next = new UserData_restaurant;
			last = last->next;
		}
		last->createUser(id);
	}
}