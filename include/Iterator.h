/**
* Iterator.h 
* circular doubly linked list te olusturulan algoritmaya ile veri kaydi
* Yaz okulu 1.Ogretim B grubu
* 1.odev
* 16/08/2020
* Bugrahan Erk Vural
*/

#ifndef ITERATOR_H
#define ITERATOR_H

#include "Node.h"

class Iterator {
public:
	Node* current;
	Iterator() {
		current = NULL;
	}
	Iterator(Node* Node) {
		current = Node;
	}
	bool IsEndNode();
	void StepNext();
	void StepBack();
	const int& GetCurrentData()const;
};

#endif