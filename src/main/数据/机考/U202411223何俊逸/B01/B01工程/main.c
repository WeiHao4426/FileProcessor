//何俊逸U202411223
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20
void setRandomArray(int *x,const int size);
//设置随机数组
void sortArrayBubble(int *x,const int size);
//使用冒泡排序将数组排序
void displayResults(int *x,const int size,int *foundNum);
//对排序后的数组进行查找，判断元素之间是否存在等差数列的关系，
//找到后打印所有符合要求的数列
int isInTheArray(int *x,const int size,int a);
//判断a是否在数组x中，是则返回1，不是则返回0
int main()
{
    int x[N];//准备一个数组记录结果
    setRandomArray(x,N);//生int isInTheArray(int *x,int a);成该数组
    int i;
    sortArrayBubble(x,N);//排序
    for( i = 0 ; i < N ; i++){
        printf("x[%d] = %d\n",i,x[i]);
    }//展示
    int num;//记录找到了几组结果
    int *foundNum;
    foundNum = &num;
    printf("get the result:\n");
    displayResults( x , N , *foundNum );//求等差数列并展示。
    printf("there are %d wanted result here", *foundNum );
    return 0;
}

void setRandomArray( int *x , const int size ){
    srand( time(NULL) );
    int i;
    for( i = 0; i < size ; i++){
        x[i] = 1 + rand() % 99;
    }
}

void sortArrayBubble(int *x,const int size){
    int i,j;
    int help = 0 ;
    for( i = 0; i < size ; i++){
        for( j = 1 ; j < size ; j++ ){
            if( x[j-1] > x[j] ){
                help = x[j-1];
                x[j-1] = x[j];
                x[j] = help;
            }


        }
    }

}

void displayResults( int *x , const int size , int *foundNum ){
    int i;
    int x1[N];
    for( i = 0 ; i < size; i++){
        x1[i] = x[i];

    }
    int j = 1;
    for(j = 1; j < 35 ; j++){//将公差从1开始递增判断
        for(i = 0; i < size ; i++){
            if( isInTheArray( x1, N, x1[i]+j ) && isInTheArray( x1, N, x1[i]+2*j ) && isInTheArray(x1,N,x1[i]-j)==0){//根据至少三个的要求作初步筛选。并且防止重复
                int many = 1;
                printf("%d ",x1[i]);
                while( isInTheArray( x1 , N , x1[i] + many * j ) ){//用while循环向后寻找可能的第四个，第五个元素，并进行打印
                    printf("%d ", x1[i] + many * j );
                    many++;

                }
                printf("\n");
            }


        }


    }



}


int isInTheArray(int *x,const int size,int a){
    int i;
    for( i = 0 ; i < size ; i++){
        if( x[i] == a ){
            return 1;
        }
    }
    return 0;

}
