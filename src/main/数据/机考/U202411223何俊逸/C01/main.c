#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 10
#define N 35
typedef struct{
    char content[N];//�ַ��������ݣ��涨����\0����
    int length;//�ַ�������Ч����
}String;
void switchIt(String *s1,String *s2);//���������ַ���
void setRandomString(String *s);
//�������һ���ַ���
void display(String *s);
void sortString(String *sArray);
int getlength(String s);
int main()
{
    srand(time(NULL));
    printf("setting the String:\n");
    String s[M];//������������������ṹ������
    String *sptr[M];//����һ��ָ������ȥ����ÿһ���ṹ�����ĵ�ַ
    String (*ssptr)[M];//����һ��ָ�봢������ṹ��������������ĵ�ַ
    ssptr = &s;
    int i;
    for( i = 0; i < M ; i++){
        sptr[i] = &s[i];
    }
    for(i = 0; i < M ; i++){
    setRandomString( sptr[i] );
    printf("s[%d] = ",i);
    display( sptr[i] );
    }
    printf("sorting the String:\n");
    sortString( ssptr );
    for( i = 0; i<M ; i++){
    printf("s[%d] = ",i);
    display( sptr[i] );
    }

    return 0;
}

void setRandomString( String *s ){
    s->length = 1 + rand()%N;
    int i,give = 0;
    for( i = 0; i < (s->length) ; i++){
        give = rand()%26;
        s->content[i] = 'a'+give;
    }
    for(i = (s->length) ; i < N ; i++){
        s->content[i] = '_';//�涨��λ�á�_��ռ��

    }


}


void display(String *s){
    int i;
    for( i = 0; i < (s->length) ; i++){
    printf("%c",s->content[i]);

    }

    printf("\n");
}

void sortString(String *sArray){
    int i,j,k;

    for(i = 0; i < M ; i++){
        for(j = 1;j<M;j++){
            if(sArray[j-1].content[0]>sArray[j].content[0]){
                switchIt(&(sArray[j-1]),&(sArray[j]));

            }
            if(sArray[j-1].content[0]==sArray[j].content[0]){

                if(sArray[j-1].length>sArray[j].length){

                    switchIt(&(sArray[j-1]),&(sArray[j]));
                }
            }

        }
    }



}
void switchIt(String *s1,String *s2){
    String s3;
    s3 = *s2;
    *s2 = *s1;
    *s1 = s3;


}
