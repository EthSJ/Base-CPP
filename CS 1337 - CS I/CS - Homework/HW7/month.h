//Homework 7

#ifndef MONTH_H
#define MONTH_H

#include <string>
#include <iostream>
using namespace std;

class month
{
//the month's name and number
private:
    string name;
    int monthNumber;
public:
    //constructors+deconstructors+overloaded operators
    month();
    month(string qq);
    month(int qq);
    ~month();
    month operator++();
    month operator++(int);
    month operator--();
    month operator--(int);

    //set and gets for number
    int getMonthNumber()
    {return monthNumber;}
    void setMonthNumber(int h)
    {monthNumber=h; }

    //set and gets for month name
    string getMonth()
    {return name;}
    void setMonth(string h)
    {name=h; }

    //overloaded input/output
    friend ostream& operator <<(ostream&, const month&);
    friend istream& operator >>(istream&, month&);


};

#endif // MONTH_H
