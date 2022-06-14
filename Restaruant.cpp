#include "Restaurant.h"

Restaurant::Restaurant() {
	this->User = NULL;
	schedules = new Schedule_restaurant[7];

	set_date(); // �����ٿ� ���� ��¥ ����
	walkInServer = new Walk_in;

	setReservationData();
}
Restaurant::~Restaurant() {
	fstream fout("ReservationRestaurant.txt", ios::out);
	if (!fout) {
		cout << "���� ���� ����" << endl;
		Sleep(500);
	}
	else {
		for (int i = 0; i < reservationData.size(); i++) {
			fout << "***\n";
			fout << reservationData[i].get_id() << '/';
			fout << reservationData[i].get_date() << '/';
			fout << reservationData[i].get_table_number() << '/';
			fout << reservationData[i].get_people() << '\n';
		}
	}
	fout.close();
	delete[]schedules;
	delete walkInServer;
}

void Restaurant::set_date() { // ���� ��¥ ����
	schedules[0].setDate("5�� 1�� �Ͽ���");
	schedules[1].setDate("5�� 2�� ������");
	schedules[2].setDate("5�� 3�� ȭ����");
	schedules[3].setDate("5�� 4�� ������");
	schedules[4].setDate("5�� 5�� �����");
	schedules[5].setDate("5�� 6�� �ݿ���");
	schedules[6].setDate("5�� 7�� �����");
}

void Restaurant::setReservationData() { // ���Ͽ��� ���� �ҷ�����
	fstream fin("ReservationRestaurant.txt", ios::in);
	string id, temp;
	int date, people, table_number;

	if (!fin) {
		cout << "���� ���� ����" << endl;
		Sleep(500);
	}
	else {
		while (getline(fin, temp)) {
			if (temp == "***") {
				getline(fin, temp, '/');
				id = temp;

				getline(fin, temp, '/');
				date = stoi(temp);

				getline(fin, temp, '/');
				table_number = stoi(temp);

				getline(fin, temp);
				people = stoi(temp);

				reservationData.push_back(Ticket_restaurant(id, date,table_number,people));
			}
		}
		for (int i = 0; i < reservationData.size(); i++) {
			cout << reservationData[i].get_id() << endl;
			int date = reservationData[i].get_date();
			schedules[date-1].appointment(&reservationData[i]);
		}
	}

	fin.close();
}

void Restaurant::appointment() {
	int date = Console_restaurant::set_date();
	reservationData.push_back(Ticket_restaurant());
	if (date != 0) {
		reservationData.back().set_id(User->get_id());
		reservationData.back().set_date(date);
		schedules[date - 1].appointment(&reservationData.back());
	}
}

void Restaurant::walk_in() {
	walkInServer->running(User);
}

void Restaurant::runServer(newUserData* User) {
	int menu = 0;
	this->User = User; 

	while (menu != 5) {  //menu 5 = �α׾ƿ�
		menu = Console_restaurant::set_menu(User->get_name());
		switch (menu) {
		case 1:
			if (User->get_age() <= 7) {
				cout << "7�� ���� ������ �Ƶ��� ������ �Ұ����մϴ�." << endl;
				Sleep(1000);
			}
			else {
				appointment();
				if (reservationData.back().get_table_number() != 0) {
					cout << "����Ǿ����ϴ�" << endl;
					Console_restaurant::clean(1000);
					menu = 5;
				}
				else {
					reservationData.erase(reservationData.end() - 1);
				}
			}
			break;
		case 2:
			cancel();
			break;
		case 3: 
			walk_in();
			break;
		case 4:
			showStat();
			break;
		}
	}
}

void Restaurant::cancel() {
	int ticket_number;
	int count = 1;

	for (int i = 0; i < reservationData.size(); i++) {
		if (reservationData[i].get_id() == User->get_id()) {
			cout << count << "�� ����" << endl;
			reservationData[i].showTicket();
			count++;
		}
	}	
	ticket_number = Console_restaurant::set_ticket_number(count-1);//?? count-1?
	count = 0;
	// ���� ������ ���̺� ��ü ������ ����ϱ�
	if (ticket_number != 0) {
		for (int i = 0; i < reservationData.size(); i++) {
			if (reservationData[i].get_id() == User->get_id()) {
				count++;
				if (count == ticket_number) {
					schedules[reservationData[i].get_date() - 1].cancel(&reservationData[i]);
					reservationData.erase(reservationData.begin() + i);
					cout << "��ҵǾ����ϴ�" << endl;
					Sleep(1000);
					break;
				}
			}
		}
	}
}

void Restaurant::showStat() { // walkin??
	int stat_menu = 0;
	int table_stat[6] = {0,};

	stat_menu = Console_restaurant::set_stat_menu();

	if (stat_menu == 1) { // ���� ���ݱ����� ���� Ƚ�� �����ֱ�
		Console_restaurant::clean(0);
		
		for (int i = 0; i < reservationData.size(); i++) {
			if (reservationData[i].get_id() == User->get_id()) {
				reservationData[i].showTicket();
			}
		}
		while (stat_menu != 0) {
			cout << "���ư��� : 0 >>";
			cin >> stat_menu;
		}

	}
	else if (stat_menu == 2) { // ���̺� ����� Ƚ�� �����ֱ�
		Console_restaurant::clean(0);
		cout << endl;
		cout << "[ 5�� 1�� ~ 7�� �Ĵ� ���� ��Ȳ ]" << endl;
		cout << endl;
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 6; j++) {
				if (schedules[i].checkTable(j+1)) {
					table_stat[j]++;
				}
			}
		}

		for (int i = 0; i < 6; i++) {
			cout << i+1 << "�� ���̺� ���� Ƚ�� : " << table_stat[i] << endl;
		}
		cout << endl;
		while (stat_menu != 0) {
			cout << "���ư��� : 0 >>";
			cin >> stat_menu;
		}
	}
}
