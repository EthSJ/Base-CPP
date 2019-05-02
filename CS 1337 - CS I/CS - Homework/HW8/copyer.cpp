//Homework 8

#include "copyer.h"
#include "filter.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//dofilter for copyer. Gets char by char and just copies it to an output. See main for output.
void copyer::doFilter(ifstream &in, ofstream &out)
{
    char got;
    while(!(in.eof()))
    {
        got=in.get();
        out << got;
    }
}
