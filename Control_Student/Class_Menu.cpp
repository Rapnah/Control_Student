#include "Class_Menu.h"
#include <string.h>
#include <algorithm>
#include <fstream>

using namespace std;

#define SHOW_INFO(index, list_student)\
	cout << "\ID\t NAME\t\t GENDER\t DATE OF BRITH\t\t\t GPA\t\n";\
	for (int index = 0; index < list_student.size(); index++)\
		{\
			cout << "\t" << list_student[index].getID() << "\t\t"<< list_student[index].getName() << "\t\t\t" << list_student[index].getBirth() << "\t" << list_student[index].getGPA() ;\
		}\
	cout << "\n";

int Menu::checkexit(const char* str)// function for exit in menu
{
	if ((strcmp(((const char*)"EXIT"),str) == 0)|| (strcmp(((const char*)"Exit"),str) == 0))
	{
		return 1;
	}
	return 0;
}

int Menu::checkNum(const char* str)// checking number in menu
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (isdigit(str[i]) == 0)// check in str have character is dicimal digit
		{
			return 0;
		}
	}
	return 1;
}

void Menu::showlistmenu()
{
	cout << "****Menu Select****\n";
	cout << "1. Update Student\n";
	cout << "2. Search Student\n";
	cout << "3. Sort Student\n";
	cout << "4. Table view Student\n";
	cout << "5. Export File Control Student\n";
	cout << "Using \"Exit\" or \"EXIT\" for exit\t";
}

void Menu::addstudent()
{
	student sv;
	char scanf_str[50];
	//char gender[20];
	double mark = 0.0;
	uint8_t day = 0, month = 0, year = 0;
	while (1)
	{
		cout << "Add Name:\t";
		cin >> scanf_str;
		sv.setName(scanf_str);
		if (checkexit(scanf_str) == 1) { return; }

		do
		{
			cout << "\nAdd Gender:\t";
			cin >> scanf_str;
			sv.setGender(scanf_str);
			if (checkexit(scanf_str) == 1) { return; }
		} while (_checkgender(scanf_str) == 0);

		cout << "Add Day of Brith\n";
		cout << "Add Day:\t";
		cin >> day;//3 v
		cout << "Add Month:\t";
		cin >> month;
		cout << "Add Year:\t";
		cin >> year;
		sv.setBirth(day,month,year);
		if (checkexit(scanf_str) == 1) { return; }

		cout << "Add GPA:\t";
		cin >> mark;
		sv.setGPA(mark);
		if (checkexit(scanf_str) == 1) { return; }

		Menu::_num_student++;
		sv.setID(Menu::_num_student);
		Menu::_list_student.push_back(sv);
		cout << "Add Student Success.\n";
	}
}

void Menu::removestudent()
{
	uint8_t clear_yet = 0;
	uint8_t id = 0;
	uint8_t new_ID = 0;
	if (_list_student.empty())
	{
		cout << "No Data in the list.\n";
		return;
	}
	while (1)
	{
		cout << "Input ID for remove: ";
		cin >> id;

			for (int i = 0; i < _list_student.size(); i++)
			{
				if (_list_student[i].getID() == id)
				{
					cout << "Erase Student ID " << _list_student[i].getID();
					_list_student.erase(_list_student.begin()+i);
					_num_student--;
					clear_yet = 1;
				}
				if (clear_yet == 1)
				{
					new_ID = _list_student[i].getID() - 1;
					_list_student[i].setID(new_ID);//test function
				}
				if (clear_yet == 0)
				{
					cout << "Wrong ID\n";
				}
			}
	}
}

void Menu::updatestudent()//search ID update name,birth,gpa,gender 
{
	static student sv; // using id in static class Student
	uint8_t index = 0;
	uint8_t month = 0, day = 0 , year = 0;
	uint8_t id = 0;
	double gpa = 0.0;
	char gender[20];
	uint8_t check_id = 0;
	char scanf_str[50];
	int choose = 0;
	//check table if empty print no student
	if (_list_student.empty())
	{
		cout << "List student is empty";
		return;
	}
	while (1) // loop check id and update student
	{
		//check ID input
		if (check_id == 0)
		{
			cout << "Input ID for update: ";
			cin >> id;

			for (int i = 0; i < _list_student.size(); i++)
			{
				if (_list_student[i].getID() == id)
				{
					sv = _list_student[i];
					index = i;
					check_id = 1;
				}
			}

			if (check_id == 0)
			{
				cout << "ID hadn't used";
			}
		}
		else if (check_id == 1)
		{
			cout << "***List Update***\n";
			cout << "1. Update Name\n";
			cout << "2. Update Gender\n";
			cout << "3. Update Birth\n";
			cout << "4. Update GPA\n";
			cout << "5. Done Update\n";
			cout << "Using \"Exit\" or \"EXIT\" for exit\t\t";
			cout << "Input: ";
			cin >> choose;

			switch (choose)
			{
			case 1:
				cout << "Input new name:\t";
				cin >> scanf_str;
				sv.setName(scanf_str);
				break;
			case 2:
				cout << "Input new Gender:\t";
				cin >> gender;
				_checkgender(gender);
				sv.setGender(gender);
				break;
			case 3:
				cout << "Input new Birth:\n";
				cout << "Input new Day:\t";
				cin >> day;
				cout << "\nInput new Month:\t";
				cin >> month;
				cout << "\nInput new Year:\t";
				cin >> year;
				sv.setBirth(day, month, year);
				break;
			case 4:
				cout << "\nInput new GPA:\t";
				cin >> gpa;
				sv.setGPA(gpa);
				break;
			case 5:
				cout << "\nDone update for student.\n"<<sv.getID();
				check_id = 0;
				_list_student[index] = sv;
				break;
			default:
				break;
			}

		}
	}
}

