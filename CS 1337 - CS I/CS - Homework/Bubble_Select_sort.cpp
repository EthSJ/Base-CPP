// Bubble and Selection sort for C++

//all "cout << "\n"" statements are for readability in output only.

#include <iostream>
using namespace std;

void BubbleSort(int arr[], const int &sizeOf);
void SelectSort(int arrayed[], const int &sizeOf);

int main()
{
    const int sizeOf = 8;
    int arr[sizeOf], arrayed[sizeOf];

    //Input of numbers from console. If not using console, use numbers: 1, 88, 5, 21, 75, 15, 9, and 12.
    cout << "Input 8 numbers. \n";
    for (int i = 0; i < sizeOf; i++)
    {
        cin >> arr[i];
        arrayed[i] = arr[i];
    }
    //output below is unsorted for first array
    cout << "Output for the first array is ";
    for (int i=0; i<sizeOf; i++)
    {
        cout << arr[i] <<" ";

    }
    cout << "\n";
    //bubble sort call
    BubbleSort(arr, sizeOf);
    cout <<"\n";

    //output below is unsorted for second array
    cout << "Output for the second array is ";
    for (int i=0; i<sizeOf; i++)
        {
            cout << arrayed[i] <<" ";

        }
    cout << "\n";
    // Selection sort call
    SelectSort(arrayed, sizeOf);

	return 0;
}
//bubble sort function
void BubbleSort(int arr[], const int &sizeOf)
{
    bool swapout;
    int tempvar;
    //Bubble sort code below
    do
        {
            swapout = false;
            for (int c = 0; c < (sizeOf-1); c++)
                {
                    if (arr[c] > arr[c + 1])
                        {
                            tempvar = arr[c];
                            arr[c] = arr[c + 1];
                            arr[c + 1] = tempvar;
                            swapout = true;
                        }
                }
         //print out array elements addition after swap.
        cout << "Output per bubble sort ";
        for (int i=0; i<8; i++)
            {
                cout << arr[i] <<" ";
            }
        cout << "\n";
        }
    while (swapout);
}
// Select sort function
void SelectSort(int arrayed[], const int &sizeOf)
{
    //selection sort
    int scanStart, indexMin, valueMin;
    for(scanStart=0; scanStart <(sizeOf-1); scanStart++)
    {
        indexMin = scanStart;
        valueMin = arrayed[scanStart];
        for(int i = scanStart+1; i < sizeOf; i++)
            {
                if (arrayed[i] < valueMin)
                    {
                        valueMin = arrayed[i];
                        indexMin = i;
                    }
            }
        arrayed[indexMin] = arrayed[scanStart];
        arrayed[scanStart] = valueMin;

        //modification to print out each round after swap
        cout << "Output per selection sort ";
        for (int i=0; i<8; i++)
            {
                cout << arrayed[i] <<" ";
            }
        cout << "\n";
    }

}
