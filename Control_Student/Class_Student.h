//Struct with ID, Name,Date of Brith, GPA, Gender.
#include <iostream>
#include <string.h>

using namespace std;

class Student
{
public:
	void setID(uint8_t _id);
	void setName(const char* _name);
	void setBrith(uint8_t _day, uint8_t _month, uint8_t _year);
	void setGender(const char* _gender);
	void getGPA(double _GPA);
	void setGPA(double _GPA);

	uint8_t getID();
	char* getName();
	char* getGender();
	double getGPA();
	uint8_t getBrith();
private:
	uint8_t _id;
	char _name[20];
	char _gender[4];
	double _GPA;
	//date of brith
	uint8_t _day;
	uint8_t _month;
	uint8_t _year;
};