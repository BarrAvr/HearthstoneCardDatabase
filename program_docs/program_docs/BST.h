#pragma once
#include <iostream>
#include "BSTNode.h"
#include "Spell.h"

template < class T > class BST {
private:
	BSTNode<T>* rootPtr;
	/* for void recursiveAdd(BSTNode<T>*& root, BSTNode<T>*newNode)

	Pre: root - BSTNode to go through and add newNode into
	if it is empty.
	newNode - Node to add to the BST.

	Post: This goes through the BST recursively and adds the
	newNode to the correct position.

	Return: nothing
	*/
	void recursiveAdd(BSTNode<T>*& root, BSTNode<T>* newNode);
	/* for recursiveDelete(T, BSTNode<T>*&)

	Pre: root - BSTNode to go through.
	newNode - Node to dalete from the BST.

	Post: This goes through the BST recursively and if
	it finds the newNode it deletes it from the BST and
	fixes the binary tree afterwards if the node deleted
	has children.

	Return: true if found, false otherwise
	*/
	bool recursiveDelete(T, BSTNode<T>*&);
	/* for recursiveSearch(BSTNode<T>*, T) const

	Pre: root - BSTNode to go through.
	T - data to search for in the BST.

	Post: This goes through the BST recursively and if
	it finds the newNode it returns true, otherwise
	if it goes through the whole binary search tree
	and doesn't find the data value, return false.

	Return: true if found, false otherwise
	*/
	bool recursiveSearch(BSTNode<T>*, T) const;
	/* for BSTNode<T> findLargest(BSTNode<T>*) const

	Pre: root - BSTNode to go through and find the
	largest value within it.

	Post: This goes through the BST recursively and
	returns the highest value data in the BST.

	Return: nothing
	*/
	BSTNode<T> findLargest(BSTNode<T>*) const;
	/* for void recurPreOrder(BSTNode<T>*, std::ostream& out) const

	Pre: root - BSTNode in BST to print.
	out - output to print to.

	Post: This recurisively prints the BST with pre-order
	traversal into the out stream.

	Return: nothing
	*/
	void recurPreOrder(BSTNode<T>*, std::ostream& out) const;
	/* for void recurPostOrder(BSTNode<T>*, std::ostream& out) const

	Pre: root - BSTNode in BST to print.
	out - output to print to.

	Post: This recurisively prints the BST with post-order
	traversal into the out stream.

	Return: nothing
	*/
	void recurPostOrder(BSTNode<T>*, std::ostream& out) const;
	/* for void recurInOrder(BSTNode<T>*, std::ostream& out) const

	Pre: root - BSTNode in BST to print.
	out - output to print to.

	Post: This recurisively prints the BST with in-order
	traversal into the out stream.

	Return: nothing
	*/
	void recurInOrder(BSTNode<T>*, std::ostream& out) const;
	/* for void recurBreadthFirst(BSTNode<T>*, std::ostream& out) const

	Pre: root - BSTNode in BST to print.
	out - output to print to.

	Post: This recurisively prints the BST with breadth-first
	traversal into the out stream.

	Return: nothing
	*/
	void recurBreadthFirst(BSTNode<T>*, std::ostream& out) const;
	void recurPrintCardsIndent(BSTNode<T>*, int, std::ostream& out) const;
	/* for void recurEmpty(BSTNode<T>*&)

	Pre: root - BSTNode to empty from BST.

	Post: Goes through each node, and checks the right and
	left children, checks if they aren't already empty, and
	if they aren't calls the function again for the left child
	and the right child. It then deletes the contents of the
	root node and makes it point to null.

	Return: nothing
	*/
	void recurEmpty(BSTNode<T>*&);
public:
	BST();
	~BST();
	T getRootData() const;
	void setRootData(T);
	/* for bool deleteNode(T)

	Pre: data - data to be deleted

	Post: calls on the recursive delete function with the parameters
	rootPtr and data.

	Return: true if found, false otherwise
	*/
	bool deleteNode(T);
	/* for void addNode(T)

	Pre: data - data to be added

	Post: calls on the recursive add function with the parameters
	rootPtr and a new BSTNode that stores data.

	Return: nothing
	*/
	void addNode(T);
	/* for bool search(T) const

	Pre: data - data to be searched

	Post: calls on the recursive search function with the parameters
	rootPtr and data.

	Return: true if found, false otherwise
	*/
	bool search(T) const;
	/* for void preOrderTraversalPrint(std::ostream& out) const;

	Pre: out - stream to output to.

	Post: calls on the recursive pre-order function with the parameters
	rootPtr and out.

	Return: nothing
	*/
	void preOrderTraversalPrint(std::ostream& out) const;
	/* for void postOrderTraversalPrint(std::ostream& out) const;

	Pre: out - stream to output to.

	Post: calls on the recursive post-order function with the parameters
	rootPtr and out.

	Return: nothing
	*/
	void postOrderTraversalPrint(std::ostream& out) const;
	/* for void inOrderTraversalPrint(std::ostream& out) const;

	Pre: out - stream to output to.

	Post: calls on the recursive in-order function with the parameters
	rootPtr and out.

	Return: nothing
	*/
	void inOrderTraversalPrint(std::ostream& out) const;
	/* for void breadthFirstTraversalPrint(std::ostream& out) const;

	Pre: out - stream to output to.

	Post: calls on the recursive breadth-first function with the parameters
	rootPtr and out.

	Return: nothing
	*/
	void breadthFirstTraversalPrint(std::ostream& out) const;
	void printCardsIndent(std::ostream& out) const;
	/* for void empty()

	Pre: rootPtr - BSTNode in BST to be emptied

	Post: Calls on the recursive empty function with
	parameters rootPtr.

	Return: nothing
	*/
	void empty();
	/* for bool isEmpty() const

	Pre: rootPtr - BSTNode to check to see if is empty

	Post: returns true if the BST is empty, false otherwise

	Return: returns true if the BST is empty, false otherwise
	*/
	bool isEmpty() const;
};

