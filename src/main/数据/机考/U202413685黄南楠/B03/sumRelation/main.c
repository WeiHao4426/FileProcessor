//黄南楠 U202413685
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 99
#define SIZE 16

void setRandomArray(int *x, const int size);

void sortArraySelect(int *x, const int size);

void displaySumRelation(int *x, const int size, int *foundNum);

void displayArray(int *x, const int size);

int main()
{
    srand(time(NULL));

    int array[SIZE] = {0};
    printf("Random array :\n");
    setRandomArray( array, SIZE );
    displayArray( array, SIZE);

    printf("Sorting array : \n");
    sortArraySelect( array, SIZE);
    displayArray( array, SIZE);

    int foundNum = 0;
    displaySumRelation( array, SIZE, &foundNum);
    printf("totally %d sum relations are found.", foundNum);

    return 0;
}

void setRandomArray(int *x, const int size)
{
    int i;
    for(i = 0; i < size; i ++){
        *(x + i) = MIN + rand() % (MAX - MIN + 1);
    }

    return;
}

void sortArraySelect(int *x, const int size)
{
    int i, j;
    int minValue, minIndex;
    for(i = 0; i < size - 1; i ++){
        minValue = *(x + i);
        for(j = i + 1; j < size; j ++){
            if(*(x + j) < minValue){
                minIndex = j;
                minValue = *(x + j);
            }
        }
        *(x + minIndex) = *(x + i);
        *(x + i) = minValue;
    }

    return;
}

void displaySumRelation(int *x, const int size, int *foundNum)
{
    int i, j;
    int k;//detect the sum relation
    for(i = 0; i < size; i ++){
        if(*(x + i) == *(x + i + 1)){
            continue;
        }//skip the same value
        for(j = i + 1; j < size; j ++){
            if(*(x + j) == *(x + j + 1)){
                continue;
            }//skip the same value
            for(k = j + 1; k < size; k ++){
                if(*(x + k) == *(x + k + 1)){
                    continue;
                }//skip the same
                if(*(x + i) + *(x + j) == *(x +k)){
                    printf("{%d, %d, %d}\n", *(x + i), *(x + j), *(x + k));
                    *foundNum += 1;
                }
            }
        }
    }
    printf("\n");

    return;
}

void displayArray(int *x, const int size)
{
    int i;
    for(i = 0; i < SIZE; i ++){
        printf("[%02d] ", *(x + i));
    }
    printf("\n");

    return;
}

