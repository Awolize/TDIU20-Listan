#include "List.h"
#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

List::List() :first{ nullptr }
{
    cout << "List is being created" << endl;
}

List::~List()
{
    cout << "List is being deleted" << endl;
    //clear();
}

List::List(List const &)
{
}

List & List::operator=(List const & rhs)
{
    // TODO: insert return statement here
    return *this;
}

List & List::operator=(List && rhs)
{
    // TODO: insert return statement here
    return *this;
}

List::List(List && rhs)
{
}

List::List(std::initializer_list<int> const value)
{	
    first = new Node{ 0, nullptr, nullptr };
    for (int i : value)
    {
	insert(i);
    }
}

void List::insert(int value)
{
    hidden_insert(value);
}

int List::at(int index) const
{
    Node *curr = first, *prev = curr;
    for (int i{ 0 }; i < index; i++)
    {
	if (i != size() - 1)
	{
	    prev = curr;
	    curr = (*curr).next;
	}
	if (i == size() - 1)
	{
	    cout << "Error, end of list was reached! ";
	    return 0;
	}
    }

    return (*curr).data;
}

void List::remove(int at)
{
    
    Node *curr = first, *prev = nullptr;
    
    if (at == 0)
    {
	first = (*first).next;
    }
    else if (at == size())
    {
	end = (*end).prev;
	(*end).next = nullptr;		   // kopplar loss den sista Noden
    }
    else if (at > size() || at < 0)
    {
	throw std::invaild_argument("index not found in list");
    }
    else
    {
	for (int i{ 0 }; i < at - 1; i++) {
	    prev = curr;
	    curr = (*curr).next;
	}
	//		Node *rem = (*curr).next;		Delete Lose Node
	(*curr).next = (*(*curr).next).next;
	(*(*(*curr).next).next).prev = curr;
	//		delete rem;
	//		rem = nullptr;
    }
}

int List::size() const
{
    Node *p = first;
    int size{ 0 };
    while (p != nullptr)
    {
	p = (*p).next;
	size++;
    }

    return size;
}

void List::hidden_insert(int value)
{
    Node *p = new Node(value);

    // om listan är tom
    if (empty()) {
	first = p;
    }
    // om ny data är större än den första gamla
    else if ((*first).data >= value) {
	(*p).next = first;
	first = p;
	(*(*p).next).prev = p;
    }
    // om den nya datan måste sorterar in i listan 
    // --------------------- funkar inte atm -----------------------
    else {
	Node *curr = first, *prev = curr;

	while (curr != nullptr) {
	    if ((*curr).data > value)
		break;
	    prev = curr;
	    curr = (*curr).next;
	}

	//		p.next = nullptr;
	//		p.prev = nullptr;
	//		p.data = value;

	if (curr != nullptr) { // search found insert point
	    (*p).next = curr;
	    (*p).prev = (*curr).prev;
	    (*(*curr).prev).next = p;
	    (*curr).prev = p;
	}
	else if (curr == nullptr) {// search did not find insert point
	    (*prev).next = p;
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
    Node *temp = new node();
    temp = end();
    if((*temp).prev != nullptr)
    {
	prev.clear();
    }
    first = (*this).next;
    (*(*this).next).prev
   
}

List::Node * List::end()
{
    Node *curr = first; 
    for (int i{0}; i < (size() -1); i++)
    {
	if (curr = nullptr)
	    break;
	prev = curr;
	curr = (*curr).next;
    }

    return curr;
}

List::Node::Node() :data{ 0 }, next{ nullptr }, prev{ nullptr }
{
}

List::Node::Node(int value) : data{ value }, next{ nullptr }, prev{ nullptr }
{
}

/*
List::Node::~Node()	// skip atm
{
    delete *this;
}

List::Node::Node(int data, Node * next) : data{ data }, next{ next }, prev{ nullptr }
{
}

List::Node::Node(int data, Node * next, Node * prev)
{
}
*/
