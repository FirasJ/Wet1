#ifndef TREE_H_
#define TREE_H_

#include <stdlib.h>
#include <cassert>

//#include <algorithm>

template<class T>
class Tree {
public:

	class TreeIsEmpty {};
	class ElementNotFound {};
	class ElementAlreadyExists {};

	class Node;
	friend class Node;

	Tree();

	virtual ~Tree();

	virtual void insert(const T& data);
	virtual void remove(const T& data);
	virtual Node* find(const T& data) const;
	Node* getMax() const;
	void clear(Node* node);
	size_t size() const;

	template<class Function>
	void preOrder(Function& function);

	template<class Function>
	void postOrder(Function& function);

	template<class Function>
	void inOrder(Function& function) const;


private:

	Node *_root;
	size_t _size;

	template<class Function>
	void subPreOrder(const Node* node, Function& function);

	template<class Function>
	void subPostOrder(const Node* node, Function& function);

	template<class Function>
	void subInOrder(const Node* node, Function& function) const;

	void rotateLL(Node* node);

	void rotateRR(Node* node);

	void rotateLR(Node* node);

	void rotateRL(Node* node);

	void rotate(Node* node);

	void updateBalanceFactor(Node* node);

	void updateHeight(Node* node);

	void update(Node* leaf);

	Tree<T>::Node* findAux(Node* node, const T& data) const;

	typename Tree<T>::Node* removeOneSon(Node* node);

	Node*& parentSon(Node* node);

	Node* getFollowing(Node* node);

	void swapNodes(Node* node, Node* next);

};


template<class T>
class Tree<T>::Node {
public:
	friend class Tree<T>;
	Node(const T& data) : 	_data(data),
							_left(0),
							_right(0),
							_parent(0),
							_height(0),
							_balanceFactor(0)	{}
	Node(const Node& node) : 	_data(node._data),
								_left(node._left),
								_right(node._right),
								_parent(node._parent),
								_height(node._height),
								_balanceFactor(node._balanceFactor) {}
	const T& getData() { return _data; }
private:
	T _data;
	Node *_left, *_right, *_parent;
	int _height, _balanceFactor;
	Node& operator=(const Node& node);
};

template<class T>
Tree<T>::Tree() :	_root(0), _size(0) {}

template<class T>
void Tree<T>::clear(Node* node) {
	if(!node) return;
    if(node->_left) clear(node->_left);
    if(node->_right) clear(node->_right);
    delete node;
    --_size;
}

template<class T>
Tree<T>::~Tree() {
	clear(_root);
}

template<class T>
void Tree<T>::insert(const T& data) {
	Node* newNode = new Node(data);
	try {
		Node* parent = find(data);
		if(parent->_data == data) {
			throw ElementAlreadyExists();
		}
		++_size;
		newNode->_parent = parent;
		if(data < parent->_data) {
			parent->_left = newNode;
		} else {
			parent->_right = newNode;
		}
		Node* tmpNode = newNode;
		while(tmpNode != _root) {
			Node* son = tmpNode;
			tmpNode = tmpNode->_parent;
			updateBalanceFactor(tmpNode);
			if(tmpNode->_height >= son->_height + 1) return;
			if(tmpNode->_height >= son->_height + 1) return;
			updateHeight(tmpNode);
			if(abs(tmpNode->_balanceFactor) > 1) {
				rotate(tmpNode);
				return;
			}
		}
	} catch (TreeIsEmpty& e) {
		_root = newNode;
		++_size;
	}

}

template<class T>
typename Tree<T>::Node* Tree<T>::getMax() const {
	Node* max = _root;
	if(!max) {
		throw TreeIsEmpty();
	}
	while(max->_right) {
		max = max->_right;
	}
	return max;
}

template<class T>
inline size_t Tree<T>::size() const {
	return _size;
}

/*
// this function assumes Node* next has a parent.
template<class T>
void Tree<T>::swapNodes(Node* node, Node* next) {
	Node*& nextParent = parentSon(next);
	Node*& nodeParent = parentSon(node);
	nextParent = node;
	if(nodeParent)
		nodeParent = next;
	else
		_root = next;
	Node* tmp = node->_parent;
	node->_parent = next->_parent;
	next->_parent = tmp;

	std::swap(node->_balanceFactor, next->_balanceFactor);
	std::swap(node->_height, next->_height);
	std::swap(node->_left, next->_left);
	std::swap(node->_right, next->_right);
}
*/

template<class T>
void Tree<T>::swapNodes(Node* node, Node* next) {
	T& t=node->_data;
	node->_data = next->_data;
	next->_data = t;
}

template<class T>
void Tree<T>::remove(const T& data) {
	Tree<T>::Node *node;
	node = find(data); // throws if empty
	if (node->_data != data) {
		throw ElementNotFound();
	}
	if (node->_left && node->_right) { // 2 sons
		Node* next = getFollowing(node);
		swapNodes(node, next);
		node=next;
	}

	Tree<T>::Node *parent = removeOneSon(node);

	while(parent != NULL) {
		updateHeight(parent);
		updateBalanceFactor(parent);
		if(abs(parent->_balanceFactor) > 1) {
			rotate(parent);
		}
		parent = parent->_parent;
	}
	--_size;
	delete node;
}

template<class T>
typename Tree<T>::Node*& Tree<T>::parentSon(Node* node) {
	assert(node);
	if (node->_parent)
		return (node->_parent->_left == node) ?
				node->_parent->_left : node->_parent->_right;
	return node->_parent;
}

