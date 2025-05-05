//U202413452 孙陈宇科
//A03
#include <stdio.h>
#include <stdlib.h>

int getGCD(int x, int y);
void displayGCD(int x, int y);

int main()
{
    int k;
    printf("请输入范围[3,30]的正整数k\n");
    scanf("%d", &k);

    if(k < 3 || k > 30)
    {
        printf("输入错误");
        return 0;
    }//判断异常输入

    int i, j;
    int counter = 0;
    for(i = 3; i < 30; i ++)
    {
        for(j = i + 1; j < 31; j ++)
        {
            if(getGCD(i, j) == k)
            {
                displayGCD(i, j);
                counter ++;
            }
        }
    }
    //没有结果时的输出
    if (counter == 0)
    {
        printf("没有整数对的最大公约数是k");
    }

    return 0;
}
//求两数最大公约数
int getGCD(int x, int y)
{
    while(y != 0){
        int tem = y;
        y = x % y;
        x = tem;
    }
    return x;
}
//打印最大公约数信息
void displayGCD(int x, int y)
{
    printf("GCD(%d,%d)=%d\n", x, y, getGCD(x, y));
    return;
}


