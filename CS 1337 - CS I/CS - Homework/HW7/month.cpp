//Homework 7

#include "month.h"

#include <string>
#include <iostream>

//makes a bland blank jan.
month::month()
{
   name = "January";
   monthNumber=1;
}
//makes a month with just a name
month::month(string qq)
{
    //quickly sets name, then looks at the first couple letters to determine which month number it is.
    name = qq;
    if(toupper(qq[0]) == 'J' && toupper(qq[1])=='A')
        monthNumber=1;
    if(toupper(qq[0]) == 'F')
        monthNumber=2;
    if(toupper(qq[0]) == 'M'&& toupper(qq[1])=='A' && toupper(qq[2])=='R')
        monthNumber=3;
    if(toupper(qq[0]) == 'A' && toupper(qq[1])=='P')
        monthNumber=4;
    if(toupper(qq[0]) == 'M'&& toupper(qq[1])=='A' && toupper(qq[2])=='Y')
        monthNumber=5;
    if(toupper(qq[0]) == 'J' && toupper(qq[1])=='U' && toupper(qq[2])=='N')
        monthNumber=6;
    if(toupper(qq[0]) == 'J' && toupper(qq[1])=='U' && toupper(qq[2])=='L')
        monthNumber=7;
    if(toupper(qq[0]) == 'A' && toupper(qq[1])=='U')
        monthNumber=8;
    if(toupper(qq[0]) == 'S')
        monthNumber=9;
    if(toupper(qq[0]) == 'O')
        monthNumber=10;
    if(toupper(qq[0]) == 'N')
        monthNumber=11;
    if(toupper(qq[0]) == 'D')
        monthNumber=12;

}
//makes a month with just what number
month::month(int qq)
{
    //quickly sets the number, the looks at the number to determine the name.
    monthNumber= qq;
    if(qq==1)
        name="January";
    if(qq==2)
        name="February";
    if(qq==3)
        name="March";
    if(qq==4)
        name="April";
    if(qq==5)
        name="May";
    if(qq==6)
        name="June";
    if(qq==7)
        name="July";
    if(qq==8)
        name="August";
    if(qq==9)
        name="September";
    if(qq==10)
        name="October";
    if(qq==11)
        name="November";
    if(qq==12)
        name="December";
}

//prefix add
month month::operator++()
{
    //add one to month
    monthNumber = monthNumber + 1;
    //set back to real month if OoB
    if(monthNumber == 13)
        monthNumber = 1;
    //set month based on number
    if(monthNumber==1)
        name="January";
    if(monthNumber==2)
        name="February";
    if(monthNumber==3)
        name="March";
    if(monthNumber==4)
        name="April";
    if(monthNumber==5)
        name="May";
    if(monthNumber==6)
        name="June";
    if(monthNumber==7)
        name="July";
    if(monthNumber==8)
        name="August";
    if(monthNumber==9)
        name="September";
    if(monthNumber==10)
        name="October";
    if(monthNumber==11)
        name="November";
    if(monthNumber==12)
        name="December";
    return *this;
}
//postfix add
month month::operator++(int)
{
    month temp = *this;
    //adds one to month
    monthNumber = monthNumber + 1;
    //set back to real month if OoB
    if(monthNumber == 13)
        monthNumber = 1;
    //set to month via number search
    if(monthNumber==1)
        name="January";
    if(monthNumber==2)
        name="February";
    if(monthNumber==3)
        name="March";
    if(monthNumber==4)
        name="April";
    if(monthNumber==5)
        name="May";
    if(monthNumber==6)
        name="June";
    if(monthNumber==7)
        name="July";
    if(monthNumber==8)
        name="August";
    if(monthNumber==9)
        name="September";
    if(monthNumber==10)
        name="October";
    if(monthNumber==11)
        name="November";
    if(monthNumber==12)
        name="December";
    return temp;
}

//prefix minus
month month::operator--()
{
    //subtracts one from month
    monthNumber = monthNumber - 1;
    //Set back to real month if OoBs
    if(monthNumber == 0)
        monthNumber = 12;
    //set month via number search
    if(monthNumber==1)
        name="January";
    if(monthNumber==2)
        name="February";
    if(monthNumber==3)
        name="March";
    if(monthNumber==4)
        name="April";
    if(monthNumber==5)
        name="May";
    if(monthNumber==6)
        name="June";
    if(monthNumber==7)
        name="July";
    if(monthNumber==8)
        name="August";
    if(monthNumber==9)
        name="September";
    if(monthNumber==10)
        name="October";
    if(monthNumber==11)
        name="November";
    if(monthNumber==12)
        name="December";
    return *this;
}

//postfix minus
month month::operator--(int)
{
    month temp = *this;
    //subtracts one from month
    monthNumber = monthNumber - 1;
    //set back to real month if OoB
    if(monthNumber == 0)
        monthNumber = 12;
    //Set month via number search
    if(monthNumber==1)
        name="January";
    if(monthNumber==2)
        name="February";
    if(monthNumber==3)
        name="March";
    if(monthNumber==4)
        name="April";
    if(monthNumber==5)
        name="May";
    if(monthNumber==6)
        name="June";
    if(monthNumber==7)
        name="July";
    if(monthNumber==8)
        name="August";
    if(monthNumber==9)
        name="September";
    if(monthNumber==10)
        name="October";
    if(monthNumber==11)
        name="November";
    if(monthNumber==12)
        name="December";
    return temp;
}

//overloaded cout
ostream& operator << (ostream& str, const month &obj)
{
    //outputs the month's name and number. via returning stream
    str << "Name of month: " << obj.name << "\nNumber of month: " << obj.monthNumber << "\n";
    return str;
}

//overloaded cin.
istream& operator >>(istream& str, month& obj)
{
    //gets the name of the month
    cout << "Please enter the name: ";
    string nameIt;
    getline(cin, nameIt);
    obj.name=nameIt;

    //gets the number of the month
    cout << "Number of month: ";
    cin >> obj.monthNumber;

    //returns stream
    return str;
}


//month deconstructor
//doesn't really do anything fancy at the moment
month::~month()
{

}

