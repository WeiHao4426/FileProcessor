// ���� ���紴2401��
// U202410809
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 35 // �ַ�������󳤶�

typedef struct
{
    char content[N] ; // �ַ�������
    int length ; // �ַ�������Ч����
}String ;

// �����ַ������� �� ����Ϊ0��N�����ֵ
void setRandomString(String *s);
// �õ����󽻼�����
void getStringIntersection(String *s1 , String *s2 , String *result ) ;
// չʾ�ַ������ַ��ͳ���
void displayString( String s ) ;

int main()
{
    // ���������ַ����ṹ����������������
    srand(time(NULL)) ;

    String string1 ; // ��ʼ���ַ����ṹ��
    String string2 ;

    setRandomString(&string1) ; // �����ַ������� �� ����Ϊ0��N(35)�����ֵ
    setRandomString(&string2) ;

    displayString(string1) ; // չʾ�ַ�������
    displayString(string2) ;

    // ���ú����õ����󽻼�����
    String result ;
    getStringIntersection(&string1 , &string2 , &result) ;
    displayString(result) ; // չʾ����
    return 0;
}
// �����ַ������� �� ����Ϊ0��N�����ֵ
void setRandomString(String *s)
{
    s->length = rand( ) % N ;
    int i ;
    for ( i = 0 ; i < s->length ; i ++ )
    {
        if (rand( ) % 2 == 0) // �趨ΪСд
        {
            s->content[i] = 'a' + rand( ) % 26 ;
        }
        else // �趨Ϊ��д
        {
            s->content[i] = 'A' + rand( ) % 26 ;
        }
    }
}
// �õ����󽻼�����
void getStringIntersection(String *s1 , String *s2 , String *result )
{
    int a[256] = {0} ; // ��Ϊ��ǿ����������ͬ��ĸ��ASCII����ᳬ��256

    int i ;
    int k = 0 ;
    result->length = 0 ;

    for ( i = 0 ; i < s1->length ; i ++ ) // �ȱ�ǵ�һ��
    {
        a[s1->content[i]] = 1 ; // ����ASCII�������
    }

    for ( i = 0 ; i < s2->length ; i ++ ) // �ٲ鿴�Ƿ�����ͬ���
    {
        if ( a[s2->content[i]] == 1 ) // ˵������������ͬԪ��
        {
            result->content[k++] = s2->content[i] ;
            result->length ++ ;
        }
    }
}
// չʾ�ַ������ַ��ͳ���
void displayString( String s )
{
    int i ;
    for ( i = 0 ; i < s.length ; i ++ )
    {
        printf("%c",s.content[i]) ;
    }
    printf("\nThe string has total %d alp\n\n",s.length) ;
}
