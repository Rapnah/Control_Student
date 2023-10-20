//Struct with ID, Name,Date of Brith, GPA, Gender.
#pragma once
#include <iostream>
#include <string.h>
#include <cstdint>

using namespace std;

class student
{
public:
	void setID(uint8_t _id);
	void setName(const char* _name);
	void setBirth(uint8_t _day, uint8_t _month, uint8_t _year);
	void setGender(const char* _gender);
	void getGPA(double _GPA);
	void setGPA(double _GPA);

	uint8_t getID();
	char* getName();
	char* getGender();
	double getGPA();
	uint8_t getBirth();
private:
	uint8_t _id;
	char _name[50];
	char _gender[20];
	double _GPA;
	//date of brith
	uint8_t _day;
	uint8_t _month;
	uint8_t _year;
};