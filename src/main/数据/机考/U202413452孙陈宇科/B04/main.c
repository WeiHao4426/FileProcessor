//U202413452 ������
//B04
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 16//Լ�������С

void setRandomArray(int* x, const int size);
void sortArrayInset(int* x, const int size);
void displayProductRelation(int* x, const int size, int* foundNum);
void displayArray(int* x);//��ӡ���飨�����ã�

int main()
{
    srand(time(NULL));
    int arr[MAX_NUM];
    setRandomArray(arr, MAX_NUM);
    displayArray(arr);
    sortArrayInset(arr, MAX_NUM);
    displayArray(arr);

    int foundNum;
    displayProductRelation(arr, MAX_NUM, &foundNum);//��������foundNum�����ͱ���
    printf("%d", foundNum);

    return 0;
}
//����1��99������
void setRandomArray(int* x, const int size)
{
    int i;
    for(i = 0; i < size; i ++)
    {
        x[i] = rand() % 99 + 1;
    }
}
//ͨ������������������
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
    }//�����С����ͽ���
    int i, j, t;
    for (i = 0; i < size - 2; i ++)
    {
        for(j = i + 1; j < size - 1; j ++)//ѡ������
        {
            for(t = j + 1; t < size; t ++)//���ο�������û���������ǵĺ�
            {
                if(x[i] + x[j] == x[t])
                {
                    printf("{%d,%d,%d}\n", x[i], x[j], x[t]);
                    (*foundNum) ++;//����������foundNum��ָ�룩
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
