#pragma once
#include "TellBook.h"
#include <fstream>

using namespace std;
class Tell_Book_File
{
	string fileName;
	
public:
	Tell_Book_File(string);

	void fileWrite(List);
	List fileRead();
	void fileAppend(Person);

};