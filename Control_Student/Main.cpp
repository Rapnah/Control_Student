#include <iostream>
#include "Class_Student.h"
#include "Class_Menu.h"

using namespace std;

//variable
int choose;

//function
int main()
{
	Menu mm;
	do
	{
		mm.showlistmenu();
		cin >> choose;
		switch (choose)
		{
		case 1:
			do
			{
				cout << "1. Add Student\n";
				cout << "2. Remove Student\n";
				cout << "3. Update Student\n";
				cout << "Using \"Exit\" or \"EXIT\" for exit\n";
				cin >> choose;
				switch (choose)
				{
				case 1:
					mm.addstudent();
					break;
				case 2:
					mm.removestudent();
					break;
				case 3:
					mm.updatestudent();
				default:
					break;
				}
			} while (choose != 4);
			break;
		case 2:
			do
			{
				cout << "1. Search Student by Name\n";
				cout << "2. Search Student by GPA\n";
				cout << "3. Exit\n";
				cin >> choose;
				switch (choose)
				{
				case 1:
					mm.searchstudentbyname();
					break;
				case 2:
					mm.searchstudentbygpa();
					break;
				default:
					break;
				}
			} while (choose != 3);
			break;
		case 3:
			do
			{
				cout << "1. Sort Student by GPA\n";
				cout << "2. Sort Student by Name\n";
				cout << "3. Exit\n";
				cin >> choose;
				switch (choose)
				{
				case 1:
					mm.sortstudentbygpa();
					break;
				case 2:
					mm.sortstudentbyname();
					break;
				default:
					break;
				}
			} while (choose != 3);
		case 4:
			mm.showliststudent();
			break;
		case 5:
			mm.exportlist();
			break;
		default:
			break;
		}
	} while (choose != 0);
}
