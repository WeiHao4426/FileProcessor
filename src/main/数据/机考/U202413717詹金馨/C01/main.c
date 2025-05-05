//U202413717  Υ²½πά°
#include <stdio.h>
#include<time.h>

#define M 10
#define N 35

typedef struct {
    char content[N];
    int length;
}String;

void setRandomString(String *s);
void sortString(String *sArray);

int main()
{
    srand((unsigned)time(NULL));
    int i;
    String sArray[M];
    String *sArrayPtr = sArray;

    printf("The random array :\n");
    for(i = 0;i < M;i ++)
    {
        sArray[i].length = rand()%N;
        String *s = &sArray[i];
        setRandomString(s);
        printf("%s\n",s->content);

    }

    sortString(sArrayPtr);

    printf("\nThe sorted array :\n");
    for(i = 0;i < M;i ++)
    {
        printf("%s\n",sArrayPtr->content);
        sArrayPtr ++;
    }
}

void setRandomString(String *s)
{
    int i;
    for(i = 0;i < (s->length);i ++)
    {
        s->content[i] = (char)(rand()%26 + 97);
    }
}

void sortString(String *sArray)
{
    int i,j;
    int changeNum;
    String hold;
    for(i = 1 ; i < M ; i ++)
    {
        changeNum = 0;
        for(j = 0 ; j < M - i ; j ++)
        {
            if(((sArray + j)->content[0]) > ((sArray + j + 1)->content[0]))
            {
                hold = *(sArray + j + 1);
                *(sArray + j + 1) = *(sArray + j);
                *(sArray + j) = hold;
                changeNum ++;
            }

            if(((sArray + j)->content[0]) == ((sArray + j + 1)->content[0]))
            {
                if(((sArray + j)->length) > ((sArray + j + 1)->length))
                {
                hold = *(sArray + j + 1);
                *(sArray + j + 1) = *(sArray + j);
                *(sArray + j) = hold;
                changeNum ++;
                }
            }
        }
        if(changeNum == 0)
            {
                return ;
            }
    }
    return ;
}
