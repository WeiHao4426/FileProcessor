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

//打印排序前后的字符串数组
void displayString ( String *s );

//随机生成字符串数组
void setRandomString ( String *s );

//对生成的字符串数组进行排序
void sortString ( String *sArray );

int main( void )
{
    srand(time(NULL));

    String Str[M];
    String *sptr = NULL;
    sptr = Str;

    //打印排序前的字符串数组
    printf("Setting random strings:\n");
    setRandomString( sptr );
    displayString( sptr );

    //打印排序后的字符串数组
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
        //初始化每个字符串的长度
        (s + i)->length = rand() % ( N + 1 );

        //设置内容为'a'-'z'
        for ( j = 0; j < (s + i)->length; j ++ )
        {
            (s + i)->content[j] = 'a' + rand() % 26;
        }
    }

}

void displayString ( String *s )
{
    int i, j;

    //遍历每个字符串的每个字符进行打印
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

    //定义交换时用于存放的结构体
    String hold;

    //冒泡排序
    for ( i = 1; i < M ; i ++ )
    {
        isSwapped = 0;

        for ( j = 0; j < M - 1; j ++ )
        {
            //比较二者首字母大小
            if ( sArray[j+1].content[0] < sArray[j].content[0] )
            {
                hold = sArray[j+1];
                sArray[j+1] = sArray[j];
                sArray[j] = hold;
                isSwapped ++;
            }
            //首字母大小相同，比较长度
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
