#include "TestScores.h"
#include <iostream>
using namespace std;

TestScore::TestScore()
{
    score1 = 0;
    score2 = 0;
    score3 = 0;
}


double TestScore::theAverage(int score1, int score2, int score3)
{
    double average = (score1+score2+score3)/3;
    return average;
}
