#include "TellBook.h"

TellBook::TellBook() {

}

void TellBook::Delete(Person p)
{
	int index = Search(p);

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