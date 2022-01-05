#pragma once
#include "Person.h"


class List
{
protected:
	Person* list[50];
	int current;

public:
	List();

	bool Insert(Person);
	virtual Person* Delete(Person) = 0;
	virtual int Search(Person) = 0;
	bool Update(Person);
	void Display(void (* )(Person * []));
	

};