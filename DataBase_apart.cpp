#include "DataBase.h"
#include "DataBase_apart.h"
#include "UserData.h"
#include "Console.h"
#include <iostream>
using namespace std;
#include<string>
#include<vector>

void DataBase_apart::sign_up() {
	cout << "������ ȸ������ " << endl;
	cout << "���̵� �Է��ϼ��� >>";
	cin >> id;
	if (check_id()) {
		cout << "����� �Ұ����� ���̵� �Դϴ�" << endl;
	}
	else {
		if (start == NULL) {
			start = new UserData_apart;
			last = start;
		}
		else {
			last->next = new UserData_apart;
			last = last->next;
		}
		last->createUser(id);
	}
}
