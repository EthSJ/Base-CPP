//Homework 8

#ifndef COPYER_H
#define COPYER_H
#include "filter.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//copier class inheriting from filter
class copyer : public filter
{
    //copyer's specific doFilter
public:
    void doFilter(ifstream &in, ofstream &out);
};


#endif // COPYER_H
