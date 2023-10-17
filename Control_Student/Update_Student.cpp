#include "Update_Student.h"

void Student::setID(uint8_t _id)
{
	this->_id = _id;
}

void Student::setName(const char* _name)
{
	strcpy(this->_name, _name);
}

void Student::setBrith(uint8_t _day, uint8_t _month, uint8_t _year)
{
}

void Student::setGender(const char* _gender)
{
}

void Student::setGPA(double _GPA)
{
}


