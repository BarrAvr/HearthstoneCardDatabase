#pragma once

#include "LinkNode.h"
#include <string>

template<class T>
class HashTable
{
	//Underlying array of card node pointers
	//Nodes bc of linked list resolution
	LinkNode<T>** table;
	int hashFunc(T&);
	int size;

	public:
		HashTable(int);
		~HashTable();
		int getSize();
		int getMaxNodes();
		T* operator[](int index);
		
		void add(T*);
		//Returns index in hash table
		int find(T&);
		//Returns whether remove was sucessful
		bool remove(T&);

};

template<class T>
int HashTable<T>::getSize() {
	return size;
}
template<class T>
T* HashTable<T>::operator[](int index) {
	return table[index];
}



template<class T>
HashTable<T>::HashTable(int s)
{
	size = s;
	table = new LinkNode<T>*[size];
}

template<class T>
HashTable<T>::~HashTable()
{
	LinkNode<T>* curr;
	LinkNode<T>* prev;
	for (int i = 0; i < size; i++)
	{
		curr = table[i];
		while (curr != nullptr)
		{
			prev = curr;
			curr = curr->getNext();
			delete prev;
		}
		table[i] = nullptr;
	}
	delete [] table;
}

template<class T>
int HashTable<T>::hashFunc(T& obj)
{
	std::string name = obj.getName();
	int sum = 0;
	for (char c : name) sum += c;
	return (13 * sum + 29) % size;
}

template<class T>
void HashTable<T>::add(T* obj)
{
	int index = hashFunc(*obj);
	LinkNode<T>* curr = table[index];
	LinkNode<T>* addNode = new LinkNode<T>(nullptr, obj);
	if (curr == nullptr) table[index] = addNode;
	else {
		while (curr->getNext() != nullptr)
			curr = curr->getNext();
		curr->setNext(addNode);
	}
}

template<class T>
int HashTable<T>::find(T& obj)
{
	int index = hashFunc(obj);
	LinkNode<T>* curr = table[index];
	while (curr != nullptr) {
		if (*(curr->getVal()) == obj) return index;
		curr = curr->getNext();
	}
	return -1;
}

template<class T>
bool HashTable<T>::remove(T& obj)
{
	int index = hashFunc(obj);
	LinkNode<T>* curr = table[index];
	LinkNode<T>* prev;
	
	while (curr != nullptr) 
	{
		if (*(curr->getVal()) == obj) {
			prev = curr;
			curr = curr->getNext();
			delete prev;
			while (curr != nullptr) {
				prev = curr;
				curr = curr->getNext();
			}
			prev = curr;
			return true;
		}
		curr = curr->getNext();
	}
	return false;
}
