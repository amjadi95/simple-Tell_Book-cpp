#include "TellBook.h"

TellBook::TellBook() {

}

Person* TellBook::Delete(Person p)
{

	int index = -1;
	Person * deleted = NULL;

	for (int i = 0; i < 50;i++)
	{
		if (list[i] != NULL)
		{
			if (list[i]->lastName == p.lastName && list[i]->phoneNumber == p.phoneNumber)
			{

				index = i;
				deleted = list[i];
				break;
			}
		}
	}

	if (index >= 0)
	{
		list[index] = NULL;
		for (int i = index;i < 50;i++)
		{
			if (list[i + 1] != NULL && i+1 < 50)
			{
				Person* x = list[i + 1];
				list[i] = x;
			}
			else {
				list[i] = NULL;
				current--;
				break;
			}
			
		}
	}
	return deleted;
}
List* TellBook::Search(Person p)
{
	List* l = new List();
	if ( p.lastName != "")
	{
		

		for (int i = 0;i < 50;i++)
		{
			if (list[i] != NULL)
			{
				if (p.lastName == list[i]->lastName)
				{
					l->Insert(*list[i]);
				}
			}
		}
	}
	else if ( p.firstName != "")
	{
		for (int i = 0;i < 50;i++)
		{
			if (list[i] != NULL)
			{
				if (p.firstName == list[i]->firstName)
				{
					l->Insert(*list[i]);
				}
			}
		}
	}
	return l;
}

int TellBook::SearchOneByName(Person p)
{
	for (int i = 0;i < 50;i++)
	{
		if (list[i] != NULL)
		{
			if (p.lastName == list[i]->lastName && p.firstName == list[i]->firstName)
			{
				return i;
			}
		}
	}
	return -1;
}


Person* TellBook::Update(Person p,string number)
{
	int index = SearchOneByName(p);

	if (index >= 0)
	{
		try {
			list[index]->phoneNumber = number;
			return new Person(*list[index]);
		}
		catch (const exception& e)
		{
			return NULL;
		}
	}
	return NULL;
	

}