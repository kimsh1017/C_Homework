#include "newUserData.h"

newUserData::newUserData(string id, string password, int age)
{
	this->id = id;
	this->password = password;
	this->age = age;
}

newUserData::newUserData(string id, string password, int age, string apartment_number)
{
	this->id = id;
	this->password = password;
	this->age = age;
	this->apartment_number = apartment_number;
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

string newUserData::get_apartment_number()
{
	return apartment_number;
}
