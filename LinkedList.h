// LinkedList.h

#ifndef _LINKEDLIST_h
#define _LINKEDLIST_h

#include <stddef.h>

template <class T>
struct Node
{
	T data;
	Node<T>* next;
};

template <class T>
class LinkedList
{
public:

	LinkedList();
	bool add(T data);
	T get(int index);
	T pop(void);
	T shift(void);
	int size(void) const;
	T remove(int index);
	~LinkedList();


protected:
	int _size;
	Node<T>* root;
	Node<T>* last;
	Node<T>* getNode(int index);
};

template <class T>
LinkedList<T>::LinkedList()
{
	_size = 0;
	this->root = NULL;
	this->last = NULL;
}

template <class T>
bool LinkedList<T>::add(T data)
{
	Node<T>* tmp = new Node<T>();
	tmp->data = data;
	tmp->next = NULL;

	if (root == NULL)
	{
		root = tmp;
		last = tmp;
	}
	else
	{
		last->next = tmp;
		last = tmp;
	}

	_size++;
	return true;
}

template <class T>
T LinkedList<T>::get(int index)
{
	Node<T>* searchNode = getNode(index);
	return (searchNode) ? searchNode->data : T();
}

template <class T>
T LinkedList<T>::pop()
{
	if (_size <= 0)
	{
		return T();
	}
	if (_size == 1)
	{
		T data = root->data;
		root = NULL;
		last = NULL;
		_size = 0;
		return data;
	}
	Node<T>* tmp = getNode(_size - 2);
	T data = tmp->next->data;
	delete(tmp->next);
	tmp->next = NULL;
	last = tmp;
	_size--;
	return data;
}

template <class T>
T LinkedList<T>::shift()
{
	if (_size <= 0)
	{
		return T();
	}

	if (_size == 1)
	{
		return pop();
	}

	Node<T>* _next = root->next;
	T data = root->data;
	delete(root);
	root = _next;
	_size--;
	return data;
}

template <class T>
int LinkedList<T>::size() const
{
	return this->_size;
}

template <class T>
T LinkedList<T>::remove(int index)
{
	if (index < 0 || index >= _size)
	{
		return T();
	}
	if (index == 0)
		return shift();

	if (index == _size - 1)
	{
		return pop();
	}

	Node<T>* searchNode = getNode(index - 1);
	Node<T>* toDelete = searchNode->next;
	searchNode->next = searchNode->next->next;
	T data = toDelete->data;
	delete toDelete;
	_size--;
	return data;
}

template <class T>
Node<T>* LinkedList<T>::getNode(int index)
{
	if (root && index <= _size - 1)
	{
		int start = 0;
		Node<T>* current = root;
		while (index > start)
		{
			current = current->next;
			start++;
		}
		return current;
	}
	return NULL;
}

template <class T>
LinkedList<T>::~LinkedList()
{
	Node<T>* tmp;

	while (root)
	{
		tmp = root;
		root = root->next;
		delete tmp;
	}
	_size = 0;
	delete root;
}
#endif
