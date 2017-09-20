#include <iostream>
#include "skiplist.hpp"

using namespace std;

int main() {
	SkipList::SkipList<double> *a = new SkipList::SkipList<double>();
	a->insert(1.0);
	a->print();
	cout << endl;
	cout << a->search(2.0) << endl;
	a->print();
	cout << endl;
	cout << a->search(1.0) << endl;
	a->print();
	cout << endl;
	a->drop(1.0);
	a->print();
	cout << endl;
	cout << a->search(1.0) << endl;
	a->print();
	cout << endl;
	return 0;
}
