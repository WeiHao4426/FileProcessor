//U202413383
//����:Xu Cheng

#include <stdio.h>
#include <stdlib.h>

//����������x��y�����Լ��
int getGCD ( int x, int y );

//��ӡ���߹�Լ����Ϣ
void displayGCD ( int x, int y );

int main ( void )
{
    //�����ض������Լ����������
    int k;
    int num1,num2;

    //�����ж��Ƿ��з���������������
    int counter = 0;

    printf("Please input an integer in [3,30]\n");
    scanf("%d", &k);

    //�ж��쳣����
    if ( k < 3 || k > 30 )
    {
        printf("Input Error!Please re-enter!");
    }

    else
    {
        //������Χ�ڵ�����������
        for ( num1 = 3; num1 < 30; num1 ++ )
        {
            for ( num2 = num1 + 1; num2 <= 30; num2 ++ )
            {
                if ( getGCD( num1, num2 ) == k )
                {
                    displayGCD( num1, num2 );
                    counter ++;
                }
            }
        }

        if ( counter == 0 )
        {
            printf("There is no integer pair with their GCD is %d",k);
        }
    }

    return 0;
}

int getGCD ( int x, int y )
{
    //��������
    int remainder;

    //շת����������Լ��
    while ( x != 0 )
    {
        remainder = y % x;
        y = x;
        x = remainder;
    }

    return y;
}

void displayGCD ( int x, int y )
{
    //����ֽ������
    int factor1, factor2;
    int gcd = getGCD ( x, y );

    factor1 = x / gcd;
    factor2 = y / gcd;

    printf("\nGCD(%d,%d) = %d\nBecause %d = %d * %d; %d = %d * %d\n", x, y, gcd, x, gcd, factor1, y, gcd, factor2);

}

