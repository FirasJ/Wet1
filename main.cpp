/*
 * main.cpp
 *
 *  Created on: Nov 24, 2014
 *      Author: Firas
 */

#include <iostream>

#include "iDroid.h"
#include "list.h"
#include "tree.h"

class printDobule {
public:
	void operator()(double x) {
		std::cout << x << std::endl;
	}
};

void print(double x) {
	std::cout << x << " ";
}

template<class T>
class TreeSize {
public:
	size_t counter;
	TreeSize() : counter(0) {}
	void operator()(const T& t) {
		++counter;
	}
};

template<class T>
size_t treeSize(const Tree<T>& tree) {
	TreeSize<T> size;
	tree.inOrder(size);
	return size.counter;
}

int mainDroid() {
	iDroid x;
	return 0;
}

int mainTree() {
	Tree<double> tree;
//	int x[10];
	for (int i = 0; i < 10; ++i) {
		//std::cin >> x[i];
		//tree.insert(x[i]);
		tree.insert(i);
		tree.inOrder(print);
		std::cout << std::endl;
	}
	std::cout << treeSize(tree) << std::endl;
	for (int i = 0; i < 10; ++i) {
//		tree.remove(x[i]);
		tree.remove(i);
		tree.inOrder(print);
		std::cout << std::endl;
		//std::cout << tree.find(i)->getData() << std::endl;
	}
	//tree.preOrder(print);
	//tree.inOrder(print);
	return 0;
}

int mainList() {
	List<int> list;
	for (int i = 0; i < 5; ++i) {
		int x;
		std::cin >> x;
		std::cout << list.empty();
		list.insert(x);
		std::cout << x << "inserted,";

		for (List<int>::Iterator it = list.begin(); it != list.end(); ++it)
			std::cout << *it << ",";
		std::cout << list.empty();
		std::cout << std::endl << "Found: " << *list.find(x) << "Size: "
				<< list.size();
	}
	List<int> list3(list);
	List<int> list2 = list;
	return 0;
}
