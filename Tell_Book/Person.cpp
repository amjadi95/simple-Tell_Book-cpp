#include "Person.h"


Person::Person()
{
	firstName = "";
	lastName = "";
	phoneNumber = "";
}
Person::Person(string fname, string lname, string number)
{
	firstName = fname;
	lastName = lname;
	phoneNumber = number;

}