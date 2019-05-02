

#include <iostream>
#include <ctype.h>

using namespace std;

//The node of the linked list. Named noodle for fun.
struct Noodle
{
    int number;
    Noodle* next;
};
//For testing function
void printList(Noodle* head);
void addNoodle(Noodle* &head, int num);

//What is actually requested in homework. See last two functions at bottom.
//Adds to end of queue and deletes from start, respectively.
void EndQueue(Noodle* head, int num);
void DeQueue(Noodle* &head);

int main()
{
    int num = 1, before;
    char take;
    Noodle *head = nullptr;

    //Set up a queue before adding self.
    cout<< "How many people are here before you?" << "\n";
    cin >> before;
    for(int i = 0; i < before; i++)
    {
        addNoodle(head, num);
        num++;
    }

    //Assumes you want to join the queue. Tell it y or Y.
    //Adds to end of queue, prints list, then deletes from front of queue. Otherwise, just prints the list.
    cout<< "Take a number and join the queue? (Y/N)"<< "\n";
    cin >> take;
    if(toupper(take) == 'Y')
    {
        cout << "Your number is "<< num << ".\n";
        EndQueue(head, num);
        cout<< "The current queue is: ";
        printList(head);
        cout << "\n";
        DeQueue(head);
        cout<< "The first person in line is finished, the new queue is: ";
        printList(head);
        cout<< "\n";

    }
    else
    {
        printList(head);
    }

    return 0;
}
//prints the list
void printList(Noodle* pntr)
{
    while (pntr)
    {
        cout << pntr->number <<" ";
        pntr = pntr->next;
    }
    cout << "\n";
}
//Adds a node in if head doesn't already exist + sorts. Useless here, but nice to have in case.
void addNoodle(Noodle* &head, int num)
{
    Noodle* i = new Noodle;
    i->number = num;
    i->next = nullptr;

    if (!head)
        head = i;
    else if ((i->number) < (head->number))
    {
        i->next = head;
        head = i;
    }
    else
    {
        Noodle* p1 = head;
        while (p1->next)
        {
            if ((p1->next->number) > (i->number))
            {
                i->next = p1->next;
                p1->next = i;
                return;
            }
            p1 = p1->next;
        }
        p1->next = i;
    }

}

//what is needed in homework
//adds to end of the queue
void EndQueue(Noodle* head, int num)
{
    Noodle* temp = new Noodle;
    temp->number = num;
    temp->next = NULL;

    //if head doesn't exist, it does now!
    if(!head)
    {
        head = temp;
        return;
    }
    else
    {
        Noodle* last = head;
        //finds end of the linked list while there's a next item in the list
        while(last->next)
            last=last->next;
        //links the new item to the last linked list item
        last->next = temp;
    }

}
//deletes first linked list item
void DeQueue(Noodle* &head)
{
    Noodle* temp = head;
    head = head->next;
    delete temp;
}
