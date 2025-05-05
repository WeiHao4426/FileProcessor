//name:刘宏远    U202413662    B03

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void setRandomArray( int *x, const int size );
void sortArraySelect( int *x, const int size );
void displaySumRelation( int *x, const int size, int *foundNum );

int main()
{
    srand( time(NULL) );

    const int size = 16;
    int x[size];
    int i;

    setRandomArray( x, size );

    printf("Before sorting:\n");
    for ( i = 0; i < size; i ++ )
    {
        printf("%d ", x[i] );
    }
     printf("\n\n");

    sortArraySelect( x, size );

    printf("After sorting:\n");
    for ( i = 0; i < size; i ++ )
    {
        printf("%d ", x[i] );
    }
    printf("\n\n");

    int foundNum, *foundNumptr = &foundNum;

    printf("Sum relations:\n");
    displaySumRelation( x, size, foundNumptr );
    puts("");
    printf("There are %d sum relations.", *foundNumptr );

    return 0;
}

void setRandomArray( int *x, const int size )
{
    int i;
    for ( i = 0; i < size; i ++ )
    {
        x[i] = 1 + rand() % 99;//set random integer(1-99)
    }
}

void sortArraySelect( int *x, const int size )
{
    int i, j;
    int min_value, min_index;

    for ( i = 0; i < size - 1; i ++ )
    {
        min_index = i;

//找出未排序数组中最小的元素
        for ( j = i + 1; j < size; j ++ )
        {
            min_index = ( x[min_index] < x[j] ) ? min_index : j;
        }

//是否交换
        if ( min_index != i )
        {
           min_value = x[min_index];
           x[min_index] = x[i];
           x[i] = min_value;
        }
    }
}

void displaySumRelation( int *x, const int size, int *foundNum )
{
    int i, j, k;
    int counter = 1;
    *foundNum = 0;

//遍历每一种元素组合看是否满足条件
    for ( i = 0; i < size; i ++ )
    {
        for ( j = i + 1; j < size; j ++ )
        {
            for ( k = j + 1; k < size; k ++ )
            {
                if ( *(x+i) + *(x+j) == *(x+k) )
                {
                    printf("[%d]:   %d + %d = %d\n", counter, *(x+i), *(x+j), *(x+k) );

                    counter ++;
                    (*foundNum) ++;
                }
            }
        }
    }
}
