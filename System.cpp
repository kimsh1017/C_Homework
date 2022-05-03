#include "System.h"
#include "Login.h"
#include <iostream>
using namespace std;
#include<string>

void System::running() {
	login = new Login();
	login->get_menu();
	login->getUser();
}