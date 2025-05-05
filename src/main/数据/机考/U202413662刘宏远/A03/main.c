//name：刘宏远   U202413662  A03

#include <stdio.h>
#include <stdlib.h>

int getGCD( int x, int y );
void displayGCD( int x, int y );

int main()
{
    int k, i, j, isPrint;

    printf("Please input positive integer(3-30):\n");
    scanf("%d", &k );

    isPrint = 0;

//view all the integer pairs
    for ( i = 3; i <= 30; i ++ )
    {
        for ( j = i + 1; j <= 30; j ++ )
        {
            if ( getGCD( i, j ) == k )
            {
                displayGCD( i , j );
                isPrint = 1;
            }
        }
    }

    if ( isPrint == 0 )
    {
        printf("There is no integer pair with their GCD is %d.", k );
    }

    return 0;
}

int getGCD( int x, int y )
{
    int remainder;

//辗转相除法
    while ( y != 0 )
    {
        remainder = x % y;
        x = y;
        y = remainder;
    }

    return x;
}

void displayGCD( int x, int y )
{
    int gcd = getGCD( x, y );

    printf("GCD(%2d,%2d) = %d, because %2d = %d  * %2d;because %2d = %d  * %2d.\n",
            x, y, gcd, x, gcd, x / gcd, y, gcd, y / gcd );

}
