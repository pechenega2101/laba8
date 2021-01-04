#pragma once
#include <iostream>
#include "student.h"
using namespace std;

class Node
{
public:
	student info;
	Node* next;
	Node();
	Node(student _info);

};

//class Exception
//{
//public:
//	Exception(const stList errorMessage = "Something wrong") : m_ErrorMessage(errorMessage) { }
//	friend ostream& operator<< (ostream& out, const Exception& ex)
//	{
//		out << ex.m_ErrorMessage << '\n'; return out;
//	}
//private:
//	stList m_ErrorMessage;
//};


class List
{
	Node* head;
	int size;
public:
	List();
	void push(student _info);
	void pop();
	void show();
	int get_size();
	Node* get_node();
	friend ostream& operator<<(ostream& put, const Node& inf);
};



#pragma once
#include<iostream>
#include "student.h"
#include "List.h"
class Iterator
{
	Node* node;
	int size;
	int tmp;
public:
	friend List;
	friend ostream& operator<<(ostream& put, const Iterator& I);
	Iterator(List* elem);
	void begin();
	Iterator& operator ++();
	student operator*();
	void operator = (student _info);
	void search(student _info);
	Iterator& operator[](int ElemIndex);
	void ShellSort();
	void NewShellSort();
};


