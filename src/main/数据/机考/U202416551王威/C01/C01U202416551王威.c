#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 10
#define N 35

typedef struct
{
    char content[N];
    int length;
}String;

void setRandomString ( String *s );
void sortString ( String *sArray );



int main()
{
    String s[M];
    setRandomString ( s );
    sortString ( s );
}

void setRandomString ( String *s )
{
    srand ( time (NULL));
    int index1 = 0;
    int index2 = 0;
    for ( ; index1 < M; index1 ++ )
    {
        (*(s + index1)).length = rand() % 36;
        for ( ; index2 < (*(s + index1)).length; index2 ++ )
        {
            (*(s + index1)).content[index2] = 97 + rand() % 26;
        }
        printf ("[%d] %s\n",index1,(*(s + index1)).content);
    }
}

void sortString ( String *s );//冒泡排序
{
    int in1 = 0;
    int in2;
    int value;//前两个是循环量，最后一个是为了交换两元素
    for ( ; in1 < M; in1 ++ )
    {
        for ( in2 = in1 ; in2 < M - 1; in2 ++)
        {
           if ((*(s + in2)).content[0] > (*(s + in2+ 1)).content[0])
           {
               value = (*(s + in2)).content[0];
               (*(s + in2)).content[0] = (*(s + in2 + 1)).content[0];
               (*(s + in2 + 1)).content[0] = value;
           }
        }
    }
    printf ("[%d] %s\n",index1,(*(s + index1)).content);
}
