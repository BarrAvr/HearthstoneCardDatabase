#pragma once

#include "LinkNode.h"
#include "SinglyLinkedList.h"
#include <string>

template<class T>
class HashTable
{
	// Underlying array of singly linked list pointers
	// lists because of linked list resolution
	SinglyLinkedList<T>** table;
	int size; // Member that is depended on load factor
	const double LOAD_FACTOR = 0.75; // Intended ratio of max # of elements in hash table to size of hash table
	int hashFunc(const T&) const;

	public:
		HashTable(int);
		~HashTable();
		
		int getSize() const;
		int getMaxNodes();
		SinglyLinkedList<T>* operator[](int index) const;
		template<class U>
		friend std::ostream& operator<<(std::ostream& out, const HashTable<U>& list);
		
		void add(T*);
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
	size = abs(count) / LOAD_FACTOR;
	table = new SinglyLinkedList<T>*[size];
}


/* Destructor for HashTable
 * Pre: None
 * Post: All dynamically allocated memory of HashTable is released
 */
template<class T>
HashTable<T>::~HashTable()
{
	SinglyLinkedList<T>*& curr = table[0];

	for (int i = 0; i < size; i++) {
		curr = table[i];
		if (curr != nullptr) curr->empty();
		curr = nullptr;
	}
	delete [] table;
}

/* Getter method for HashTable
 * Pre: None
 * Post: Returns the size/length of the underlying array in the hash table
 */
template<class T>
int HashTable<T>::getSize() const {
	return size;
}

/* Overloaded subscript operator for HashTable
 * Pre: Valid index is passed in
 * Post: Returns pointer to the const linked list at the index position in the hash table
 */
template<class T>
SinglyLinkedList<T>* HashTable<T>::operator[](int index) const {
	if (index < 0 || index >= size) throw "ERROR: Index out of bounds";
	return table[index];
}

/* Overloaded output operator for HashTable
 * Pre: Valid ostream and HashTable objects are passed int
 * Post: Outputs cards in every linked list line by line from the start to the end of the HashTable
 */
template<class U>
std::ostream& operator<<(std::ostream& out, const HashTable<U>& table)
{
	for (int i = 0; i < table.getSize(); i++) {
		if (table[i] == nullptr)
			out << "Empty Position " << std::endl;
		else
			out << *(table[i]);
	}
	return out;
}

/* Getter method for HashTable
 * Pre: HashTable object exists
 * Post: Returns the maximum length of a linked list used for collision resolution
 */
template<class T>
int HashTable<T>::getMaxNodes() {
	int currMax;
	int max = 0;
	for (int i = 0; i < size; i++) {
		if (table[i] != nullptr) {
			currMax = table[i]->getCount();
			if (currMax > max) max = currMax;
		}
		
	}
	return max;
}


/* Hashing algorithm for hash table that uses a pseudorandom approach
 * Pre: Valid object is passed in
 * Post: An integer corresponding to an array position is returned
 */
template<class T>
int HashTable<T>::hashFunc(const T& obj) const
{
	std::string name = obj.getName();
	int sum = 0;
	for (char c : name) sum += c;
	return (13 * sum + 29) % size;
}

/* Hashing algorithm for hash table
 * Pre: Valid object address to be added is passed in
 * Post: A node containing the object address is added to the hash table
 *       Collisions are handled by appending the node to the end of the linked list at the collision
			-Linked List Resolution
 */
template<class T>
void HashTable<T>::add(T* obj)
{
	int index = hashFunc(*obj);
	SinglyLinkedList<T>* curr = table[index];
	if (curr == nullptr) 
		table[index] = new SinglyLinkedList<T>(UNSORTED, obj);
	else
		curr->add(obj);
}

/* Find method for Hash Table
 * Pre: Valid object to be found is passed in
 * Post: An integer corresponding to the underlying array position where the object is found is returned, -1 if not found
 */
template<class T>
int HashTable<T>::find(const T& obj) const
{
	int index = hashFunc(obj);
	SinglyLinkedList<T>* curr = table[index];
	if (curr == nullptr || curr->find(obj) == nullptr)
		index = -1;
	return index;
}

/* Remove method for Hash Table
 * Pre: Valid object is passed in
 * Post: If the object is removed, true is returned, false otherwise
 */
template<class T>
bool HashTable<T>::remove(const T& obj)
{
	int index = hashFunc(obj);
	SinglyLinkedList<T>*& curr = table[index];
	
	if (curr != nullptr || curr->find(obj) == nullptr) return false;
	if (curr->getCount() == 1) {
		curr->empty();
		curr = nullptr;
	}
	else curr->remove(obj);

	return true;
}
