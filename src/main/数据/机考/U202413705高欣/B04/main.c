#include <stdio.h>
#include <stdlib.h>

void setRandomArray(int *x,const int size);
void sortArrayInsert(int *x,const int size);
void displayProductRelation(int *x,const int size,int *foundNum);
int main()
{
    srand(time(NULL));
    const int size = 16;
    int a[size];
    int foundNum = 0;
    int *fPtr = &foundNum;
    setRandomArray(a,size);
    sortArrayInsert(a,size);
    displayProductRelation(a,size,fPtr);
    return 0;
}
void setRandomArray(int *x,const int size)
{
        int i;
        for(i=0;i<size;i++)
        {
            x[i] = 1+rand()%99;
        }
        for(i=0;i<size;i++)
        {
            printf("%d ",x[i]);
        }
        printf("\n");
        return;
}
void sortArrayInsert(int *x,const int size)
{
    int i,j;
    int insert;
    for(i=1;i<=size;i++)
    {
        insert = x[i];
        for(j=i-1;j>=0&&insert<x[j];j--)
        {
            x[j+1] = x[j];
        }
        if(j!=i-1)
        {
            x[j] = insert;;
        }
    }
    for(i=0;i<size;i++)
    {
        printf("%d ",x[i]);
    }
    return;
}
void displayProductRelation(int *x,const int size,int *foundNum)
{
    int i,j,m;
    for(i=0;i<size-2;i++)
    {
        for(j=i+1;j<size-1;j++)
        {
            for(m=j+1;m<size;m++)
            {
                if(x[m]==x[i]*x[j])
                {
                    printf("%d,%d,%d",x[i],x[j],x[m]);
                    *foundNum++;
                }
            }
        }
    }
    return;
}
