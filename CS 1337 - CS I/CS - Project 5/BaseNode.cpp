//BaseNode.cpp (part of baseNode.h) for Project 5

//Liste faire: rein.
//Last 3 changes: added comments, added functions, created class.

//base includes
#include <iostream>
#include "BaseNode.h"
using namespace std;

//basenode creation. Simply sets the text character to space.
BaseNode::BaseNode()
{
    textChar = ' ';
}

//Overloaded constructor. Sets text, x, and y off provided variables.
//Added silly names for the fun of it.
BaseNode::BaseNode(char sillyNames, int forThe, int funOfIt)
{
    textChar = sillyNames;
    x=forThe;
    y=funOfIt;
}

//BaseNode deconstructor.
//debug text in comments.
BaseNode::~BaseNode()
{
    //cout<<"This is basenode destructor being called!\n";
}
