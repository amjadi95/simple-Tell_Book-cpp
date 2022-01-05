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
				break;
			}
			
		}
		
		current--;
		return deleted;
	}
}
List* TellBook::Search(Person p)
{
	List* l;
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

int TellBook::SearchOne(Person p)
{
	for (int i = 0;i < 50;i++)
	{
		if (list[i] != NULL)
		{
			if (p.lastName == list[i]->lastName && p.phoneNumber == list[i]->phoneNumber)
			{
				return i;
			}
		}
	}
}