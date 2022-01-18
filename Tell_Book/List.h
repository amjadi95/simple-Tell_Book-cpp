#pragma once
#include "Person.h"


class List
{
protected:
	Person* list[50];
	int current;
	int size;

public:
	List();

	bool Insert(Person);
	virtual Person* Delete(Person) ;
	virtual List* Search(Person) ;
	virtual Person* Update(Person,string);
	void Display(void (* )(Person * []));
	int Count();
	List* getList();
	int Size();
	Person* getItem(int);

};