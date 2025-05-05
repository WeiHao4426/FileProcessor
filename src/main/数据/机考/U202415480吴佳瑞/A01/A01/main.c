#include <stdio.h>
#include <stdlib.h>

int isNarcissistic(int x);//�ж��Ƿ�Ϊˮ�ɻ���
void displayNarcissisti(int x);//չʾˮ�ɻ����ֽ�ʽ

int main()
{
    int i;
    for ( i = 200; i <= 1000; i ++ )//200��1000֮���ˮ�ɻ���
    {
        if(isNarcissistic(i))
        {
            displayNarcissisti(i);
        }
    }
    return 0;
}
int isNarcissistic(int x)//�ж��Ƿ�Ϊˮ�ɻ���
{
    if ( x <= 0 )
    {
        return 0;
    }
    else
    {
        int sum = 0;
        int temp = x;//�ݴ�temp��ֵ��Ϊ����sum��temp���Ƚ�
        while ( x > 0 )
        {
            sum += (x % 10) * (x % 10) * (x % 10);
            x /= 10;
        }
        if ( sum == temp )
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
void displayNarcissisti(int x)//չʾˮ�ɻ����ֽ�ʽ
{
    if( isNarcissistic(x) )
    {
        printf("%d = ",x);
        while ( x > 0 )
        {
            if ( x / 10 > 0 )
            {
                printf("%d^3 + ",(x % 10));
            }
            else
            {
                printf("%d^3\n",(x % 10));
            }
            x /= 10;
        }
    }
    else
    {
        printf("It is not a narcissistic number.\n");
    }
}
