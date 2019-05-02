
#include <iostream>

using namespace std;

void bubbleSort(char *point);
void driverFunc(char *point);

//evil global variable for size.
const int SIZE = 10;

//Makes a pointer and calls driverFunction.
int main()
{
    char *point;
    driverFunc(point);

    return 0;
}
//bubble sorts with the pointer
void bubbleSort(char *point)
{
    bool swapped;
    int temp;
    do
    {
        swapped = false;
        for(int i=0;i<(SIZE-1);i++)
            {
                 if(*(point+i) > *(point+i+1))
                 {
                     temp = *(point+i);
                     *(point+i) = *(point+i+1);
                     *(point+i+1) = temp;
                     swapped = true;
                 }
            }
    }while (swapped);
}

void driverFunc(char *point)
{
    //makes dynamic array and points point to first part.
    char *dynamArray = new char[SIZE];
    point = dynamArray;

    //user input for what's going into it at each spot.
    cout << "Input a number for spots 1 - 10: ";
    for(int i=0; i < SIZE; i++)
    {
        cin >> *(point+i);
    }

    //spits out what array looks like now.
    cout<< "Array before sorting "<< "\n";
    for(int i=0; i < SIZE; i++)
    {
        cout<< *(point+i);
        if(i==(SIZE-1))
            cout<< ".\n";
        else
            cout<<", ";
    }
    //bubble sorts
    bubbleSort(point);

    //spits out sorted array
    cout<< "Array after sorting "<< "\n";
    for(int i=0; i < SIZE; i++)
    {
        cout<< *(point+i);
        if(i==(SIZE-1))
            cout<< ".\n";
        else
            cout<<", ";
    }
    //clean up
    delete [] dynamArray;
}
