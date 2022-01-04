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
	virtual int Search(string, string);
	virtual void Update(string, string);
	void Display(void (* )(Person * []));
	

};