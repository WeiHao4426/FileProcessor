//by韦竞翔

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 10
#define N 35

typedef struct{
    char content[N];
    int length;
}String;

void setRandomString(String *s);
void sortString(String *s);

int main()
{
    String s[M];
    setRandomString(s);
    sortString(s);
    int i,j;
    for(i = 0;i < M;i ++){
        for(j = 0;j < s[i].length;j ++){
             printf("%c",s[i].content[j]);
        }
        printf("\n");
    }
    return 0;
}

void setRandomString(String *s){
    srand(time(NULL));
    int i,j;
    for(i = 0;i < M;i ++){
        s[i].length = rand() % N;
        for(j = 0;j < s[i].length;j ++){
            s[i].content[j] = rand() % 10 + '0';
        }
    }
}

void sortString(String *s){
    int i,j,temp;
    String Temp;
    //根据数组首数字排序，使用选择排序
    for(i = 1;i < M;i ++){
        Temp = s[i];
        temp = s[i].content[0];
        for(j = i - 1;j >= 0 && s[j].content[0] > temp;j --){
            s[j + 1] = s[j];
        }
        if(j != i - 1){
            s[j + 1] =  Temp;
        }
    }
    int t = 0;
    int *pt = &t;
    int t2 = 0;
    int *pt2 = &t2;
    //想根据数组长度排序，但无果
    while(i < M){
        //判断是否为数组首字母相同的项
        for(i = *pt;i < M - 1;i++){
            if(s[i].content[0] != s[i + 1].content[0]){
                break;
            }
            *pt = i;
        }
        //将首字母相同的项根据长度排序
        for(i = *pt2 + 1;i < *pt;i ++){
            Temp = s[i];
            temp = s[i].length;
            for(j = i - 1;j >= *pt2 && s[j].length > temp;j --){
                s[j + 1] = s[j];
            }
            if(j != i - 1){
                s[j + 1] =  Temp;
            }
        }
        *pt2 = *pt;
        i = *pt;
    }
}
