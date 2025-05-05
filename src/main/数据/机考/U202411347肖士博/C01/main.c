#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 10
#define N 35


//肖士博U202411347
typedef struct{
    char content[N];
    int length;
}String;

void setRandomString(String *s);
void sortString(String *sArray);

int main()
{
    srand(time(NULL));
    String x[M];

    setRandomString(x);

    int i = 0;
    for(i = 0; i < M; i ++)
    {
        printf("%s, %d\n", x[i].content, x[i].length);
    }
    printf("\n");

    sortString(x);
    for(i = 0; i < M; i ++)
    {
        printf("%s, %d\n", x[i].content, x[i].length);
    }
    printf("\n");
    return 0;
}

void setRandomString(String *s)
{
    int i,j;
    for(j = 0; j < M; j ++)
    {
        s[j].length = rand() % 34 + 1;
        for(i = 0; i < s[j].length; i ++)
        {
           s[j].content[i] = rand() % 26 + 'a';
        }
        s[j].content[i] = '\0';//保证最后为'\0'
    }
    return;
}


void sortString(String *sArray)//类似冒泡排序
{
    int i,j;
    int swap = 0;
    for(i = 1; i < M; i ++)
    {
        swap = 0;
        for(j = 0; j < M - i; j ++)
        {
            if(sArray[j].content[0] > sArray[j + 1].content[0]||(sArray[j].content[0] == sArray[j + 1].content[0]
                                                                 &&sArray[j].length > sArray[j + 1].length))
            {
                int temp;
                String x;
                x.length = sArray[j + 1].length;
                sArray[j + 1].length = sArray[j].length;
                sArray[j].length = x.length;
                for(temp = 0; temp < N; temp ++)
                {

                    x.content[temp] = sArray[j + 1].content[temp];
                    sArray[j + 1].content[temp] = sArray[j].content[temp];
                    sArray[j].content[temp] = x.content[temp];
                }
                swap ++;
            }
        }
        if(swap == 0)
        {
            break;
        }
    }
    return;
}


