#include <stdio.h>
#include <stdlib.h>

int isNarcissistic(int x);
void displayNarcissistic(int x);

int main()
{

int x;
int i;
/*
scanf("%d",&i);
x=isNarcissistic(i);
    if(x==1)
    {
     displayNarcissistic(i);
    }
    */
for(i=200;i<1001;i++)
{
    x=isNarcissistic(i);

    if(x==1)
    {
     displayNarcissistic(i);
    }
}


}
int isNarcissistic(int x)
{
    int thousand = x/1000;
    int hundred = x/100;
    int ten = x/10 - hundred*10;
    int ge = x % 10;
    if(thousand*thousand*thousand + hundred*hundred*hundred + ten*ten*ten + ge*ge*ge==x)
    {return 1;
    }
    else{
        return 0;
    }
}
void displayNarcissistic(int x)
{
    int thousand = x/1000;
    int hundred = x/100;
    int ten = x/10 - hundred*10;
    int ge = x % 10;
    if(thousand*thousand*thousand + hundred*hundred*hundred + ten*ten*ten + ge*ge*ge==x)
    {
        printf("%d=%d 3 +%d 3 +%d 3 \n",x,hundred,ten,ge);
    }

    }

