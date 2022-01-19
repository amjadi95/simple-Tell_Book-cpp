#include "TellBook.h"
#include <iostream>
#include <Windows.h>

using namespace std;


void set_cursor(int x = 0, int y = 0)
{
	HANDLE handle;
	COORD coordinates;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(handle, coordinates);
}

void loading() {
	system("cls");
	set_cursor(0, 5);
	float progress = 0.0;
	while (progress <= 1.1) {
		int barWidth = 70;
		Sleep(300);
		cout << "[";
		int pos = barWidth * progress;
		for (int i = 0; i < barWidth; i++) {
			if (i < pos)  cout << "=";
			else if (i == pos) cout << ">";
			else cout << " ";
		}
		cout << "] " << int(progress * 100.0) << " %\r";
		cout.flush();

		progress += 0.10; // for demonstration only
	}
}

TellBook::TellBook() {
	file = new Tell_Book_File("example");
	loadFileData();
}

void TellBook::loadFileData()
{
	List _list = file->fileRead();

	loading();

	if (_list.Count() > 0)
	{
		try {
			for (int i = 0; i < _list.Count(); i++)
			{
				Person* p = _list.getItem(i);
				if (p != NULL)
				{
					Insert(*p);
				}
			}
			cout << "\n  ** DATA LOADED SUCCESSFULLY ** \n\n";
		}
		catch (const exception& e) {
			cout << "\n  ** LOADING DATA FROM FILE FAILED \n\n";
		}
		
	}
	else {
		cout << "\n  ** NO DATA FOUND \n\n";
	}
	set_cursor(0, 12);
	system("pause");
}
bool TellBook::Print() {
	List l;
	for (int i = 0; i < size;i++)
	{
		if (list[i] != NULL)
		{
			Person p = *list[i];
			l.Insert(p);
		}

	}
	bool success = file->fileWrite(l);

	return success;

};

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