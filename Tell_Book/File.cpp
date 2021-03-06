#include "File.h"
#include "List.h"
#include <iostream>

Tell_Book_File::Tell_Book_File(string name)
{
	fileName = name + ".txt";
}

bool Tell_Book_File::fileWrite(List<Person> list)
{
	ofstream fout;
	fout.open(fileName);
	if (!fout.is_open())
	{
		cout << "\n\n ** file can't be open \n\n";
		return false;
	}
	else {
		fout << "group\tsex\tname\tfamili\tmobile\n";
		for (int i = 0; i < list.Count();i++)
		{
			Person* p = list.getItem(i);
			if(p != NULL)
			{
				fout << p->group << "\t" <<
					p->gender << "\t" <<
					p->firstName << "\t" <<
					p->lastName << "\t" <<
					p->phoneNumber << "\n";
			}
			else {
				break;
			}
			
		}
	}
	fout.close();
	cout << "\n\n DATA SAVED SUCCESSFULLY  ( EXAMPLE.TXT ) \n\n\n";
	return true;
}
List<Person> Tell_Book_File::fileRead()
{
	List<Person> _list;

	ifstream fin;
	fin.open(fileName, ios::in);
	if (!fin)
	{
		cout << "\n\n ** file can't be open \n\n";
	}
	else {
		
		string line;
		getline(fin, line);
		while (!fin.eof())
		{
			string fname = "", lname = "", number = "",gender = "",group ="";
			getline(fin, line );
			int  i = 0;
			while (i < line.size())
			{
				if (line[i] != '\t')
				{
					group = group + line[i];
					i++;
				}
				else {
					i++;
					break;
				}
				
			}
			while (i < line.size())
			{
				if (line[i] != '\t')
				{
					gender = gender + line[i];
					i++;
				}
				else {
					i++;
					break;
				}
				
			}
			while (i < line.size())
			{
				if (line[i] != '\t')
				{
					fname = fname+ line[i];
					i++;
				}
				else {
					i++;
					break;
				}
				
			}
			while (i < line.size())
			{
				if (line[i] != '\t')
				{
					lname = lname + line[i];
					i++;
				}
				else {
					i++;
					break;
				}
				

			}
			while (i < line.size())
			{
				if (line[i] != '\n')
				{
					number = number + line[i];
					i++;
				}
				else {
					i++;
					break;
				}
				
			}
			if (line == "")
				break;
			Person p(fname, lname, number, gender == "F" ? 1 : 0);
			_list.Insert(p);
		}
	}
	fin.close();
	return _list;
}
bool Tell_Book_File::fileAppend(Person p)
{
	ofstream fout;
	fout.open(fileName, ios::app);
	if (!fout)
	{
		cout << "\n\n ** file can't be open \n\n";
		return false;
	}
	else {
		fout << p.group << "\t" <<
			p.gender << "\t" <<
			p.firstName << "\t\t" <<
			p.lastName << " \t\t" <<
			p.phoneNumber << "\n";

	}
	fout.close();

	cout << "\n\n\n RECORD ADDED TO FILE SUCCESSFULLY ( EXAMPLE.TXT ) \n\n\n";
	return true;
}