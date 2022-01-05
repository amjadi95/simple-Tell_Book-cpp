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
	virtual Person* Delete(Person) ;
	virtual List* Search(Person) ;
	virtual bool Update(Person);
	void Display(void (* )(Person * []));
	int Count();
	List* getList();
	

};