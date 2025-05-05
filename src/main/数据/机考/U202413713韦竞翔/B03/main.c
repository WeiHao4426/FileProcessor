//by Τ����

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
    //��displaySumRelation�У�foundNumÿ��λ�洢һ��С����
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

//ѡ������
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
    int target,judge;//judge�洢��������ֵ�������ж��Ƿ�������֮��
    for(i = 0;i < size;i ++){
        for(j = i + 1;j < size;j ++){
            target = *(x + i) + *(x + j);
            judge = binarySearch(x,0,size,target);
            //ʹ��һλ���飬ÿ��λ���洢һ����Ϣ
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

//�۰����
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
