#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void setRandomArray(int *x, const int size);
void sortArraySelect(int *x, const int size);
void displaySumRelation(int *x, const int size, int *foundNum);
void printArray(int *x, const int size);

int main()
{
    const int size = 16;
    int x[size];
    setRandomArray(x, size);
    sortArraySelect(x, size);

    int *foundNum = (int*)malloc(sizeof(int));
    displaySumRelation(x, size, foundNum);
    free(foundNum);

    return 0;
}

void setRandomArray(int *x, const int size)
{
    srand(time(NULL));
    int i = 0;
    for (; i < size; i++){
        x[i] = rand() % 99 +1;
    }
    printArray(x, size);
}

void sortArraySelect(int *x, const int size)
{
    int i, j, index, value;
    for (i = 0; i < size - 1; i++){
        index = i;
        for (j = i + 1; j < size; j++){
            if (x[j] < x[index]){
                index = j;
            }
        }
        value = x[index];
        x[index] = x[i];
        x[i] = value;
    }
    printArray(x, size);
}

void displaySumRelation(int *x, const int size, int *foundNum)
{
    int i, j, k;
    for (i = 2; i < size; i++){
        for (j = 1; j <= i - 1; j++){
            for (k = 0; k <= j - 1; k++){
                if (x[i] == x[j] + x[k]){
                    (*foundNum)++;
                    printf("{%d,%d,%d}\n", x[k], x[j], x[i]);
                }
            }
        }
    }
    if (*foundNum == 0){
        printf("Not found.");
    }
}

void printArray(int *x, const int size)
{
    int i = 0;
    for (; i <size; i++){
        printf("%d ", x[i]);
    }
    printf("\n");
}


