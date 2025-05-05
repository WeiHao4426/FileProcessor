//Yang Qinghan U202413716
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE    20
#define VASIZE  99

void setRandomArray(int *a, const int size);
void insertSort(int a[], const int size);
void displayResults(int *a, const int size, int *foundNum);

void printArray(int a[], const int size);

int main()
{
    srand(time(NULL));

    int a[SIZE];
    int foundNum ;
    setRandomArray(a, SIZE);
    printf("The random array is:\n");
    /*a[0] = 1;
    a[2] = 3;
    a[3] = 9;*/
    printArray(a, SIZE);

    insertSort(a, SIZE);
    printf("The sorted array is:\n");
    printArray(a, SIZE);


    displayResults(a, SIZE, &foundNum);

    return 0;
}

void setRandomArray(int *a, const int size)
{
    int i;
    for(i = 0; i < size; i ++)
    {
        a[i] = rand() % VASIZE + 1;
    }

    return;
}
void insertSort(int a[], const int size)
{
    int insertValue, i, j, hold;
    for(i = 1; i < size; i ++)
    {
        insertValue = a[i];
        for(j = i - 1; j >= 0 && a[j] > insertValue; j --)
        {
            hold = a[j];
            a[j] = a[j + 1];
            a[j + 1] = hold;
        }
    }

    return;
}
void displayResults(int *a, const int size, int *foundNum)
{
    *foundNum = 0;
    int mem[50];
    float foundedK[50] = {0};
    int current, i, j, k;
    if(size > 50)
    {
        printf("Can't input such a big array!\n");
        *foundNum = -1;
        return;
    }

    for(i = 0; i < size - 2; i++)
    {
        mem[0] = a[i];
        for(j = i + 1; j < size - 1; j ++)
        {
            mem[1] = a[j];
            current = 1;
            if(foundedK[i] * mem[0] - mem[1] < 0.0001
               && foundedK[i] * mem[0] - mem[1] > -0.0001)//Judge whether the numbers have been founded before.
            {
                break;
            }

            for(k = j + 1; k < size; k ++)
            {
                if(a[k] * mem[current - 1] == mem[current] * mem[current])
                {
                    current ++;
                    mem[current] = a[k];
                }
            }
            if(current > 1)//Judge whether the numbers are more than 3.
            {
                //printf("In");
                foundedK[j] = (float) mem[1] / mem[0];//store the k.
                *foundNum += 1;
                printf("%d\n", *foundNum);
                printArray(mem, current + 1);
                printf("\n");
            }
        }
    }
    printf("Total find %d arrays.\n", *foundNum);
    return;
}

void printArray(int a[], const int size)
{
    int i ;
    for(i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
        if(i % 5 == 4)
        {
            printf("\n");
        }
    }

    return;
}
