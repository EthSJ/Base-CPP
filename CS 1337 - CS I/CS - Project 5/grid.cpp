//Grid.cpp (part of grid.h) for
//Liste faire: rein.
//Last 3 changes: Added comment, wrote display, added comments.

//base includes
#include <iostream>
#include "grid.h"
using namespace std;

//creates the grid. Code provided by Jason Smith.
grid::grid()
{
    Gridnode *r1, *r2, *p;
    //create first node on row 1
    r1 = new Gridnode;
    r1->x = 1;
    r1->y = 1;
    head = r1;
    //create rest of row 1
    for (int i = 2; i <= 50; i++ )
    {
        r2 = new Gridnode;
        //link left and right pointers
        r2->left = r1;
        r1->right = r2;
        //initialize row and column
        r2->x = 1;
        r2->y = i;
        //move r1 forward
        r1 = r2;
    }
    //reset r1 to beginning of row
    r1 = head;
    //create remaining rows
    for (int i = 2; i <= 50; i++)
    {
        r2 = new Gridnode;
        //link up and down
        r2->up = r1;
        r1->down = r2;
        //initialize row and column
        r2->x = i;
        r2->y = 1;
        //move r1 down to hold beginning of row
        r1 = r2;
        //create rest of row
        for (int j = 2; j <= 50; j++)
        {
            p = new Gridnode;
            //initialize row and column
            p->x = i;
            p->y = j;
            //link to node on the left
            p->left = r2;
            r2->right = p;
            //link to node above
            p->up = r2->up->right;
            p->up->down = p;
            //move r2 forward
            r2 = p;
        }
    }
}
//creates the grid as well, but has the added benefit of adding in a premade head node.
grid::grid(Gridnode *h)
{
    head = h;
    Gridnode *r1, *r2, *p;
    //create first node on row 1
    r1 = new Gridnode;
    r1->x = 1;
    r1->y = 1;
    head = r1;
    //create rest of row 1
    for (int i = 2; i <= 50; i++ )
    {
        r2 = new Gridnode;
        //link left and right pointers
        r2->left = r1;
        r1->right = r2;
        //initialize row and column
        r2->x = 1;
        r2->y = i;
        //move r1 forward
        r1 = r2;
    }
    //reset r1 to beginning of row
    r1 = head;
    //create remaining rows
    for (int i = 2; i <= 50; i++)
    {
        r2 = new Gridnode;
        //link up and down
        r2->up = r1;
        r1->down = r2;
        //initialize row and column
        r2->x = i;
        r2->y = 1;
        //move r1 down to hold beginning of row
        r1 = r2;
        //create rest of row
        for (int j = 2; j <= 50; j++)
        {
            p = new Gridnode;
            //initialize row and column
            p->x = i;
            p->y = j;
            //link to node on the left
            p->left = r2;
            r2->right = p;
            //link to node above
            p->up = r2->up->right;
            p->up->down = p;
            //move r2 forward
            r2 = p;
        }
    }
}

//Grid deconstructor. Debug text inside.
grid::~grid()
{
    //For suspected grid being unable to delete, decomment below
    //cout<<"Grid has been obliterated from this\n";
}

//comment on working goes here.
void grid::display()
{
    //Create two temps. One points to head, the other to nothing.
    Gridnode *temp = head;
    Gridnode *temp2;
    //Change i<50 to number of nodes up/down or WILL crash!
    //loops setting temp2 to temp doing loop, adding break and then moving down one.
    for(int i=0;i<50;i++)
    {
        temp2 = temp;
        //Prints going right below.
        for(int w=0;w<50;w++)
        {
            cout<<temp2->textChar;
            temp2 = temp2->right;
        }
        cout<<"\n";
        temp=temp->down;
    }
    cout<<"\n\n";
}

