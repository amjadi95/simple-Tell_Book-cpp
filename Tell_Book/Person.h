#pragma once
#include <string>
using namespace std;

class Person
{
public:
	string firstName;
	string lastName;
	string phoneNumber;
	char gender;
	char group;
	Person();
	Person(string,string,string,bool);
};
