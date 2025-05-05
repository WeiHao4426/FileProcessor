#include <stdio.h>
#include <stdlib.h>

int isNarcissistic(int x);
void displayNarcissisti(int x);
int main()
{
    int i;
    for(i=200;i<=1000;i++)
    {
        if(isNarcissistic(i))
        {
            displayNarcissisti(i);
        }
    }
    return 0;
}
int isNarcissistic(int x)
{
    int a,b,c,d;//a,b,c,d 依次为千位，百位，十位，个位
    a = x/1000;
    b = x/100%10;
    c = x/10%10;
    d = x%10;
    if(x == a*a*a + b*b*b + c*c*c + d*d*d)
    {
        return 1;
    }
    else
    {
     return 0;
    }
}
void displayNarcissisti(int x)
{
    if(isNarcissistic(x))
    {
        printf("%d = %d^3 + %d^3 + %d^3\n",x,x/100%10,x/10%10,x%10);
    }
    else
    {
        printf("It is not a narcissistic number.\n");
    }
}
