#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void setRandomArray(int *x ,const int size);
void displayArrayBubble(int *x,const int size);
void displayResults(int *x , const int size, int *foundnum );
void sorting_2(int num[], const int size);



int main()
{
    srand((int)time(NULL));
    int num[20] = {0};
    const int size = 20;
    int i = 0;

    setRandomArray(num , size);
    for( i = 0 ; i < size ; i ++ ){
       printf("num[%02d] = %d\n",i,num[i]);
    }

    printf("\nafter sorting : \n");
    sorting_2(num , size);
    //displayArrayBubble( num , size);
    for( i = 0 ; i < size ; i ++ ){
       printf("num[%02d] = %d\n",i,num[i]);
    }

    return 0;
}

void setRandomArray(int *x ,const int size){
    int i = 0;
    for( i = 0 ;i < size ; i ++){
        x[i] = rand()%99 + 1;
    }
}

void displayArrayBubble(int *x,const int size){
    int i = 0 , j = 0;
    for( i = 0 ; i < size - 1 ; i ++){
        for( j = 0 ;j < size - 1 - i ; j ++){
            if( x[j] > x[ j + 1]){
                int temp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;
            }
        }
    }
}

void displayResults(int *x , const int size, int *foundnum ){

}

void sorting_2(int num[] ,const int size){
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

