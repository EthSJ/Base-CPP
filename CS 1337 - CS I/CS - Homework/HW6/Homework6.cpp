

#include "TestScores.h"
#include <iostream>

using namespace std;

int main()
{
    TestScore test;
    int s1,s2,s3;
    cout<<"What are your test scores?\n";
    cin>> s1 >>s2 >>s3;
    test.changeScore1(s1);
    test.changeScore2(s2);
    test.changeScore3(s3);

    cout<<"Your average is "<< test.theAverage(s1, s2, s3) <<".\n";


    return 0;
}



