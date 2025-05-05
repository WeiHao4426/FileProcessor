//U202411282 LiQiFeng
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 16

void setRandomArray( int *x , const int size ) ;
void sortArrayInsert( int *x , const int size ) ;
void displayProductRelation( int *x , const int size , int *foundNum ) ;

int main()
{
    srand( time( NULL)) ;
    int i, x = 0 ;
    int *iptr = &x ;
    int num[ SIZE ] ;

    setRandomArray( num , SIZE ) ;

    printf( "The original array is: \n") ;
    for( i = 0 ; i < SIZE ; i ++ )
    {
        printf( "%d ", num[ i ] );
    }
    printf( "\n\n") ;

    sortArrayInsert( num, SIZE ) ;

    printf( "The sorted array is: \n") ;
    for( i = 0 ; i < SIZE ; i ++ )
    {
        printf( "%d ", num[ i ] );
    }
    printf( "\n\n") ;

    displayProductRelation( num , SIZE , iptr ) ;

    if( *iptr == 0 )
    {
        printf( "There is no pairs are found\n" );
    }

    else
    {
        printf( "There is %d pairs are found\n", *iptr );
    }

    return 0;
}

void setRandomArray( int *x , const int size )
{
    int i ;
    for( i = 0 ; i < size ; i ++ )
    {
        x[ i ] = rand() % 99 + 1 ;
    }
}

void sortArrayInsert( int *x , const int size )//插入排序
{
    int i, j, temp;

    for( i = 1 ; i < size ; i ++ )
    {
        temp = x[ i ] ;

        for( j = i - 1 ; ( j >= 0 ) && ( x[ j ] > temp ) ; j -- )
        {
            x[ j + 1 ] = x[ j ] ;
        }

        if( j != i - 1 )
        {
            x[ j + 1 ] = temp ;
        }
    }
}

void displayProductRelation( int *x , const int size , int *foundNum )
{
    int i, j, k ;

    //枚举找出符合条件的组
    //用*foundNum进行计数
    for( i = 0 ; i < size ; i ++ )
    {
        for( j = i + 1 ; j < size ; j ++ )
        {
            for( k = j + 1 ; k < size ; k ++ )
            {
                if( x[ i ] * x[ j ] == x[ k ] )
                {
                    printf("( %d, %d ) = %d \n", x[ i ], x[ j ], x[ k ] ) ;
                    (*foundNum) ++ ;
                }
            }
        }
    }
}
