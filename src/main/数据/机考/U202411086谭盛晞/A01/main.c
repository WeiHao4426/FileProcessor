#include <stdio.h>
#include <stdlib.h>
//choose A01  Ì·Ê¢•„ U202411086
#define BEGIN 200
#define END 1000
int isNarcissistic(int x);//return 0 or 1

void displayNarcissistic(int x);//if x is Narcissistic,display it,if not,tell the user

int findNumbers(int x);//find how many numbers x has
int main(void)
{
    int integer;

    printf("I can help you see whether your number is Narcissistic or not!\n");

    printf("please input a positive integer(q or negative numbers to quit)\n");

    if( scanf("%d", &integer) != 1 || integer <= 0 ){
        printf("wrong input");
    }
    else {
        displayNarcissistic(integer);
    }
    int i;
    printf("here is the narcissistic between 200 and 1000\n");
    for(i = BEGIN; i <= END; i++){
        displayNarcissistic(i);
    }
    return 0;
}

int findNumbers(int x){
    int divider = 10;
    int counter = 0;
    while(x){
        x /= divider;
        ++counter;
    }
    return counter;
}

int isNarcissistic(int x){
    int counter = findNumbers(x);
    int hold = x;//to hold the value of x
    int i,j;
    int sumOfCubes = 0;
    for (i = 0; i < counter; i++){
        j = x % 10;
        x /= 10;
        sumOfCubes += j * j * j;
    }//en of for loop
    int ret = 0;
    if(sumOfCubes == hold){
        ret = 1;
    }
    return ret;
}

void displayNarcissistic(int x){
    if(isNarcissistic(x) == 1){
        printf("Yes,it is!\n");
        printf("%d = ", x);
        int counter = findNumbers(x);
        int i,j;
        //as the last number should not be accompanied by "+" , the number of loop should minus 1
         for (i = 0; i < (counter - 1); i++){
        j = x % 10;
        x /= 10;
        printf("%d^3 + ", j);
    }//end of for loop
        j = x % 10;
        printf("%d^3\n", j);
    }
    else{
        printf("It is not a narcissistic number.\n");
    }
}
