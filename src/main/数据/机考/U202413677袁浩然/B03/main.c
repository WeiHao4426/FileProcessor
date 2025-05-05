//袁浩然 U202413677
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void setRandomArray(int *x ,const int size);
void sortArraySelect(int *x, const int size);
void displaySumRelation(int *x , const int size, int *foundNum );

int main()
{
    srand((int)time(NULL));
    int num[16] = {0};
    const int size = 16;
    int i = 0 ,cnt = 0;
    int *foundNum = &cnt;

    setRandomArray(num , size);
    for( i = 0 ; i < size ; i ++ ){
       printf("num[%02d] = %d\n",i,num[i]); //测试要求1代码
    }

    printf("\nafter sorting : \n");
    sortArraySelect(num , size);

    for( i = 0 ; i < size ; i ++ ){//测试要求2代码
       printf("num[%02d] = %d\n",i,num[i]);
    }

    displaySumRelation(num , size, foundNum); //测试要求3代码

    printf("\n foundNum = %d" , cnt);
    return 0;
}

void setRandomArray(int *x ,const int size){
    int i = 0;
    for( i = 0 ;i < size ; i ++){
        x[i] = rand()%99 + 1;
    }
}

void sortArraySelect(int num[] ,const int size){
    int i = 0 , j = 0;
    for( i = 0 ; i < size - 1 ; i ++){
        int min = i;
        for(j = i + 1 ; j < size ; j ++){
            if(num[j] < num[min]){
                min = j;
            }
        }
        int temp = num[min];
        num[min] = num[i];
        num[i] = temp;
    }
}

void displaySumRelation(int *x , const int size, int *foundNum ){
    int i = 0 , j = 0 , k = 0;
    int count = 0;
    for( i = size - 1 ; i > 1 ; i -- ){
        for( j = 0 ; j < i - 1 ; j ++){
            for( k = j + 1 ; k < i ; k ++){
                if( x[i] == x[j] + x[k]){
                    printf("{%d ,%d ,%d}\n",x[j] , x[k] , x[i]);
                    count ++;
                }
            }
        }
    }
    *foundNum = count;
}

