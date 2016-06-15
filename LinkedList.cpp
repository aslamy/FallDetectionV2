// 
// 
// 
/*
#include "LinkedList.h"

template <typename T>
LinkedListClass<T>::LinkedListClass() {
	size= 0;
	this->root = NULL;
	this->last = NULL;
}

template <typename T>
bool LinkedListClass<T>::add(T data)
{
	ListNode<T> *tmp = new ListNode<T>();
	tmp->data = data;
	tmp->next = NULL;

	if(root==NULL)
	{
		root = tmp;
		last = tmp;
	}else
	{
		last->next = tmp;
		last = tmp;
	}

	size++;
	return true;

}

template <typename T>
T LinkedListClass<T>::get(int index)
{
	if(root)
	{
		int start = 0;
		ListNode<T> current = root;
		while (index>start)
		{
			current = current.next;
			start++;
		}
		return current.data;
	}
	return T();

}
*/