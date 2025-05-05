//郑蕊
//U202410367

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 10
#define N 35
typedef struct{
    char content[N];
    int length;
}String;

void displayString(String *s);

//设置字符串的内容为随机字母
void setRandomString(String *s);

//根据String对象的首字母对String数组·元素进行排序
void sortString(String *sArray);


int main()
{
    srand(time(NULL));
    String *string[M];
    printf("Before sorted:\n");
    int i;
    for( i=0 ; i < M ; i++ )
    {
        setRandomString(string[i]);
        displayString(string[i]);
    }

    sortString(string[M]);
    printf("After sorted:\n");

    for(i=0;i<M;i++)
    {
    displayString(string[i]);
    }


    return 0;
}

//打印字符串
void displayString(String *s)
{

    int i;
    for( i=0;i<s->length;i++ )
    {
        printf("%c",s->content[i]);
    }
    printf("\n");
}//

void setRandomString(String *s)
{
    srand(time(NULL));
    s->length=rand( ) % N;


    int i;
    for( i=0;i<s->length;i++ );
    {
        s->content[i]='a'+rand( ) % 26;
    }

    s->content[s->length]='\0';
}

void sortString(String *sArray)
{
    //排序
    int i,j;
    for( i=0;i<M;i++ )
    {
        for( j=0;j<M-1;j++ )
        {
            if(sArray[j].content[0]>sArray[j+1].content[0])
            {
                String temp;
                temp=sArray[j+1];
                sArray[j+1]=sArray[j];
                sArray[j]=temp;
            }
            else if(sArray[j].content[0] == sArray[j+1].content[0])
            {
                if(sArray[j].length>sArray[j+1].length)
                {
                    String temp;
                    temp=sArray[j+1];
                    sArray[j+1]=sArray[j];
                    sArray[j]=temp;
                }
            }
        }
    }
}
