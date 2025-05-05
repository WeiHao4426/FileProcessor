#include <stdio.h>
#include <stdlib.h>

int isNarcissistic(int x);//判断是否为水仙花数
void displayNarcissisti(int x);//展示水仙花数分解式

int main()
{
    int i;
    for ( i = 200; i <= 1000; i ++ )//200到1000之间的水仙花数
    {
        if(isNarcissistic(i))
        {
            displayNarcissisti(i);
        }
    }
    return 0;
}
int isNarcissistic(int x)//判断是否为水仙花数
{
    if ( x <= 0 )
    {
        return 0;
    }
    else
    {
        int sum = 0;
        int temp = x;//暂存temp的值，为后续sum和temp作比较
        while ( x > 0 )
        {
            sum += (x % 10) * (x % 10) * (x % 10);
            x /= 10;
        }
        if ( sum == temp )
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
void displayNarcissisti(int x)//展示水仙花数分解式
{
    if( isNarcissistic(x) )
    {
        printf("%d = ",x);
        while ( x > 0 )
        {
            if ( x / 10 > 0 )
            {
                printf("%d^3 + ",(x % 10));
            }
            else
            {
                printf("%d^3\n",(x % 10));
            }
            x /= 10;
        }
    }
    else
    {
        printf("It is not a narcissistic number.\n");
    }
}
