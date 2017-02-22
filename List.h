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
    List(List const&);							// copy
    List & operator=(List const & rhs);			//
    List & operator=(List && rhs);				//
    List(List && rhs);							// move
    List(std::initializer_list<int> const);
    void insert(int value);						// tryck in på plats value
    int at(int index) const;					// Find på plats
    void remove(int index);						// remove
    int size() const;							// Hur stor är listan
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
    void hidden_insert(int value);
    bool empty();
    void clear();
    Node* first;
    Node* end();
};

//Free function 
//  std::ostream & operator<< (std::ostream & D_list);  
#endif

