/**
* Node.cpp
* circular doubly linked list te olusturulan algoritmaya ile veri kaydi
* Yaz okulu 1.Ogretim B grubu
* 1.odev
* 16/08/2020
* Bugrahan Erk Vural
*/
#include "Node.h"

Node::Node(const int data, Node* next , Node* prev ) {
	this->data = data;
	this->next = next;
	this->prev = prev;
}