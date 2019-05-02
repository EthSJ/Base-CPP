//Gridnode.cpp (part of gridnode.h)
//Liste faire: rein.
//Last 3 changes: Added comments, added gridnode, added debug for counting destruction/construction (correct number).

#include <iostream>
#include "gridnode.h"
using namespace std;

/* Debug comments in c-style comments */
/*int q=1, w=1;*/

//default gridnode constructor.
Gridnode::Gridnode()
{
   /*cout<<"Created Node "<<q<<" of 2500\n";*/
    up=down=left=right=NULL;

    /*q++;*/
}

//Gridnode overloaded constructor. Takes four pointers. Useful for adding in weird places.
Gridnode::Gridnode(Gridnode *l, Gridnode *r, Gridnode *u, Gridnode *d)
{
    up = u;
    down = d;
    left = l;
    right = r;
}

//Grid node deconstructor. Deletes pointers.
Gridnode::~Gridnode()
{
    /*cout<<"Deleted Node " <<w<< " of 2500\n";*/

    delete up;
    delete down;
    delete left;
    delete right;

    /*w++;*/
}
