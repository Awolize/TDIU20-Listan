#include "stdafx.h"
#include "List.h"
#include <iostream>

using namespace std;

List::List() :first{ nullptr }
{
	cout << "Object is being created" << endl;
}

List::~List()
{
	cout << "Object is being deleted" << endl;
	clear();
}

List::List(List const & l) :first{ clone(l.first) }
{
}

void List::insert(int i)
{
	first = new Node{ i, nullptr };
}

void List::remove(int index)
{
    // prev kopplas om till next
    Node(data.prev, prev.next, next.prev); // uuuh
}

List & List::operator=(List const & rhs)
{
	List copy{ rhs };
	swap(first, copy.first);
	return *this;
}

List & List::operator=(List && rhs)
{
	swap(first, rhs.first);
	return *this;
	// TODO: insert return statement here
}

List::List(List && l) :first{ l.first }
{
	l.first = nullptr;
}

List::List(initializer_list<int> li) : first{}
{
	for (int i : li)
	{
	    insert(li);
	}
}

void List::clear()
{
}

List::Node::Node(int d, Node * n)
{
}
