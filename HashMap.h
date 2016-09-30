// HashTable.h

#ifndef _HASHMAPE_h
#define _HASHMAPE_h
#include <WString.h>
#include "LinkedList.h"
#include <WString.h>


template <class K, class V>
struct Entry
{
	K key;
	V value;
};

template <class V>
class HashMap
{
public:
	HashMap();
	~HashMap();
	V put(String key, V value);
	V get(String key);
	bool remove(String key);


protected:

	LinkedList<Entry<String, V> >* list;
};

template <class V>
HashMap<V>::HashMap()
{
	list = new LinkedList<Entry<String, V> >();
}

template <class V>
HashMap<V>::~HashMap()
{
	delete list;
}

template <class V>
V HashMap<V>::put(String key, V value)
{
	Entry<String, V>* entry = new Entry<String, V>();
	entry->key = key;
	entry->value = value;
	list->add(*entry);
	return value;
}

template <class V>
V HashMap<V>::get(String key)
{
	for (int i = 0; i < list->size(); i++)
	{
		if (list->get(i).key.equalsIgnoreCase(key))
		{
			return list->get(i).value;
		}
	}
	return V();
}

template <class V>
bool HashMap<V>::remove(String key)
{
	for (int i = 0; i < list->size(); i++)
	{
		if (list->get(i).key.equalsIgnoreCase(key))
		{
			list->remove(i);
			return true;
		}
	}
	return false;
}
#endif
