#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//varible
int choose;

//function
void main()
{
	do
	{
		cout << "****Menu Select****\n"; 
		cout << "1. Update Student\n";
		cout << "2. Search Student\n";
		cout << "3. Sort Student\n";
		cout << "4. Table view Student\n";
		cout << "5. Export File Control Student\n";
		cin >> choose;
		switch (choose)
		{
		case 1:
			do
			{
				cout << "1. Add Student\n";
				cout << "2. Remove Student\n";
				cout << "3. Exit\n";
				cin >> choose;
			} while (choose != 3);
			break;
		case 2:
			do
			{
				cout << "1. Search Student by Name\n";
				cout << "2. Search Student by ID\n";
				cout << "3. Exit\n";
				cin >> choose;
			} while (choose != 3);
			break;
		case 3:
			do
			{
				cout << "1. Sort Student by GPA\n";
				cout << "2. Sort Student by Name\n";
				cout << "3. Exit\n";
				cin >> choose;
			} while (choose != 3);
		case 4:
		case 5:
		default:
			break;
		}
	} while (choose != 0);
}