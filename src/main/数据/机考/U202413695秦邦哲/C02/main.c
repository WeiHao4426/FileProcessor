//�ذ���
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 10
#define N 35
void setRandomString(String *s);
void sortString(String*sArray);

typedef struct
{
char content[N];
int length;

}String;

int main()
{
   String string1;//����һ���ṹ��
   setRandomString(&string1 );//�����ַ�������
   printf("δ������ַ���Ϊ��%s\n�����ǣ�%d\n",string1.content,string1.length);
   sortString(&string);//���ַ����ź���
    printf("��������ַ���Ϊ�� %s\n�����ǣ�%d\n",string1.content,string1.length);
    return 0;
}


void setRandomString(String *s)//�����ַ�������
{
    srand(time(NULL));
    String.length=rand()%(N+1);//���������ȷ������
    int i=0;
    char arr[String.length]={0};
    for(i=0;i<String.length;i++)
    {
        int m=rand()%(M-1)+1;//�����ɵ�����������ַ�����
        arr[i]='m';
    }

}

void sortString(String*sArray)//��������ַ������к�˳��

{



}

























