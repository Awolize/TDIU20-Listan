#ifndef LIST_H
#define LIST_H

//#include initializer_list 
class List
{

public:
    List();
    ~List();
    List(List const&) // copy
    List & operator=(List const & rhs); //
    List & operator=(List && rhs); //
    List(List && rhs); // move
    List(std::initializer_list<int>); 
    void insert(int value); // tryck in på plats value
    int at(int index) const; // Find på plats
    void remove(int index); // remove
    int size(); // Hur stor är listan
private:
    class Node
    {
    public: 
	Node();
	~Node();
	int data;
	Node(int data, Node* next, Node* prev);
	Node* next;
	Node* prev;
    };
    void clear();
    Node* first;
    Node* end;
};
  
//Free function
    std::ostream & operator<< (std::ostream & D_list);  
#endif
