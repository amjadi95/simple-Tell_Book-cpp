#pragma once
#include <iostream>
#include "TellBook.h"
using namespace std;


void display(Person* p[])
{
	cout << "\n\n\n";

	for (int i = 0; i < 3; i++)
	{
		if (p[i] != NULL)
		{
			cout << p[i]->firstName << "\t" << p[i]->lastName << "\t" << p[i]->phoneNumber << "\n\n";
		}

	}
}
void insertMenu(TellBook* t)
{
	system("cls");

	Person p;
	cout << "\n ENTER FIRST NAME :";
	cin >> p.firstName;

	cout << "\n ENTER LAST NAME :";
	cin >> p.lastName;

	cout << "\n ENTER PHONE NUMBER :";
	cin >> p.phoneNumber;

	bool b = t->Insert(p);

	if (b)
	{
		cout << "\n\n INSERTION DONE!";
	}
	else {
		cout << "\n\n INSERTION FAILED!!!";
	}

	cout << "\n\n";

	system("pause");
}

void deleteMenu(TellBook* t)
{
	system("cls");

	Person p;

	cout << "\n ENTER LAST NAME :";
	cin >> p.lastName;

	cout << "\n ENTER PHONE NUMBER :";
	cin >> p.phoneNumber;

	Person* temp = t->Delete(p);

	if (temp != NULL)
	{
		cout << "\n\n " << temp->firstName << "  " << temp->lastName << "  " << temp->phoneNumber << "\n";
		cout << "\n RECORD HAS BEEN DELETED!";
	}
	else {
		cout << "\n\n DELETION FAILED!!!";
	}

	cout << "\n\n";

	system("pause");
}

void searchMenu(TellBook* t)
{
	system("cls");

	Person p;
	char c;
	cout << "\n\n 1)BY LAST NAME \n";
	cout << "\n\n 2)BY FIRST NAME\n";
	cout << "\n\n 0)BACK TO MAIN MENU \n";
	cin >> c;
	while (1)
	{
		switch (c)
		{
		case '1':
		{
			cout << "\n Enter LAST NAME :";
			cin >> p.lastName;
			break;
		}
		case '2':
		{
			cout << "\n Enter FIRST NAME :";
			cin >> p.firstName;
			break;
		}
		case '0':
		{
			return;
		}
		default:

		}

		List * l = t->Search(p);

		if (l->Count() != 0)
		{
			cout << "\n\n\n";
			l->Display(display);
		}
		else {
			cout << "\n\n NO RECORD FOUND!!!";
		}

	}



	cout << "\n\n";

	system("pause");
}

void updateMenu(TellBook* t)
{
	system("cls");

	Person p;
	cout << "\n\n ENTER FIRST NAME :";
	cin >> p.firstName;

	cout << "\n ENTER LAST NAME :";
	cin >> p.lastName;

	int index = t->Search(p);


}


void mainMenu(TellBook* t)
{
	while (1)
	{
		char c;
		system("cls");

		cout << "\n 1)INSERT \n";
		cout << "\n 2)DELETE \n";
		cout << "\n 3)UPDATE \n";
		cout << "\n 4)SEARCH \n";
		cout << "\n 5)DISPLAY \n";
		cout << "\n 0)Exit \n";

		cin >> c;

		switch (c)
		{
		case '1':
		{
			insertMenu(t);
		}
		case '2':
		{
			deleteMenu(t);
		}
		case '3':
		{
			updateMenu(t);
		}
		case '4':
		{
			searchMenu(t);
		}
		case '5':
		{
			t->Display(display);
		}
		case '0':
		{
			return;
		}
		default:
		{

		}
		}
	}

}
