//Homework 8

#ifndef ENCRYPTER_H
#define ENCRYPTER_H
#include "filter.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//encrypter. inherits from filter
class encrypter : public filter
{
//prevents the key from being obtained.
private:
    int key;
//makes and sets the key
public:
    encrypter(int i)
    {key=i;}

    //encrypter's specific doFilter
    void doFilter(ifstream &in, ofstream &out);
};

#endif // ENCRYPTER_H
