//詹金馨 U202413717 水仙花数
#include <stdio.h>

//判断是否是水仙花数
int isNarcissistic(int x);
//打印水仙花数的分式
void displayNarcissistic(int x);

int main()
{
    int i ,isOrNot ;
    for( i = 200 ; i <= 1000 ; i ++ )
    {
        //这里为了输出结果简洁，在主函数判断是否为水仙花数，实际上如果不是水仙花数，也可以用printf函数打印错误信息
        isOrNot = isNarcissistic( i );
        if( isOrNot == 1 )
        {
            displayNarcissistic( i );
        }

    }
    return 0 ;
}

int isNarcissistic(int x)
{
    int digitNum,result = 0;
    int origin = x;
    while( x > 0 )
    {
        digitNum = x % 10;
        result += (digitNum * digitNum * digitNum);
        x /= 10;
    }
    if(result == origin)
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

    int digitNum = 0;
    printf("%d =" , x);
    while(x != 0)
    {
        digitNum = x % 10;
        printf(" %d^3" , digitNum);
        x /= 10;
        if(x != 0)
        {
            printf(" +");
        }
        if(x == 0)
        {
            printf("\n");
        }
    }
}
