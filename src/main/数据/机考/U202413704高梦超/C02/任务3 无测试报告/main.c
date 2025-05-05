//高梦超 U202413704
//来不及测试
#include<stdio.h>
#include<time.h>

#define M 10
#define N 35
typedef struct{
    char content[N];//字符串的内容，规定不以'\0' 结束
    int length;//字符串的有效长度
    }String;
void setRandomString(String*s);//进行测试，观看能否正确随机生成

void sortString(String*sArray);//进行测试，观看能否正确排序

int main(void)
{
    int i,j;
    String a[M];
    setRandomString(a);
    sortString(a);

    for(i = 0;i < M;i ++)
    {
        for(j = 0;j < a[i].length;j ++)
        {
           printf("%c",a[i].content[j]);
        }
        printf("\n");//打印出排序后的结果
    }
    return 0;
}
void setRandomString(String*s)
{
    srand(time(NULL));
    int i,j;
    for(i = 0;i < M;i ++)
    {
        s[i].length = rand () % 36;
        for(j = 0;j < s[i].length;j ++)
        {
            s[i].content[j] = rand () % 9 + 1;
        }
    }
}
void sortString(String*sArray)
{
    int i,j,t;
    char str[N];//用于实现数组交换
    for(i = 1;i < M;i ++)
    {
        for(j = 0;j < M - i;j ++)
        {
            if(sArray[j].content[0] > sArray[i].content[0])
            {
                for(t = 0;t < sArray[j].length;t ++)
                {
                    int k = 0;
                    str[k] = sArray[j].content[t];
                    k ++;
                }
                for(t = 0;t < sArray[i].length;t ++)
                {
                    sArray[j].content[t] = sArray[i].content[t];
                }
                for(t = 0;t < sArray[i].length;t ++)
                {
                    int k = 0;
                    sArray[i].content[t] = str[k];
                    k ++;
                }
            }
            else if(sArray[j].content[0] = sArray[i].content[0])
            {
                if(sArray[j].length > sArray[i].length)
                {
                    for(t = 0;t < sArray[j].length;t ++)
                    {
                        int k = 0;
                        str[k] = sArray[j].content[t];
                        k ++;
                    }
                    for(t = 0;t < sArray[i].length;t ++)
                    {
                        sArray[j].content[t] = sArray[i].content[t];
                    }
                    for(t = 0;t < sArray[i].length;t ++)
                    {
                        int k = 0;
                        sArray[i].content[t] = str[k];
                        k ++;
                    }
                }
            }
        }
    }
}
