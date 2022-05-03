#include "Console.h"
#include <iostream>
#include <string>
using namespace std;

int Console::temp_int = 0;
string Console::temp_string = "";

int Console::get_int() {
	cin >> temp_int;
	return temp_int;
}

string Console::get_string() {
	cin >> temp_string;
	return temp_string;
}