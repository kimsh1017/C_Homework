#include "newUserData.h"

newUserData::newUserData(string id, string password, int age)
{
	this->id = id;
	this->password = password;
	this->age = age;
}

string newUserData::get_id()
{
	return id;
}

string newUserData::get_password()
{
	return password;
}

int newUserData::get_age()
{
	return age;
}
