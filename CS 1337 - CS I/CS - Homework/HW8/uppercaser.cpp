//Homework 8

#include "uppercaser.h"
#include "filter.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//changes to an upper case letter. Returns letter.
char uppercaser::transformer(char ch)
    {
        ch = toupper(ch);
        return ch;
    }

//gets char by char from input, converts it, and then outputs it back to output.
void uppercaser::doFilter(ifstream &in, ofstream &out)
{
    char got;
    while(!(in.eof()))
    {
        got= in.get();
        got = transformer(got);
        out << got;
    }
}
