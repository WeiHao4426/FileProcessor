//ñûìíè¯ U202410288

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define M 10
#define N 35

typedef struct
{
    char content[N];
    int length;
}String;

void setRandomString(String *s);
void getStringIntersection(String *s1,String *s2,String *result);
void displayString(String *s);



int main()
{
    srand(time(NULL));

    String s1;
    setRandomString(&s1);
    printf("string1:");
    displayString(&s1);
    printf("\n");
    String s2;
    setRandomString(&s2);
    printf("string2:");
    displayString(&s2);

    String result;
    getStringIntersection(&s1,&s2,&result);
    printf("\nthe intersection is:");
    displayString(&result);


    return 0;
}

void setRandomString(String *s)
{
    String *str = s;
    int i;
    str->length = rand() % (N + 1);
    for(i = 0; i < (str->length); i ++)
    {
        int caps = rand() % 2;//´óÐ¡Ð´Ëæ»ú
        if(caps == 0)
        {
            str->content[i] = 'a' + rand() % 26;
        }
        if(caps == 1)
        {
            str->content[i] = 'A' + rand() % 26;
        }
    }
    str->content[str->length] = '\0';
}

void getStringIntersection(String *s1,String *s2,String *result)
{
    int i,j,k = 0;
    for(i = 0;i < s1->length;i ++)
    {
        for(j = 0; j < s2->length;j ++)
        {
            if(s1->content[i] == s2->content[j])
            {
                result->content[k] = s1->content[i];
                k ++;
            }
        }
    }
    result->length = k + 1;
    //int num = 0;
    for(i = 0;i < result->length;i ++)
    {
        for(j = i + 1;j < result->length;j ++)
        {
            if(result->content[i] == result->content[j])
            {
                for(;j < result->length - 1; j ++)
                {
                    result->content[j] = result->content[j + 1];

                }
                result->content[j + 1] = '\0';
                result->length --;

            }
        }
    }
}

void displayString(String *s)
{
    String *str = s;
    int i;
    for(i = 0; i < (str->length);i ++)
    {
        printf("%c",str->content[i]);
    }
    printf("(length = %d)",str->length);
}
