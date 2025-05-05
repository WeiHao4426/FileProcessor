//黄南楠 U202413685
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 10
#define N 35
#define MIN 'a'
#define MAX 'A'

typedef struct{
    char content[N];
    int length;
} String;

void setRandomString(String *s);

void sortString(String *sArray);
void stringCopy(String* s1, String* s2);//copy s2 to s1
void swapTwoStrings(String* s1, String* s2);

void printString(String *s);

int main()
{
    srand(time(NULL));

    String string[M];
    setRandomString( string );
    printString( string );
    printf("\n");

    sortString( string );
    printString( string );

    return 0;
}

void setRandomString(String *s)
{
    int i;
    String *sPtr = s;
    for(; sPtr < s + M; sPtr ++){
        sPtr->length = 1 + rand() % N;
        for(i = 0; i < sPtr->length; i ++){
            sPtr->content[i] = 'a' + rand() % ('z' - 'a' + 1);
        }
    }

    return;
}
void stringCopy(String* s1, String* s2)
{
    int i;
    for(i = 0; i < s2->length; i ++){
        s1->content[i] = s2->content[i];
    }
    s1->length = s2->length;

    return;
}

void swapTwoStrings(String* s1, String* s2)
{
    String *temp = (String *)malloc(sizeof(String));

    stringCopy(temp, s1);
    stringCopy(s1, s2);
    stringCopy(s2, temp);

    free(temp);

    return;
}

void sortString(String *sArray)
{
    int i, j, isSwapped = 0;
    for(i = 0; i < M - 1; i ++){
        isSwapped = 0;
        for(j = 1; j < M - i; j ++){
            if((sArray + j)->content[0] < (sArray + j - 1)->content[0] || \
               (((sArray + j)->content[0] == (sArray + j - 1)->content[0]) && ((sArray + j)->length < (sArray + j - 1)->length))){
                    swapTwoStrings((sArray + j), (sArray + j - 1));
                    isSwapped ++;
               }
        }
        if(!isSwapped){
            break;
        }
    }

    return;
}

void printString(String *s)
{
    int i, j;
    for(i = 0; i < M; i ++){
        for(j = 0; j < (s + i)->length; j ++){
            printf("%c", (s + i)->content[j]);
        }
        printf("\n");
    }

    return;
}
