#include "File.h"
#include "student.h"
#include "Exception.h"

File& operator<<(File& file, const char* s)
{
	try {
		if (!file.file.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
	}
	string str = s;
	file.file << str;
	return file;
}

fstream& operator<<(fstream& out, student& student) {
	try {
		if (!out.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
	}
	int a = out.tellg();
	string art_name = student.get_name();
	size_t len1 = art_name.length() + 1;

	int group = student.get_group();
	int rating = student.get_rating();
	int money = student.get_money();

	out.write((char*)(&len1), sizeof(len1));
	out.write((char*)(art_name.c_str()), len1);

	out.write((char*)(&group), sizeof(group));
	out.write((char*)(&rating), sizeof(rating));
	out.write((char*)(&money), sizeof(money));


	return out;
}

File& operator<<(File& file, student& student)
{
	int pos = 0, a = 0, size = 0;
	try {
		if (!file.file.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
	}
	if (file.key == txt) {
		file.file << student.get_name() << " " << student.get_group() << " " << student.get_rating() << " " << student.get_money() << endl;
	}
	else if (file.key == bin) {
		string name = student.get_name();
		size_t len1 = name.length() + 1;

		int group = student.get_group();
		int rating = student.get_rating();
		int money = student.get_money();


		file.file.write((char*)(&len1), sizeof(len1));
		file.file.write((char*)(name.c_str()), len1);


		file.file.write((char*)(&group), sizeof(group));
		file.file.write((char*)(&rating), sizeof(rating));
		file.file.write((char*)(&money), sizeof(money));


	}
	return file;
}

student File::read()
{
	string str;
	student t;
	getline(this->file, str, ' ');
	t.set_name(str);
	getline(this->file, str, ' ');
	t.set_group(stoi(str));
	getline(this->file, str, ' ');
	t.set_rating(stoi(str));
	getline(this->file, str);
	t.set_money(stoi(str));
	return t;
}

ostream& operator<<(ostream& out, File& file)
{
	int a = 0;
	try {
		if (!file.file.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
	}
	if (file.key == txt) {
		string str;
		while (!file.file.eof()) {
			std::getline(file.file, str);
			a = file.file.tellg();
			cout << str << endl;
		}
	}
	else if (file.key == bin) {
		int i = 0;
		int size = 0, step = 0;
		while (i < file.size) {
			int group;
			int rating;
			int money;

			size_t len;

			file.file.read((char*)(&len), sizeof(len));
			char* name = new char[len];

			file.file.read((char*)(name), len);
			name[len - 1] = '\0';

			file.file.read((char*)(&group), sizeof(int));
			file.file.read((char*)(&rating), sizeof(int));
			file.file.read((char*)(&money), sizeof(int));


			cout << name << " " << group << " " << rating << " " << money << endl;

			delete[] name;
			i++;

		}
	}
	return out;
}



void File::edit(int line, student ms[])
{
	this->open("wr");

	int a, b;

	try {
		if (!file.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
		return;
	}
	student tmp;
	if (this->key == txt) {
		string temp;
		for (int i = 0; i < line - 1; i++) {
			std::getline(this->file, temp);
		}
		std::getline(this->file, temp, ' ');
		tmp.set_name(temp);
		std::getline(this->file, temp, ' ');
		tmp.set_group(stoi(temp));
		std::getline(this->file, temp, ' ');
		tmp.set_rating(stoi(temp));
		std::getline(this->file, temp, ' ');
		tmp.set_money(stoi(temp));
	}
	else if (this->key == bin) {
		size_t len;
		for (int i = 0; i < line; i++) {
			this->file.read((char*)(&len), sizeof(len));
			char* n = new char[len];
			string name;
			int group = 0;
			int rating = 0;
			int money = 0;

			this->file.read((char*)(n), len);
			name = n;
			name[len - 1] = '\0';
			this->file.read((char*)(&group), sizeof(int));
			this->file.read((char*)(&rating), sizeof(int));
			this->file.read((char*)(&money), sizeof(int));

			this->file.read((char*)(&len), sizeof(len));
			this->file.read((char*)(n), len);

			tmp.set_name(name);
			tmp.set_group(group);
			tmp.set_rating(rating);
			tmp.set_money(money);
		}
		a = file.tellg();
	}

	cout << "What do you want to change?\n1 - name\n2-group\n3-rating\n4-moneyriction" << endl;
	int choice;
	cin >> choice;
	cout << "Put new data: ";
	switch (choice) {
	case 1: {
		string a;
		rewind(stdin);
		cin >> a;
		tmp.set_name(a);
		break;
	}
	case 2: {
		int a;
		cin >> a;
		tmp.set_group(a);
		break;
	}
	case 3: {
		int a;
		cin >> a;
		tmp.set_rating(a);
		break;
	}
	case 4: {
		int a;
		cin >> a;
		tmp.set_money(a);
		break;
	}

		  a = file.tellg();
		  file.seekg(0, ios_base::end);
		  b = file.tellg();
		  this->file.seekg(0, ios_base::beg);
		  if (this->key == txt) {
			  string temp;
			  for (int i = 0; i < line - 1; i++) {
				  getline(this->file, temp);
			  }
			  int pos = this->file.tellg();
			  this->file.seekg(pos, ios_base::beg);
			  this->file << tmp;
			  return;
		  }
		  else if (this->key == bin) {
			  for (int i = 0; i < line - 1; i++) {

				  size_t len;
				  this->file.read((char*)(&len), sizeof(len));
				  char* n = new char[len];
				  string name;
				  int group = 0;
				  int rating = 0;
				  int money = 0;
				  this->file.read((char*)(n), len);
				  name = n;
				  name[len] = '\0';
				  this->file.read((char*)(&group), sizeof(int));
				  this->file.read((char*)(&rating), sizeof(int));
				  this->file.read((char*)(&money), sizeof(int));
				  this->file.read((char*)(n), len);

				  this->file.read((char*)(&len), sizeof(len));
				  this->file.read((char*)(&n), len);

				  delete[]n;
			  }
			  int pos = this->file.tellg();

			  char* last = new char[b - a];
			  this->file.read((char*)last, b - a);

			  this->close();
			  this->open("w");
			  pos = this->file.tellg();
			  file << tmp;
			  for (int i = 0; i < get_size(); i++) {
				  if (i != line - 1)
					  file << ms[i];
				  else {
					  ms[i].set_name(tmp.get_name());
					  ms[i].set_group(tmp.get_group());
					  ms[i].set_rating(tmp.get_rating());
					  ms[i].set_money(tmp.get_money());

				  }
			  }
		  }

		  this->close();
	}
}


