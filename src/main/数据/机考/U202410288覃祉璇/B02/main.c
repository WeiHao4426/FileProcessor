//覃祉璇 U2022410288

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20
void setRandomArray(int *x,const int size);
void sortArrayInsert(int *x,const int size);
void diasplayResults(int *x,const int size,int *foundNum);

int main()
{
    srand(time(NULL));
    int array[SIZE] = {0};
    int i;

    setRandomArray(array,SIZE);
    for(i = 0;i < SIZE ; i ++)
    {
        printf("[%02d]%02d  ",i,array[i]);//用于测试数组是否设置完成
    }
    sortArrayInsert(array,SIZE);
    printf("\n");
    for(i = 0;i < SIZE ; i ++)
    {
        printf("[%02d]%02d  ",i,array[i]);//用于测试数组是否排序完成
    }
    printf("\n");

    int foundNum = 0;
    diasplayResults(array,SIZE,&foundNum);
    printf("Total found %d team(s)",foundNum);



    return 0;
}
void setRandomArray(int *x,const int size)
{
    int i;
    for(i = 0;i < SIZE ; i ++)
    {
        x[i] = rand()%99 + 1;
    }
}

void sortArrayInsert(int *x,const int size)
{
    int i,j,insert_value;
    for(i = 1; i < SIZE ; i ++)
    {
        insert_value = x[i];
        for(j = i - 1;(j >= 0) && (x[j] > insert_value); j --)
        {
            x[j + 1] = x[j];
        }
        if(j != i - 1)
        {
            x[j + 1] = insert_value;
        }
    }
}

void diasplayResults(int *x,const int size,int *foundNum)
{
    int i,j,k,integer;
    int n,gainNum;
    for(i = 0;i < size - 2; i ++)
    {
        for(j = i + 1; j < size - 1; j ++)
        {
            if(x[j] % x[i] == 0)
            {
                integer = x[j] / x[i];
                for(k = j + 1;k < size; k ++)
                {
                    if((x[k] % x[j] == 0)&&(x[k] / x[j] == integer)&&(integer != 1))
                    {
                        (*foundNum) ++;
                        gainNum = x[k] * integer;
                        printf("{%02d,%02d,%02d",x[i],x[j],x[k]);
                        n = (size + k)/2;
                        while((n < size) && (n > k))
                        {
                            if(x[n] == gainNum)
                            {
                                printf(",%02d",x[n]);
                                gainNum = x[n] * integer;
                                n = (n + size) / 2;
                                continue;
                            }
                            if (x[n] < gainNum)
                            {
                                n = (n + size) / 2;
                            }
                            if (x[n] > gainNum)
                            {
                                n = (n + k) / 2;
                            }
                        }
                        printf("}\n");
                    }
                }
            }
        }
    }
}
