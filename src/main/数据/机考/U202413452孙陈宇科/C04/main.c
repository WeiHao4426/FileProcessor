//U202413452 孙陈宇科
//C04
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 10
#define N 35
typedef struct{
    char content[N];
    int length;
}String;

void testSetString(void);//测试用的
void setRandomString(String*s);
void getStringIntersection(String* s1, String* s2, String* result);
void displayString(String* s);//测试用的

int main()
{
    srand(time(NULL));
    String s1, s2, result;
    //testSetString();
    setRandomString(&s1);
    displayString(&s1);
    setRandomString(&s2);
    displayString(&s2);

    getStringIntersection(&s1, &s2, &result);
    displayString(&result);

    return 0;
}

void setRandomString(String*s)
{
    s->length = rand() % 36;
    int i;
    for (i = 0; i < N; i ++)
    {
        s->content[i] = '\0';
    }//字符串清零

    if(s->length == 0) return;

    for (i = 0; i < s->length; i ++)
    {
        s->content[i] = rand() % 52;
        if(s->content[i] < 26)
        {
            s->content[i] += 'a';//生成小写字母
        }else
        {
            s->content[i] = s->content[i] - 26 + 'A';//生成大写字母
        }
    }
}

void getStringIntersection(String* s1, String* s2, String* result)
{
    int i;
    for (i = 0; i < N; i ++)
    {
        result->content[i] = '\0';
    }//字符串清零
    int j, counter = 0;
    for (i = 0; i < s1->length; i ++)
    {
        for (j = 0; j < s2->length; j ++)
        {
            if (s1->content[i] == s2->content[j])
            {
                result->content[counter] = s2->content[j];
                counter ++;
                break;//防止重复
            }
        }
    }

    result->length = counter;
}

void displayString(String* s)
{
    printf("%d\n", s->length);
    int i;
    for(i = 0; i < N; i ++)
    {
        printf("%c",s->content[i]);
    }
    printf("\n");
}

void testSetString(void)
{
    String s1;
    setRandomString(&s1);
    int i;
    for(i = 0; i <= N; i ++){
        for(setRandomString(&s1);s1.length != i;setRandomString(&s1)){}
        displayString(&s1);
    }
}
