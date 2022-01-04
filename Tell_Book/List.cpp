#include "List.h"

List::List()
{
	for (int i = 0; i < 50; i++)
	{
		list[i] = NULL;
	}
	current = 0;
}

bool List::Insert(Person p)
{
	try
	{
		if (current < 50)
		{
			list[current++] = new Person(p);
		}
	}
	catch(const exception& e)
	{
		return false;
	}
	return true;
	
}

void List::Display(void (*func)(Person* []))
{
	Person* temp[50];
	for (int i = 0; i < 50; i++)
	{
		temp[i] = list[i];
	}

	func(temp);

}