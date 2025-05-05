//黄南楠 U202413685
#include <stdio.h>
#include <stdlib.h>

#define MIN 200
#define MAX 1000


int isNarcissistic(int x);

void displayNarcissistic(int x);

int main()
{
//输入某数x（100-999）

    int number;
    printf("please input a number (100 - 999): ");
    scanf("%d", &number);
    if(number < 100 || number > 999){
        printf("input error!");
    }else{
        displayNarcissistic( number );
    }


//查找水仙花数（200-1000）
    int n;//待判断数
    int count = 0;
    for(n = MIN; n < MAX; n ++){
        if(isNarcissistic( n )){
            count ++;
            printf("[%d] ", count);
            displayNarcissistic( n );
        }
    }


    return 0;
}


int isNarcissistic(int x)
{
    int fact[3], i = 0, temp = x;
    int isNarcissistic = 0;
    for(i = 0; i < 3; i ++){
        fact[i] = temp % 10;
        temp /= 10;
    }

    if(fact[0] * fact[0] * fact[0] + fact[1] * fact[1] * fact[1] + fact[2] * fact[2] * fact[2] == x ){
        isNarcissistic = 1;
    }

    return isNarcissistic;
}

void displayNarcissistic(int x)
{
    int i, isPrint;
    isPrint = isNarcissistic( x );
    if(isPrint == 1){
        printf("%d = ", x);
        int fact[3];
        for(i = 0; i < 3; i ++){
            fact[i] = x % 10;
            x /= 10;
            printf("%d^3 ", fact[i]);
            if(i < 2){
                printf("+ ");
            }
        }
        printf("\n");
    } else {
        printf("It is not a narcissistic number");
    }


    return;
}
