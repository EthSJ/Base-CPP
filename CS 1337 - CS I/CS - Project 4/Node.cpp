//Project 4
#include "Node.h"

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//Overloaded constructor. Simply sets all coeffcients.
Node::Node(double co, double dow, double ex, char tr[])
{
    coefficient=co;
    downCo=dow;
    exponent=ex;
    strcpy(trig, tr);
    next = nullptr;
}

//Deconstructor. Error messages due current functionallity
Node::~Node()
{

}
//Gets the trig starting at the first term.
char* Node::getTrig()
{
    char* c = &trig[0];
    return c;
}
//sets the trig by way of copying.
void Node::setTrig(char trigg[])
{
    strcpy(trigg, trig);
}



