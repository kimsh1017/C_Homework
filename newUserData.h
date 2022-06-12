#ifndef NEWUSERDATA_H
#define NEWUSERDATA_H
#include <string>
using namespace std;

class newUserData {
	string id, password;
	int age;
public:
	newUserData(string, string, int);
	string get_id();
	string get_password();
	int get_age();
};
#endif

