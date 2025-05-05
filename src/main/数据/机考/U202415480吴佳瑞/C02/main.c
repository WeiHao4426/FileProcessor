#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 10
#define N 35

typedef struct {
    char content[N];
    int length;
}String;

void setRandomString(String *s);
void sortString(String *sArray);
void displayString(String *s);

int main()
{
    srand(time(NULL));
    String stringlist[M];
    String *s = stringlist;
    setRandomString(s);
    displayString(s);
    return 0;
}
void setRandomString(String *s)
{
    int i, j, slength;
    for ( i = 0; i < M; i ++ )
    {
        slength = rand() % (N + 1);
        s[i].length = slength;
        for ( j = 0; j < slength; j ++ )
        {
            s[i].content[j] = '1' + rand() % 9;
        }
    }
}
void displayString(String *s)
{
    int i, j;
    for ( i = 0; i < M; i ++ )
    {
        for (j = 0; j < s[i].length; j ++ )
        {
            printf("%s",s[i].content[i]);
        }
        printf("\n");
    }
}
void sortString(String *sArray)
{
    int i, j;
    String stemp ;//用于后续交换顺序
    for ( i = 0; i < M - 1; i ++ )
    {
        for ( j = i; j < M - 1; j ++ )
        {
            if ( sArray[j].content[0] > sArray[j + 1].content[0] )
            {
                stemp = sArray[j];
                sArray[j] = sArray[j + 1];
                sArray[j + 1] = stemp;
            }
            else if ( sArray[j].content[0] == sArray[j + 1].content[0] && sArray[j].length > sArray[j+1].length )
            {
                stemp = sArray[j];
                sArray[j] = sArray[j + 1];
                sArray[j + 1] = stemp;
            }
        }
    }
}
