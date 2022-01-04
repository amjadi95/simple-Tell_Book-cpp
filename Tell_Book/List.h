#pragma once
#include "Person.h"


class List
{
private:
	Person* list[50];
	int current;

public:
	List();

	void Insert(Person);
	virtual void Delete(Person);
	virtual int Search(Person);
	virtual void Update(Person);
	void Display(void (* )(Person * []));
	

};