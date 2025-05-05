// ����
// U202410809
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int isNarcissistic( int x ) ; // �ж��ǲ���ˮ�ɻ��������򷵻�1 �������򷵻�0
void displayNarcississistic( int x ) ; // �жϲ��Ҵ�ӡˮ�ɻ����ķֽ�ʽ
int main()
{
    int i ;
    for ( i = 200 ; i < 1000 ; i ++)
    {
        if ( isNarcissistic( i ) ) // �����ˮ�ɻ���
        {
            displayNarcississistic( i );
        }
    }
    return 0;
}
// �ж��ǲ���ˮ�ɻ��������򷵻�1 �������򷵻�0
int isNarcissistic( int x )
{
    int a1 ; // ��λ��
    int a2 ; // ʮλ��
    int a3 ; // ��λ��

    a3 = x / 100 ;
    a2 = ( x - a3 * 100 ) / 10 ;
    a1 = x - a3 * 100 - a2 * 10 ;

    if ( x == a1 * a1 * a1 + a2 * a2 * a2 + a3 * a3 * a3 )
    {
        return 1 ;
    }
    return 0 ;

}
// �жϲ��Ҵ�ӡˮ�ɻ����ķֽ�ʽ
void displayNarcississistic( int x )
{
    // �����ˮ�ɻ���
    if ( isNarcissistic( x ) )
    {
        int a1 ; // ��λ��
        int a2 ; // ʮλ��
        int a3 ; // ��λ��

        a3 = x / 100 ;
        a2 = ( x - a3 * 100 ) / 10 ;
        a1 = x - a3 * 100 - a2 * 10 ;

        printf("%d = %d**3 + %d**3 + %d**3\n", x , a1 , a2 , a3 );
    }
    else
    {
        printf("It is not a narcissistic number.\n");
    }
}
