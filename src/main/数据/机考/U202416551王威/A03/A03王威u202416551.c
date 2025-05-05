//计算最大公约数
#include <stdio.h>
#include <stdlib.h>

int getGCD ( int x, int y );
void displayGCD ( int x, int y );

int main()
{
    int x;//题目要求两个变量一个叫x，一个叫y
    int y;
    printf ("请输入两个正整数：\n");
    scanf ("%d,%d", &x, &y );
    displayGCD ( x, y );
    getGCD ( x, y );
    //接下来是要求三的内容
    int max2;//求3——30最大公约数为它
    int index1;
    int index2;//这两个用来遍历，求出最大公约数
    int num = 0;//用来记符合要求的对数
    printf ("请输入3——30的一个整数\n");
    scanf ("%d", &max2 );
    for ( index1 = 3; index1 <= 30; index1 ++ )
    {
        for ( index2 = index1 + 1; index2 <= 30; index2 ++ )
        {
            if ( max2 == getGCD ( index1, index2 ))
            {
                num ++;
                printf ("GCD(%d, %d) = %d\n", index1, index2, max2 );
            }
        }
    }
    if ( num == 0 )
    {
        printf ("There is no integer pair with their GCD is %d.", max2);
    }
    return;
}

int getGCD ( int x, int y )
{
    int index;//用来求最大公约数
    if ( x >= y )
    {
        index = y;
    }
    else
    {
        index = x;
    }
    for ( ; ( x % index != 0 ) || ( y % index != 0 ); index -- )
    {
        printf ("");
    }
    return index;
}

displayGCD ( int x, int y )
{
    int max1;
    max1 = getGCD ( x, y );//max1就是最大公约数
    printf ("GCD(%d,%d) = %d,because %d = %d * %d; %d = %d * %d\n", x, y, max1, x, max1, (x / max1), y, max1, (y / max1));
}
