#include <iostream>
#include <vector>
#include <initializer_list>
#include "List.h"
#include <stdexcept>
using namespace std;


List::List() :first{ nullptr }
{
    cout << " List is being created" << endl;
}

List::~List()
{
    cout << " List is being deleted" << endl;
    clear();
}

List::List(List const & rhs) : first{nullptr}
{
    first = new Node(rhs.first->data);
    Node* rhs_curr = rhs.first->next;
    Node* prev = first;
    while (rhs_curr) {
	prev->next = new Node(rhs_curr->data);
	rhs_curr = rhs_curr->next;
	prev = prev->next;
    }
//Använd inte insert vid kopiering, Det är fruktansvärt innefektivt att traversera hela listan vid varje insättning // fixat
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
}

List::List(List && rhs) : first{ rhs.first }
{
    rhs.first = nullptr;
}

List::List(std::initializer_list<int> const value) : first{}
{
    for (int i : value)
	insert(i);
}

void List::insert(int value)
{
    hidden_insert(value);
}

int List::at(int index) const
{
    Node *curr = first;
    for (int i{ 0 }; i < index; i++)
    {
	if (i != size() - 1)
	{
	    curr->prev = curr;
	    curr = curr->next;
	}
	if (i == size() - 1)
	{
	    cout << "Error, end of list was reached! ";
	    return 0;
	}
    }
    return curr->data;
}

void List::remove(int at)
{
    if (at == 0)
    {
	Node *curr = first->next;
	delete first;
	first = curr;
    }
    else if (at == size() - 1)
    {
	Node *curr = first;
	while (curr->next != nullptr) {
	    curr->prev = curr;
	    curr = curr->next;
	}
	curr->prev->next = nullptr;
	delete curr;
    }
    else if (at > size() || at < 0)
    {
	throw std::invalid_argument("Index not found in list.");
    }
    else
    {
	Node *curr = first, *prev = curr;
	for (int i{ 0 }; i < at; i++) {
	    prev = curr;
	    curr = curr->next;
	}
	curr->next->prev = prev;
	prev->next = curr->next;
	delete curr;
    }
}

int List::size() const
{
    Node *p = first;
    int size{ 0 };
    while (p != nullptr)
    {
	p = p->next;
	size++;
    }

    return size;
}

void List::hidden_insert(int value)
{
    Node *p = new Node(value);

    if (empty()) 
    { 
	first = p;
	p->prev = p;
	p->next = nullptr;
    }
    else if (first->data >= value) 
    {
	p->next = first;
	first->prev = p;
	first = p;
    }
    else 
    {
	Node *curr = first, *prev = curr;

	while (curr != nullptr) 
	{
	    if (curr->data > value)
	    {
		break;
	    }
	    prev = curr;
	    curr = curr->next;
	}

	if (curr != nullptr) 
	{
	    p->next = curr;
	    p->prev = curr->prev;
	    curr->prev->next = p;
	    curr->prev = p;
	}
	else if (curr == nullptr) 
	{
	    prev->next = p;
	    p->prev = prev;
	}
    }
}

bool List::empty()
{
    if (first == nullptr)
	return true;
    else
	return false;
}

void List::clear()
{
    Node *curr = first;
    while (first != nullptr)
    {
	curr->prev = curr;
	curr = curr->next;
	delete first;
	first = curr;
    }
    delete curr;
}

List::Node * List::end()
{
    Node *curr = first;
    for (int i{ 0 }; i < (size() - 1); i++)
    {
	if ((curr = nullptr))
	{
	    break;
	}
	curr->prev = curr;
	curr = curr->next;
    }

    return curr;
}

List::Node::Node() :data{ 0 }, next{ nullptr }, prev{ nullptr }
{
}

List::Node::Node(int value) : data{ value }, next{ nullptr }, prev{ nullptr }
{
}

List::Node::~Node()
{
}

List::Node::Node(int data, Node * next) : data{ data }, next{ next }, prev{ nullptr }
{
}

