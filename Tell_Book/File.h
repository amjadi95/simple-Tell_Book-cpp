#pragma once
#include "List.h"
#include <fstream>

using namespace std;
class Tell_Book_File
{
private:
	string fileName;
	
public:
	Tell_Book_File(string);

	bool fileWrite(List);
	List fileRead();
	bool fileAppend(Person);

};