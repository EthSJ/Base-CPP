//Homework 8

#ifndef UPPERCASER_H
#define UPPERCASER_H
#include "filter.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//changes to upper, inherits from filter
class uppercaser : public filter
{
//doFilter specific to uppercaser
//traansformer changes to upper.
public:
    void doFilter(ifstream &in, ofstream &out);
    char transformer(char ch);

};

#endif // UPPERCASER_H
