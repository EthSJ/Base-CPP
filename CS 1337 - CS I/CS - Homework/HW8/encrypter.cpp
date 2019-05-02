//Homework 8

#include "encrypter.h"
#include "filter.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//doFilter for encrypter. gets char by char and adds the key to it and stores it back to output
void encrypter::doFilter(ifstream &in, ofstream &out)
    {
        char got;
        while(!(in.eof()))
        {
            got = in.get();
            got = got+key;
            out << got;
        }
    }

