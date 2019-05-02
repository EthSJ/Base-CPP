//Homework 8

#ifndef FILTER_H
#define FILTER_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//virtual function of the doFilter
class filter
{
public:
    virtual void doFilter(ifstream &in, ofstream &out);
};

#endif // FILTER_H
