/**
* CircularDoublyLinkedList.cpp
* circular doubly linked list te olusturulan algoritmaya ile veri kaydi
* Yaz okulu 1.Ogretim B grubu
* 1.odev
* 16/08/2020
* Bugrahan Erk Vural
*/
#include "CircularDoublyLinkedList.h"

Node* CircularDoublyLinkedList::FindPreviousNode(int index) {
	Node* prev = head;
	int i = 1;
	for (Node* itr = head; i != index; itr = itr->next, i++) {
		prev = prev->next;
	}
	return prev;
}
int CircularDoublyLinkedList::count()const {
	return size;
}
bool CircularDoublyLinkedList::isEmpty()const {
	return size == 0;
}
void CircularDoublyLinkedList::add(const int& item) {
	insert(size, item);
}
void CircularDoublyLinkedList::insert(int index, const int& item) {
	//if(index<0 || index>size) hata
	if (index == 0) {
		if (size == 0) {
			head = new Node(item);
			head->next = head->prev = head;
		}
		else {
			head = new Node(item, head, head->prev);
			head->next->prev = head;
			head->prev->next = head;
		}
	}
	else {
		Node* prv = FindPreviousNode(index);
		prv->next = new Node(item, prv->next, prv);
		prv->next->next->prev = prv->next;
	}
	size++;
}
const int& CircularDoublyLinkedList::first() {
	//if(isEmpty()) throw ListeBos();
	return head->data;
}
const int& CircularDoublyLinkedList::last() {
	//if(isEmpty()) throw ListeBos();
	return head->prev->data;
}
int CircularDoublyLinkedList::indexOf(const int& item)const {
	int index = 0;
	for (Node* itr = head; index < size; itr = itr->next) {
		if (itr->data == item) return index;
		index++;
	}
	return -1;
}
void CircularDoublyLinkedList::remove(const int& item) {
	int index = indexOf(item);
	//if(index == -1 )hata
	removeAt(index);
}
void CircularDoublyLinkedList::removeAt(int index) {
	//if(index<0 || index>=size) hata
	Node* del;
	if (index == 0) {
		del = head;
		if (size == 1) {
			head = head->next = head->prev = NULL;
		}
		else {
			head = head->next;
			head->prev = del->prev;
			del->prev->next = head;
		}
		
		size--;
		delete del;
	}
}
	bool CircularDoublyLinkedList::find(const int& item) const {
		int index = 0;
		for (Node* itr = head; index < size; itr = itr->next, index++) {
			if (itr->data == item) return true;
		}
		return false;
}
const int& CircularDoublyLinkedList::elementAt(int index) {
	if (index == 0) return first();
	return FindPreviousNode(index)->next->data;
}
void CircularDoublyLinkedList::clear() {
	while (!isEmpty()) {
		removeAt(0);
	}
}
void CircularDoublyLinkedList::printNodesFromPositionReverseOrder(int index) {
	//if(index<=0 || index>=size) hata
	int i = 0;
	for (Node* itr = FindPreviousNode(index + 1); i < size; itr = itr->prev, i++)
		cout << itr->data << " ";
	cout << endl;
}
void CircularDoublyLinkedList::printReverseOrder() {
	printNodesFromPositionReverseOrder(size - 1);
}
