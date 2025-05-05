//U202413383
//Author:Xu Cheng

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 10
#define N 35

typedef struct{
    char content[N];
    int length;
}String;

//��ӡ����ǰ����ַ�������
void displayString ( String *s );

//��������ַ�������
void setRandomString ( String *s );

//�����ɵ��ַ��������������
void sortString ( String *sArray );

int main( void )
{
    srand(time(NULL));

    String Str[M];
    String *sptr = NULL;
    sptr = Str;

    //��ӡ����ǰ���ַ�������
    printf("Setting random strings:\n");
    setRandomString( sptr );
    displayString( sptr );

    //��ӡ�������ַ�������
    printf("\nAfter sorting:\n");
    sortString( sptr );
    displayString( Str );

    return 0;
}

void setRandomString ( String *s )
{
    int i, j;

    for ( i = 0; i < M; i ++ )
    {
        //��ʼ��ÿ���ַ����ĳ���
        (s + i)->length = rand() % ( N + 1 );

        //��������Ϊ'a'-'z'
        for ( j = 0; j < (s + i)->length; j ++ )
        {
            (s + i)->content[j] = 'a' + rand() % 26;
        }
    }

}

void displayString ( String *s )
{
    int i, j;

    //����ÿ���ַ�����ÿ���ַ����д�ӡ
    for ( i = 0; i < M; i ++ )
    {
        for ( j = 0; j < (s+i)->length; j ++ )
        {
            printf("%c",(s+i)->content[j]);
        }
        printf("\n");
    }

}

void sortString ( String *sArray )
{
    int i, j;
    int isSwapped;

    //���彻��ʱ���ڴ�ŵĽṹ��
    String hold;

    //ð������
    for ( i = 1; i < M ; i ++ )
    {
        isSwapped = 0;

        for ( j = 0; j < M - 1; j ++ )
        {
            //�Ƚ϶�������ĸ��С
            if ( sArray[j+1].content[0] < sArray[j].content[0] )
            {
                hold = sArray[j+1];
                sArray[j+1] = sArray[j];
                sArray[j] = hold;
                isSwapped ++;
            }
            //����ĸ��С��ͬ���Ƚϳ���
            else if ( sArray[j+1].content[0] == sArray[j].content[0] )
            {
                if ( sArray[j+1].length < sArray[j].length )
                {
                    hold = sArray[j+1];
                    sArray[j+1] = sArray[j];
                    sArray[j] = hold;
                }
            }
        }

        if( isSwapped == 0 )
        {
            break;
        }
    }
}
