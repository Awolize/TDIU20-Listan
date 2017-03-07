#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <vector>
#include <initializer_list>
class List
{
public:
    List();
    ~List();
    List(List const &);		       		
    List & operator=(List const & rhs);	       	
    List & operator=(List && rhs);		   
    List(List && rhs);		       		       
    List(std::initializer_list<int> const);		
    void insert(int value);			   
    int at(int index) const;			
    void remove(int index);		    	       	
    int size() const;				       	
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

/*
Bra jobbat med labben!.



Gå igenom cc filen för mina kommentarer och rätta till där det är fel.
end pekarfunktionen
*/
