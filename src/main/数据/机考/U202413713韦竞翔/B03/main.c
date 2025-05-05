//by 韦竞翔

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 16

void setRandomArray(int *x,const int size);
void sortArraySelect(int *x,const int size);
int displaySumRelation(int *x,const int size,int *foundNum);
int binarySearch(int *x,int left,int right,int target);

int main()
{
    int x[SIZE];
    int foundNum[1000];
    setRandomArray(x,SIZE);
    sortArraySelect(x,SIZE);
    int t = displaySumRelation(x,SIZE,foundNum);
    int i;
    //在displaySumRelation中，foundNum每三位存储一个小数组
    for(i = 0;i < t;i += 3){
        printf("{%d+%d=%d}\n",*(foundNum + i),*(foundNum + i + 1),*(foundNum + i + 2));
    }
    return 0;
}

void setRandomArray(int *x,const int size){
    srand(time(NULL));
    int i;
    for(i = 0;i < size;i ++){
        *(x + i) = rand() % 100;
    }
}

//选择排序
void sortArraySelect(int *x,const int size){
    int i,j,temp;
    for(i = 1;i < size;i ++){
        temp = *(x + i);
        for(j = i - 1;j >= 0 && *(x + j) > temp;j --){
            *(x + j + 1) = *(x + j);
        }
        if(j != i - 1){
            *(x + j + 1) = temp;
        }
    }
}

int displaySumRelation(int *x,const int size,int *foundNum){
    int i,j;
    int t = 0;
    int target,judge;//judge存储函数返回值，用来判断是否是两数之和
    for(i = 0;i < size;i ++){
        for(j = i + 1;j < size;j ++){
            target = *(x + i) + *(x + j);
            judge = binarySearch(x,0,size,target);
            //使用一位数组，每三位数存储一个信息
            if(judge == 1){
                *(foundNum + t) = *(x + i);
                t ++;
                *(foundNum + t) = *(x + j);
                t ++;
                *(foundNum + t) = target;
                t ++;
            }
        }
    }
    return t--;
}

//折半查找
int binarySearch(int *x,int left,int right,int target){
    int mid;
    while(mid != right){
        mid = (left +right) / 2;
        if(*(x + mid) == target){
            return 1;
        }else if(*(x + mid) < target){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return -1;
}
