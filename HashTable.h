// HashTable.h

#ifndef _HASHTABLE_h
#define _HASHTABLE_h
#include <WString.h>
#include "LinkedList.h"

template <class T>
class HashTable
{

 public:
	 HashTable(int size);

	 
private:
	int size;
	
	LinkedList<int> *list;
	template <class V >
	class Entry
	{
		String key;
		V value;
		Entry(String key, V value)
		{
			this->key = key;
			this->value;
		}


	};

};

template <class T>
HashTable<T>::HashTable(int size): size(0) {
	list = new LinkedList<int>();
}


#endif

