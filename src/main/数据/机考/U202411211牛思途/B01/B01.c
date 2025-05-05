#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// authored by niusitu U202411211
const int size=20;
void setRandomArray(int *x, const int size);
void sortArrayBubble(int *x,const int size);
void displayResults(int *x,const int size, int *foundNum);
int main()
{
int array[size];
int *x=&array[0];
int count=0;
int *foundNum = &count;
setRandomArray(x,size);
printf("\n");
sortArrayBubble(x,size);
displayResults(x,size,foundNum);
return 0;
}
void setRandomArray(int *x, const int size)
{
    int i;
    srand(time(NULL));
    for(i = 0; i < size;i++)
    {
        *(x+i)=((rand())%99)+1;
        printf("%d ",*(x+i));
    }
}
void sortArrayBubble(int *x,const int size)
{
    int i;
    int j;
    for(i=0;i<size;i++)
    {
        for(j=size;j>i;j--)
    {
        int temp;
        if((*(x+j))< (*(x+j-1)))
        {
            temp=*(x+j-1);
            *(x+j-1)=*(x+j);
            *(x+j)=temp;
        }
    }
    }
    for(i=0;i<size;i++)
    {
        printf("%d ",*(x+i));
    }
    }
void displayResults(int *x,const int size, int *foundNum)
{
    int i;
    for (i = 0;i<size-3;i++)
    {
    while(*(x+i+1) - *(x+i) == *(x+i+2) - *(x+i+1))
    {
        if(*(x+i) - *(x+i-1) != *(x+i+1) - *(x+i)){
            printf("\n%d %d %d\n",*(x+i),*(x+i+1),*(x+i+2));
                *foundNum++;
        }
        else{
            printf("\n%d \n",*(x+i+2));
        }
    i++;

    printf("\n%d\n",*foundNum);
    }
    }

}

