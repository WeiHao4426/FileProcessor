#include <stdio.h>
#include <stdlib.h>
// U202413453
int isNarcissistic(int x)
{
    int a = x /100;
    int b = x %100 /10;
    int c = x %10;
    if( x == a*a*a + b*b*b + c*c*c){
        return 1;
    }else{
    return 0;
    }
}

void displayNarcissistic(int x)
{
     scanf("%d",&x);
     int isNarcissistic();
     int a = x /100;
     int b = x %100 /10;
     int c = x %10;
     if( isNarcissistic(x) == 1){
        printf("%d=%d*%d*%d+%d*%d*%d+%d*%d*%d",x,a,a,a,b,b,b,c,c,c);
     }else{
     printf("It is not a narcissistic number.");
     }
}
int main()
{
    int isNarcissistic();
    void displayNarcissistic();
    int num = 199;
    for(;num <= 1000;num ++){
        if( isNarcissistic(num) == 1){
        printf("%4d\n",num);
        }
    }
     return 0;
}
