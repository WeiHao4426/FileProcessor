//高梦超 U202413704
#include<stdio.h>
#include<time.h>

#define SIZE 16

void setRandomArray(int *x,const int size);

void sortArraySelect(int *x,const int size);

void displaySumRelation(int *x,const int size,int *foundNum);

int main(void)
{
    int i = 0;//用于循环打印出排序后的数组
    int a[SIZE];
    int foundNum= 0;
    setRandomArray(a,SIZE);
    sortArraySelect(a,SIZE);
    for(;i < SIZE;i ++)
    {
        printf("%5d",a[i]);
    }
    printf("\n");
    displaySumRelation(a,SIZE,&foundNum);

    if(foundNum == 0)
    {
        printf("Not found!");
    }
    else if(foundNum != 0)
    {
        printf("\nFound!Total %d pairs",foundNum);
    }

    return 0;
}
void setRandomArray(int *x,const int size)
{
    srand(time(NULL));
    int i = 0;

    for(i = 0;i < size;i ++)
    {
        x[i] = rand() % 100 + 1;
    }
}
void sortArraySelect(int *x,const int size)
{
    int i = 0;
    int j = 0;
    int min_index,min_value;
    for(i = 0;i < size - 1;i ++)
    {
        min_index = i;
        for(j = i + 1;j < size;j ++)
        {
            if(x[min_index] > x[j])
                {
                    min_index = j;
                }
        }
        if(min_index != i)
        {
            min_value = x[i];
            x[i] = x[min_index];
            x[min_index] = min_value;
        }
    }
}
void displaySumRelation(int *x,const int size,int *foundNum)
{
     int i,j,k;//用于循环
     for(i = 0;i < size;i ++)
     {
         for(j = i + 1;j < size;j ++)
         {
             for(k = j + 1;k < size;k ++)
             {
                 if(x[i] + x[j] == x[k])
                 {
                     (*foundNum)++;
                     printf("%d + %d = %d\n",x[i],x[j],x[k]);
                 }
             }
         }
     }
}

