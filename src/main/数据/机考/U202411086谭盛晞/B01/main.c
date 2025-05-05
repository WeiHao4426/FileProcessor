#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
#define MAX 99
//chooseB01 Ì·Ê¢•„  Ñ§ºÅU202411086
void setRandonArray(int x[], const int size);

void sortArrayBubble(int x[], const int size);

//as I am unfamiliar with pointers,I used another arrayN as my pointer.
void displayResults(int x[], const int size, int N[]);

int main()
{
    int arr[SIZE] ={0};//initialize the array
    setRandonArray(arr, SIZE);
    sortArrayBubble(arr, SIZE);
   int foundNum[1] = {0};
    displayResults(arr, SIZE, foundNum);
    printf("find %d qualified element groups", foundNum[0]);
    return 0;
}

void setRandonArray(int x[], const int size){
    srand( time(NULL) );
    int i;
    for(i = 0; i < size; i++){
        x[i] =  rand() % MAX + 1;//use % to control x[]
    }
}

void sortArrayBubble(int x[], const int size){
    int i,j;
    int  isSwapped,hold;
    for(i = 0; i < size; i++){
        isSwapped = 0;
        for(j = 0; j < (size - i); j++){
            if(x[j] > x[j+1]){
                hold = x[j];
                x[j] = x[j+1];
                x[j+1] = hold;
                ++isSwapped;
            }
        }//end of inner for loop
        if( isSwapped == 0){
            break;
        }
    }//end of outer for loop
     for(i = 0; i < size; i++){
        printf("%d ",x[i]);//to see the sorted array
    }
}
void displayResults(int x[], const int size, int N[]){
    int differenceMax = (MAX - 1) / 2;
    int i,j,n;
    int numOfElement;
    int potential[20] = {0};//an array to record potential qualified members
    int potentialPosition[20] = {0};//record the index of potential qualified members
    for( i = 0; i < differenceMax; i++){
            for(j = 0; j < size; j++){
                    numOfElement = 0;
                    potential[0] = x[j];
                    potentialPosition[0] = j;
                for(n = 1; n < size - j; n++){
                    if(x[j] == (x[j+n] - i) ){
                        ++numOfElement;
                        potential[numOfElement] = x[j+n];
                        potentialPosition[numOfElement] = j + n;
                    }
            }
             if(numOfElement >= 3){
                ++N[0];
                printf("\nfind one:\n");
                int c;
                for(c = 0; c < numOfElement; c++){
                    printf("arr[%d] = %d, ", potentialPosition[c], potential[c]);
                 }
                }
            }//the inner one to see if x[j] could be the element of this group

    }//the outer loop to record the difference from 0 to its max
}
