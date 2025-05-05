#include <stdio.h>
#include <stdlib.h>
int getGCD(int x, int y);
void displayGCD(int x, int y);

int main()
{
    //int x,y;
    //scanf("%d%d", &x, &y);
    //int gcd = getGCD(x, y);
    //printf("%d\n", gcd);
    //displayGCD(x, y);
    //上述代码为测试函数功能的代码
    int input;
    printf("Please input positive integer k(3-30)\n");
    scanf("%d", &input);
    if(input > 30||input < 3)
    {
        printf("Error!Invalid input");//防止用户输入错误，进行报错
        return 0;
    }
    int i,j;
    int num = 0;
    for(i = 3; i <= 30; i ++)
    {
        for(j = i; j <= 30; j ++)
        {
            if(getGCD(i, j) == input)
            {
                displayGCD(i, j);
                num ++;
            }
        }
    }
    if(num == 0)
    {
        printf("There is no integer pair with their GCD is k");
    }
    return 0;
}

int getGCD(int x, int y)
{
    int i;
    int temp;
    if(x > y)
    {
        temp = x;
        x = y;
        y = temp;
    }
    for(i = x; i >= 1; i --)
    {
        if(y % i == 0&&x % i == 0)
        {
            return i;
        }
    }
    return 1;//最小公约数为1
}

void displayGCD(int x, int y)
{
    int temp =  getGCD(x, y);
    printf("GCD(%d,%d) = %d, because %d = %d * %d;%d = %d * %d\n",
           x, y, temp, x, temp, x / temp, y, temp, y / temp);

}
