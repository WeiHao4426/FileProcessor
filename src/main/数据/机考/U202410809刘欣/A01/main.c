// 刘欣
// U202410809
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int isNarcissistic( int x ) ; // 判断是不是水仙花数，是则返回1 ，不是则返回0
void displayNarcississistic( int x ) ; // 判断并且打印水仙花数的分解式
int main()
{
    int i ;
    for ( i = 200 ; i < 1000 ; i ++)
    {
        if ( isNarcissistic( i ) ) // 如果是水仙花数
        {
            displayNarcississistic( i );
        }
    }
    return 0;
}
// 判断是不是水仙花数，是则返回1 ，不是则返回0
int isNarcissistic( int x )
{
    int a1 ; // 个位数
    int a2 ; // 十位数
    int a3 ; // 百位数

    a3 = x / 100 ;
    a2 = ( x - a3 * 100 ) / 10 ;
    a1 = x - a3 * 100 - a2 * 10 ;

    if ( x == a1 * a1 * a1 + a2 * a2 * a2 + a3 * a3 * a3 )
    {
        return 1 ;
    }
    return 0 ;

}
// 判断并且打印水仙花数的分解式
void displayNarcississistic( int x )
{
    // 如果是水仙花数
    if ( isNarcissistic( x ) )
    {
        int a1 ; // 个位数
        int a2 ; // 十位数
        int a3 ; // 百位数

        a3 = x / 100 ;
        a2 = ( x - a3 * 100 ) / 10 ;
        a1 = x - a3 * 100 - a2 * 10 ;

        printf("%d = %d**3 + %d**3 + %d**3\n", x , a1 , a2 , a3 );
    }
    else
    {
        printf("It is not a narcissistic number.\n");
    }
}
