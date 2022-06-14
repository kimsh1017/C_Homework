#include "Walk_in.h"

Walk_in::Walk_in() {
	table = new Table[2];
	table[0].set_seat_number(4);
	table[1].set_seat_number(4);
	User = NULL;

	setWalkInData();
}
Walk_in::~Walk_in() {
	fstream fout("WalkInData.txt", ios::out);
	string temp;
	if (!fout) {
		cout << "���� ���� ���� " << endl;
		Sleep(500);
	}
	else {
		for (int i = 0; i < 2; i++) {
			if (table[i].get_id() != "---") {
				fout << "***\n";
				fout << table[i].get_id() << '/' << i << '\n';
			}
		}
		while(!waitingList.empty()) {
			fout << "@@@\n";
			fout << waitingList.front() << '\n';
			waitingList.pop_front();
		}
	}
	fout.close();
	delete []table;
}
void Walk_in::setWalkInData() {
	fstream fin("WalkInData.txt",ios::in);
	string temp,id;
	int table_number;

	if (!fin) {
		cout << "���� ���� ���� " << endl;
		Sleep(500);
	}
	else {
		while (getline(fin, temp)) {
			if (temp == "***") {

				getline(fin, temp,'/');
				id = temp;

				getline(fin, temp);
				table_number = stoi(temp);

				table[table_number].appointment(id);
			}
			else if (temp == "@@@") {
				getline(fin, id);
				waitingList.push_back(id);
			}
		}
	}
	fin.close();
}


void Walk_in::running(newUserData* User) {
	this->User = User;
	int people = 0;
	int menu = 0;
	Console_restaurant::clean(0);
	cout << endl;

	if (checkTableUser()) { // �̹� �Ļ���
		cout << "���� �Ļ����Դϴ�" << endl;
		cout << "�Ļ縦 �����Ͻðڽ��ϱ�? (1:�� / 2: �ƴϿ�)>>";
		cin >> menu;

		if (menu == 1) {
			if (table[0].get_id() == User->get_id()) {
				table[0].cancel();
			}
			else {
				table[1].cancel();
			}
		}
	}
	else if (checkListUser()) { //waitingList�� ���� ��
		if (waitingList[0] == User->get_id() && checkTableEmpty()) {
			cout << "�ڸ��� ������ϴ�" << endl;
			cout << "���̺� û����.." << endl;
			Sleep(1000);
			showTable();
			seatTable();
			waitingList.pop_front();
		}
		else {
			for (int i = 0; i < waitingList.size(); i++) {
				if (waitingList[i] == User->get_id()) {
					cout << User->get_name() << "�� ���� ��� ������ " << i + 1 << "�� �Դϴ�" << endl;
					Sleep(1000);
				}
			}
		}
	}
	else { // waiting_list���� ���� ��
		people = Console_restaurant::set_walk_in_people();
		cout << endl;

		if (people != 0) {
			if (waitingList.size() != 0) { // �� ������
				cout << "���� " << waitingList.size() << "���� ������Դϴ�" << endl;
				cout << "����Ͻðڽ��ϱ�? (1:�� / 2: �ƴϿ�)>>";
				cin >> menu;

				if (menu == 1) {
					waitingList.push_back(User->get_id());
				}
			}
			else { // �� ������
				if (checkTableEmpty()) {
					showTable();
					seatTable();
				}
				else {
					cout << "���� ������ ���̺��� ��� ������Դϴ�" << endl;
					cout << "����Ͻðڽ��ϱ�? (1:�� / 2: �ƴϿ�)>>";
					cin >> menu;

					if (menu == 1) {
						waitingList.push_back(User->get_id());
					}
				}
			}
		}
	}
}

bool Walk_in::checkTableUser() {
	for (int i = 0; i < 2; i++) {
		if (User->get_id() == table[i].get_id()) {
			cout << "���� " << i + 1 << "�� ���̺��� �Ļ����Դϴ�." << endl;
			return true;
		}
	}
	return false;
}

bool Walk_in::checkListUser() {
	for (int i = 0; i < waitingList.size(); i++) {
		if (waitingList[i] == User->get_id()) {
			return true;
		}
	}
	return false;
}

void Walk_in::showTable() {
	Console_restaurant::clean(0);
	cout << endl;
	cout << "   o  o " << "   " << "   o  o" << endl;
	cout << "����������������" << "   " << "������������������" << endl;
	cout << "��1 " << table[0].get_appointed(0) << "��" << "   " << "�� 2 " << table[1].get_appointed(0) << "��" << endl;
	cout << "����������������" << "   " << "������������������" << endl;
	cout << "   o  o " << "   " << "   o  o" << endl;
}

bool Walk_in::checkTableEmpty() {
	if (table[0].get_id() != "---" && table[1].get_id() != "---") {
		return false;
	}
	return true;
}

void Walk_in::seatTable() {
	int table_number = 0;
	cout << "������ ���̺� ��ȣ�� �Է����ּ��� >>";

	while (table_number == 0) {
		cin >> table_number;

		if (table_number > 2 || table_number < 1) {
			cout << "�߸��� �Է��Դϴ�" << endl;
			table_number = 0;
		}
		else if (table[table_number - 1].get_id() != "---") {
			cout << "���� �� ���� �ڸ��Դϴ�" << endl;
			table_number = 0;
		}
		else {
			table[table_number - 1].appointment(User->get_id());
		}
	}
}