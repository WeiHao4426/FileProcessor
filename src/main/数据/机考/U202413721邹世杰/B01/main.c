//邹世杰    U202413721
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void setRandomArray(int *x,const int size);
void sortArrayBubble(int *x,const int size);
void displayResult(int *x,const int size,int foundnum);

int main()
{
    srand(time(NULL));
    int x[SIZE] = {0};
    int foundNum = 0;
    setRandomArray(x,SIZE);
    sortArrayBubble(x,SIZE);
    displayResult(x,SIZE,foundNum);
    printf("%d",foundNum);

    return 0;
}

void setRandomArray(int *x,const int size)
{
    int i = 0;
    for(;i < size;i ++)
    {
        x[i] = rand()%99 + 1;
    }
    return;
}

void sortArrayBubble(int *x,const int size)
{
    int i = 0;
    for(;i < size;i ++)
    {
        int n = 0;
        for(;n < size-i-1;n ++)
        {
            if(x[n] > x[n+1])
            {
                int max = x[n];
                x[n] = x[n+1];
                x[n+1] = max;
            }
        }
    }
    return;
}

int displayResult(int *x,const int size,int foundnum)
{
    int n = 0;
    for(;n < size-2;n ++)
    {
        if(x[n+2]+x[n] == 2*x[n+1])
        {
            *foundnum ++;
            printf("{%d,%d,%d}\n",x[n],x[n+1],x[n+2]);
        }
    }
    return;
}
