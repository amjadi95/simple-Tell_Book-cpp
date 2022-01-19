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


bool stringContains(string s1, string s2)
{
	int counter = 0;
	if (s1 != "" && s2 != "" && s2.size() <= s1.size())
	{
		for (int i = 0; i < s1.size(); i++)
		{
			if (s1[i] == s2[0])
			{
				for (int k = 0, j = i; k < s2.size();k++, j++)
				{
					if (j >= s1.size())
					{
						return false;
					}
					if (s2[k] == s1[j])
					{
						counter++;
					}
					else {
						counter = 0;
						break;
					}
				}
				if (counter == s2.size())
				{
					return true;
				}
			}
		}
	}
	return false;
}

TellBook::TellBook() {
	file = new Tell_Book_File("example");
	loadFileData();
}

void TellBook::loadFileData()
{
	List<Person> _list = file->fileRead();

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
	List<Person> l;
	for (int i = 0; i < Count();i++)
	{
		Person p = *list[i];
		l.Insert(p);

	}
	bool success = file->fileWrite(l);

	return success;

};

Person* TellBook::Delete(Person p)
{

	int index = -1;
	Person* deleted = NULL;

	for (int i = 0; i < Count();i++)
	{
		if (list[i]->lastName == p.lastName && list[i]->phoneNumber == p.phoneNumber)
		{

			index = i;
			deleted = list[i];
			break;
		}

	}

	if (index >= 0)
	{
		list[index] = NULL;
		for (int i = index;i < size;i++)
		{
			if (list[i + 1] != NULL && i + 1 < 50)
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
List<Person>* TellBook::Search(Person p)
{
	List<Person>* l = new List<Person>();
	if (p.lastName != "")
	{


		for (int i = 0;i < Count();i++)
		{

			if (stringContains(list[i]->lastName, p.lastName))
			{
				l->Insert(*list[i]);
			}

		}
	}
	else if (p.firstName != "")
	{
		for (int i = 0;i < Count();i++)
		{
			if (list[i] != NULL)
			{
				if (stringContains(list[i]->firstName, p.firstName))
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
	for (int i = 0;i < Count();i++)
	{
		if (p.lastName == list[i]->lastName && p.firstName == list[i]->firstName)
		{
			return i;
		}

	}
	return -1;
}


Person* TellBook::Update(Person p, string number)
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