//Homework 8

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    //reads input file
    //The output to file
    //The saved output of what it should be
    ifstream in("input.txt");
    ofstream out("output.txt");
    ofstream out2("savedoutput.txt");

    //will do the work for encrypting the file.
    //Change the number to change what it gets changed by.
    //Links to filter.
    encrypter(6) a;
    filter *ptr = &a;

    //will do the work for copying the file to a saved output
    //change out2 to change the placement file.
    //Links to filter.
    copyer b;
    filter *ptr2 = &b;

    //will do the work for changing everything to uppercase.
    //change out to change the placement file.
    //Links to filter.
    uppercaser c;
    filter *ptr3 = &c;

    //copies before doing anything
    b.doFilter(in,out2);

    //changes to upper then encrypts
    //change the order to change up how it'd work slightly.
    c.doFilter(in,out);
    a.doFilter(in, out);


    return 0;
}
