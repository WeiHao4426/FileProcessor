//U202413452 ������
//C03
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 10
#define N 35
typedef struct{
    char content[N];
    int length;
}String;

void testSetString(void);//�����õ�
void setRandomString(String*s);
void getStringUnion(String* s1, String* s2, String* result);
void displayString(String* s);//�����õ�

int main()
{
    srand(time(NULL));
    String s1, s2, result;
    //testSetString();
    setRandomString(&s1);
    displayString(&s1);
    setRandomString(&s2);
    displayString(&s2);

    getStringUnion(&s1, &s2, &result);
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
    }//�ַ�������

    if(s->length == 0) return;

    for (i = 0; i < s->length; i ++)
    {
        s->content[i] = rand() % 52;
        if(s->content[i] < 26)
        {
            s->content[i] += 'a';//����Сд��ĸ
        }else
        {
            s->content[i] = s->content[i] - 26 + 'A';//���ɴ�д��ĸ
        }
    }
}

void getStringUnion(String* s1, String* s2, String* result)
{
    int i, j;
    for (i = 0; i < N; i ++)
    {
        result->content[i] = '\0';
    }//�ַ�������
    int counter = 0;

    if(s1->length == 0 && s2->length == 0)
    {
        return;
    }else if(s1->length == 0 && s2->length != 0)
    {
        s1 = s2;
    }
    result->content[counter] = s1->content[0];
    counter ++;
    for (i = 1; i < s1->length; i ++)
    {
        for (j = 0; j < counter; j ++)
        {
            if ( s1->content[i] == result->content[j])
            {
                break;//�������ͬ�ľ�ֱ�Ӽ��s1����һ���ַ�
            }
            result->content[counter] = s1->content[i];
            counter ++;
            break;
        }
    }
    for (i = 0; i < s2->length; i ++)
    {
        for (j = 0; j < counter; j ++)
        {
            if (result->content[j] == s2->content[i])
            {
                break;//�������ͬ�ľ�ֱ�Ӽ��s2����һ���ַ�
            }
            result->content[counter] = s2->content[i];
            counter ++;
            if(counter > N)//�������������
            {
                printf("���\n");
                result->length = N;
                return;
            }
            break;
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
