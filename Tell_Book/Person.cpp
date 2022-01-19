#include "Person.h"


Person::Person()
{
	firstName = "";
	lastName = "";
	phoneNumber = "";
	group = ' ';
	gender = ' ';
}
Person::Person(string fname, string lname, string number,bool g)
{
	firstName = fname;
	lastName = lname;
	phoneNumber = number;
	gender = g ? 'F' : 'M';
	if (lname == "")
	{
		group = ' ';
	}
	else {
		char c = lname.at(0);
		if (c >= 92 && c <= 122)
		{
			c = c - 32;
		}
		group = c;
	}
	

}