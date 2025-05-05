// fuzihe U202410990
#include <stdio.h>
#include <stdlib.h>

void setRandomArray(int *x, const int size);
void sortArrayBubble(int *x, const int size);
void displayResults(int *x, const int size, int *foundNum);
int main()
{
    const int size = 20;
    int i, num  = 0;
    int array[20] = {0};
    int *iptr = array, *foundNum = &num;
    srand(time(NULL));
    setRandomArray( iptr, size);
    for(i = 0; i < size; i++){
        printf("%d ", iptr[i]);
    }
    printf("\nthe sorted array:\n");
    sortArrayBubble( iptr, size);
    for(i = 0; i < size; i++){
        printf("%d ", iptr[i]);
    }
    printf("\n");
    displayResults( iptr, size, foundNum);
    return 0;
}
void setRandomArray(int *x, const int size){
    int i;
    for(i = 0; i < size; i++){
        x[i] = rand() % 99 + 1;
    }
}

void sortArrayBubble(int *x, const int size){
    int i, j, temp, is_swapped = 0;
    for(i = 1; i < size; i++){
        for(j = 0; j < size - 1; j++){
            if(x[j] > x[j + 1]){
                temp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;
                is_swapped += 1;
            }
        }
        if(is_swapped == 0){//无交换就退出
            break;
        }
    }
}

void displayResults(int *x, const int size, int *foundNum){
    int i;
    for(i = 1; i < size - 1; i++){
        if(x[i] * 2 == x[i - 1] + x[i + 1]){
            printf("{%d,%d,%d", x[i - 1], x[i], x[i + 1]);
            int j = i + 1;
            while(j < size - 1 && x[j] * 2 == x[j - 1] + x[j + 1]){
                printf(",%d", x[j + 1]);
                j += 1;
            }
            printf("}\n");
            *foundNum += 1;
            i = j;
        }

    }
    printf("foundNum:%d", *foundNum);

}
