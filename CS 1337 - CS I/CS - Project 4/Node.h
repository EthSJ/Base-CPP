//Project 4
#ifndef NODE_H
#define NODE_H

#include <string>
#include <cstring>
using namespace std;

class Node
{
//All the variables. Needed private by default.
public:
    double coefficient;
    double downCo;
    double exponent;
    char trig[4];
    Node *next;

public:
    //node constructor
    Node()
    {next=nullptr;}

    //overloaded constructor
    Node(double co, double dow, double ex, char tr[]);

    //destructor
    ~Node();

    //Set and get Coefficient calls.
    double getCoeff()
    { return coefficient; }
    void setCoeff(double coef)
    { coefficient=coef;  }

    //Set and get Exponent calls.
    double getExpon()
    { return exponent;}
    void setExpon(double exp)
    { exponent=exp;}

    //Set and get the trig calls.
    char* getTrig();
    void setTrig(char trigg[]);

    //Just in case, get and set the next node.
    Node *getNext()
    {return next;}
    void setNext(Node* n)
    {next = n; }


};

#endif // NODE_H
