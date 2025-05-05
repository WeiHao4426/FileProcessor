/*
Authored by Zezhou Chen
U202411198
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 10
#define N 35

typedef struct
{
    char content[N];
    int length;
} String;

void sort_insert( String *array , const int arraySize );
//使用插入排序进行排序

int check( const String *x , const String *y );
//检查x是否应该放y前面 如果是返回1 否则返回0

void swap( String *x , String *y );
//交换x和y

void strcpy( const String *origin , String *target);
//将origin拷贝到target上面

void displayContent( String *x );
//打印x的content

void setRandomString( String *x );
//随机生成一串长度随机的小写字母串

void printArray(String *array , const int arraySize );
//打印所有字符串

int main ( void )
{
    srand(time(NULL));
    String *array = malloc( sizeof(String) * M );
    //申请一个空间

    int i;
    for( i = 0 ; i < M ; i ++ )
    {
        setRandomString(array+i);
    }

    printf("generte %d random array :\n" , M);
    printArray(array , M);

    sort_insert(array , M );
    printf("After sort:\n");
    printArray(array , M);

    free(array);
    return 0;
}

void sort_insert( String *array , const int arraySize )
{
    int i , j;
    for( i = 1 ; i < arraySize ; i ++ )
    {
        for( j = i ; j > 0 ; j-- )
        {
            if( check(array+j-1 , array+j) )
            {
                break;
            }
            else
            {
                swap(array+j , array+j-1);
            }
        }
    }
}

void displayContent( String *x )
{
    int i;
    for( i = 0 ; i < x->length ; i ++ )
    {
        printf("%c" , x->content[i] );
    }
    printf("\n");
}

int check( const String *x , const String *y )
{
    if( x->content[0] != y->content[0] )
    {
        return x->content[0] <= y->content[0];
    }
    return x->length <= y->length;
}

void strcpy( const String *origin , String *target)
{
    target->length = origin->length;
    int i;
    for( i = 0 ; i < target->length ; i ++ )
    {
        target->content[i] = origin->content[i];
    }
}

void swap( String *x , String *y )
{
    String *temp = malloc(sizeof(String));
    strcpy( x , temp );
    strcpy( y , x );
    strcpy ( temp , y );
}

void setRandomString( String *x )
{
    x->length = rand() % N;
    int i;
    for( i = 0 ; i < x->length ; i ++ )
    {
        x->content[i] = rand() % 26 + 'a';
    }
    if(x->length == 0)
    {
        x->content[0] = 'a';
    }
}

void printArray(String *array , const int arraySize )
{
    int i;
    for( i = 0 ; i < arraySize ; i ++ )
    {
        printf("[%d]:" , i);
        displayContent(array+i);
    }
}
