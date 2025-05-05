#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 10
#define N 35
typedef struct {
    char content[N];
    int length;
} String;

void setRandomString(String *s);
void sortString(String *sArray);
void exchangeArray(String *, String *);
void printArray(String *s);

int main()
{
   String *sArray[M];
   int i = 0;
   printf("Set random array as:\n");
   for (; i < M; i++){
        setRandomString(sArray[i]);
        printArray(sArray[i]);
   }

   printf("Sorting Strings:\n");
   sortString(sArray);

    return 0;
}

void setRandomString(String *s)
{
    srand(time(NULL));
    s->length = rand() % (N+1);
    int i = 0;
    for (; i < s->length; i++){
        s->content[i] = rand() % 26 + 'a';
    }
}

void sortString(String *sArray)
{
    int i, j, index;
    char letter1, letter2;
    for (i = 0; i < M - 1; i++){
        index = i;
        letter1 = sArray[i]->content[0];
        for (j = i + 1; j < M; j++){
            letter2 = sArray[j]->content[0];
            if (letter2 < letter1 ||
                (letter2 == letter1 && sArray[j]->length < sArray[index]->length)){
                index = j - 1;
            }
        }
        if (index != i){
            exchangeArray(sArray[i], sArray[index]);
        }
        printArray(sArray[i]);
    }
}

void exchangeArray(String *s1, String *s2)
{
    String *copy;
    int len = (s1->length > s2->length) ? s1->length : s2->length;
    int i = 0;
    for (; i < len; i++){
        copy->content[i] = s1->content[i];
        s1->content[i] = s2->content[i];
        s2->content[i] = copy->content[i];
    }
    copy->length = s1->length;
    s1->length = s2->length;
    s2->length = copy->length;
}

void printArray(String *s)
{
    int i = 0;
    for (; i < s->length; i++){
        printf("%c ", s->content[i]);
    }
    printf("\n");
}
