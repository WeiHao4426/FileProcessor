//Yang Qinghan U202413716
#include <stdio.h>
#include <stdlib.h>

int isNarcissistic(int x);
void displayNarcissisti(int x);

int main()
{
    //displayNarcissisti(153);
    //displayNarcissisti(14);
    //printf("153 : %d", isNarcissistic(153));
    /*int a = -1;
    printf("%u", a);*/
    int i;
    for(i = 200; i < 1000; i ++)
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
    /*This is the former one
    int a1 = x % 10;
    int a2 = x / 10 % 10;
    int a3 = x / 100;

    int num = a1 * a1 * a1 + a2 * a2 * a2 + a3 * a3 * a3;*/
    /*This the advanced one, of course an int type number can't bigger than 1e11 so
    there is no need to add a error warning.*/

    int a[10] = {0};
    int size = 0;
    int temp = x;
    while(temp > 0)
    {
        a[size] = temp % 10;
        temp /= 10;
        size ++;
    }

    int num = 0;
    int i;
    for(i = 0; i < size; i ++)
    {
        num += a[i] * a[i] *a[i];
    }
    if(x == num )
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
    /*This is the former one.
        int a1 = x % 10;
        int a2 = x / 10 % 10;
        int a3 = x / 100;

        printf("%d = %d^3 + %d^3 + %d^3 \n", x, a1, a2, a3);*/

    //This is the advanced one.
    if(isNarcissistic(x))
    {
        int a[10] = {0};
        int size = 0;
        int temp = x;
        while(temp > 0)
        {
            a[size] = temp % 10;
            temp /= 10;
            size ++;
        }

        printf("%d = ", x);
        int i;
        for(i = 0; i < size - 1; i ++)
        {
            printf("%d^3 + ", a[i]);
        }
        printf("%d^3\n", a[size - 1]);
    }
    else
    {
        printf("It is not a narcissistic number.\n");
    }

    return;
}
