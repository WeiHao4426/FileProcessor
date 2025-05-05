//U202413383
//姓名:Xu Cheng

#include <stdio.h>
#include <stdlib.h>

//获得输入参数x和y的最大公约数
int getGCD ( int x, int y );

//打印二者公约数信息
void displayGCD ( int x, int y );

int main ( void )
{
    //定义特定的最大公约数和整数对
    int k;
    int num1,num2;

    //用来判断是否有符合条件正整数对
    int counter = 0;

    printf("Please input an integer in [3,30]\n");
    scanf("%d", &k);

    //判断异常输入
    if ( k < 3 || k > 30 )
    {
        printf("Input Error!Please re-enter!");
    }

    else
    {
        //遍历范围内的所有整数对
        for ( num1 = 3; num1 < 30; num1 ++ )
        {
            for ( num2 = num1 + 1; num2 <= 30; num2 ++ )
            {
                if ( getGCD( num1, num2 ) == k )
                {
                    displayGCD( num1, num2 );
                    counter ++;
                }
            }
        }

        if ( counter == 0 )
        {
            printf("There is no integer pair with their GCD is %d",k);
        }
    }

    return 0;
}

int getGCD ( int x, int y )
{
    //设置余数
    int remainder;

    //辗转相除法求最大公约数
    while ( x != 0 )
    {
        remainder = y % x;
        y = x;
        x = remainder;
    }

    return y;
}

void displayGCD ( int x, int y )
{
    //定义分解的因数
    int factor1, factor2;
    int gcd = getGCD ( x, y );

    factor1 = x / gcd;
    factor2 = y / gcd;

    printf("\nGCD(%d,%d) = %d\nBecause %d = %d * %d; %d = %d * %d\n", x, y, gcd, x, gcd, factor1, y, gcd, factor2);

}

