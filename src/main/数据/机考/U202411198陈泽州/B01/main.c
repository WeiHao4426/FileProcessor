/*
Authored by Zezhou Chen
U202411198
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20
#define MAXX 99

void sort_bubble( int array[] , const int arraySize );
//������������

void swap( int *x , int *y );
//����������

void setRandomArray( int *x , const int size );
//�����������

void displayArray( int *x , const int size );
//��ӡ����

void displayResult( int *x , const int size , int *foundNum );

void printArrayWithSameDifference( int start , int differ , int counter);

int main ( void )
{
    srand(time(NULL));
    int array[N];
    setRandomArray( array , N );
    printf("Before Sort:\n");
    displayArray( array , N );
    sort_bubble( array , N );
    printf("After Sort:\n");
    displayArray( array , N );
    int foundNum = 0;
    displayResult(array , N , &foundNum );
    printf("foundNum = %d \n" , foundNum);
    return 0;
}

void swap( int *x , int *y )
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort_bubble( int array[] , const int arraySize )
{
    int i , j , isSwapped;
    //��¼�Ƿ���н���
    for( i = 1 ; i < arraySize ; i ++ )
    {
        isSwapped = 0;
        for( j = 0 ; j < arraySize - i ; j++ )
        {
            if(array[j] > array[j+1])
            {
                swap(array+j , array+j+1);
                isSwapped = 1;
            }
        }
        if( !isSwapped )
        {
            break;
        }
    }
}

void setRandomArray( int *x , const int size )
{
    int i;
    for( i = 0 ; i < size ; i ++ )
    {
        *( x + i ) = rand() % MAXX + 1;
    }
}

void displayArray( int *x , const int size )
{
    int i ;
    for( i = 0 ; i < size ; i ++ )
    {
        printf("%2d " , *(x + i) );
    }
    printf("\n");
}

void displayResult( int *x , const int size , int *foundNum )
{
    int i , j , k , counter , differ ;
    //counter ��¼����
    //differ ��¼����
    for( i = 0 ; i < size - 2 ; i ++ )
    {
        if( i > 0 && *(x + i) == *(x + i - 1) )
        {
            continue;
        }
        //�����һ���Ѿ��������˾������������ظ�

        for( j = i + 1 ; j < size - 1 ; j ++ )
        {
            if( j > i + 1 && *(x + j) == *(x + j - 1) )
            {
                continue;
            }
            differ = *(x + j) - *(x + i);
            counter = 2;
            for( k = j + 1 ; k < size ; k ++ )
            {
                if(*(x + k ) == *(x + i) + differ * counter )
                {
                    counter++;
                    (*foundNum)++;
                    printf("[%02d]:" , *foundNum);
                    printArrayWithSameDifference(*(x + i) , differ , counter );
                }
            }
        }
    }
}

void printArrayWithSameDifference( int start , int differ , int counter)
{
    int i;
    for( i = 0 ; i < counter ; i ++ )
    {
        printf("%2d " , start + differ * i);
    }
    printf("\n");
}
