//高梦超 U202413704
#include<stdio.h>

int getGCD(int x,int y);

void displayGCD(int x,int y);

int main(void)
{
    int a = 0;
    int b = 0;//用于存放输入的正整数
    int k = 0;//寻找是否有一对整数的最大公约数是输入的数
    int count = 0;//用于计数满足条件的整数对
    printf("please input an integer(3 - 30) to find:\n");
    scanf("%d",&k);
    if(k >= 3&&k <= 30)//确保输入的k值正确
    {
        int i,j;//用于循环
        for(i = 3;i <= 30;i ++)
        {
            for(j = 3;j <= 30;j ++)
            {
                if(k == getGCD(i,j)&&i != j)
                {
                    displayGCD(i,j);
                    count++;
                }
            }
        }
    }
    else
    {
        printf("Error!");
        return 1;
    }
    if(count == 0)
    {
        printf("There is no integer pair with theirGCD is k");
    }

    return 0;
}
int getGCD(int x,int y)
{
    int temp = 0;
    while(y != 0)
    {
        temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}
void displayGCD(int x,int y)
{
    int GCD = getGCD(x,y);
    printf("\nGCD(%d,%d) = %d,because %d = %d * %d,%d = %d * %d",
           x,y,GCD,x,GCD,x / GCD,y,GCD,y / GCD);

}
