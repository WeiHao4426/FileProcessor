/*
Authored by Zezhou Chen
U202411198
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 4
#define LOw 200
#define HIGH 1000

int isNarcissistic( int x );
//��ˮ�ɻ����򷵻�1 ��֮�򷵻�0

void displayNarcissisti( int x );

int divideX( int array[] , int x );
//��x��ֳ�һλһλ�� ����ֵ��x��λ��

int main ( void )
{
    int i;
    for( i = LOw ; i <= HIGH ; i ++ )
    {
        if(isNarcissistic(i))
        {
            displayNarcissisti(i);
        }
    }

    return 0;
}

int isNarcissistic( int x )
{
    int array[MAXLEN] = {0};
    int counter = divideX(array , x);

    int i;
    for( i = 0 ; i < counter ; i ++ )
    {
        x -= array[i] * array[i] * array[i];
    }
    //x��ȥÿһλ������

    return (x == 0);
    //��������򷵻�1;��֮�򷵻�0
}

void displayNarcissisti( int x )
{
    if(isNarcissistic(x))
    {
        printf("%3d = " , x );
        int array[MAXLEN] = {0};
        int counter = divideX(array , x);
        while(--counter)
        {
            printf("%d^3 + " , array[counter]);
        }
        printf("%d^3\n" , array[0] );
        //��֤���һλ�����*��
    }else
    {
        printf("It is noy a Narcissistic number\n");
    }
}

int divideX( int array[] , int x )
{
    int counter = 0;
    while( x )
    {
        array[counter] = x % 10;
        x /= 10;
        counter++;
    }
    return counter;
}
