#pragma once

#include "List.h"

class TellBook : public List
{
public:
	Person* Delete(Person);
	List* Search(Person);
	int SearchOne(Person);
	TellBook();
};
