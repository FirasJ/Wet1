#ifndef _AVLTEST_H
#define _AVLTEST_H

#include <iostream>
#include <iomanip>
#include "TestUtils.h"
#include "AVL.h"

/**
 * Create an AVL tree called 'avl' with Pairs as the data (assumes 'avl' is already defined)
 * The structure of the AVL tree built should allow easy testing
 * of all 4 types of rolling for insertion:
 *
 *                      (40,0)
 *                     /      \
 *               (20,0)        (60,0)
 *              /    \        /      \
 *         (10,0)  (30,0)  (50,0)  (70,0)
 */
#define AVL_BALANCED_SETUP(avl) \
		avl.remove_all(); \
		avl.insert(Pair(40,0)); \
		avl.insert(Pair(20,0)); \
		avl.insert(Pair(60,0)); \
		avl.insert(Pair(10,0)); \
		avl.insert(Pair(30,0)); \
		avl.insert(Pair(50,0)); \
		avl.insert(Pair(70,0));

/**
 * Create an AVL tree called 'fibo' with ints as the data (assumes 'fibo' is already defined)
 * Greate for testing removal.
 * The structure of the AVL tree built should be a fibonacci tree
 * of height 4:
 *                           50
 *                     _____/  \____
 *                   20             80
 *                  /  \           /  \
 *                 10  40        70   100
 *                    /         /     /  \
 *                  30        60    90   120
 *                                        /
 *                                      110
 */
#define AVL_FIBO_SETUP(fibo) \
		fibo.remove_all(); \
		fibo.insert(50); \
		fibo.insert(20); \
		fibo.insert(80); \
		fibo.insert(10); \
		fibo.insert(40); \
		fibo.insert(70); \
		fibo.insert(100); \
		fibo.insert(30); \
		fibo.insert(60); \
		fibo.insert(90); \
		fibo.insert(120); \
		fibo.insert(110);

// Removes the items from the fibo tree, from a to l
#define AVL_REMOVE_FIBO(a,b,c,d,e,f,g,h,i,j,k,l,fibo); \
		AVL_FIBO_SETUP(fibo); \
		ASSERT_NO_THROW(fibo.remove(a)); \
		ASSERT_TRUE(is_avl(fibo)); \
		ASSERT_NO_THROW(fibo.remove(b)); \
		ASSERT_TRUE(is_avl(fibo)); \
		ASSERT_NO_THROW(fibo.remove(c)); \
		ASSERT_TRUE(is_avl(fibo)); \
		ASSERT_NO_THROW(fibo.remove(d)); \
		ASSERT_TRUE(is_avl(fibo)); \
		ASSERT_NO_THROW(fibo.remove(e)); \
		ASSERT_TRUE(is_avl(fibo)); \
		ASSERT_NO_THROW(fibo.remove(f)); \
		ASSERT_TRUE(is_avl(fibo)); \
		ASSERT_NO_THROW(fibo.remove(g)); \
		ASSERT_TRUE(is_avl(fibo)); \
		ASSERT_NO_THROW(fibo.remove(h)); \
		ASSERT_TRUE(is_avl(fibo)); \
		ASSERT_NO_THROW(fibo.remove(i)); \
		ASSERT_TRUE(is_avl(fibo)); \
		ASSERT_NO_THROW(fibo.remove(j)); \
		ASSERT_TRUE(is_avl(fibo)); \
		ASSERT_NO_THROW(fibo.remove(k)); \
		ASSERT_TRUE(is_avl(fibo)); \
		ASSERT_NO_THROW(fibo.remove(l)); \
		ASSERT_TRUE(is_avl(fibo));

class AVLTest {
	
	/**
	 * Define a test tree object: a pair of ints.
	 * Include default comparison operators by the left int.
	 */
	class Pair {
	public:
		int x;
		int y;
		
		Pair(int X, int Y) : x(X), y(Y) {}
	
