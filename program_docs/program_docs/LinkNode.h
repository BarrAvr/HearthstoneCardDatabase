#pragma once

template<class T>
class LinkNode
{
private:
	LinkNode* next;
	T* val;

public:
	LinkNode();
	LinkNode(const LinkNode<T>* const, const T* const);

	T* getVal() const;
	LinkNode* getNext() const;
	void setVal(const T* const);
	void setNext(const LinkNode<T>* const);
};

//Creates an empty LinkNode object 
//Pre: none
//Post: Empty LinkNode object created
template<class T>
LinkNode<T>::LinkNode() {
	next = nullptr;
	val = nullptr;
}

//Creates a LinkedNode object 
//Pre: none
//Post: LinkedNode object created with specified values
template<class T>
LinkNode<T>::LinkNode(const LinkNode<T>* const n, const T* const v) {
	next = n;
	val = v;
}



//Returns pointer to value of node
//Pre: LinkNode Object exists
//Post: value is returned
template<class T>
T* LinkNode<T>::getVal() const {
	return val;
}

//Returns pointer to next node
//Pre: LinkNode Object exists
//Post: value is returned
template<class T>
LinkNode<T>* LinkNode<T>::getNext() const {
	return next;
}

//Sets pointer to next node
//Pre: LinkNode Object exists
//Post: next is set
template<class T>
void LinkNode<T>::setNext(const LinkNode<T>* const n) {
	next = n;
}

//Sets pointer to value of node
//Pre: LinkNode Object exists
//Post: value is set
template<class T>
void LinkNode<T>::setVal(const T* const v) {
	val = v;
}