template < class T >
BST<T>::BST() : rootPtr(nullptr) {

}

template < class T >
BST<T>::~BST() {
	this->empty();
}

template < class T >
T BST<T>::getRootData() const {
	return rootPtr->getData();
}

template < class T >
void BST<T>::setRootData(T data) {
	if (rootPtr == nullptr) {
		rootPtr = new BSTNode<T>(data);
	}
	else {
		rootPtr->setData(data);
	}
}

template < class T >
bool BST<T>::deleteNode(T data) {
	return recursiveDelete(data, rootPtr);
}

template < class T >
bool BST<T>::recursiveDelete(T data, BSTNode<T>*& root) {
	if (root == nullptr) {
		return false;
	}
	if (*data < *(root->getData())) {
		return recursiveDelete(data, root->getLeftChild());
	}
	else if (*data > * (root->getData())) {
		return recursiveDelete(data, root->getRightChild());
	}
	else {
		if (root->getLeftChild() == nullptr) {
			BSTNode<T>* ptr = root;
			root = ptr->getRightChild();
			delete ptr;
			return true;
		}
		else if (root->getRightChild() == nullptr) {
			BSTNode<T>* ptr = root;
			root = ptr->getLeftChild();
			delete ptr;
			return true;
		}
		else {
			BSTNode<T> largest = findLargest(root);
			root->setData(largest.getData());
			return recursiveDelete(largest.getData(), root->getLeftChild());
		}
	}
}

template < class T >
BSTNode<T> BST<T>::findLargest(BSTNode<T>* root) const {
	if (root->getRightChild() == nullptr) {
		return *root;
	}
	else {
		return findLargest(root->getRightChild());
	}
}


template < class T >
void BST<T>::addNode(T data) {
	BSTNode<T>* newNode = new BSTNode<T>(data);
	recursiveAdd(rootPtr, newNode);
}

template < class T >
void BST<T>::recursiveAdd(BSTNode<T>*& root, BSTNode<T>* newNode) {
	if (root == nullptr) {
		root = newNode;
	}
	else if (*(newNode->getData()) < *(root->getData())) {
		recursiveAdd(root->getLeftChild(), newNode);
	}
	else {
		recursiveAdd(root->getRightChild(), newNode);
	}
}

template < class T >
bool BST<T>::search(T data) const {
	bool b;
	b = recursiveSearch(rootPtr, data);
	return b;
}

