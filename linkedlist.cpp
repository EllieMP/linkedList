#include <cstddef> // needed for NULL on newer compilers
#include "linkedlist.hpp"

LinkedList::LinkedList() {
    first->value = NULL;
    first->next = nullptr;
    last->value = NULL;
    last->next = nullptr;
    size = 0;
}

ostream& operator<< (ostream& out, const LinkedList& LL) {
    Node* tempNode = LL.first; //Makes a temporary copy of first
    for (int i = 0; i < LL.size; ++i) {
        out << tempNode->value << " ";
        tempNode = tempNode->next; //Moves temp node to the next node
    }
}


bool LinkedList::InsertFirst(int v) {
    Node* newNode = new Node;
    if (newNode == nullptr) return false;  //If we run out of memory return false
    newNode->value = v;
    newNode->next = first;
    first = newNode;
    if (size == 0) last = newNode;
    size++;
    return true;
}
bool LinkedList::InsertLast(int v) {
    Node* newEndNode = new Node;
    if (newEndNode == nullptr) return false;  //If we run out of memory return false
    newEndNode->value = v;
    newEndNode->next = last;
    last = newEndNode;
    if (size == 0) first = newEndNode;
    size++;
    return true;
}