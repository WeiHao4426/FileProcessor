//Authored by huang yan zhe U202413657
#include <stdio.h>
#include <stdlib.h>
#define SIZE 16
#define MIN 1
#define MAX 99

//set an array of random integers
void setRandomArray( int *x, const int size );
//sort the array with select-sorting method
void sortArraySelect( int *x, const int size );
//display sum relations in array
void displaySumRelation( int *x, const int size, int *foundNum );

int main( void )
{
    srand(time(NULL));
    int foundNum = 0;
    int array[SIZE] = {0};

    setRandomArray( array, SIZE );
    sortArraySelect( array, SIZE );
    displaySumRelation( array, SIZE , &foundNum );

    printf("\nFind %d in total.",foundNum);

    return 0;
}

void setRandomArray( int *x, const int size )
{
    int i;
    printf("Generated array:\n");
    for( i = 0 ; i < size ; i ++)
    {
        *(x + i) = MIN + rand() % MAX;
        printf("%4d",*(x + i));
    }
    printf("\n");

    return;
}

void sortArraySelect( int *x, const int size )
{
    int i,j;
    int min_index;
    int min_value;
    for( i = 0 ; i < size - 1 ; i ++)
    {
        min_index = i;
        for( j = i ; j < size ; j ++)//find the index of the min-value
        {
            if( *(x + j) < *(x + min_index) )
            {
                min_index = j;
            }
        }
        if( min_index != i )//exchange it with i
        {
            min_value = *(x + min_index);
            *(x + min_index) = *(x + i);
            *(x + i) = min_value;
        }
    }

    printf("Sorted Array:\n");
    for( i = 0 ; i < size ; i ++)//print the sorted array
    {
        printf("%4d",*(x + i));
    }
    printf("\n");
    return;
}

void displaySumRelation( int *x, const int size, int *foundNum )
{
    int i,j,k;
    for( i = 0 ; i < SIZE ; i ++)
    {
        for( j = i + 1 ; j < SIZE ; j ++)
        {
            int sum = *(x + i) + *(x + j);//get sum of each two numbers in array;
            for( k = 0 ; k < SIZE ; k ++)//check whether the sum is in the array
            {
                if( *(x + k) == sum )
                {
                    (*foundNum) ++;
                    printf("Find[%d]:{%d,%d,%d}\n",*foundNum,*(x + k),*(x + i),*(x + j));
                }
            }
        }
    }

    return;
}
