//�������Լ��
#include <stdio.h>
#include <stdlib.h>

int getGCD ( int x, int y );
void displayGCD ( int x, int y );

int main()
{
    int x;//��ĿҪ����������һ����x��һ����y
    int y;
    printf ("������������������\n");
    scanf ("%d,%d", &x, &y );
    displayGCD ( x, y );
    getGCD ( x, y );
    //��������Ҫ����������
    int max2;//��3����30���Լ��Ϊ��
    int index1;
    int index2;//����������������������Լ��
    int num = 0;//�����Ƿ���Ҫ��Ķ���
    printf ("������3����30��һ������\n");
    scanf ("%d", &max2 );
    for ( index1 = 3; index1 <= 30; index1 ++ )
    {
        for ( index2 = index1 + 1; index2 <= 30; index2 ++ )
        {
            if ( max2 == getGCD ( index1, index2 ))
            {
                num ++;
                printf ("GCD(%d, %d) = %d\n", index1, index2, max2 );
            }
        }
    }
    if ( num == 0 )
    {
        printf ("There is no integer pair with their GCD is %d.", max2);
    }
    return;
}

int getGCD ( int x, int y )
{
    int index;//���������Լ��
    if ( x >= y )
    {
        index = y;
    }
    else
    {
        index = x;
    }
    for ( ; ( x % index != 0 ) || ( y % index != 0 ); index -- )
    {
        printf ("");
    }
    return index;
}

displayGCD ( int x, int y )
{
    int max1;
    max1 = getGCD ( x, y );//max1�������Լ��
    printf ("GCD(%d,%d) = %d,because %d = %d * %d; %d = %d * %d\n", x, y, max1, x, max1, (x / max1), y, max1, (y / max1));
}
