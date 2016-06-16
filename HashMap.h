// HashTable.h

#ifndef _HASHMAPE_h
#define _HASHMAPE_h
#include <WString.h>
#include "LinkedList.h"



template <class  K, class  V>
struct  Entry
{
	K key;
	V value;
};

template <class K, class V>
class HashMap
{

 public:
	 HashMap();
	 ~HashMap();
	 V put(K key,V value);
	 V get(K key);
	 bool remove(K key);


protected:	

	LinkedList<Entry<K,V> > *list;


};

template <class K, class  V>
HashMap<K,V>::HashMap()
{
	list = new LinkedList<Entry<K, V> >();
}

template <class K, class V>
HashMap<K, V>::~HashMap()
{
	delete list;
}

template <class K, class V>
V HashMap<K, V>::put(K key, V value)
{
	//remove(key);
	Entry<K, V> *entry = new Entry<K, V>();
	entry->key = key;
	entry->value = value;
	list->add(*entry);
	return value;
}

template <class K, class V>
V HashMap<K, V>::get(K key)
{
	for(int i = 0; i< list->size();i++)
	{
		if(list->get(i).key == key)
		{
			return list->get(i).value;
		}
	}
	return V();
}

template <class K, class V>
bool HashMap<K, V>::remove(K key)
{
	for (int i = 0; i< list->size(); i++)
	{
		if (list->get(i).key == key)
		{
			list->remove(i);
			return true;
		}
	}
	return false;
}
#endif

