#pragma once
#include "LinkNode.h"
#include <iostream>

const enum SORT {ASCENDING, DESCENDING, UNSORTED};

template<class T>
class SinglyLinkedList
{
protected:
	LinkNode<T>* head;
	LinkNode<T>* tail;
	int count;
	int sort;

public:
	SinglyLinkedList();
	SinglyLinkedList(int);
	SinglyLinkedList(int, T*);
	SinglyLinkedList(int, T*, T*);
	~SinglyLinkedList();
	void printTSVFormat(std::ostream& out);
	LinkNode<T>* find(const T&) const;
	LinkNode<T>* find(int) const;
	LinkNode<T>* findPrev(const T&) const;
	bool compare(const T&, const T&) const;
	void add(T*);
	int getCount() const;
	bool remove(const T&);
	void empty();

	template<class U>
	friend std::ostream& operator<<(std::ostream& out, const SinglyLinkedList<U>& list);
};

//Creates an empty SinglyLinkedList object 
//Pre: none
//Post: Empty SinglyLinkedList object created
template<class T>
SinglyLinkedList<T>::SinglyLinkedList() {
	count = 0;
	sort = UNSORTED;
	head = nullptr;
	tail = nullptr;

}

//Creates an empty SinglyLinkedList object with specified sort characteristic
//Pre: none
//Post: Empty SinglyLinkedList object created with specified sort characteristic
template<class T>
SinglyLinkedList<T>::SinglyLinkedList(int x) {
	count = 0;
	sort = x;
	head = nullptr;
	tail = nullptr;
}

//Creates an empty SinglyLinkedList object with specified sort characteristic and specified value
//Pre: none
//Post: Empty SinglyLinkedList object created with specified sort characteristic and specified value
template<class T>
SinglyLinkedList<T>::SinglyLinkedList(int x, T* h) {
	count = 1;
	sort = x;
	head = new LinkNode<T>(nullptr, h);
	tail = head;
}

//Creates an empty SinglyLinkedList object with specified sort characteristic and specified values
//Pre: none
//Post: Empty SinglyLinkedList object created with specified sort characteristic and specified values
template<class T>
SinglyLinkedList<T>::SinglyLinkedList(int x, T* h, T* t) {
	count = 1;
	sort = x;
	head = new LinkNode<T>(nullptr, h);
	tail = new LinkNode<T>(nullptr, t);
	head->setNext(tail);
}
 
//Destroys the list and all nodes in it 
//Pre: List exists
//Post: List is destroyed
template<class T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
	empty();
}

//Returns amount of nodes in the list 
//Pre: List exists
//Post: count is returned
template<class T>
int SinglyLinkedList<T>::getCount() const {
	return count;
}

//Adds a new value to the list based on its sorting behavior
//Pre: List exists
//Post: A new element is added to the list
template<class T>
void SinglyLinkedList<T>::add(T* value){
	LinkNode<T>* newNode = new LinkNode<T>(nullptr, value);

	if (count == 0) {
		head = newNode;
		tail = newNode;
	}
	else {
		if (sort == UNSORTED) {
			tail->setNext(newNode);
			tail = newNode;
		}
		else {
			LinkNode<T>* prevNode = findPrev(*value);
			if(prevNode == nullptr) {
				newNode->setNext(head);
				head = newNode;
			}
			else {
				newNode->setNext((prevNode->getNext()));
				prevNode->setNext(newNode);
				if (newNode->getNext() == nullptr) tail = newNode;
			}
		}
	}
	count++;
}

//Removes a specified value
//Pre: List exists
//Post: Returns true if element is removed successfully or false if the element is not found
template<class T>
bool SinglyLinkedList<T>::remove(const T& value) {
	LinkNode<T>* prevFound = findPrev(value);
	LinkNode<T>* found = find(value);
	bool isSuccessful = true;
	
	if (count == 0 || found == nullptr) {
		isSuccessful = false;
	}
	else if (prevFound != nullptr) {
		if (found->getNext() == nullptr) prevFound->setNext(nullptr);
		else prevFound->setNext(found->getNext());
		delete found;
		count--;
	} 
	else if (prevFound == nullptr)
	{
		head = head->getNext();
		delete found;
		count--;
	}
	return isSuccessful;
}

//Returns a node which contains the specified value
//Pre: List exists
//Post: Returns the node containing the specified value or nullptr if it is not found
template<class T>
LinkNode<T>* SinglyLinkedList<T>::find(const T& value) const {
	if (count == 0) return nullptr;
	LinkNode<T>* found = head;
	for (int i = 0; i < count; i++) {
		if (*(found->getVal())==value) break;
		found = found->getNext();
	}
	return found;
}

//Returns a node at the specified position, 0 being the head
//Pre: List exists
//Post: Returns the node containing the specified value or nullptr if it is not found
template<class T>
LinkNode<T>* SinglyLinkedList<T>::find(int depth) const
{
	if (depth < 0 || depth >= count) return nullptr;
	LinkNode<T>* curr = head;
	for (int i = 0; i < depth; i++)
	{
		curr = curr->getNext();
	}
	return curr;
}

//Returns the node before the one which contains the specified value
//Pre: List exists
//Post: Returns the previous node or nullptr if it is not found
template<class T>
LinkNode<T>* SinglyLinkedList<T>::findPrev(const T& value) const {
	if (count == 0) return nullptr;
	LinkNode<T>* found = head;
	LinkNode<T>* prevFound = nullptr;
	for (int i = 0; i < count; i++) {
		if (compare(*(found->getVal()), value)) break;
		prevFound = found;
		found = found->getNext();
	}
	return prevFound;
}

//Returns whether a node can be placed in front of another node
//Helper function for findPrev()
//Pre: List exists
//Post: boolean value is returned
template<class T>
bool SinglyLinkedList<T>::compare(const T& nodeVal, const T& val) const
{
	bool comp = false;

	if (sort == UNSORTED)
		comp = (val == nodeVal);
	else if (sort == ASCENDING)
		comp = (nodeVal > val || nodeVal == val);
	else if (sort == DESCENDING)
		comp = (nodeVal < val || nodeVal == val);

	return comp;
}

//Prints out all values in the list 
//Pre: List exists
//Post: All values are printed out or an empty list is indicated
template<class T>
std::ostream& operator<<(std::ostream& out, const SinglyLinkedList<T>& list) {
	if (list.head == nullptr) {
		out << "List is empty" << std::endl << std::endl;
		return out;
	}
	LinkNode<T>* print = list.head;
	for (int i = 0; i < list.count; i++) {
		if (i == 0) out << "******LIST START********" << std::endl;
		out << *(print->getVal());
		print = print->getNext();
		if (i == list.count - 1) out << "----------LIST END----------" << std::endl << std::endl;
	}
	return out;
}

template<class T>
void SinglyLinkedList<T>::printTSVFormat(std::ostream& out) {
	LinkNode<T>* print = head;
	for (int i = 0; i < count; i++) {
		*(print->getVal()).printToTSVFile(out);
		print = print->getNext();
	}

}
//Empties out list
//Pre: List exists
//Post: List contains no nodes
template<class T>
void SinglyLinkedList<T>::empty() {
	LinkNode<T>* node;
	for (int i = 0; i < count; i++)
	{
		node = head;
		head = head->getNext();
		delete node;
	}
	count = 0;
	node = nullptr;
	tail = nullptr;
}


