//���γ� U202413704
//����������
#include<stdio.h>
#include<time.h>

#define M 10
#define N 35
typedef struct{
    char content[N];//�ַ��������ݣ��涨����'\0' ����
    int length;//�ַ�������Ч����
    }String;
void setRandomString(String*s);//���в��ԣ��ۿ��ܷ���ȷ�������

void sortString(String*sArray);//���в��ԣ��ۿ��ܷ���ȷ����

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
        printf("\n");//��ӡ�������Ľ��
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
    char str[N];//����ʵ�����齻��
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
