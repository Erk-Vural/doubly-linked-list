/**
* Node.h 
* circular doubly linked list te olusturulan algoritmaya ile veri kaydi
* Yaz okulu 1.Ogretim B grubu
* 1.odev
* 16/08/2020
* Bugrahan Erk Vural
*/

#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

struct Node
{
	struct Node* next;
	struct Node* prev;
	int data;
	Node(const int data, Node* next = NULL, Node* prev = NULL);
};
#endif