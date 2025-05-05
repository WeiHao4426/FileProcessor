//詹金馨 U202413717
#include <stdio.h>
#include<time.h>
#define xSize 20

void setRandomArray(int *x,const int size);
void displayArray(int *x,const int size);
void sortArrayBubble(int *x,const int size);
void displayResults(int *x,const int size,int *foundNum);

int main()
{
     int foundNum,xArray[xSize];
     int *xPtr = xArray;
     int *fPtr = &foundNum;

     setRandomArray(xPtr,xSize);
     printf("The random array :\n");
     displayArray(xPtr,xSize);

     sortArrayBubble(xPtr,xSize);
     printf("The sorted array :\n");
     displayArray(xPtr,xSize);

     //displayResults(xPtr,xSize,fPtr);
     //printf("共找到%d组。",*fPtr);
}

void setRandomArray(int *x,const int size)
{
    srand((unsigned)time(NULL));
    int i;
    for(i = 0 ; i < size ; i ++)
    {
        *x = rand()%99 + 1;
        x ++;
    }
}

void displayArray(int *x,const int size)
{
    int i;
    for(i = 0;i < size; i ++)
    {
        if(i == size - 1)
        {
            printf("%d\n",*x);
        }
        else{
            printf("%d  ",*x);
            x ++;
        }
    }
}

void sortArrayBubble(int *x,const int size)
{
    int i,j;
    int changeNum,hold;
    for(i = 1 ; i < size ; i ++)
    {
        changeNum = 0;
        for(j = 0 ; j < xSize - i ; j ++)
        {
            if(*(x + j) > *(x + j + 1))
            {
                hold = *(x + j + 1);
                *(x + j + 1) = *(x + j);
                *(x + j) = hold;
                changeNum ++;
            }
        }
        if(changeNum == 0)
            {
                return ;
            }
    }
    return ;


}

