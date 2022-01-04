#pragma once

#include "List.h"

class TellBook : public List
{
public:
	void Delete(Person);
	int Search(Person);
};