		// Default comparison: by the left field first
		bool operator<(const Pair& p) const {
			return (x==p.x ? y<p.y : x<p.x);
		}
		bool operator==(const Pair& p) const {
			return x==p.x && y==p.y;
		}
		bool operator!=(const Pair& p) const {
			return !(*this == p);
		}
	};
	
	/**
	 * Create two comparison classes for comparing Pairs:
	 * one to compare the int on the left, and one to compare the int on the right
	 */
	class LeftCompare: public AVL<Pair>::Compare<int,Pair> {
		bool less(const int& a, const Pair& b) const {
			return a<b.x;
		}
		bool equal(const int& a, const Pair& b) const {
			return a==b.x;
		}
	};
	class RightCompare: public AVL<Pair>::Compare<int,Pair> {
		bool less(const int& a, const Pair& b) const {
			return a<b.y;
		}
		bool equal(const int& a, const Pair& b) const {
			return a==b.y;
		}
	};
	
	int abs(int x) { return x<0 ? -x : x; }
	
	// Used to make sure this is an AVL tree - ordered,
	// and no balance factor is not in [-1,0,1]
	template<typename T>
	bool is_avl(const AVL<T>& avl) {
		return (is_ordered<T>(avl) && good_pointers<T>(avl) && is_balanced<T>(avl));
	}
	
	// Helper method for is_avl(): used to make sure the tree is in order
	template<typename T>
	bool is_ordered(const AVL<T>& avl) {
		for (typename AVL<T>::const_iterator i = avl.infix_begin(); !i.is_null() && !(i.next().is_null()) ; i = i.next()) {
			ASSERT_TRUE(avl._cmp->leq(*i._tree_node, *i.next()._tree_node));
		}
		return true;
	}

	template<typename T>
	bool good_pointers(typename AVL<T>::const_iterator i) {
		if (i.is_null()) return true;					// Null nodes are always OK
		if (!i.left().is_null() && i.left().up() != i) {// Are we disowned by the left child?
			return false;
		}
		if (!i.right().is_null() && i.right().up() != i) {
			return false;
		}
		return (good_pointers<T>(i.left()) && good_pointers<T>(i.right()));
	}
	
	template<typename T>
	bool good_pointers(const AVL<T>& avl) {
		if (avl.is_empty()) return true;				// Make sure they're both empty at once
		return (good_pointers<T>(avl._root) && avl._root->_dad == NULL);
	}

	template<typename T>
	bool is_balanced(const AVL<T>& avl) {
		for (typename AVL<T>::const_iterator i = avl.infix_begin(); !(i.is_null()); i = i.next()) {
			int left_height = i.left().is_null() ? -1 : i.left()->height();
			int right_height = i.right().is_null() ? -1 : i.right()->height();
			ASSERT_TRUE(abs(left_height - right_height) < 2);	// Make sure it's balanced
		}
		return true;
	}
	
	// Helper method for is_avl(): checks the height of the node
	template<typename T>
	int height(const typename AVL<T>::Node& node) {
		if (!node) return -1;	// Null nodes have a height of zero
		int a = height(*(node.left()));
		int b = height(*(node.right()));
		return (a>b ? a+1 : b+1);
	}
	
	// Prints the tree, for testing purposes (only int trees)
	void print_avl(const AVL<int>& avl, bool infix = true) {
		if (infix) {
			for (AVL<int>::const_iterator i = avl.infix_begin(); !i.is_null(); i = i.next()) {
				std::cout << *i << ",";
			}
			std::cout << "\n";
		}
		else print_avl(avl.root());
	}
	void print_avl(AVL<int>::const_iterator i, int indent = 0) {
		if (!i.is_null()) {
			if (indent) {
				std::cout << std::setw(indent) << ' ';
			}
			std::cout << *i << "\n ";
			if (i->right()) print_avl(i->right(), indent + 4);
			if (i->left()) print_avl(i->left(), indent + 4);
		}
	}
	
	/**
	 * Test methods
	 */
	bool create() {
		AVL<int> avl;
		
		return true;
	}
	
