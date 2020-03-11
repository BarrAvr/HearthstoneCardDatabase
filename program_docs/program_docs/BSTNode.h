#pragma once

template <typename T>
class BSTNode {
private:
	T data;
	BSTNode<T>* leftChild;
	BSTNode<T>* rightChild;
public:
	BSTNode();
	BSTNode(T);
	~BSTNode();
	BSTNode(T, BSTNode<T>*, BSTNode<T>*);
	void setData(T);
	void setRightChild(BSTNode<T>*);
	void setLeftChild(BSTNode<T>*);
	T getData() const;
	BSTNode<T>*& getRightChild();
	BSTNode<T>*& getLeftChild();
};

template <typename T>
BSTNode<T>::BSTNode() : data(0), leftChild(nullptr), rightChild(nullptr) {

}

template <typename T>
BSTNode<T>::BSTNode(T newData) : leftChild(nullptr), rightChild(nullptr) {
	data = newData;
}

template <typename T>
BSTNode<T>::BSTNode(T newData, BSTNode<T>* right, BSTNode<T>* left) : data(newData), leftChild(left), rightChild(right) {

}

template <typename T>
BSTNode<T>::~BSTNode() {

}

template <typename T>
void BSTNode<T>::setData(T d) {
	data = d;
}

template <typename T>
void BSTNode<T>::setRightChild(BSTNode<T>* right) {
	rightChild = right;
}

template <typename T>
void BSTNode<T>::setLeftChild(BSTNode<T>* left) {
	leftChild = left;
}

template <typename T>
T BSTNode<T>::getData() const {
	return data;
}

template <typename T>
BSTNode<T>*& BSTNode<T>::getRightChild() {
	return rightChild;
}

template <typename T>
BSTNode<T>*& BSTNode<T>::getLeftChild() {
	return leftChild;
}