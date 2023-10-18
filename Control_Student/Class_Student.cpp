#include "Class_Student.h" 

void Student::setID(uint8_t _id)
{
	this->_id = _id;
}

void Student::setName(const char* _name)
{
	strcpy_s(this->_name, _name);
}

void Student::setBrith(uint8_t _day, uint8_t _month, uint8_t _year)
{
	this->_day = _day;
	this->_month = _month;
	this->_year = _year;
}

void Student::setGender(const char* _gender)
{
	strcpy_s(this->_gender, _gender);
}

void Student::getGPA(double _GPA)
{
	this->_GPA = _GPA;
}

uint8_t Student::getID()
{
	return _id;
}

char *Student::getName()
{
	return _name;
}

char* Student::getGender()
{
	return _gender;
}

double Student::getGPA()
{
	return _GPA;
}

uint8_t Student::getBrith()
{
	cout << "" << _day << "/" << _month << "/" << _year;
}
