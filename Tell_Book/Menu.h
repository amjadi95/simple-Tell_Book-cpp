#pragma once
#include <iostream>
#include "TellBook.h"
using namespace std;


void display(List<Person>* list)
{
	system("cls");
	cout << "\n\n\n";
	cout << "  group" << "\t" <<
		"gender" << "\t" <<
		"name" << "\t\t" <<
		"famili" << "\t\t" <<
		"mobile" << "\n\n";
	if (list != NULL)
	{
		for (int i = 0; i < list->Count(); i++)
		{
			Person* p = list->getItem(i);
			cout << i + 1 << "_" <<
				p->group << "\t" <<
				p->gender << "\t" <<
				p->firstName << "\t\t" <<
				p->lastName << "\t\t" <<
				p->phoneNumber << "\n\n";
		}

	}
	
}
void insertMenu(TellBook* t)
{
	system("cls");

	string fname, lname, number, gender;
	cout << "\n ENTER FIRST NAME :";
	cin >> fname;

	cout << "\n ENTER LAST NAME :";
	cin >> lname;

	cout << "\n ENTER PHONE NUMBER :";
	cin >> number;

	cout << "\n ENTER GENDER (female=1 , male=0) :";
	cin >> gender;

	bool g = gender == "1" ? 1 : 0;

	Person p(fname, lname, number, g);
	bool b = t->Insert(p);

	if (b)
	{
		cout << "\n\n INSERTION DONE!";
	}
	else {
		cout << "\n\n INSERTION FAILED!!!";
	}

}

void deleteMenu(TellBook* t)
{
	system("cls");


	string lname = "", number = "";
	cout << "\n ENTER LAST NAME :";
	cin >> lname;

	cout << "\n ENTER PHONE NUMBER :";
	cin >> number;

	Person p("", lname, number, 1);

	Person* temp = t->Delete(p);

	if (temp != NULL)
	{
		cout << "\n\n " << temp->firstName << "  " << temp->lastName << "  " << temp->phoneNumber << "\n";
		cout << "\n RECORD HAS BEEN DELETED!";
	}
	else {
		cout << "\n\n  NO RECORD FOUND!!!";
	}


}

void searchMenu(TellBook* t)
{

	while (1)
	{
		system("cls");
		string fname = "", lname = "";
		char c;
		cout << "\n\n 1)BY LAST NAME \n";
		cout << "\n\n 2)BY FIRST NAME\n";
		cout << "\n\n 0)BACK TO MAIN MENU \n\n";
		cout << " >";
		cin >> c;

		switch (c)
		{
		case '1':
		{
			cout << "\n Enter LAST NAME :";
			cin >> fname;
			break;
		}
		case '2':
		{
			cout << "\n Enter FIRST NAME :";
			cin >> lname;
			break;
		}
		case '0':
		{

		}
		default:
		{
			return;
		}
		}
		Person p(fname, lname, "", 1);
		List<Person>* l = t->Search(p);

		if (l->Count() != 0)
		{
			cout << "\n\n\n";
			l->Display(display);
		}
		else {
			cout << "\n\n NO RECORD FOUND!!!";
		}
		cout << "\n\n\n\n";


		system("pause");

	}
}

void updateMenu(TellBook* t)
{
	system("cls");

	string fname = "", lname = "";
	cout << "\n\n ENTER FIRST NAME :";
	cin >> fname;

	cout << "\n ENTER LAST NAME :";
	cin >> lname;

	Person p(fname, lname, "", 1);
	int i = t->SearchOneByName(p);



	if (i >= 0)
	{
		Person old = *t->getItem(i);
		cout << "\n\n " << old.firstName << "  " << old.lastName << "  " << old.phoneNumber << " (old record)\n\n";

		cout << "\n ENTER NEW PHONE NUMBER :";
		string n;
		cin >> n;

		Person* temp = t->Update(p, n);

		if (temp != NULL)
		{
			cout << "\n\n " << temp->firstName << "  " << temp->lastName << "  " << temp->phoneNumber << "\n";
			cout << "\n\n RECORD UPDATED!";
		}
		else {
			cout << "\n\n UPDATE FAILED!!!";
		}
	}
	else
	{
		cout << "\n\n NO RECORD FOUND!!!";
	}


}


void mainMenu()
{
	TellBook* t = new TellBook();

	while (1)
	{
		char c;
		system("cls");
		cout << " >check my Github\n    <https://github.com/amjadi95/simple-Tell_Book-cpp/tree/master/Tell_Book> \n\n";

		cout << "\n  1)INSERT \n";
		cout << "\n  2)DELETE \n";
		cout << "\n  3)UPDATE \n";
		cout << "\n  4)SEARCH \n";
		cout << "\n  5)DISPLAY \n";
		cout << "\n  6)SAVE CHANGES ( to file ) \n";
		cout << "\n  0)Exit \n\n";
		cout << "\n  >";
		cin >> c;

		switch (c)
		{
		case '1':
		{
			insertMenu(t);
			break;
		}
		case '2':
		{
			deleteMenu(t);
			break;
		}
		case '3':
		{
			updateMenu(t);
			break;
		}
		case '4':
		{
			searchMenu(t);
			break;
		}
		case '5':
		{
			t->Display(display);

			break;
		}
		case '6':
		{
			t->Print();

			break;
		}
		case '0':
		{
			return;
		}
		default:
		{

		}
		}



		cout << "\n\n\n\n";


		system("pause");
	}

}
