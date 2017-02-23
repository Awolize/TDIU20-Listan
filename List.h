#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <vector>
#include <initializer_list>
//#include initializer_list valgrind a.out
//skapa egna testfall/mainprogram, allt måste testas
class List
{
public:
    List();
    ~List();
    List(List const &);							// copy, finished (List l{ t };)
    List & operator=(List const & rhs);				// copy, finished (b = c;)
    List & operator=(List && rhs);				// Cut
    List(List && rhs);							// move
    List(std::initializer_list<int> const);		// insert vektor of int
    void insert(int value);						// tryck in på plats value, finished
    int at(int index) const;					// Find på plats, finished
    void remove(int index);						// remove, finished
    int size() const;							// Hur stor är listan, finished
private:
    class Node
    {
    public:
	Node();
	~Node();
	Node(int);
	Node(int data, Node* next);
	Node(int data, Node* next, Node* prev);
	int data;
	Node* next;
	Node* prev;
    };
    void clear();
    void hidden_insert(int value);
    bool empty();
    Node* first;
    Node* end();
};
#endif
