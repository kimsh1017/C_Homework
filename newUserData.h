#ifndef NEWUSERDATA_H
#define NEWUSERDATA_H
#include <string>
using namespace std;

class newUserData {
	string id, password,apartment_number;
	int age;
public:
	newUserData(string, string, int);
	newUserData(string, string, int, string);
	string get_id();
	string get_password();
	int get_age();
	string get_apartment_number();
};
#endif

