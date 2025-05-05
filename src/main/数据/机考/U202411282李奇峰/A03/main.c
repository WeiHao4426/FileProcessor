//U202411282 LiQiFeng
#include <stdio.h>
#include <stdlib.h>
#define MIN 3
#define MAX 30

int getGCD( int x , int y ) ;
int Min( int x , int y ) ;
void displayGCD( int x , int y ) ;

int main()
{
    //ans用于后续记录满足条件对数
    int i, j, k, ans = 0 ;

    printf( "please input your wanted integer :\n");
    scanf( "%d", &k ) ;

    if( k <= 0 )
    {
        printf( "Invalid input !") ;
        return 0 ;
    }
    //枚举查找
    for( i = MIN ; i <= MAX ; i ++ )
    {
        for( j = i ; j <= MAX ; j ++ )
        {
            if( getGCD( i , j ) == k )
            {
                ans ++ ;
                displayGCD( i , j ) ;
            }
        }
    }

    if( ans == 0 )
    {
        printf("\nThere is no integer pair with their GCD is %d !", k ) ;
    }

    else
    {
        printf("\nYhere is %d integer pair with their GCD is %d !", ans , k ) ;
    }

    return 0;
}

int Min( int x , int y )
{
    if( x < y )
    {
        return x ;
    }
    return y ;
}

int getGCD( int x , int y )
{
    int min = Min( x , y ) ;
    //从大到小找到最大公约数（第一个数）
    for( ; min >= 1 ; min -- )
    {
        if( x % min == 0 && y % min == 0 )
        {
            return min ;
        }
    }
}

void displayGCD( int x , int y )
{
    printf( "GCD(%d,%d) = %d\n", x, y, getGCD( x, y )) ;
}
