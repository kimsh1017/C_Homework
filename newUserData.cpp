#include "newUserData.h"

newUserData::newUserData(string id, string password, int age, string name)
{
	this->id = id;
	this->password = password;
	this->age = age;
	this->name = name;
	this->apartment_number = "";
}

newUserData::newUserData(string id, string password, int age, string apartment_number, string name)
{
	this->id = id;
	this->password = password;
	this->age = age;
	this->apartment_number = apartment_number;
	this->name = name;
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

string newUserData::get_name() {
	return name;
}
