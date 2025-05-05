//Yang Qinghan U202413716
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 10
#define N 35
#define CHARSIZE 26

typedef struct{
    char content[N];
    int length;
}String;

void setArray(String *sArray);
void setRandomString(String *s);
void insertSort(String *a);
int isSmaller(String s1, String s2);

void printStrings(String *sArray);

int main()
{
    srand(time(NULL));
    String sArray[M];
    setArray(sArray);

    printf("The random strings are:\n");
    printStrings(sArray);

    insertSort(sArray);
    printf("The sorted strings are:\n");
    printStrings(sArray);

    return 0;
}

void setArray(String *sArray)
{
    int i;
    for(i = 0; i < M; i ++)
    {
        setRandomString(sArray + i);
    }

    return;
}
void setRandomString(String *s)
{
    s->length = rand() % N + 1;
    int i;
    for(i = 0; i < s->length; i ++)
    {
        s->content[i] = rand() % CHARSIZE + 'a';
    }

    return;
}
void insertSort(String *a)
{
    int  i, j;
    String insertValue, hold;
    for(i = 1; i < M; i ++)
    {
        insertValue = a[i];
        for(j = i - 1; j >= 0 && isSmaller( insertValue,a[j]); j --)
        {
            hold = a[j];
            a[j] = a[j + 1];
            a[j + 1] = hold;
        }
    }

    return;
}
int isSmaller(String s1, String s2)
{
    if(s1.content[0] < s2.content[0])
    {
        return 1;
    }
    else if(s1.content[0] > s2.content[0])
    {
        return 0;
    }
    else if(s1.length < s2.length)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

void printStrings(String *sArray)
{
    int i, j;
    for(i = 0; i < M; i ++)
    {
        printf("Length(%d):", sArray[i].length);
        for(j = 0; j < sArray[i].length; j ++)
        {
            printf("%c",sArray[i].content[j]);
        }
        printf("\n");
    }

    return;
}
