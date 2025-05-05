//ղ��ܰ U202413717 ˮ�ɻ���
#include <stdio.h>

//�ж��Ƿ���ˮ�ɻ���
int isNarcissistic(int x);
//��ӡˮ�ɻ����ķ�ʽ
void displayNarcissistic(int x);

int main()
{
    int i ,isOrNot ;
    for( i = 200 ; i <= 1000 ; i ++ )
    {
        //����Ϊ����������࣬���������ж��Ƿ�Ϊˮ�ɻ�����ʵ�����������ˮ�ɻ�����Ҳ������printf������ӡ������Ϣ
        isOrNot = isNarcissistic( i );
        if( isOrNot == 1 )
        {
            displayNarcissistic( i );
        }

    }
    return 0 ;
}

int isNarcissistic(int x)
{
    int digitNum,result = 0;
    int origin = x;
    while( x > 0 )
    {
        digitNum = x % 10;
        result += (digitNum * digitNum * digitNum);
        x /= 10;
    }
    if(result == origin)
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

    int digitNum = 0;
    printf("%d =" , x);
    while(x != 0)
    {
        digitNum = x % 10;
        printf(" %d^3" , digitNum);
        x /= 10;
        if(x != 0)
        {
            printf(" +");
        }
        if(x == 0)
        {
            printf("\n");
        }
    }
}
