// Homework 2(C.12)


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    char vowel;

    //Start of naming commands file
    ifstream vowelsIn;

    string fileInName;
    cout << "Name the file you wish to work with: ";
    cin >> fileInName;

    //Finishes naming file to open. Include .txt on file name, case sensitive, and must give path if located outside of default
    vowelsIn.open(fileInName);

    fstream vowelsOut;
    vowelsOut.open("Vowels_" + fileInName, ios::out);

    do
    {
        //gets the next character in input file
        vowel = vowelsIn.get();
        //checks for capital vowels.
        if (vowel == 'A'||vowel == 'E'||vowel=='I'||vowel=='O'||vowel=='U')
            {
                vowelsOut << vowel;
            }

        //check for lower case vowel.
        if (vowel=='a'||vowel=='e'||vowel=='i'||vowel=='o'||vowel=='u')
            {
                vowelsOut << vowel;
            }
        //Checks for newline
        if(vowel == '\n')
            {
                vowelsOut << '\n';
            }

        }while (!vowelsIn.eof());

        vowelsIn.close();
        vowelsOut.close();

    return 0;
}
