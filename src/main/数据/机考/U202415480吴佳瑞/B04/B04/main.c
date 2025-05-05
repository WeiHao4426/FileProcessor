#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void setRandomArray(int *x, const int size);
void displayArray(int *x, const int size);
void sortArrayInsert(int *x, const int size);
void displayProductRelation(int *x, const int size, int *foundNum);

int main()
{
    srand(time(NULL));
    int size = 16;
    int arr[16];
    int *x = arr;
    setRandomArray(x, size);
    displayArray(x, size);
    sortArrayInsert(x, size);
    displayArray(x, size);
    int num = 0;
    int *foundNum = &num;
    displayProductRelation(x, size, foundNum);
    return 0;
}

void setRandomArray(int *x, const int size)
{
    int i;
    for ( i = 0; i < size; i ++ )
    {
        x[i] = 1 + rand() % 99;
    }
}
void displayArray(int *x, const int size)
{
    int i;
    for ( i = 0; i < size; i ++ )
    {
        printf("%d ",x[i]);
    }
    printf("\n");
}

void sortArrayInsert(int *x, const int size)
{
    int i, j, temp;
    for ( i = 1; i < size; i ++ )
    {
        temp = x[i];
        for ( j = i - 1; j >= 0 && x[j] > temp; j -- )
        {
            x[j + 1] = x[j];
        }
        x[j + 1] = temp;
    }
}
void displayProductRelation(int *x, const int size, int *foundNum)
{
    int i, j, k;
    for ( i = 0; i < size - 2 && x[i] < 10; i ++ )
    {
        for ( j = i + 1; j < size - 1; j ++ )
        {
            for ( k = j + 1; k < size; k ++ )
            {
                if ( x[i] * x[j] == x[k] )
                {
                    printf("{%d,%d,%d}",x[i],x[j],x[k]);
                    printf("\n");
                    (*foundNum) ++;
                }
            }
        }
    }
    printf("find total %d numbers",*foundNum);
}


