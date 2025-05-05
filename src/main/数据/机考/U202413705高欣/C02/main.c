#include <stdio.h>
#include <stdlib.h>

#define M   10
#define N   35
typedef struct{
        char content[N];
        int length;
}String;

void setRandomString(String *s);
void sortString(String *sArray);
void displayString(String *sArray);
int main()
{
    srand(time(NULL));
    String array[M];
    for(i=0;i<M;i++)
    {
        setRandomString(array[i]);
    }
    return 0;
}
void setRandomString(String *s)
{
    String *sPtr = s;
    sPtr.length = rand()%(N+1);
    int i;
    for(i=0;i<sPtr->length;i++)
    {
        sPtr->content[i] = '1' + rand()%9;
    }
    return;
}
void sortString(String *sArray)
{
    Stirng *aPtr = sArray;
    int i,j;
    String insert;
    for(i=0;i<M;i++)
    {
        insert = aPtr[i];
        for(j=i+1;j<M&&;j++)
        {

        }
    }
}
void displayString(String *sArray)
{
    String *Ptr = &sArray;
    int i,j;
    for(i=0;i<M;i++)
    {
        for(j=0;j<Ptr->length;j++)
        {
            printf("%c",Ptr->content[j]);
        }
        printf("\n");
        Ptr++;
    }
}
