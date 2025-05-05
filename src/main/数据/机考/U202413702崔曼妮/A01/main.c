//崔曼妮

#include <stdio.h>
#include <math.h>
int isNarcissistic(int num);
void displayNarcissisti(int num);


int main()
{
    for (int i = 200;i <= 1000;i++){
        if(isNarcissistic(i) == 1){
           displayNarcissisti(i);
        }
    }

    return 0;
}

int isNarcissistic(int num)
{
    int num1,num2,num3,num4,sum;
    int temp = num;
    num1 = temp/1000;
    temp %= 1000;
    num2 = temp/100;
    temp %= 100;
    num3 = temp/10;
    temp %= 10;
    num4 = temp;
    //计算三次方之和
    sum = pow(num1,3) + pow(num2,3) + pow(num3,3) + pow(num4,3);
    if(sum == num){
        return 1;
    }
    else{
        return 0;
    }
}
void displayNarcissisti(int the_num)
{
    if(isNarcissistic(the_num) == 1){

        printf("is a narcissistic number\n");
        int num[4];
        int temp = the_num;
        printf("%d=",the_num);
        num[0] = temp/1000;
        temp %= 1000;
        num[1] = temp/100;
        temp %= 100;
        num[2] = temp/10;
        temp %= 10;
        num[3] = temp;
        int i = 0;
        while(num[i] == 0){
            i++;
        }
        for(;i < 4;i++){
            printf("%d^3",num[i]);
            if(i != 3){
                printf(" + ");
            }
        }
        printf("\n");

    }
    else{
        printf("it is not a narcissistic number\n");
    }
}
