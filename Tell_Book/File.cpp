#include "File.h"
#include <iostream>

Tell_Book_File::Tell_Book_File(string name)
{
	fileName = name + ".txt";
}

void Tell_Book_File::fileWrite(List list)
{
	ofstream fout;
	fout.open(fileName, ios::out);
	if (!fout)
	{
		cout << "\n\n ** file can't be open \n\n";
	}
	else {
		fout << "group\tsex\tname\t\tfamili\t\tmobile\n";
		for (int i = 0; i < list.Size();i++)
		{
			Person p = *list.getItem(i);
			fout << p.firstName << "\t" <<
				p.lastName << "\t" <<
				p.phoneNumber << "\t\t" <<
				p.phoneNumber << " \t\t" <<
				p.firstName << "\n";
		}
	}
}
List Tell_Book_File::fileRead()
{
	ifstream fin;
	fin.open(fileName, ios::in);
	if (!fin)
	{
		cout << "\n\n ** file can't be open \n\n";
	}
	else {
		while (!fin.eof())
		{
			string line;
			getline(fin, line);
			cout << line;

		}
	}
}
void Tell_Book_File::fileAppend(Person p)
{
	ofstream fout;
	fout.open(fileName, ios::app);
	if (!fout)
	{
		cout << "\n\n ** file can't be open \n\n";
	}
	else {
		fout << p.firstName << "\t" <<
			p.lastName << "\t" <<
			p.phoneNumber << "\t\t" <<
			p.phoneNumber << " \t\t" <<
			p.firstName << "\n";

	}
}