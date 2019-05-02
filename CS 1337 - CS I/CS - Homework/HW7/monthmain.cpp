//Homework 7

#include <string>
#include <iostream>
#include "month.h"

using namespace std;

int main()
{
    //Shows off a month that is default then added twice to.
    month url;
    cout << "Month number " <<url.getMonthNumber() <<" which means it's " <<url.getMonth()<<"\n";
    url++;
    cout << "Month number is now " <<url.getMonthNumber() <<" which means it's " <<url.getMonth()<<"\n";
    ++url;
    cout << "Month number is now " <<url.getMonthNumber() <<" which means it's " <<url.getMonth()<<"\n\n";
    url.~month();

    //shows off a month that is made via number and then subtracted from
    month url2(5);
    cout << "Month number " <<url2.getMonthNumber() <<" which means it's " <<url2.getMonth()<<"\n";
    url2--;
    cout << "Month number is now " <<url2.getMonthNumber() <<" which means it's " <<url2.getMonth()<<"\n";
    --url2;
    cout << "Month number is now " <<url2.getMonthNumber() <<" which means it's " <<url2.getMonth()<<"\n\n";
    url.~month();

    //shows off a month made by month name and overloaded cout
    month url3("March");
    cout <<url3<<"\n";
    url3.~month();

    //shows off a default month overriden with the cin.
    month url4;
    cin >> url4;
    cout << "Month number " <<url4.getMonthNumber() <<" which means it's " <<url4.getMonth()<<"\n\n";
    url4.~month();

    //shows off a return 0;
    return 0;
}
