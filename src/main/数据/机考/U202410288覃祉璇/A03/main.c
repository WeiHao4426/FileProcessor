//覃祉璇 U202410288

#include <stdio.h>
#include <stdlib.h>

int getGCD(int x,int y);
void displayGCD(int x,int y);

int main()
{
    int integer1,integer2;
    printf("please input an integer[3,30]:");
    scanf("%d",&integer1);
    if((integer1 < 3) ||(integer1 > 30))
    {
        printf("error!");
        return 0;
    }
    printf("please input another integer[3,30]:");
    scanf("%d",&integer2);
    if((integer2 < 3) ||(integer2 > 30))
    {
        printf("error!");
        return 0;
    }
    getGCD(integer1,integer2);
    displayGCD(integer1,integer2);

    return 0;
}

int getGCD(int x,int y)
{
    int min,max;
    int i;
    if(x < y)
    {
        min = x;
        max = y;
    }
    else
    {
        min = y;
        max = x;
    }
    while(min != 0)
    {
        i = max % min;
        max = min;
        min = i;
    }

    //printf("%d",max);//用于检查
    return max;
}

void displayGCD(int x,int y)
{
    int GCD = getGCD(x,y);
    printf("GCD(%d,%d) = %d\n",x,y,GCD);
    printf("because %d = %d * %d; %d = %d * %d",x,GCD,(x / GCD),y,GCD,(y / GCD));
}

