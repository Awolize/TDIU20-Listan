// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <initializer_list>
#include "List.h"


using namespace std;

int main()
{
    List t{};
    t.insert(8);
    t.insert(7);
    t.insert(3);
    t.insert(4);
    t.insert(2);
    t.insert(8);
    t.insert(7);

    cout << "Size of list: " << t.size() << endl;
    cout << endl;
    cout << "List: " << endl;
    for (int a{0}; a < t.size(); a++) {
	cout << t.at(a) << endl;
    }
    cout << endl;
    return 0;
}
