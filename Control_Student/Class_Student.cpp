#include "Class_student.h" 

void student::setID(uint8_t _id)
{
	this->_id = _id;
}

void student::setName(const char* _name)
{
	strcpy_s(this->_name, _name);
}

void student::setBirth(uint8_t _day, uint8_t _month, uint8_t _year)
{
	this->_day = _day;
	this->_month = _month;
	this->_year = _year;
}

void student::setGender(const char* _gender)
{
	strcpy_s(this->_gender, _gender);
}

void student::setGPA(double _GPA)
{
	this->_GPA = _GPA;
}

uint8_t student::getID()
{
	return _id;
}

char *student::getName()
{
	return _name;
}

char* student::getGender()
{
	return _gender;
}

double student::getGPA()
{
	return _GPA;
}

uint8_t student::getBirth()
{
	cout << "" << _day << "/" << _month << "/" << _year;
	return _day;
	return _month; 
	return _year;
}
