#pragma once
#include "Person.h"


class List
{
private:
	Person* list[50];
	int current;

public:
	List();

	bool Insert(Person);
	virtual void Delete(Person);
	virtual int Search(Person);
	bool Update(Person);
	void Display(void (* )(Person * []));
	

};