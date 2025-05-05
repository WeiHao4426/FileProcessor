// fuzihe U202410990
#include <stdio.h>
#include <stdlib.h>

int isNarcissistic(int x);
void displayNarcissistic(int x);
int main()
{
    int i;
    for(i = 200; i <= 1000; i++){
        if(isNarcissistic(i) == 1){
            displayNarcissistic(i);
            printf("\n");
        }
    }
    /*printf("input an integer:");
    scanf("%d", &i);
    printf("isNarcissistic(i):%d", isNarcissistic(i));
    displayNarcissistic(i);  测试函数1，2*/
    return 0;
}

int isNarcissistic(int x){
    int i, sum = 0;
    for(i = 1; x / i != 0; i = i * 10){
        sum += (x / i % 10) * (x / i % 10) * (x / i % 10);
    }
    if(sum == x){
        return 1;
    }
    return 0;

}

void displayNarcissistic(int x){
    if(isNarcissistic(x) == 1){
        int len = 1;
        while(x / len != 0){
            len *= 10;
        }
        len = len / 10;
        printf("%d =", x);
        for(; len > 1; len /= 10){
            printf(" %d^3 +", x / len % 10);
        }
        printf(" %d^3", x / len % 10);

    }
    else{
        printf("It is not a narcissistic number");
    }
}
