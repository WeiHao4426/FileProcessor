#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void setRandomArray(int *x,const int size)
{
    srand(time(NULL));
    int array[20] = { rand() };
    int i = (rand() % 99) + 1;
    *x = &i;
    printf("%d\n",*x);
}

void sortArrayBubble(int *x,const int size)
{
    srand(time(NULL));
    int array[20] = { 0 };
    int i = 1;
    int max = 0;
    for(;0 < i < 19;i ++)
    {
        if(array[i] > array[i + 1]){
            max = array[i];
            array[i] = array[i + 1];
            array[i + 1] = max;
        }
    }
    printf("%d\n",array[20]);
}

void displayResults(int *x,const int size,int *foundNum)
{
     int l = 0;
     int m = 1;
     int r = 2;
     if()

}
