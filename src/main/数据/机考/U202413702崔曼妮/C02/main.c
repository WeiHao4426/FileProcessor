//崔曼妮

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 10
#define N 35
typedef struct {
    char content[N];
    int length;
} String;
String* setRandomString(String *s);
void sortString(String *sArray[]);
int main()
{
    srand((unsigned int)time(NULL));
    String theStrings[M];
    for (int i = 0;i < M;i++){
        setRandomString(&theStrings[i]);
    }
    String* ptrString[M];//创建指针数组方便传入
    for (int i = 0;i <  M;i++){
        ptrString[i] = &theStrings[i];
    }
    printf("\n");
    sortString(ptrString);

    return 0;
}

String* setRandomString(String *s)
{
    s->length = rand()%(N+1);
    for (int i = 0;i < s->length;i++){
        s->content[i]='0'+rand()%10;
    }
    for (int i = 0;i < s->length;i++){
        printf("%c",s->content[i]);
    }
    printf("\n");
}
void sortString(String *sArray[])
{
    String hold;
    int isSwapped,j;
    //冒泡排序
    for (int i = 1;i < M;i++){
        isSwapped=0;
        for (j = 0;j < M - i;j++){
            if((sArray[j]->content[0]>sArray[j+1]->content[0])||(sArray[j]->content[0]==sArray[j+1]->content[0]&&sArray[j]->length>sArray[j+1]->length)){
                hold=*(sArray[j]);
                *(sArray[j])=*(sArray[j + 1]);
                *(sArray[j + 1])=hold;
                isSwapped ++;
            }
        }
        if(isSwapped == 0){
            break;
        }
    }
    printf("aftersort:\n");
    for (int i = 0;i < M;i++){
        for (int k = 0;k < sArray[i]->length;k++){
            printf("%c",sArray[i]->content[k]);
        }
        printf("\n");
    }
}
