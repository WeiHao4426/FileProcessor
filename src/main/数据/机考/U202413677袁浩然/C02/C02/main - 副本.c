#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 10
#define N 35

typedef struct{
    char content[N];
    int length;
} string;

void setRandomString(string *s);
void sortString(string *s);


int main()
{
    srand((int )time(NULL));
    string str[M];
    int j = 0, i = 0;

    setRandomString(str);

    for( i = 0 ; i < M ; i ++){//打印初始化的结果
        for( j = 0 ;j < str[i].length ;j ++){
            printf("%c",str[i].content[j]);
            if(j == str[i].length - 1){
                printf("\n");
            }
        }
    }

    sortString(str);
    printf("\n");
    for( i = 0 ; i < M ; i ++){//打印初始化的结果
        for( j = 0 ;j < str[i].length ;j ++){
            printf("%c",str[i].content[j]);
            if(j == str[i].length - 1){
                printf("\n");
            }
        }
    }

    return 0;
}

void setRandomString(string *str){
    int j = 0, i = 0;

    for( i = 0 ; i < M ; i ++){
        int templen = rand()%(N + 1);
        str[i].length = templen;
        for( j = 0 ; j < N ; j ++){
            str[i].content[j] = 48 + rand()%9 + 1;
        }
    }
}

void sortString(string *str){
    int i = 0 , j = 0;
    for( i = 0 ; i < M - 1 ; i ++){
        for( j = 0 ;j < M - 1 - i ; j ++){
            if( str[j].content[0] > str[j + 1].content[0]){
                string temp = str[j];
                temp.content[temp.length] = '\0';
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }else if(str[j].content[0] == str[j + 1].content[0] &&  str[j].length > str[j + 1].length){
                string temp = str[j];
                temp.content[temp.length] = '\0';
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}



