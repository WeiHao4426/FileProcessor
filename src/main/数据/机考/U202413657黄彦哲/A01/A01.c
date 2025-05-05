//Authored by huang yan zhe U202413657
#include <stdio.h>
#include <stdlib.h>
#define NUM_RANGE 5//NUM_RANGE = 5 means the number in this program will not be bigger than 10^5
#define MIN 200
#define MAX 1000

//find Narcissistic number
int isNarcissistic( int x );
//display narcissistic number
void displayNarcissistic( int x );

int main( void )
{
    int i£»
    for( i = MIN ; i < MAX ; i ++)
    {
        if( isNarcissistic( i )  == 1 )
        {
            displayNarcissistic( i );
        }
    }

    return 0;
}

int isNarcissistic( int x )
{
    int i,j;
    int num = x;
    int digits[NUM_RANGE] = {0};//get every digit of the input integer
    for( i = 0 ; x != 0 ; i ++)
    {
        digits[i] = x % 10;
        x = x / 10;
    }

    int sum = 0;
    for( j = 0 ; j < NUM_RANGE ; j ++ )
    {
        sum += (digits[j] * digits[j] * digits[j]);
    }

    if( sum == num )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void displayNarcissistic( int x )
{
    if( isNarcissistic( x ) == 1 )
    {
        int i,j;
        int num = x;
        int digits[NUM_RANGE] = {0};
        for( i = 0 ; x != 0 ; i ++)
        {
            digits[i] = x % 10;
            x = x / 10;
        }
        printf("%d=",num);
        for( j = 0 ; j < i ; j ++)
        {
            printf("%d^3+",digits[j]);
        }
        printf("\b\n");
    }
    else
    {
        printf("It is not a narcissistic number.\n");
    }
    return;
}