template < class T >
bool BST<T>::recursiveSearch(BSTNode<T>* root, T data) const {
	if (root == nullptr) {
		return false;
	}
	if (*data < *(root->getData())) {
		return recursiveSearch(root->getLeftChild(), data);
	}
	else if (*data > * (root->getData())) {
		return recursiveSearch(root->getRightChild(), data);
	}
	else {
		return true;
	}
}

//preorder (Root – Left – Right)
template < class T >
void BST<T>::preOrderTraversalPrint(std::ostream& out) const {
	if (rootPtr != nullptr) {
		recurPreOrder(rootPtr, out);
	}
	else {
		out << "Tree is empty" << std::endl;
	}
}

template < class T >
void BST<T>::recurPreOrder(BSTNode<T>* root, std::ostream& out) const {
	if (root != nullptr) {
		out << *(root->getData());
		out << std::endl;
		recurPreOrder(root->getLeftChild(), out);
		recurPreOrder(root->getRightChild(), out);
	}
}

//postorder (Left – Right – Root)
template < class T >
void BST<T>::postOrderTraversalPrint(std::ostream& out) const {
	if (rootPtr != nullptr) {
		recurPostOrder(rootPtr, out);
	}
	else {
		out << "Tree is empty" << std::endl;
	}
}

template < class T >
void BST<T>::recurPostOrder(BSTNode<T>* root, std::ostream& out) const {
	if (root != nullptr) {
		recurPostOrder(root->getLeftChild(), out);
		recurPostOrder(root->getRightChild(), out);
		out << *(root->getData());
		out << std::endl;
	}
	else {
		out << "Tree is empty" << std::endl;
	}
}

//inorder (Left – Root – Right)
template < class T >
void BST<T>::inOrderTraversalPrint(std::ostream& out) const {
	if (rootPtr != nullptr) {
		recurInOrder(rootPtr, out);
	}
	else {
		out << "Tree is empty" << std::endl;
	}
}

template < class T >
void BST<T>::recurInOrder(BSTNode<T>* root, std::ostream& out) const {
	if (root != nullptr) {
		recurInOrder(root->getLeftChild(), out);
		out << *(root->getData());
		out << std::endl;
		recurInOrder(root->getRightChild(), out);
	}
}

template < class T >
void BST<T>::breadthFirstTraversalPrint(std::ostream& out) const {
	if (rootPtr != nullptr) {
		out << *(rootPtr->getData()) << std::endl;
		recurBreadthFirst(rootPtr, out);
	}
}

template < class T >
void BST<T>::recurBreadthFirst(BSTNode<T>* root, std::ostream& out) const {
	if (root->getLeftChild() != nullptr) {
		out << *(root->getLeftChild()->getData());
		out << std::endl;
	}
	if (root->getRightChild() != nullptr) {
		out << *(root->getRightChild()->getData());
		out << std::endl;
	}
	if (root->getLeftChild() != nullptr) {
		recurBreadthFirst(root->getLeftChild(), out);
	}
	if (root->getRightChild() != nullptr) {
		recurBreadthFirst(root->getRightChild(), out);
	}
}

template < class T >
void BST<T>::empty() {
	recurEmpty(rootPtr);
}

template < class T >
void BST<T>::recurEmpty(BSTNode<T>*& root) {
	if (root->getLeftChild() != nullptr) {
		recurEmpty(root->getLeftChild());
	}
	if (root->getRightChild() != nullptr) {
		recurEmpty(root->getRightChild());
	}
	if (root != nullptr) {
		delete root;
		root = nullptr;
	}
}

template < class T >
bool BST<T>::isEmpty() const {
	return rootPtr == nullptr;
}

template < class T >
void BST<T>::printCardsIndent(std::ostream& out) const {
	recurPrintCardsIndent(rootPtr, 0, out);
}

template < class T >
void BST<T>::recurPrintCardsIndent(BSTNode<T>* root, int numIndents, std::ostream& out) const {
	if (root->getRightChild() != nullptr) recurPrintCardsIndent(root->getRightChild(), numIndents + 1, out);
	for (int i = 0; i < numIndents; i++) {
		out << '\t';
	}
	out << root->getName() << std::endl;
	if (root->getLeftChild() != nullptr) recurPrintCardsIndent(root->getLeftChild(), numIndents + 1, out);
}
