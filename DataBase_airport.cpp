#include "DataBase.h"
#include "DataBase_airport.h"
#include "UserData.h"
#include "UserData_airport.h"
#include "Console.h"
#include <iostream>
using namespace std;
#include<string>
#include<vector>

void DataBase_airport::sign_up() {
	cout << "�װ��� ȸ������ " << endl;
	cout << "���̵� �Է��ϼ��� >>";
	cin >> id;
	if (check_id()) {
		cout << "����� �Ұ����� ���̵� �Դϴ�" << endl;
	}
	else {
		if (start == NULL) {
			start = new UserData_airport;
			last = start;
		}
		else {
			last->next = new UserData_airport;
			last = last->next;
		}
		last->createUser(id);
	}
}