#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define M 10
#define N 35

typedef struct
{
    char content[N];

    int length;
}String;

//设置字符串的内容为随机数字
void setRandomString(String *s);

void sortString(String *s);

int main()
{
    String array[M];

    int i,j;

    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            array[i].content[j]=0;
        }
    }

    setRandomString(array);

    for(i=0;i<M;i++)
    { printf("%d.",i+1);
        for(j=0;j<array[i].length;j++)
        {
            printf("%c",array[i].content[j]);
        }
        printf("\n");//作为区分
    }

    sortString(array);

    printf("\n");

    for(i=0;i<M;i++)
    {
        printf("%d.",i+1);
        for(j=0;j<array[i].length;j++)
        {
            printf("%c",array[i].content[j]);
        }
        printf("\n");
    }


}

void setRandomString(String *s)
    {
        srand(time(NULL));

        int i=0,m=0,j=0;

        for(i=0;i<M;i++)
        {
            m=rand()%(N+1);

            (s+i)->length=m;

            for(j=0;j<m;j++)
            {
                (s+i)->content[j]=(char)(rand()%10+48);

            }
        }
    }


void sortString(String *s)
{
   int i=0;
   int j=0;
   String m;

    for(i=1;i<=M-1;i++)
    {
        for(j=0;j<=M-1-i;j++)
        {
            if((s+j)->content[0]>(s+j+1)->content[0])
            {
                m=*(s+j);

                *(s+j)=*(s+j+1);

                *(s+j+1)=m;
            }
        else if((s+j)->content[0]=(s+j+1)->content[0])
            {
                if((s+j)->length>(s+j+1)->length)
                {
                     m=*(s+j);

                *(s+j)=*(s+j+1);

                *(s+j+1)=m;
                }
    }


            }

        }


}



