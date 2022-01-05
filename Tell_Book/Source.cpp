#include <iostream>
#include "TellBook.h"
#include "Menu.h"
using namespace std;


void main()
{
	TellBook * t = new TellBook();
	mainMenu(t);
	

	system("pause");
}