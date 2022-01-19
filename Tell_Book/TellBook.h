#pragma once
#include "File.h"
#include "List.h"

class TellBook : public List<Person>
{
private:
	Tell_Book_File* file;
	void loadFileData();
public:
	Person* Delete(Person);
	List<Person>* Search(Person);
	int SearchOneByName(Person);
	Person* Update(Person, string);
	TellBook();
	bool Print();
};
