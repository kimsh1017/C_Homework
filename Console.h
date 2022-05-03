#ifndef CONSOLE_H
#define CONSOLE_H
#include <iostream>
using namespace std;
#include<string>

class Console {
	static int temp_int;
	static string temp_string;
public:
	static int get_int();
	static string get_string();
};
#endif