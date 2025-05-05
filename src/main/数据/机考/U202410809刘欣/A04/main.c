// 刘欣
// U202410809
#include <stdio.h>
#include <stdlib.h>
int getLCM(int x , int y ); // 获得x和y的最小公倍数
void displayLCM( int x , int y ) ; // 打印倍数信息
int main()
{
    printf("Please input the integer in [3,30]\n");
    int i , k , j ;
    scanf("%d",&k) ;
    if ( k < 3 || k > 30 )
    {
        printf("INPUTERROR !!!") ;
        return 0 ;
    }
    int have = 0 ;
    for ( i = 3 ; i <= 30 ; i ++ )
    {
        for ( j = 3 ; j <= 30 ; j ++ )
        {
            if ( j > i )
            {
                break ;
            }
            if ( getLCM( i , j ) == k )
            {
                displayLCM( i , j ) ;
                have = 1 ;
            }
        }
    }
    if (have == 0)
    {
        printf("There is no integer pair with their LCM is k \n");
    }
    return 0;
}
int getLCM(int x , int y ) // 获得x和y的最小公倍数
{
    int i ;
    for ( i = ( x >= y ? x : y ); ; i ++ )
    {
        if ( i % x == 0 && i % y == 0 )
        {
            return i ;
        }
    }
}
void displayLCM( int x , int y )  // 打印倍数信息
{
    int LCM = getLCM( x , y ) ;
    printf("LCM(%d,%d) = %d , because %d * %d = %d ;%d * %d = %d \n",
           x , y , LCM , x , LCM / x , LCM , y , LCM / y , LCM ) ;
}
