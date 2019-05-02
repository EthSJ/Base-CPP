#ifndef TESTSCORES_H
#define TESTSCORES_H

using namespace std;

class TestScore
{
private:
    int score1;
    int score2;
    int score3;

public:
    TestScore();

    int getScore1()
    { return score1;  }

    int getScore2()
    { return score2;  }

    int getScore3()
    { return score3;  }

    void changeScore1(int scored)
    { score1 = scored; }

    void changeScore2(int scored)
    { score2 = scored; }

    void changeScore3(int scored)
    { score3 = scored; }

    double theAverage(int score1, int score2, int score3);
};

#endif // TESTSCORES_H
