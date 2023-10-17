#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//varible
int choose;

//function
void main()
{
	
	cout << "****Menu Select****";
	//cout << "1.1 Add Student"; 
	cout << "1. Update Student";
	//cout << "1.2 Remove Student";
	cout << "2. Search Student";
	//cout << "2.1 Search Student by Name";
	//cout << "2.2 Search Student by ID";
	cout << "3. Sort Student";
	//cout << "3.1 Sort Student by GPA";
	//cout << "3.2 Sort Student by Name";
	cout << "4. Table view Student";
	cout << "5. Export File Control Student";
	cin >> choose;
	switch (choose)
	{
	case 1:
		cout << "Add Student";
		cout << "Remove Student";
		cout << "Exit";
		cin >> choose;
		break;
	case 2:
	case 3:
	case 4:
	case 5:
	default:
		break;
	}
}