	bool insert() {
		AVL<int> avl;
		ASSERT_TRUE(avl.is_empty());				// Make sure we start empty
		ASSERT_TRUE(avl.get_height() == -1);
		ASSERT_TRUE(avl.get_total() == 0);			// Every update, check list emptiness, total elements, height and balance factor
		ASSERT_NO_THROW(avl.insert(2));				// 2
		ASSERT_FALSE(avl.is_empty());
		ASSERT_TRUE(avl.get_total() == 1);
		ASSERT_TRUE(avl._root->_hl == -1);
		ASSERT_TRUE(avl._root->_hr == -1);
		ASSERT_TRUE(avl._root->bf() == 0);
		ASSERT_TRUE(avl.get_height() == 0);
		ASSERT_THROWS(AVL<int>::ItemAlreadyExists, avl.insert(2));
		ASSERT_NO_THROW(avl.insert(1));				//    2
		ASSERT_FALSE(avl.is_empty());				//   /
		ASSERT_TRUE(avl.get_total() == 2);			//  1
		ASSERT_TRUE(avl._root->_hl == 0);
		ASSERT_TRUE(avl._root->_hr == -1);
		ASSERT_TRUE(avl._root->bf() == 1);
		ASSERT_TRUE(avl._root->_left->bf() == 0);
		ASSERT_TRUE(avl.get_height() == 1);
		ASSERT_NO_THROW(avl.insert(3));				//    2
		ASSERT_FALSE(avl.is_empty());				//   / \ 
		ASSERT_TRUE(avl.get_total() == 3);			//  1   3
		ASSERT_TRUE(avl._root->bf() == 0);
		ASSERT_TRUE(avl._root->_left->bf() == 0);
		ASSERT_TRUE(avl._root->_right->bf() == 0);
		ASSERT_TRUE(avl.get_height() == 1);
		ASSERT_TRUE(*avl.infix_begin() == 1);		// Make sure the list is in order
		ASSERT_TRUE(*avl.infix_begin().next() == 2);
		ASSERT_TRUE(*avl.infix_end() == 3);
		ASSERT_TRUE(is_balanced(avl));				// Make sure it's an AVL tree
		ASSERT_TRUE(good_pointers(avl));
		ASSERT_TRUE(is_ordered(avl));
		
		return true;
	}
	
	bool insert_rolls() {
		AVL<int> avl;
		
		// Basics:
		ASSERT_NO_THROW(avl.insert(1));		//  1              2
		ASSERT_TRUE(avl.get_total() == 1);	//   \           /  \ 
		ASSERT_TRUE(is_balanced(avl));		//    2   ===>  1    3
		ASSERT_TRUE(good_pointers(avl));	//     \ 
		ASSERT_TRUE(is_ordered(avl));		//      3
		ASSERT_NO_THROW(avl.insert(2));	
		ASSERT_TRUE(avl.get_total() == 2);	
		ASSERT_TRUE(is_balanced(avl));
		ASSERT_TRUE(good_pointers(avl));
		ASSERT_TRUE(is_ordered(avl));
		ASSERT_NO_THROW(avl.insert(3));		
		ASSERT_TRUE(avl.get_total() == 3);
		ASSERT_TRUE(is_balanced(avl));
		ASSERT_TRUE(good_pointers(avl));
		ASSERT_TRUE(is_ordered(avl));
		
		// Throw some more into the tree
		ASSERT_NO_THROW(avl.remove_all());
		for (int i = 1; i <= 20; i++) {
			ASSERT_NO_THROW(avl.insert(i));
			ASSERT_TRUE(is_balanced(avl));				// Make sure it's an AVL tree
			ASSERT_TRUE(good_pointers(avl));
			ASSERT_TRUE(is_ordered(avl));
		}
		
		return true;
	}
	
