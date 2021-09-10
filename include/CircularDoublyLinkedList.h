/**
* CircularDoublyLinkedList.h 
* circular doubly linked list te olusturulan algoritmaya ile veri kaydi
* Yaz okulu 1.Ogretim B grubu
* 1.odev
* 16/08/2020
* Bugrahan Erk Vural
*/


#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "Node.h"

class CircularDoublyLinkedList {
private:
	Node* head;
	int size;

	Node* FindPreviousNode(int index);
public:
	CircularDoublyLinkedList() {
		head = NULL;
		size = 0;
	}
	int count()const;
	bool isEmpty()const;
	void add(const int& item);
	void insert(int index, const int& item);
	const int& first();
	const int& last();
	int indexOf(const int& item)const;
	void remove(const int& item);
	void removeAt(int index);
	bool find(const int& item) const;
	const int& elementAt(int index);
	void clear();
	void printNodesFromPositionReverseOrder(int index);
	void printReverseOrder();
	friend ostream& operator<<(ostream& screen, CircularDoublyLinkedList& right) {
		int index = 0;
		for (Node* itr = right.head; index < right.size; itr = itr->next, index++) {
			screen << itr->data << " ";
		}
		screen << endl;
		return screen;
	}
	~CircularDoublyLinkedList() {
		clear();
	}
	
	
};
#endif