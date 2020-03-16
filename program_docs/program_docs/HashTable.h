#pragma once

#include "LinkNode.h"
#include <string>

template<class T>
class HashTable
{
	// Underlying array of card node pointers
	// Nodes because of linked list resolution
	LinkNode<T>** table;
	const int SIZE; // Member that is depended on load factor
	const double LOAD_FACTOR; // Intended ratio of max # of elements in hash table to size of hash table
	int hashFunc(const T&) const;

	public:
		HashTable(int);
		~HashTable();
		
		int getSize() const;
		// int getMaxNodes();
		const LinkNode<T>* operator[](int index) const;
		
		void add(const T* const);
		int find(const T&) const;
		bool remove(const T&);

};


/* Constructor for HashTable
 * Pre: The intended max number of elements is passed to the constructor
 * Post: A hash table is created with size = count / load factor
 *	     Negative counts are automatically turned into valid, positive counts
 */
template<class T>
HashTable<T>::HashTable(int count)
{
	LOAD_FACTOR = 0.75;
	SIZE = abs(count) / LOAD_FACTOR;
	table = new LinkNode<T>*[SIZE];
}


/* Destructor for HashTable
 * Pre: HashTable object exists when called
 * Post: All dynamically allocated memory of HashTable is released
 */
template<class T>
HashTable<T>::~HashTable()
{
	LinkNode<T>* curr;
	LinkNode<T>* prev;
	for (int i = 0; i < SIZE; i++)
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

/* Getter method for HashTable
 * Pre: HashTable object exists
 * Post: Returns the size/length of the underlying array in the hash table
 */
template<class T>
int HashTable<T>::getSize() const {
	return SIZE;
}

/* Overloaded subscript operator for HashTable
 * Pre: HashTable object exists and valid index is passed in
 * Post: Returns pointer to the head const Node of the linked list at the index position in the hash table
 */
template<class T>
const LinkNode<T>* HashTable<T>::operator[](int index) const {
	if (index < 0 || index >= SIZE) throw "ERROR: Index out of bounds";
	return table[index];
}

/* Hashing algorithm for hash table
 * Pre: Valid object 
 */
template<class T>
int HashTable<T>::hashFunc(const T& obj) const
{
	std::string name = obj.getName();
	int sum = 0;
	for (char c : name) sum += c;
	return (13 * sum + 29) % SIZE;
}

template<class T>
void HashTable<T>::add(const T* const obj)
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
int HashTable<T>::find(const T& obj) const
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
bool HashTable<T>::remove(const T& obj)
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
