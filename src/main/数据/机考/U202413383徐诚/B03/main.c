//U202413383
//Author:Xu Cheng

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//�����������
void setRandomArray ( int *x, const int size );
//��ӡ����ǰ������
void displayArray ( int *x, const int size );
//ʹ��ѡ�������������
void sortArraySelect ( int *x, const int size );
//�����Ƿ��������֮�͹�ϵ����ϲ���ӡ����
void displaySumRelation ( int *x, const int size, int *foundNum );

int main( void )
{
    srand(time(NULL));
    const int size = 16;
    int myArray[size];
    int *iptr = &myArray[0];

    //���ó�ʼ����
    printf("Setting random array:\n");
    setRandomArray( iptr, size );
    displayArray( iptr, size );

    //��ӡ�������к�����
    printf("\nAfter sorting by selection:\n");
    sortArraySelect( iptr, size );
    displayArray( iptr, size );

    int total = 0;
    int *num = &total;

    //���ҷ�������֮�͹�ϵ�����
    printf("\nAll pairs meet the Sum Relation:\n");
    displaySumRelation( iptr, size, num );
    printf("Find total %d pairs",*num);

    return 0;
}

void displayArray ( int *x, const int size )
{
    int i;
    for ( i = 0; i < size; i ++ )
    {
        printf("%4d",*x);
        x ++;
    }
}

void setRandomArray ( int *x, const int size )
{
    int i;
    for ( i = 0; i < size; i ++ )
    {
        *x = 1 + rand() % 99;
        x ++;
    }
}

void sortArraySelect ( int *x, const int size )
{
    int i, j;
    int min_index, min_value;
    for ( i = 0; i < size - 1; i ++ )
    {
        min_index = i;
        for ( j = i + 1; j < size; j ++ )
        {
            if ( *(x + min_index) > *(x + j) )
            {
                min_index = j;
            }
        }
        if( min_index != i )
        {
            min_value = *(x + min_index);
            *(x + min_index) = *(x + i);
            *(x + i) = min_value;
        }
    }
}

void displaySumRelation ( int *x, const int size, int *foundNum )
{
    //�����ܷ���Ҫ��ı������
    int i, j, k;

    //i, j, k �ֱ����������������Ķ�Ӧλ��
    for ( i = 0; i < size - 2; i ++ )
    {
        for ( j = i + 1; j < size - 1; j ++ )
        {
            for ( k = j + 1; k < size; k ++ )
            {
                if ( (*(x+i)) + (*(x+j)) == (*(x+k)) )
                {
                    printf("{%d,%d,%d}\n", *(x+i), *(x+j), *(x+k));
                    (*foundNum) ++;
                }
            }
        }
    }
}
