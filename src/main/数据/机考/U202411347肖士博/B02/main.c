#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

//肖士博U202411347

void setArrayInsert(int *x, const int size);
void setRandomResults(int *x, const int size);
void displayResults(int *x, const int size, int *foundNum);
int main()
{
    int x[SIZE] = {0};//清零
    srand(time(NULL));
    setRandomResults(x, SIZE);
    int i = 0;
    for(i = 0; i < SIZE; i ++)
    {
        printf("%d ", x[i]);
    }
    printf("\n");
    sortArrayInsert(x, SIZE);
    for(i = 0; i < SIZE; i ++)
    {
        printf("%d ", x[i]);
    }
    printf("\n");
    int num = 0;
    int *foundNum = &num;
    displayResults(x, SIZE, *foundNum);
    printf("\nFound :%d", *foundNum);

    return 0;
}


void sortArrayInsert(int *x, const int size)
{
    int i,j;
    int value;
    for(i = 1; i < size; i ++)
    {
        value = x[i];
        for(j = i - 1; j >= 0&&x[j] > value; j --)
        {
            x[j + 1] = x[j];
        }
        if(j != i - 1)
        {
            x[j + 1] = value;
        }
    }
    return;
}

void setRandomResults(int *x, const int size)
{
    int i;
    for(i = 0; i < size; i ++)
    {
        x[i] = rand() % 99 + 1;//得到1-99的随机数
    }
    return;
}

void displayResults(int *x, const int size, int *foundNum)
{
    int i = 0;
    int point, begin;
    int found = 0;
    int num = 0;
    for(i = 0; i < size - 2; i ++)//防止溢出
    {
        if(found == 0)
        {
            if(x[i] * x[i + 2] == x[i + 1] * x[i + 1])
            {
                begin = i;//等比数列开始
                point = i + 2;//结尾
                found = 1;
                num ++;
            }
        }
        else if(found == 1)
        {
            if(x[i] * x[i + 2] == x[i + 1] * x[i + 1])
            {
                point ++;
            }
            else
            {
                found = 0;
                int temp;
                printf("{");
                for(temp = begin; temp <= point; temp ++)
                {
                    printf("%d", x[temp]);
                    if(temp != point)//最后一次不打印，
                    {
                        printf(",");
                    }
                }
                printf("}\n");

            }
        }

    }
    foundNum = &num;
    return;
}