void Menu::searchstudentbyname()
{
	uint8_t check_name = 0;
	char scanf_char[50];
	cout << "Input Name:\t";
	cin >> scanf_char;
	for (int i = 0; i < _list_student.size(); i++)
	{
		if (strcmp(_list_student[i].getName(), (const char*)scanf_char) == 0)
		{
			cout << "ID\t Name\t\t Gender\t Date of Birth\t\t\t GPA\t\n";
			cout << "\t" << _list_student[i].getID() << "\t\t" << _list_student[i].getGender() << "\t\t\t" << _list_student[i].getBirth() << "\t\n" << _list_student[i].getGPA();
			check_name = 1;
		}
	}
	if (check_name == 0)
		cout << "Name isn't in list.\n";
}

void Menu::searchstudentbygpa()
{
	uint8_t check_GPA = 0;
	double gpa = 0.0;
	cout << "Input GPA:\t";
	cin >> gpa;
	for (int i = 0; i < _list_student.size(); i++)
	{
		if (_list_student[i].getGPA() == gpa)
		{
			cout << "ID\t Name\t\t Gender\t Date of Birth\t\t\t GPA\t\n";
			cout << "\t" << _list_student[i].getID() << "\t\t" << _list_student[i].getGender() << "\t\t\t" << _list_student[i].getBirth() << "\t\n" << _list_student[i].getGPA();
			check_GPA = 1;
		}
	}
	if (check_GPA == 0)
		cout << "GPA isn't in list.\n";
}

void Menu::sortstudentbyname()//find way use sort in lib
{
	if (_list_student.empty())
	{
		cout << "List didn't cerate";
		return;
	}
	vector<student> list_sortbyname;
	list_sortbyname = _list_student;
	student sv;
	for (int i = 0; i < list_sortbyname.size() - 1; i++) 
	{ 
		for (int j = i + 1; j < list_sortbyname.size(); j++) 
		{ 
			if (strcmp(list_sortbyname[i].getName(), list_sortbyname[j].getName()) > 0)
			{
				sv = list_sortbyname[i];
				list_sortbyname[i] = list_sortbyname[j];
				list_sortbyname[j] = sv;
			}
		}
	}
	SHOW_INFO(index, list_sortbyname);
}

void Menu::sortstudentbygpa()
{
	if(_list_student.empty())
	{
		cout << "List didn't cerate";
		return;
	}
	vector<student> list_sortbygpa;
	list_sortbygpa = _list_student;
	student sv;
	for (int i = 0; i < list_sortbygpa.size() - 1; i++)
	{
		for (int j = i + 1; j < list_sortbygpa.size(); j++)
		{
			if (list_sortbygpa[i].getGPA() > list_sortbygpa[j].getGPA())
			{
				sv = list_sortbygpa[i];
				list_sortbygpa[i] = list_sortbygpa[j];
				list_sortbygpa[j] = sv;
			}
		}
	}
	SHOW_INFO(index, list_sortbygpa);
}

void Menu::showliststudent()
{
	cout << "\ID\tNAME\t\tGENDER\tDATE OF BRITH\tGPA\t\n"; \
		for (int index = 0; index < _list_student.size(); index++)\
		{\
			cout << "\t" << _list_student[index].getID() << "\t\t" << _list_student[index].getName() << "\t\t\t" << _list_student[index].getBirth() << "\t" << _list_student[index].getGPA(); \
		}\
			cout << "\n";
}

void Menu::exportlist()
{
	vector<student> list_exportstudent;
	list_exportstudent = _list_student;
	ofstream liststudent;
	liststudent.open("student.txt");
	liststudent << "\ID\t NAME\t\t GENDER\t DATE OF BRITH\t\t\t GPA\t\n"; \
		for (int index = 0; index < list_exportstudent.size(); index++)\
		{\
			cout << "\t" << list_exportstudent[index].getID() << "\t\t" << list_exportstudent[index].getName() << "\t\t\t" << list_exportstudent[index].getBirth() << "\t" << list_exportstudent[index].getGPA(); \
		}\
			cout << "\n";
	liststudent.close();
}

int Menu::_checkgender(const char* gender)// definr input only male,female,other
{
	if ((strcmp((const char*)"Male",gender)!=0) && (strcmp((const char*)"Female",gender)!=0) && (strcmp((const char*)"Other",gender)!=0))
	{
		std::cout << "You can input Male/Female or Other !!";
		return 0;
	}
	else
	{
		return 1;
	}
}

int Menu::_checkgpa(uint8_t _gpa) // check number input in range.
{
	if (_gpa < 0.0 || _gpa > 4.0)
	{
		std::cout << "Error Type !! Please Type 0.0 to 4.0";
		return -1;
	}
	return _gpa;
}

	