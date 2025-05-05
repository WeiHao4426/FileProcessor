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
//void sortString(String *sArray);
int main()
{
String str[M];
int i;
String *s = &str[M];
for (i=0; i<M;i++)
{
    setRandomString(s+i);
}
//sortString(s);
return 0;
}
void setRandomString(String *s)
{
    srand(time(NULL));
    s->length =(rand()%35)+1;
    int i;
    for(i=0;i<s->length;i++)
    {
        s->content[i]='a + rand()%26';
        printf("%c",s+i);
    }
}
void sortString(String *sArray)
{
    //冒泡排序比较
        for(i=0;i<M;i++)
    {
        for(j=M;j>i;j--)
    {
char temp;
        if(('*(s+j)')< ('*(s+j-1))')
        {
            temp='*(s+j-1))');
            '*(s+j-1)'='*(s+j)';
            '*(s+j)'=temp;
        }
    }
    }
    for(i=0;i<M;i++)//在排完序的情况下比较首字母
    {
        if(('*(s+i)')== ('*(s+i+1))')$$(s+i)->length>(s+i+1)->length)
        {
            int temp=0;
            temp='(s+i)';
            ('(s+i)')= ('(s+i+1))');
            '(s+i+1))'= temp;
        }
        }

}
