//Authored by huang yan zhe U202413657
#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 100
#define MIN 1
#define MAX 10000

//distinguish whether a number is a function
int isPerfect( int x );
//display perfect number
void displayPerfect( int x );

int main( void )
{
   int i;
   for( i = MIN ; i < MAX ; i ++)
   {
       if( isPerfect(i) )
       {
           displayPerfect( i );
       }
   }

   return 0;
}

int isPerfect( int x )
{
    int i;
    int num = x;
    int counter = 1;//count the number of factors of number
    int factors[MAX_NUM] = {0};
    factors[0] = 1;
    for( i = 2 ; i < x ; i ++)
    {
        if(x % i == 0)
        {
            factors[counter] = i;//get factors and allocate them in an array
            counter ++;
        }
    }

    int sum = 0;
    for( i = 0 ; i < counter ; i ++)
    {
        sum = sum + factors[i];// add all the factors together
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

void displayPerfect( int x )
{
    if( isPerfect( x ) )
    {
        printf("%d=",x);
        int i;
        int num = x;
        int counter = 1;
        int factors[MAX_NUM] = {0};
        factors[0] = 1;
        for( i = 2 ; i < x ; i ++)
        {
            if(x % i == 0)
            {
                factors[counter] = i;
                counter ++;
            }
        }

        for( i = 0 ; i < counter ; i ++)
        {
            printf("%d*",factors[i]);
        }
        printf("\n");
    }
    else
    {
        printf("It is not a perfect number.");
    }

    return;
}
