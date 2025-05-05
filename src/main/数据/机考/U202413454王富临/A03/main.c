#include <stdio.h>
#include <stdlib.h>

int getGCD(int, int);
void displayGCD(int, int);

int main()
{
    int k, i, j, count = 0;
    printf("Input an integer k:(3~30)");
    scanf("%d", &k);

    for (i = 3; i <= 30; i++){
        for (j = 3; j <= 30; j++){
            if (k == getGCD(i, j)){
                displayGCD(i, j);
                count++;
            }
        }
    }
    if (count == 0){
        printf("There is no integer pair with their GCD is k");
    }
    return 0;
}

int getGCD(int x, int y)
{
    int a;
    while (y != 0){
        a = x % y;
        x = y;
        y = a;
    }
    return x;
}

void displayGCD(int x, int y)
{
    int gcd = getGCD(x, y);
    printf("GCD(%d,%d) = %d, ", x, y, gcd);
    printf("because %d = %d * %d; %d = %d * %d\n", x, gcd, x/gcd, y, gcd, y/gcd);
}