	bool remove() {
		AVL<int> fibo;
		
		// Make sure the removal method is silent
		ASSERT_NO_THROW(fibo.remove(10));			// Try removing from an empty AVL
		AVL_FIBO_SETUP(fibo);
		ASSERT_NO_THROW(fibo.remove(15));			// Try removing a non-existant item
		ASSERT_TRUE(is_balanced(fibo));				// Make sure it's still an AVL tree
		ASSERT_TRUE(good_pointers(fibo));
		ASSERT_TRUE(is_ordered(fibo));
		
		// Try removing one each time
		ASSERT_TRUE(is_balanced(fibo));
		ASSERT_TRUE(good_pointers(fibo));
		ASSERT_TRUE(is_ordered(fibo));
		for (int i = 10; i <= 120; i += 10) {
			AVL_FIBO_SETUP(fibo);
//			std::cout << "Before remove:\n";
//			print_avl(fibo);
			ASSERT_NO_THROW(fibo.remove(i));
//			std::cout << "After remove:\n";
//			print_avl(fibo);
			ASSERT_FALSE(fibo.exists(i));
			for (int j = 10; j<=120; j+=10) {
				if (j==i) continue;
				ASSERT_TRUE(fibo.exists(j));
			}
			ASSERT_TRUE(is_balanced(fibo));
			ASSERT_TRUE(good_pointers(fibo));
			ASSERT_TRUE(is_ordered(fibo));
		}
		
		// Try removing onlythe root each time
		AVL_FIBO_SETUP(fibo);
		int x=0;
		while (!fibo.is_empty()) {
//			std::cout << "Iteration " << ++x << ", current state:\n";
//			print_avl(fibo);
			ASSERT_NO_THROW(fibo.remove(fibo.root()));
			ASSERT_TRUE(is_balanced(fibo));
			ASSERT_TRUE(good_pointers(fibo));
			ASSERT_TRUE(is_ordered(fibo));
		}
		
		// Try some random removal orders... Make sure removing the root
		// is one of them, and going backwards / forwards is also included
		AVL_REMOVE_FIBO(10,20,30,40,50,60,70,80,90,100,110,120,fibo);	// In order
		AVL_REMOVE_FIBO(120,110,100,90,80,70,60,50,40,30,20,10,fibo);	// Backwards
		AVL_REMOVE_FIBO(50,40,60,80,100,120,10,30,20,70,90,110,fibo);	// Root first
		AVL_REMOVE_FIBO(20,40,60,80,100,120,10,30,50,70,90,110,fibo);
		AVL_REMOVE_FIBO(10,30,50,70,90,110,20,40,60,80,100,120,fibo);
		AVL_REMOVE_FIBO(10,30,50,70,90,110,120,100,80,60,40,20,fibo);
		AVL_REMOVE_FIBO(20,40,60,80,100,120,110,90,70,50,30,10,fibo);
		
		return true;
	}
	
	bool iteration() {
		AVL<int> fibo;
		AVL_FIBO_SETUP(fibo);
		AVL<int>::iterator i = fibo.root();
		
		// Try getting the NULL iterator in the fibo tree
		ASSERT_NO_THROW(i = i.left().left().left());
		ASSERT_THROWS(AVL<int>::NullIterator, i.up());
		ASSERT_NO_THROW(i = fibo.root());
		ASSERT_NO_THROW(i = i.right().left().left().left());
		ASSERT_THROWS(AVL<int>::NullIterator, i.up());
		
		// Make sure we start in the right place
		i = fibo.root();
		ASSERT_TRUE(i == 50);
		
		// Try taking a walk
		ASSERT_NO_THROW(i = i.right().right().right().left());
		ASSERT_TRUE(i == 110);
		ASSERT_NO_THROW(i = i.up().left());
		ASSERT_TRUE(i == 110);
		ASSERT_NO_THROW(i = i.up().up());
		ASSERT_TRUE(i == 100);
		ASSERT_NO_THROW(i = i.left());
		ASSERT_TRUE(i == 90);
		ASSERT_NO_THROW(i = i.up().up().left());
		ASSERT_TRUE(i == 70);
		
		return true;
	}
	
