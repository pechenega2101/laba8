#include "student.h"
#include "Exception.h"

ostream& operator<<(ostream& out, const student& student)
{
	try {
		if (student.name == " ")
		{
			throw 2;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
	}
	out << student.name << " " << student.group << " " << student.rating << " " << student.money << endl;
	return out;
}

istream& operator>>(istream& in, student& student)
{
	in >> student.name;
	in >> student.group;
	in >> student.rating;
	in >> student.money;
	return in;
}

bool operator==(student num1, student num2) {
	if (num1.get_name() == num2.get_name() && num1.get_group() == num2.get_group() && num1.get_rating() == num2.get_rating() &&
		num1.get_money() == num2.get_money()) {
		return true;
	}
	else {
		return false;
	}
}


string student::get_name() {
	return this->name;
}
int student::get_group() {
	return this->group;
}
int student::get_rating() {
	return this->rating;
}
int student::get_money() {
	return this->money;
}

void student::set_name(string temp) {
	this->name = temp;
}
void student::set_group(int temp) {
	this->group = temp;
}
void student::set_rating(int temp) {
	this->rating = temp;
}
void student::set_money(int temp) {
	this->money = temp;
}

bool operator >(const student a, const student b)
{
	if (a.money > b.money)
		return true;
	else
		return false;
}

bool operator <(const student a, const student b)
{
	if (a.money < b.money)
		return true;
	else
		return false;
}
