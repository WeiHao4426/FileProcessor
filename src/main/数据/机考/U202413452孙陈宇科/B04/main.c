//U202413452 孙陈宇科
//B04
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 16//约定数组大小

void setRandomArray(int* x, const int size);
void sortArrayInset(int* x, const int size);
void displayProductRelation(int* x, const int size, int* foundNum);
void displayArray(int* x);//打印数组（测试用）

int main()
{
    srand(time(NULL));
    int arr[MAX_NUM];
    setRandomArray(arr, MAX_NUM);
    displayArray(arr);
    sortArrayInset(arr, MAX_NUM);
    displayArray(arr);

    int foundNum;
    displayProductRelation(arr, MAX_NUM, &foundNum);//主函数里foundNum是整型变量
    printf("%d", foundNum);

    return 0;
}
//创建1到99的数组
void setRandomArray(int* x, const int size)
{
    int i;
    for(i = 0; i < size; i ++)
    {
        x[i] = rand() % 99 + 1;
    }
}
//通过插入排序升序排序
void sortArrayInset(int* x, const int size){
    int i, j, tem = 0;

    for(i = 1; i < size; i ++)
    {
        tem = x[i];

        for(j = i - 1; (j >= 0) && (tem < x[j]); j --)
        {
            x[j + 1] = x[j];
        }

        if(j != i - 1)
        {
            x[j + 1] = tem;
        }
    }
}

void displayProductRelation(int* x, const int size, int* foundNum)
{
    if(size <= 3)
    {
        return;
    }//数组大小不足就结束
    int i, j, t;
    for (i = 0; i < size - 2; i ++)
    {
        for(j = i + 1; j < size - 1; j ++)//选两个数
        {
            for(t = j + 1; t < size; t ++)//依次看后面有没有数是他们的和
            {
                if(x[i] + x[j] == x[t])
                {
                    printf("{%d,%d,%d}\n", x[i], x[j], x[t]);
                    (*foundNum) ++;//计数（这里foundNum是指针）
                }
            }
        }
    }
}

void displayArray(int* x){
    int i;
    for(i = 0; i < MAX_NUM; i ++)
    {
        printf("%d ",x[i]);
    }
    printf("\b\b\n");
}