template<class T>
typename Tree<T>::Node* Tree<T>::removeOneSon(Node* node) {
	assert(node);
	Node*& son = parentSon(node);
	if (!node->_left && !node->_right) { // leaf node
		if (son) {
			son = NULL;
		} else {
			_root = NULL;
		}
	} else if (node->_left && !node->_right) { // only left son
		if (!son) {
			_root = node->_left;
			node->_left->_parent = NULL;
		} else {
			son = node->_left;
			node->_left->_parent = node->_parent;
		}
	} else { // only right son
		if (!son) {
			_root = node->_right;
			node->_right->_parent = NULL;
		} else {
			son = node->_right;
			node->_right->_parent = node->_parent;
		}
	}
	return node->_parent;
}

template<class T>
typename Tree<T>::Node* Tree<T>::getFollowing(Node* node) {
	assert(node && node->_right);
	Node* tmp = node->_right;
	while(tmp->_left) {
		tmp = tmp->_left;
	}
	return tmp;
}


template<class T>
typename Tree<T>::Node* Tree<T>::findAux(Node* node, const T& data) const {
	if (node->_data > data && node->_left) {
		return findAux(node->_left, data);
	}
	if (node->_data < data && node->_right) {
		return findAux(node->_right, data);
	}
	return node;
}

template<class T>
typename Tree<T>::Node* Tree<T>::find(const T& data) const {
	if (!_root) throw TreeIsEmpty();
	Node* node = findAux(_root, data);
/*	if(node->_data != data) {
		throw ElementNotFound();
	} */
	return node;
}

template<class T>
template<class Function>
void Tree<T>::preOrder(Function& function) {
	subPreOrder(_root, function);
}

template<class T>
template<class Function>
void Tree<T>::postOrder(Function& function) {
	subPostOrder(_root, function);
}

template<class T>
template<class Function>
void Tree<T>::inOrder(Function& function) const {
	subInOrder(_root, function);
}

template<class T>
template<class Function>
void Tree<T>::subPreOrder(const Node* node, Function& function) {\
    if(node) {
    	function(node->_data);
        if(node->_left) subPreOrder(node->_left, function);
        if(node->_right) subPreOrder(node->_right, function);
    }
}

template<class T>
template<class Function>
void Tree<T>::subPostOrder(const Node* node, Function& function) {
    if(node) {
        if(node->_left) subPostOrder(node->_left, function);
        if(node->_right) subPostOrder(node->_right, function);
        function(node->_data);
    }
}

template<class T>
template<class Function>
void Tree<T>::subInOrder(const Node* node, Function& function) const {
    if(node) {
        if(node->_left) subInOrder(node->_left, function);
        function(node->_data);
        if(node->_right) subInOrder(node->_right, function);
    }
}

template<class T>
void Tree<T>::rotateLL(Node* node) {
	if(node->_parent) {
		( node->_parent->_left == node ) ? node->_parent->_left = node->_left : node->_parent->_right = node->_left;
	} else {
		_root = node->_left;
	}
	node->_left->_parent = node->_parent;
	node->_parent = node->_left;
	Node* tmp = node->_left->_right;
	node->_left->_right = node;
	if(tmp)
		tmp->_parent = node;
	node->_left = tmp;

	updateHeight(node);
	updateHeight(node->_parent);

	updateBalanceFactor(node);
	updateBalanceFactor(node->_parent);
}

template<class T>
void Tree<T>::rotateRR(Node* node) {
	if(node->_parent) {
		( node->_parent->_left == node ) ? node->_parent->_left = node->_right : node->_parent->_right = node->_right;
	} else {
		_root = node->_right;
	}
	node->_right->_parent = node->_parent;
	node->_parent = node->_right;
	Node* tmp = node->_right->_left;
	node->_right->_left = node;
	if(tmp)
		tmp->_parent = node;
	node->_right = tmp;

	updateHeight(node);
	updateHeight(node->_parent);

	updateBalanceFactor(node);
	updateBalanceFactor(node->_parent);
}

template<class T>
void Tree<T>::rotateLR(Node* node) {
	rotateRR(node->_left);
	rotateLL(node);
}

template<class T>
void Tree<T>::rotateRL(Node* node) {
	rotateLL(node->_right);
	rotateRR(node);
}

template<class T>
void Tree<T>::rotate(Node* node) {
	int left = node->_left ? node->_left->_balanceFactor : 0;
	int right = node->_right ? node->_right->_balanceFactor : 0;
	if(node->_balanceFactor == 2) {
		if(left >= 0) {
			rotateLL(node);
			return;
		} else {
			rotateLR(node);
			return;
		}
	} else {
		if(right <= 0) {
			rotateRR(node);
			return;
		} else {
			rotateRL(node);
			return;
		}
	}
}

template<class T>
void Tree<T>::updateBalanceFactor(Node* node) {
	if(!node) return;
	int right = node->_right ? node->_right->_height : -1;
	int left = node->_left ? node->_left->_height : -1;
	node->_balanceFactor = left - right;
}

template<class T>
void Tree<T>::updateHeight(Node* node) {
	if(!node) return;
	int right = node->_right ? node->_right->_height : -1;
	int left = node->_left ? node->_left->_height : -1;
	node->_height = 1 + (left > right ? left : right);
}

template<class T>
void Tree<T>::update(Node* leaf) {
	Node* tmpNode = leaf;
	while(tmpNode) {
		updateHeight(tmpNode->_parent);
		tmpNode = tmpNode->_parent;
	}
	while(tmpNode) {
		updateBalanceFactor(tmpNode->_parent);
		tmpNode = tmpNode->_parent;
	}
}

#endif /* TREE_H_ */
