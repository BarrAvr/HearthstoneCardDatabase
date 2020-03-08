#pragma once

#include "LinkNode.h"

template<class T>
class HashTable
{
	//Underlying array of card node pointers
	//Nodes bc of linked list resolution
	LinkNode<T>** table;
	int hashFunc(T&);

	public:
		HashTable(int);
		~HashTable();
		
		void add(T*);
		//Returns index in hash table
		int find(T&);
		//Returns whether remove was sucessful
		bool remove(T&);
};
