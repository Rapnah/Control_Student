#include "Class_Menu.h"

using namespace std;

#define SHOW_INFO(index, list_student)\
	cout << "\ID\t NAME\t\t GENDER\t DATE OF BRITH\t\t\t GPA\t\n";\
	for (int index = 0; index < list_student.size(); index++)\
		{\
			cout << "\t" << list_student[index].getID() << "\t\t"<< list_student[index].getName() << "\t\t\t" << list_student[index].getBrith() << "\t" << list_student[index].getGPA() ;\
		}\
	cout << "\n";

//#define ENTER_INFO(info,script,statement)\
//	do\
//	{\
//		std::cout << info; \
//		std::cin >> script);\
//		if (checkexit(script)==1)\
//		{\
//			return;\
//		}\
//	} while (statement);

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
	cout << "Using \"Exit\" or \"EXIT\" for exit";
}

void Menu::addstudent()
{
	Student sv;
	char scanf_str[50];
	double mark = 0.0;
	uint8_t day = 0, month = 0, year = 0;
	while (1)
	{
		cout << "Add Name: \n";
		cout << "Using \"Exit\" or \"EXIT\" for exit\n";
		cin >> scanf_str;
		sv.setName(scanf_str);

		cout << "Add Gender: \n";
		cout << "Using \"Exit\" or \"EXIT\" for exit\n";
		cin >> scanf_str;
		sv.setGender(scanf_str);

		cout << "Add Day of Brith \n";
		cout << "Using \"Exit\" or \"EXIT\" for exit\n";
		cout << "Add Day: \n";
		cin >> day;//3 v
		cout << "Add Month: \n";
		cin >> month;
		cout << "Add Year: \n";
		cin >> year;
		sv.setBrith(day,month,year);

		cout << "Add GPA: \n";
		cout << "Using \"Exit\" or \"EXIT\" for exit\n";
		cin >> mark;
		sv.setGPA(mark);

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
					_list_student[new_ID].getID();//test function
				}
				if (clear_yet == 0)
				{
					cout << "Wrong ID\n";
				}
			}
	}
}

void Menu::updatestudent()
{
}

void Menu::searchstudentbyname()
{
}

void Menu::searchstudentbygpa()
{
}

void Menu::sortstudentbyname()
{
}

void Menu::sortstudentbygpa()
{
}

void Menu::showliststudent()
{
}

void Menu::exportlist()
{

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
