#ifndef DATABASE_H
#define DATABASE_H
#include "newUserData.h"

#include <iostream>
using namespace std;
#include<string>
#include<vector>
#include "Console.h"
#include <fstream>

class DataBase {
protected:
	const char* filename;
	fstream fin;
	fstream fout;
public:
	DataBase();

	virtual void sign_up(string);
	virtual newUserData* sign_in(string,string);
	virtual bool check_id(string);
};
#endif
