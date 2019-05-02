//Gridnode.h (part of gridnode.cpp)
//Liste faire: possible removal of grid being friend class. Right now, easier to leave that way.
//Last 3 changes: Added comments, split up gridnode and basenode (inheriting properly now), added overloaded constructor.

#ifndef GRIDNODE_H
#define GRIDNODE_H

//Base includes.
#include "BaseNode.h"
#include <iostream>
using namespace std;

class Gridnode : public BaseNode
{
//friend class of grid (makes it easier to code grid).
friend class grid;
//private members. Specific to gridnode. Some from basenode. See basenode.h.
private:
    Gridnode* left;
    Gridnode* right;
    Gridnode* up;
    Gridnode* down;

public:
    //Constructors for base and overloaded and destructor. See gridnode.cpp
    Gridnode();
    Gridnode(Gridnode *l, Gridnode *r, Gridnode *u, Gridnode *d);
    ~Gridnode();

    //Set and get method for going/setting left(west) pointers.
    Gridnode *getLeft()
    {return left;}
    void setLeft(Gridnode *w)
    {left=w;}

    //Set and get methods for going/setting right(east) pointers.
    Gridnode *getRight()
    {return right;}
    void setRight(Gridnode *e)
    {right=e;}

    //Set and get method for going/setting up(north) pointers.
    Gridnode *getUp()
    {return up;}
    void setUp(Gridnode *n)
    {up=n;}

    //Set and get method for going/setting down(south) pointers.
    Gridnode *getDown()
    {return down;}
    void setDown(Gridnode *s)
    {down=s;}
};

#endif // LINKEDLIST_H
