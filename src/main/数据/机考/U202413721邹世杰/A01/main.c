#include <stdio.h>
#include <stdlib.h>

#define MIN 200
#define MAX 1000
#define MAX_NUM 4

int isNarcissistic(int x);
void displayNarcissistic(int x);

int main()
{
    int num = MIN;
    for(;num <= MAX;num ++)
    {
       displayNarcissistic(num);
    }
    return 0;
}

int isNarcissistic(int x)
{
    int numout, all;
    all = 0;
    int x0 = x;//����x����
    while(x0!=0)
    {
        numout = x0 % 10;//��ȡ��λ�ϵ�����
        all = all + numout*numout*numout;//�ۼӼ���������
        x0 = x0/10;//������һλ
    }
    if(all == x)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void displayNarcissistic(int x)
{
    if(isNarcissistic(x) == 1)
    {
        printf("%d = ",x);
        int x0 = x;
        int num[MAX_NUM] = {0};
        int n = 0;
        while(x0!=0)
        {
            num[n] = x0 % 10;//��ȡ��λ�ϵ�����
            n ++;
            x0 = x0/10;//������һλ
        }
        n = n - 1;
        for(;n > 0;n --)
        {
            printf("%d^3 + ",num[n]);
        }
        printf("%d^3\n",num[n]);
        return;
    }
    else
    {
        printf("It is not a narcissistic number.\n");
        return;
    }
}
