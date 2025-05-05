//U202411282 LiQiFeng
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 10
#define N 35

typedef struct{
    char content[ N ] ;
    int length ;
} String ;

void setRandomString( String *s ) ;
void sortString( String *sArray ) ;
void exchange( String *s1 , String *s2 ) ;

int main()
{
    int i, j ;
    srand( time( NULL)) ;
    String string[ M ] = { 0 } ;

    setRandomString( string ) ;
    printf( " The original array is:\n") ;
    printf( " Length  Content\n");
    for( i = 0 ; i < M ; i ++ )
    {
        printf( " %-6d  ", string[ i ].length ) ;
        for( j = 0 ; j < string[ i ].length ; j ++ )
        {
            printf( "%d ", string[ i ].content[ j ] ) ;
        }
        printf( "\n") ;
    }

    sortString( string ) ;
    printf( "\n The sorted array is:\n") ;
    printf( " Length  Content\n");
    for( i = 0 ; i < M ; i ++ )
    {
        printf( " %-6d  ", string[ i ].length ) ;
        for( j = 0 ; j < string[ i ].length ; j ++ )
        {
            printf( "%d ", string[ i ].content[ j ] ) ;
        }
        printf( "\n") ;
    }

    return 0;
}

void setRandomString( String *s )
{
    int i, j ;
    for( i = 0 ; i < M ; i ++ )
    {
        s[ i ].length = rand() % ( N + 1 ) ;

        for( j = 0 ; j < s[ i ].length ; j ++ )
        {
            s[ i ].content[ j ] = rand() % 9 + 1 ;
        }
    }
}

void sortString( String *sArray )
{
    int i, j, ans, k ;
    char min;

    for( i = 0 ; i < M ; i ++ )
    {

        k = 0 ;//k�����ҳ��ж��ٸ���С�ڻ����min
        ans = i ;//ans�����ж��Ƿ�����С��min
        min = sArray[ i ].content[ 0 ] ;

        for( j = i + 1 ; j < M ; j ++ )
        {
            if( min > sArray[ j ].content[ 0 ] )
            {
                min = sArray[ j ].content[ 0 ] ;
                ans = j ;
                k = 1 ;//һ��min�ı�ʹk�ظ���ʼֵ
            }

            else if( min == sArray[ j ].content[ 0 ] )
            {
                k ++ ;//ͳ���Ƿ��ж��
            }
        }

        if( ans != i )//��Ҫ��������
        {
            if( k == 1 )//��һ��С��min
            {
                exchange( &sArray[ ans ] , &sArray[ i ]) ;
            }

            else//���С��min�����н�һ������
            {
                for( j = ans + 1 ; j < M ; j ++ )
                {
                    //�Ƚ�length
                    if( ( min == sArray[ j ].content[ 0 ] ) && ( sArray[ ans ].length > sArray[ j ].length ) )
                    {
                        ans = j ;
                    }
                }

                if( ans != i )
                {
                    exchange( &sArray[ ans ] , &sArray[ i ]) ;
                }
            }

        }

        else//���ܴ��ڵ���min����
        {
            if( k != 0 )//���ڵ���min���������н�һ������
            {
                for( j = i + 1 ; j < M ; j ++ )
                {
                    //�Ƚ�length
                    if( ( min == sArray[ j ].content[ 0 ] ) && ( sArray[ ans ].length > sArray[ j ].length ) )
                    {
                        ans = j ;
                    }
                }

                if( ans != i )
                {
                    exchange( &sArray[ ans ] , &sArray[ i ]) ;
                }
            }
        }
    }
}

void exchange( String *s1 , String *s2 )
{

    String s3 ;

    s3 = *s1 ;
    *s1 = *s2 ;
    *s2 = s3 ;

}
