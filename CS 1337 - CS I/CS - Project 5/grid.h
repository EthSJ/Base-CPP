//Grid.h (part of grid.cpp) for Project 5

//Liste faire: rein.
//Last 3 changes: Added comments, added gethead, set first part back to private (from protected).

#ifndef GRID_H
#define GRID_H

//base includes.
#include <iostream>
#include "gridnode.h"
using namespace std;

class grid
{
private:
    //the head node
    Gridnode *head;
public:
    //default constructor, overloaded, and destructor. See grip.cpp
    grid();
    grid(Gridnode *h);
    ~grid();

    //Despite the name, does only the exciting task of returning head node.
    Gridnode* getHead()
    {return head;}

    //displays the grid. see grip.cpp
    void display();

};

#endif // GRID_H
