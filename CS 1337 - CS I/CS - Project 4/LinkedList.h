//Project 4
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <cstring>
#include "Node.h"
using namespace std;

class LinkedList
{
private:
    //points to head node.
    Node* head;

public:
    //Linked list constructors and finally deconstructor.
    LinkedList();
    LinkedList(Node *next);
    ~LinkedList();

    //simply returns where the head is.
    Node* getLead()
    {return head;}

    //Add nodes + get rid of node.
    void addNode(Node* newNode);
    void addToEnd(Node* newNode);
    void deleteNode(Node* &head, int exponent);

    //prints the node.
    //See LinkedList.cpp for more specifics on changes need to be made before using.
    void printList(Node* ptr);

};

#endif // LINKEDLIST_H

