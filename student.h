#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class student
{

	private:
		string name;
		int group;
		int rating;
		int money;
	public:
		student() {
			this->name = " ";
			this->group = 10;
			this->rating = 10;
			this->money = 10;
		}
		student(string name, int group, int rating, int money) {
			this->name = name;
			this->group = group;
			this->rating = rating;
			this->money = money;
		}
		friend ostream& operator<<(ostream& out, const student& art);
		friend istream& operator>>(istream& in, student& art);
		friend bool operator==(const student num1, const student num2);

		string get_name();
		int get_group();
		int get_rating();
		int get_money();

		void set_name(string);
		void set_group(int);
		void set_rating(int);
		void set_money(int);


		friend bool operator<(const student t1, const student t2);
		friend bool operator>(const student t1, const student t2);
};

