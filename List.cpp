#include "List.h"
#include "Exception.h"

Node::Node() : info(), next(NULL) {}
Node::Node(student _info) : info(_info), next(NULL) {}

List::List() : head(NULL), size(0) {}

void List::push(student _info)
{
	if (head == NULL)
	{
		Node* elem = new Node(_info);
		head = new Node(_info);
		elem->next = head;
		head = elem;
		size++;
	}
	else
	{
		Node* temp = head;
		int count = 0;
		while (count < size - 1)
		{
			temp = temp->next;
			count++;
		}
		temp->next = new Node(_info);
		temp->next->next = head;
		size++;
	}
}

void List::pop()
{
	if (size == 0)
		throw Exception();
	Node* temp = head;
	head = head->next;
	delete temp;
	size--;
	Node* tp = head;
	int count = 0;
	while (count < size - 1)
	{
		tp = tp->next;
		count++;
	}
	tp->next = head;
}

Node* List::get_node()
{
	return head;
}

int List::get_size()
{
	return size;
}

void List::show()
{
	if (size == 0)
		throw Exception();
	Node* temp = head;
	int count = 0;
	while (count < size)
	{
		cout << "   " << temp->info;
		temp = temp->next;
		count++;
	}
}

ostream& operator<<(ostream& put, const Node& node)
{
	put << node.info;
	return put;
}


Iterator::Iterator(List* elem) : tmp(0)//çäåñü tmp - òåêóùèé ýëåìåíò
{
	node = elem->get_node();
	size = elem->get_size();
}

void Iterator::begin()
{
	if (size == 0)
		throw Exception();
	if (tmp != 0)
	{
		while (tmp < size)
		{
			tmp++;
			node = node->next;
		}
		tmp = 0;
	}
}

ostream& operator<<(ostream& put, const Iterator& I)
{
	put << I.node;
	return put;
}

void Iterator::search(student _info)
{
	if (size == 0)
		throw Exception();
	int count = 0;
	while (count < size)
	{
		if (_info == node->info)
		{
			cout << _info << endl << "Found!" << endl;
		}
		if (tmp == size - 1)
		{
			tmp = 0;
		}
		else
		{
			tmp++;
		}
		node = node->next;
		count++;

	}
	cout << endl << "Nothing is found!" << endl;
}

Iterator& Iterator:: operator ++()
{
	if (size == 0)
		throw Exception();
	if (size == 1)
		tmp = 0;
	else
		tmp++;
	node = node->next;
	return *this;
}

student Iterator:: operator *()
{
	return node->info;
}

void Iterator:: operator = (student _info)
{
	if (size == 0)
		throw Exception();
	node->info = _info;
}

Iterator& Iterator:: operator[](int ElemIndex)
{
	if (size == 0)
		throw Exception();
	Node* temp = node;
	while (1)
	{
		if (tmp == ElemIndex)
		{
			node = temp;
			return *this;
		}
		temp = temp->next;
		if (tmp == size - 1)
			tmp = 0;
		else
			tmp++;
	}
}

void Iterator::ShellSort()
{
	if (size == 0)
		throw Exception();
	int gap, i, j;
	student temp;
	for (gap = size / 2; gap > 0; gap /= 2)
		for (i = gap; i < size; i++)
			for (j = i - gap; j >= 0 && (*this)[j].node->info > (*this)[j + gap].node->info; j -= gap)
			{
				temp = (*this)[j].node->info;
				(*this)[j].node->info = (*this)[j + gap].node->info;
				(*this)[j + gap].node->info = temp;
			}
}

void Iterator::NewShellSort()
{
	if (size == 0)
		throw Exception();
	int gap, i, j;
	student temp;
	for (gap = size / 2; gap > 0; gap /= 2)
		for (i = gap; i < size; i++)
			for (j = i - gap; j >= 0 && (*this)[j].node->info.get_name() > (*this)[j + gap].node->info.get_name() && (*this)[j].node->info.get_money() > (*this)[j + gap].node->info.get_rating(); j -= gap)
			{
				temp = (*this)[j].node->info;
				(*this)[j].node->info = (*this)[j + gap].node->info;
				(*this)[j + gap].node->info = temp;
			}
}
