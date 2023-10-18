#pragma once
#include <iostream>
#include <vector>
#include <string.h>
#include <cctype>
#include <sstream>
#include "Class_Student.h"

class Menu
{
public:
	int checkexit(const char* str);
	int checkNum(const char* str);
	void showlistmenu();
	void addstudent();
	void removestudent();
	void updatestudent();
	void searchstudentbyname();
	void searchstudentbygpa();
	void sortstudentbyname();
	void sortstudentbygpa();
	void showliststudent();
	void exportlist();
private:
	std::vector<Student> _list_student;
	static uint8_t  _num_student;
	int _checkgender(const char* gender);
	int _checkgpa(uint8_t _gpa);
};
