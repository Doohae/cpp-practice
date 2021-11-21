#ifndef D_LINKED_LIST
#define D_LINKED_LIST

#include <iostream>
using namespace std;

template <typename T>
class Node {
	template <typename T>
	friend class DoublyLinkedList;
public:
	Node(const T data);
private:
	Node *next;
	Node *prev;
	T data;
};

template <typename T>
class DoublyLinkedList {
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	bool insert(const T data, const int index);
	bool remove(const int index);
	int size() const;
	void print(ostream & stream);
private:
	Node<T> *head;
	Node<T> *tail;
	int numNodes;
	void init();
	Node<T> *findNode(const int index);
};

template <typename T>
Node<T>::Node(const T data) {
	this->data = data;
	this->next = NULL;
	this->prev = NULL;
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
	init();
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	Node<T> *current = head;
	Node<T> *next = NULL;

	while (current != NULL) {
		next = current->next;
		delete current;
		current = next;
	}
}

template <typename T>
bool DoublyLinkedList<T>::insert(const T data, const int index) {
	if (index < 0 || index > numNodes) {
		return false;
	}
	else {
		Node<T> *newNode = new Node<T>(data);

		if (index == 0) {
			newNode->next = head;

			if (numNodes == 0) {
				tail = newNode;
			}
			else {
				head->prev = newNode;
			}

			head = newNode;
		}
		else if (index == numNodes) {
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
		else {
			Node<T> *current = findNode(index);
			Node<T> *nextNode = current->next;

			newNode->next = current->next;
			newNode->prev = current;
			current->next = newNode;
			nextNode->prev = newNode;
		}
		numNodes++;

		return true;
	}
}

template <typename T>
bool DoublyLinkedList<T>::remove(const int index) {
	if (index < 0 || index >= numNodes) {
		return false;
	}
	else {
		Node<T> *current = NULL;

		if (index == 0) {
			current = head;
			head = current->next;
			head->prev = NULL;
			delete current;
		}
		else {
			current = findNode(index);
			Node<T> *nextNode = current->next->next;

			delete current->next;
			current->next = nextNode;
			
			if (index == numNodes - 1) {
				tail = current;
			}
			else {
				nextNode->prev = current;
			}
		}
		numNodes--;

		return true;
	}
}

template <typename T>
int DoublyLinkedList<T>::size() const {
	return numNodes;
}

template <typename T>
void DoublyLinkedList<T>::print(ostream & stream) {
	Node<T> *current = head;

	while (current != NULL) {
		stream << current->data << endl;
		current = current->next;
	}
}

template <typename T>
void DoublyLinkedList<T>::init() {
	head = NULL;
	tail = NULL;
	numNodes = 0;
}

template <typename T>
Node<T> *DoublyLinkedList<T>::findNode(const int index) {
	Node<T> *current = NULL;

	if (index < numNodes / 2) {
		current = head;

		for (int i = 1; i < index; i++) {
			current = current->next;
		}

		return current;
	}
	else {
		current = tail;

		for (int i = numNodes; i > index; i--) {
			current = current->prev;
		}

		return current;
	}
}
#endif