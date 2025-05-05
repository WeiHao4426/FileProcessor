#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void setRandomArray ( int *x, const int size );//获取随机数数组，元素取值范围1到99
void sortArraySelect ( int *x, const int size );//对数组元素升序排序,运用选择排序
void displaySumRelation( int *x, const int size, int *foundNum );//打印所有符合一元素为另外两元素和的情况，并返回个数

int main()
{
    const int size = 16;
    int *x[size] ;
    srand( time( NULL));
    setRandomArray ( *x, size );
    sortArraySelect ( *x, size );
    int num = 0;
    int *irr = &num;
    displaySumRelation( *x, size, *irr );
}

void setRandomArray ( int *x, const int size )
{
    int integer1 = 0;//用来循环增加的变量
    for ( ; integer1 < size; integer1 ++ )
    {
        *(x + integer1) = rand() % 100;
    }
}

void sortArraySelect ( int *x, const int size )//选择排序
{
    int index1;//每次循环确定的最小值应放入的数组位置
    int index2;//循环筛选出最小值
    int insertIndex;//确定最小值所在的数组位置
    int value;//用来交换两数位置

    for ( index1 = 0; index1 < size; index1 ++ )
    {
        insertIndex = index1;
        for ( index2 = index1 + 1; index2 < size; index2 ++ )
        {
            if ( *(x + index2) < *(x + insertIndex) )
            {
                insertIndex = index2;
            }
        }
        if ( insertIndex != index1 )
        {
            value = *(x + index1);
            *(x + index1) = *(x + insertIndex);
            *(x + insertIndex) = value;
        }
    }
}

void displaySumRelation( int *x, const int size, int *foundNum )
{
    int change1;
    int change2;
    int change3;
    for ( change1 = 0; change1 < size; change1 ++ )
    {
        for ( change2 = change1 + 1; change2 < size; change2 ++ )
        {
            for ( change3 = change2 + 1; change3 < size; change3 ++ )
            {
                if ( *(x + change1) + *(x + change2) == *(x + change3))
                {
                    *foundNum ++;
                    printf ("{%d,%d,%d}\n", *(x + change1), *(x + change1), *(x + change1));
                }
            }
        }
    }
    printf ("一共有%d对", *foundNum );
}
