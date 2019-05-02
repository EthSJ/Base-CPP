//BaseNode.h (part of baseNode.cpp) for Project 5
//Liste faire: rein.
//Last 3 changes: Added comments, corrected private to protected, created class.

#ifndef BASENODE_H
#define BASENODE_H

class BaseNode
{
//Base parts. Includes text character, x and y coordinates.
protected:
    char textChar;
    int x;
    int y;
public:
    //Constructor, overloaded constructor, and destructor. see BaseNode.cpp
    BaseNode();
    BaseNode(char, int, int);
    ~BaseNode();

    //Get and set method for text character.
    char getText()
    {return textChar;}
    void setText(char t)
    {textChar=t;}

    //get and set method for x coordinate.
    int getX()
    {return x;}
    void setX(int t)
    {x=t;}

    //get and set method for y coordinate.
    int getY()
    {return y;}
    void setText(int t)
    {y=t;}

};

#endif // BASENODE_H
