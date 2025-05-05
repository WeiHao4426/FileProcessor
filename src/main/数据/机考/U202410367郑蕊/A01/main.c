#include <stdio.h>
#include <stdlib.h>

int isNarcissistic(int x);

void displayNarcissistic(int x);

int main()
{
    int x;
    scanf("%d",&x);
    if(isNarcissistic( x ))
    {
        printf("%d is Narcissistic\n",x);
    }
    else
    {
        printf("%d is not Narcissistic\n",x);
    }
    displayNarcissistic(x);

    int i;
    for(i=200;i<1000;i++)
    {
        if( isNarcissistic( i ) )
        {
            displayNarcissistic( i );
        }
    }
    return 0;
}

int isNarcissistic( int x )
{
    //求出各位数上的数字
    int x1 = x%10 ;
    int x2 = x/10%10 ;
    int x3 = x/100 ;

    //判断各位数上的数字的立方和是否等于该数
    if ( x == x1*x1*x1 + x2*x2*x2 + x3*x3*x3 )
    {
        return 1;
    }
    else
    {
    return 0;
    }

}

void displayNarcissistic(int x)
{
    int x1 = x%10 ;
    int x2 = x/10%10 ;
    int x3 = x/100 ;

    //判断是否是水仙花数
    if(isNarcissistic( x ))
    {
        //打印其分解式
        printf("%d = %d^3 + %d^3 + %d^3 \n",x,x3,x2,x1);
    }
    else
    {
        printf("It is not narcissistic number.\n");
    }
}
