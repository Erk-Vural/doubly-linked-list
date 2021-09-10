/**
* Iterator.cpp
* circular doubly linked list te olusturulan algoritmaya ile veri kaydi
* Yaz okulu 1.Ogretim B grubu
* 1.odev
* 16/08/2020
* Bugrahan Erk Vural
*/
#include "Iterator.h"

bool Iterator::IsEndNode() {
	return current == NULL;
}
void Iterator::StepNext() {
	if (!IsEndNode())
		current = current->next;
}
void Iterator::StepBack() {
	if (!IsEndNode())
		current = current->prev;
}
const int& Iterator::GetCurrentData()const {
	return current->data;
}