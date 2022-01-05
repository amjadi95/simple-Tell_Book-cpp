#pragma once

#include "List.h"

class TellBook : public List
{
public:
	Person* Delete(Person);
	int Search(Person);
	TellBook();
};
