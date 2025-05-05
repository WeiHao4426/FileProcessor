#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isNarcissistic( int x);
void displayNarcissistic( int x);

int main()
{
    srand((int)time(NULL));
    unsigned int num = 153;
    /*
    if(isNarcissistic(num) == 1){
        printf("%d is a Narcissistic num\n",num);           //要求1测试用代码
    }else{
        printf("It is not a Narcissistic num\n",num);
    }
    */
    for( num = 200 ; num <= 1000 ; num ++){
        displayNarcissistic(num );
    }

    displayNarcissistic(num );              //要求2测试用代码

    return 0;

}

int isNarcissistic(int x){
    int remain = x;
    int sum = 0;

    do{
        sum += (remain % 10)*(remain % 10)*(remain % 10);
        remain /= 10 ;
    }while(remain > 0);

    if(sum == x){
        return 1;
    }else{
        return 0;
    }
}

void displayNarcissistic(int x){

    int remain = x ;
    int temp = 0;
    if(isNarcissistic(x) == 1){
        printf("%d = ",x);
        do{
            temp = remain % 10;
            remain /= 10 ;
            printf("%d * %d * %d",temp,temp,temp);
            if(remain > 0){
                printf(" + ");
            }
        }while(remain > 0);
            printf("\n");

    }else{
        //printf("It is not a Narcissistic num");  测试要求3时为了界面简洁避免重复语句刷屏，注释掉了这两行
           // printf("\n");

    }

}
