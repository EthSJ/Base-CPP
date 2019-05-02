//Project 4
#include "LinkedList.h"

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//linked list marker.
LinkedList::LinkedList()
{
    head = NULL;
}

//overloaded linked list constructor.
LinkedList::LinkedList(Node *next)
{
    head = next;
}

//Linked List obliterator. Deletes all nodes as well.
LinkedList::~LinkedList()
{
    Node *del = head;
    while (del!= NULL)
    {
        head = head->next;
        delete del;
        del = head;
    }
    head = NULL;
}

//adds a new node in.
//If no head, add. If it's bigger than head, swap. Else find a spot for it.
void LinkedList::addNode(Node* newNode)
{

    if (!head)
        head = newNode;
    else if ((newNode->exponent) > (head->exponent))
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node* p1 = head;
        while (p1->next)
        {
            if ((p1->next->exponent) < (newNode->exponent))
            {
                newNode->next = p1->next;
                p1->next = newNode;
                return;
            }
            p1 = p1->next;
        }
        p1->next = newNode;
    }

}
//Adds to the end of the list. Used for trig.
//Also useful other times as well. Considering making add to head function as well.
void LinkedList::addToEnd(Node* newNode)
{

    //if head doesn't exist, it does now!
    if(!head)
    {
        head = newNode;
        return;
    }
    else
    {
        Node* last = head;
        //finds end of the linked list while there's a next item in the list
        while(last->next)
            last=last->next;
        //links the new item to the last linked list item
        last->next = newNode;
    }
}

//deletes a node from the list. Matches by exponent.
void LinkedList::deleteNode(Node* &head, int exponent)
{
    if (!head)
        cout << "Empty list!\n";
    else if (head->exponent == exponent)
    {
        Node* hold = head;
        head = head->next;
        delete hold;
    }
    else
    {
        Node* p1 = head;
        while (p1->next)
        {
            if (p1->next->exponent == exponent)
            {
                Node* hold = p1->next;
                p1->next = p1->next->next;
                delete hold;
                return;
            }
            p1 = p1->next;
        }
        cout << "Number not in list\n";
    }
}

//recursively prints the list of all the nodes out.
//Edit middle if and last else statement as node variables change.
void LinkedList::printList(Node* ptr)
{
    //print it out
    if(ptr==NULL)
    {
        cout << "\n";
        return;
    }
    if(ptr->trig[0]== 'c' || ptr->trig[0] == 's' || ptr->trig[0]=='t')
    {
        if(ptr->trig[0]== 'c')
            cout<<ptr->coefficient<<"cos ("<<((ptr->exponent))<<"x) ";
        if(ptr->trig[0]== 's')
            cout<<ptr->coefficient<<"sin ("<<((ptr->exponent))<<"x) ";
        if(ptr->trig[0]== 't')
            cout<<ptr->coefficient<<"tan ("<<((ptr->exponent))<<"x) ";
    }
    else
        cout << ptr->coefficient <<"x^"<<ptr->exponent <<" ";
    printList(ptr->next);
}

