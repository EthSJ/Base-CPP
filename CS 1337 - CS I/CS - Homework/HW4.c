
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void bubbleSort(char *point);
void driverFunc(char *point);

/*evil global variable for size.*/
const int SIZE = 10;

/*Makes a pointer and calls driverFunction.*/
int main()
{
    char *point;
    driverFunc(point);

    return 0;
}
/*bubble sorts with the pointer*/
void bubbleSort(char *point)
{
    bool swapped;
    int temp, i;
    do
    {
        swapped = false;
        for(i=0;i<(SIZE-1);i++)
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
    int i,c,k;
    /*makes dynamic array and points point to first part.*/
    point =malloc(SIZE * sizeof(int));

    /*user input for what's going into it at each spot.*/
    printf("Input a number for spots 1 - 10: ");
    for(i=0; i < SIZE; i++)
    {
        scanf("%i",point+i);
    }

    /*spits out what array looks like now.*/
    printf("Array before sorting \n");
    for(c=0; c < SIZE; c++)
    {
        printf("%c", *(point+c));
        if(c==(SIZE-1))
            printf(".\n");
        else
            printf(", ");
    }
    /*bubble sorts*/
    bubbleSort(point);

    /*spits out sorted array*/
    printf("Array after sorting \n");
    for(k=0; k < SIZE; k++)
    {
        printf("%c\n",*(point+k));
        if(k==(SIZE-1))
            printf(".\n");
        else
            printf(", ");
    }
    /*clean up*/
    free(point);
}
