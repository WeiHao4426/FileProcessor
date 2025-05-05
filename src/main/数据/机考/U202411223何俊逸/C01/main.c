#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 10
#define N 35
typedef struct{
    char content[N];//字符串的内容，规定不以\0结束
    int length;//字符串的有效长度
}String;
void switchIt(String *s1,String *s2);//交换两个字符串
void setRandomString(String *s);
//随机设置一个字符串
void display(String *s);
void sortString(String *sArray);
int getlength(String s);
int main()
{
    srand(time(NULL));
    printf("setting the String:\n");
    String s[M];//在主函数中设置这个结构体数组
    String *sptr[M];//声明一个指针数组去储存每一个结构体对象的地址
    String (*ssptr)[M];//声明一个指针储存这个结构体数组的数组名的地址
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
        s->content[i] = '_';//规定空位用“_”占据

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
