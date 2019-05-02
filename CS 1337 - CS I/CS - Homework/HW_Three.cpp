

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

bool testPassword(char password[]);

int main()
{
    char passwordArr[14];
    int lengthOf;

//tells user password requirements and sets up length to check if too short.
    cout << "Input a password at least 6 to 14 characters long and must contain at least one upper case letter, one lower case letter, a number, and a punctuation symbol." << "\n";
    cin.getline(passwordArr, 14);
    lengthOf = strlen(passwordArr);

//Checks if password is too short. If fails, requests again.
    while (lengthOf < 5)
    {
        cout << "Password too short, please reenter." << "\n";
        cin.getline(passwordArr, 14);
    }

//test the password special conditions(upper,lower, number, punc) If fails, requests again.
    if (testPassword(passwordArr))
        cout << "Password is good." << "\n";
    else
    {
        cout << "Your password is not valid." <<"\n";
        cin.getline(passwordArr, 14);
    }

    return 0;
}


bool testPassword(char password[])
{
//all set to false until the password passes that test.
	bool anUpper = false, aLower = false, aDigit = false, puncMark = false ;

//goes through password until a requirement is either filled or not
	for (int i = 0 ; password[i] ; i++ )
		if (isupper(password[i]) )
			anUpper = true ;

		else if (islower(password[i]) )
			aLower = true ;

		else if (isdigit(password[i]) )
			aDigit = true ;

        else if (ispunct(password[i]))
            puncMark = true;

	if ((anUpper && aLower && aDigit && puncMark))
		return true;
	else
		return false ;
}
