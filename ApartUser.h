#ifndef APARTUSER_H
#define APARTUSER_H
#include "DataBase.h"

class ApartUser :public DataBase {
	int TotalApartId;
public:
	ApartUser();
	~ApartUser();
	void sign_up(string);
	bool check_id(string);
};
#endif