	bool infix_iteration() {
		AVL<int> fibo;
		AVL<Pair> avl;
		AVL_FIBO_SETUP(fibo);
		AVL_BALANCED_SETUP(avl);
		
		// Iterate over the fibonacci tree
		int x = 10;
		for (AVL<int>::iterator i = fibo.infix_begin(); !i.is_null(); i = i.next()) {
			ASSERT_TRUE(*i == x);
			x += 10;
		}
		
		// Iterate over the balanced tree
		Pair p(10,0);
		for (AVL<Pair>::iterator i = avl.infix_begin(); !i.is_null(); i = i.next()) {
			ASSERT_TRUE(*i == p);
			p.x += 10;
		}
		
		return true;
	}
	
	/*bool list_construction() {
		
		// Create a list
		List<int> list;
		for (int i = 1; i <= 10; i++) {
			list.insert_at_tail(i);
		}
		
		// Create a bad list
		List<int> bad_list;
		bad_list.insert_at_tail(1);
		bad_list.insert_at_tail(3);
		bad_list.insert_at_tail(2);
		
		// Try creating with both types
		AVL<int> avl = list;
		AVL<int>::iterator i = avl.infix_begin();
		List<int>::iterator j = list.begin();
		while(!i.is_null()) {
			ASSERT_TRUE(*i == *j);
			ASSERT_TRUE(*j == *i);
			ASSERT_NO_THROW(i = i.next());
			ASSERT_NO_THROW(++j);
		}
		ASSERT_TRUE(j.is_null());
		
		return true;
	}*/
	
	bool compare() {
		AVL<int> fibo, fibo2;
		AVL<Pair> avl, avl2;
		AVL_FIBO_SETUP(fibo);
		ASSERT_TRUE(fibo2 != fibo);
		AVL_FIBO_SETUP(fibo2);
		ASSERT_TRUE(fibo2 == fibo);
		ASSERT_TRUE(avl == avl2);		// Compare empty trees
		AVL_BALANCED_SETUP(avl);		// Now create two tree with different structures, and the same elements
		avl2.insert(Pair(30,0));		//             3
		avl2.insert(Pair(20,0));		//           /   \ 
		avl2.insert(Pair(50,0));		//         2      5
		avl2.insert(Pair(10,0));		//        /      / \ 
		avl2.insert(Pair(40,0));		//       1      4   7
		avl2.insert(Pair(70,0));		//                 /
		avl2.insert(Pair(60,0));		//                6
		ASSERT_FALSE(avl2 == avl);
		
		return true;
	}
	
	bool existance() {
		AVL<int> avl, fibo;
		ASSERT_NO_THROW(avl.exists(1));	// Allow empty search
		ASSERT_FALSE(avl.exists(1));
		AVL_FIBO_SETUP(fibo);
		AVL_FIBO_SETUP(avl);
		ASSERT_NO_THROW(fibo.exists(1));	// Find something that doesn't exist
		ASSERT_FALSE(fibo.exists(1));
		ASSERT_NO_THROW(fibo.exists(10));	// Find something that does
		ASSERT_TRUE(fibo.exists(10));
		ASSERT_TRUE(fibo == avl);			// Make sure nothing changed
		
		return true;
	}
	
	bool find() {
		AVL<Pair> avl, avl_copy;
		AVL<Pair>::iterator i;
		LeftCompare lc;
		RightCompare rc;
		Pair p(1,0);
		
		// Try to fail
		ASSERT_TRUE(avl.find(p).is_null());
		AVL_BALANCED_SETUP(avl);
		AVL_BALANCED_SETUP(avl_copy);
		ASSERT_NO_THROW(i = avl.find(Pair(20,0)));		// Normal find
		ASSERT_FALSE(i.is_null());
		ASSERT_TRUE(*i == Pair(20,0));
		ASSERT_NO_THROW(i = avl.find(30, &lc));			// Left find
		ASSERT_FALSE(i.is_null());
		ASSERT_TRUE(*i == Pair(30,0));
		ASSERT_NO_THROW(i = avl.find(0, &rc));			// Right find
		ASSERT_FALSE(i.is_null());
		ASSERT_TRUE((*i).y == 0);
		
		// Make sure the trees weren't hurt
		ASSERT_TRUE(avl == avl_copy);
		
		return true;
	}
	
