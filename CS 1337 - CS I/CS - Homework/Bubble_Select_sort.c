/* Bubble and Selection sort for C

//all "puts( "\n")" statements are for readability in output only.*/

#include <stdio.h>
/* Includes boolean values. Needed for the Bubble sort */
#include <stdbool.h>

void BubbleSort(int arr[], const int sizeOf);
void SelectSort(int arrayed[], const int sizeOf);

int main()
{
    const int sizeOf = 8;
    int arr[8], arrayed[8], i;

    /*Input of numbers from console. If not using console, use numbers: 1, 88, 5, 21, 75, 15, 9, and 12. */
    puts("Input 8 numbers.");
    for (i = 0; i < sizeOf; i++)
    {
        scanf(" %d", &arr[i]);
        arrayed[i] = arr[i];
    }

    /*output below is unsorted for first array */
    puts("Output for the first array is ");
    for (i=0; i<sizeOf; i++)
    {
        printf(" %i", arr[i]);

    }
    puts("\n");
    /*bubble sort call*/
    BubbleSort(arr, sizeOf);
    puts("\n");

    /*output below is unsorted for second array */
    puts("Output for the second array is ");
    for (i=0; i<sizeOf; i++)
        {
            printf(" %d", arrayed[i]);

        }
    puts("\n");
    /* Selection sort call */
    SelectSort(arrayed, sizeOf);

    return 0;
}

/*bubble sort function */
void BubbleSort(int arr[], const int sizeOf)
{
    bool swapout;
    int tempvar, i;
    /*Bubble sort code below*/
    do
        {
            swapout = false;
            for (i = 0; i < (sizeOf-1); i++)
                {
                    if (arr[i] > arr[i + 1])
                        {
                            tempvar = arr[i];
                            arr[i] = arr[i + 1];
                            arr[i + 1] = tempvar;
                            swapout = true;
                        }
                }
         /*print out array elements addition after swap.*/
        puts("Output per bubble sort ");
        for (i=0; i<8; i++)
            {
                printf(" %d", arr[i]);
            }
        puts("\n");
        }
    while (swapout);
}

/* Select sort function */
void SelectSort(int arrayed[], const int sizeOf)
{
    /*selection sort */
    int scanStart, indexMin, valueMin, i;
    for(scanStart=0; scanStart <(sizeOf-1); scanStart++)
    {
        indexMin = scanStart;
        valueMin = arrayed[scanStart];
        for(i = scanStart+1; i < sizeOf; i++)
            {
                if (arrayed[i] < valueMin)
                    {
                        valueMin = arrayed[i];
                        indexMin = i;
                    }
            }
        arrayed[indexMin] = arrayed[scanStart];
        arrayed[scanStart] = valueMin;

        /*modification to print out each round after swap*/
        puts("Output per selection sort ");
        for (i=0; i<8; i++)
            {
                printf(" %d", arrayed[i]);
            }
        puts("\n");
    }

}
