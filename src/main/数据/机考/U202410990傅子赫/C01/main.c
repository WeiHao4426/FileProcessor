#include <stdio.h>
#include <stdlib.h>
#define M 10
#define N 35
typedef struct{
    char content[N];
    int length;
}String;
void setRandomString(String *s);
void sortString(String *sArray);
int main()
{
    int i;
    srand(time(NULL));
    String array[M];
    String *p = array;
    setRandomString(p);
    for(i = 0; i < M; i++){
        printf("%s   %d\n", p[i].content, p[i].length);
    }
    sortString(p);
    printf("\nsorted array:\n");
    for(i = 0; i < M; i++){
        printf("%s   %d\n", p[i].content, p[i].length);
    }
    return 0;
}

void setRandomString(String *s){
    int i, j;
    for(i = 0; i < M; i++){
        s[i].length = rand() % (N + 1);
        for(j = 0; j < s[i].length; j++){
            s[i].content[j] = 'a' + rand() % 26;
        }
        s[i].content[j] = '\0';
    }
}

void sortString(String *sArray){
    String temp;
    int i, j, is_swapped = 0;
    for(i = 1; i < M; i++){
        for(j = 0; j < M - 1; j++){
            if(sArray[j].content[0] > sArray[j + 1].content[0]){//比较首字母
                temp = sArray[j];
                sArray[j] = sArray[j + 1];
                sArray[j + 1] = temp;
                is_swapped += 1;
            }
            else{
                if(sArray[j].content[0] == sArray[j + 1].content[0] && sArray[j].length > sArray[j + 1].length){//首字母一样比较长度
                temp = sArray[j];
                sArray[j] = sArray[j + 1];
                sArray[j + 1] = temp;
                is_swapped += 1;
                }
            }
        }
        if(is_swapped == 0){
            break;
        }
    }
}