	bool listify() {
		
		// Create some lists to work with
		AVL<int> fibo;
		AVL<Pair> avl;
		AVL_FIBO_SETUP(fibo);
		AVL_BALANCED_SETUP(avl);
		List<int> fibo_list;
		ASSERT_NO_THROW(fibo_list = fibo.to_list());
		List<Pair> avl_list;
		ASSERT_NO_THROW(avl_list = avl.to_list());
		
		// Make sure we're good
		AVL<int>::iterator fibo_i = fibo.infix_begin();
		List<int>::iterator fibo_j = fibo_list.begin();
		while (!fibo_i.is_null()) {
			ASSERT_TRUE(*fibo_i == *fibo_j);
			ASSERT_TRUE(*fibo_j == *fibo_i);
			ASSERT_NO_THROW(fibo_j++);
			ASSERT_NO_THROW(fibo_i = fibo_i.next());
		}
		ASSERT_TRUE(fibo_j.is_null());
		AVL<Pair>::iterator avl_i = avl.infix_begin();
		List<Pair>::iterator avl_j = avl_list.begin();
		while (!avl_i.is_null()) {
			ASSERT_TRUE(*avl_i == *avl_j);
			ASSERT_NO_THROW(avl_j++);
			ASSERT_NO_THROW(avl_i = avl_i.next());
		}
		ASSERT_TRUE(avl_j.is_null());
		
		// And the structure is OK
		ASSERT_TRUE(is_balanced(avl));				// Make sure it's an AVL tree
		ASSERT_TRUE(good_pointers(avl));
		ASSERT_TRUE(is_ordered(avl));
		ASSERT_TRUE(is_balanced(fibo));				// Make sure it's an AVL tree
		ASSERT_TRUE(good_pointers(fibo));
		ASSERT_TRUE(is_ordered(fibo));
		
		return true;
	}
		
	bool imprint() {
		AVL<int> fibo, fibo_copy;
		List<int> list;
		ASSERT_NO_THROW(fibo.imprint(list));	// Empty structures should work
		AVL_FIBO_SETUP(fibo);
		list.insert_at_head(1);
		ASSERT_THROWS(AVL<int>::EmptyAVL, fibo_copy.imprint(list));
		ASSERT_THROWS(AVL<int>::BadListSize, fibo.imprint(list));
		AVL_FIBO_SETUP(fibo_copy);
		
		// Try inserting a badly organized list
		list.insert_at_tail(0);
		for (int i = 2; i <= 11; i++) {
			list.insert_at_tail(i);
		}
		ASSERT_THROWS(AVL<int>::UnsortedList, fibo.imprint(list));
		
		// Try inserting a good list
		list.remove_head();
		list.remove_head();
		list.insert_at_head(1);
		list.insert_at_head(0);
		ASSERT_NO_THROW(fibo.imprint(list));
		
		// Make sure that the same structure isn't enough for comparison
		ASSERT_FALSE(fibo == fibo_copy);
		
		// And the structure is OK
		ASSERT_TRUE(is_balanced(fibo));				// Make sure it's an AVL tree
		ASSERT_TRUE(good_pointers(fibo));
		ASSERT_TRUE(is_ordered(fibo));
		
		return true;
	}

public:
	AVLTest() {
		RUN_TEST(create);
		RUN_TEST(insert);
		RUN_TEST(insert_rolls);
		RUN_TEST(remove);
		RUN_TEST(iteration);
//		RUN_TEST(list_construction);
		RUN_TEST(existance);
		RUN_TEST(find);
		RUN_TEST(listify);
		RUN_TEST(compare);
		RUN_TEST(imprint);
	}
};

#endif