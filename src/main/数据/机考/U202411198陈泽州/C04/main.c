/*
Authored by Zezhou Chen
U202411198
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 35

typedef struct
{
    char content[N];
    int length;
} String;

void displayContent( String *x );
//打印x的content

void setRandomString( String *x );
//随机生成一串长度随机的小写字母串

void getStringUnion(String *s1 , String *s2 , String *result );

int main ( void )
{
    srand(time(NULL));
    String s1;
    String s2;

    setRandomString(&s1);
    setRandomString(&s2);
    printf("s1 is :\n");
    displayContent(&s1);
    printf("s2 is :\n");
    displayContent(&s2);

    printf("the Union is:\n");
    String result;
    result.length = 0;
    getStringUnion( &s1 , &s2 , &result );
    displayContent(&result);

    return 0;
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

void getStringUnion(String *s1 , String *s2 , String *result )
{
    int i , ischecked , j;
    //ischecked 记录该字符之前是否出现过了
    for( i = 0 ; i < s1->length ; i ++ )
    {
        ischecked = 0;
        for( j = i - 1 ; j > 0 ; j -- )
        {
            if( s1->content[i] == s1->content[j] )
            {
                ischecked = 1;
                break;
            }
        }
        if(ischecked)
        {
            continue;
        }
        //检查该字符之前是否出现过

        for( j = 0 ; j < s2->length ; j ++ )
        {
            if( s1->content[i] == s2->content[j] )
            {
                result->content[result->length] = s1->content[i];
                result->length++;
                break;
            }
        }
    }
}
