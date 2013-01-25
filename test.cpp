#include <iostream>
#include "dllist.h"

using namespace std;

typedef LinkedList<int> IntList;

int main(int argc, char const *argv[])
{
	
	IntList list;
	list.push_back(10);
	list.push_back(20);
	list.push_front(-20);
	list.push_front(158);
	list.push_back(-1);


	list.print();
	cout << endl << endl;
	cout << "pop_back: " << list.pop_back() << endl;
	cout << "pop_back: " << list.pop_back() << endl;
	cout << endl << endl;

	list.print();
	list.push_back(12);
	list.push_back(16);

	cout << endl << endl;

	list.print();
	cout << "pop_front: " << list.pop_front() << endl;
	cout << "pop_front: " << list.pop_front() << endl;
	cout << endl << endl;

	list.print();

	cout << "at(0)" << list.at(0) << endl;
	cout << "at(2)" << list.at(2) << endl;

	cout << endl << endl;
	list.push_back(11);
	list.push_back(155);
	list.push_back(-199);


	for(IntList::Node iter = list.begin(); !iter.isEnd(); ++iter){
		cout << iter.value() * 10 << endl;
	}

	cout << endl << endl;

	cout << "[0]: " << list[0] << endl;
	list[0] = 11;
	cout << "[0]: " << list[0] << endl;

	cout << endl << endl;

	for(IntList::Node iter = list.begin(); !iter.isEnd(); ++iter){
		cout << iter.value() << endl;
	}

	cout << endl << endl;
	cout << "is empty?: " << list.isEmpty() << endl;
	cout << "size: " << list.size() << endl;

	cout << endl << endl;
	cout << "Inserting " << -1000 << endl;
	list.insert(list.begin(), -1000);
	
	list.print();
	cout << "size: " << list.size() << endl;

	cout << endl << endl;

	cout << "While loop...\n";
	IntList::Node iter = list.begin();
	// This needs work. Consider using a special Node* end pointer
	while(true){
		cout << iter.value() << endl;
		if(iter.isEnd()) break;
		iter++;

	}

	cout << endl << endl;
	list.empty();
	cout << "is empty?: " << list.isEmpty() << endl;
	cout << "size: " << list.size() << endl;

	return 0;
}