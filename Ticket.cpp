#include "Ticket.h"
#include <iostream>
#include <string>
using namespace std;

Ticket::Ticket() {
	name = "";
	date = 0;
}
void Ticket::showTicket() {
	cout << "티켓 출력" << endl;
}
