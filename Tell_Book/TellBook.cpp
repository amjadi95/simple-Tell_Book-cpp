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
int TellBook::Search(Person p)
{
	if ( p.lastName != "")
	{
		for (int i = 0;i < 50;i++)
		{
			if (list[i] != NULL)
			{
				if (p.lastName == list[i]->lastName)
				{
					return i;
				}
			}
		}
	}
	else if ( p.phoneNumber != "")
	{
		for (int i = 0;i < 50;i++)
		{
			if (list[i] != NULL)
			{
				if (p.phoneNumber == list[i]->phoneNumber)
				{
					return i;
				}
			}
		}
	}
	return -1;
}