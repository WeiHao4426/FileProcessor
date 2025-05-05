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
//是水仙花数则返回1 反之则返回0

void displayNarcissisti( int x );

int divideX( int array[] , int x );
//将x拆分成一位一位的 返回值是x的位数

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
    //x减去每一位的立方

    return (x == 0);
    //如果减完则返回1;反之则返回0
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
        //保证最后一位不输出*号
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
