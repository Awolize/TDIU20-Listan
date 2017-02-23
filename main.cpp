// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <initializer_list>
#include "List.h"
using namespace std;

int main()
{
	cout << "________________New test Case:________________ " << endl;
	cout << "Function: 'Insert, size'" << endl;
	List t{};
	t.insert(8);
	t.insert(2);
	t.insert(8);
	t.insert(10);
	t.insert(5);
	t.insert(3);
	cout << "Size of list t: " << t.size() << endl;
	cout << "List: ";
	for (int a{ 0 }; a < t.size(); a++) {
		cout << t.at(a) << " ";
	}
	cout << endl;
	cout << endl;

	cout << "________________New test Case:________________ " << endl;
	cout << "Function: 'Constructor copy'" << endl;
	cout << "l a copy from t." << endl;
	List l{ t };
	cout << "Size of list l: " << l.size() << endl;
	cout << "List: ";
	for (int a{ 0 }; a < l.size(); a++) {
		cout << l.at(a) << " ";
	}
	cout << endl;
	cout << endl;

	cout << "________________New test Case:________________ " << endl;
	cout << "Function: 'Remove'" << endl;

	t.remove(4);

	cout << "Removing index 4." << endl;;
	cout << "Size of list t: " << t.size() << endl;
	cout << "List: ";
	for (int a{ 0 }; a < t.size(); a++) {
		cout << t.at(a) << " ";
	}
	cout << endl;
	cout << endl;

	cout << "________________New test Case:________________ " << endl;
	cout << "Function: 'Swap'" << endl;
	List b{};
	List c{};
	c.insert(3);
	c.insert(4);
	b.insert(1);
	b.insert(2);
	cout << "List b: ";
	for (int a{ 0 }; a < b.size(); a++) {
		cout << b.at(a) << " ";
	}
	cout << endl;
	cout << "List c: ";
	for (int a{ 0 }; a < c.size(); a++) {
		cout << c.at(a) << " ";
	}
	cout << endl;
	b = c;
	cout << "**Swap**" << endl;

	cout << "List b: ";
	for (int a{ 0 }; a < b.size(); a++) {
		cout << b.at(a) << " ";
	}
	cout << endl;
	cout << "List c: ";
	for (int a{ 0 }; a < c.size(); a++) {
		cout << c.at(a) << " ";
	}
	cout << endl;
	cout << endl;
	
	cout << "________________New test Case:________________ " << endl;
	cout << "Function: 'copy and remove the old one'" << endl;
	
	List k{1,2,3};

	cout << "List k: ";
	for (int a{ 0 }; a < k.size(); a++) {
		cout << k.at(a) << " ";
	}
	cout << endl;
	List lhej{std::move(k)};

	cout << "**Move**" << endl;

	cout << "List lhej: ";
	for (int a{ 0 }; a < lhej.size(); a++) {
		cout << lhej.at(a) << " ";
	}
	cout << endl << "Size of List k: " << k.size() << endl;
	cout << "Size of List lhej: " << lhej.size() << endl;
	
	List u{74,7,7,7,7,7,7,7,7,7,7,7,75,3,54,5,654,65,456,45};
	List lhej1{4,5,6,6};
	lhej1 = std::move(u);

	for (int a{ 0 }; a < lhej1.size(); a++) {
		cout << lhej1.at(a) << " ";
	}
	cout << endl << u.size() << endl;
	for (int a{ 0 }; a < u.size(); a++) {
	    cout << u.at(a) << " ";
	}
	cout << endl;
	return 0;
}
