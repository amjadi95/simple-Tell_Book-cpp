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

void List::Display(void (*func)(Person* []) = NULL)
{
	Person* temp[50];
	for (int i = 0; i < 50; i++)
	{
		temp[i] = list[i];
	}

	if(func != NULL)
		func(temp);

}

Person* List::Update(Person p,string number)
{
	return NULL;

}

Person*  List::Delete(Person p) {

	return NULL;
}
List* List::Search(Person p)
{
	return NULL;
}

int List::Count()
{
	if (current == 0)
		return 0;
	else
		return current + 1;
	
}

List* List::getList()
{
	List* l = new List();
	for (int i = 0; i < 50;i++)
	{
		if (list[i] != NULL)
		{
			l->Insert(*list[i]);
		}
	}
	return l;
}

