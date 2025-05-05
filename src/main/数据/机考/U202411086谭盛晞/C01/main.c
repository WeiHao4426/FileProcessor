#include <stdio.h>
#include <stdlib.h>
#define M 10
#define N 35
void setRandonString(String *s);

void sortString(String *sArray);
int main()
{
    /*typedef struct{
        char content[N];
        int length;
    }String;
    struct *sPtr = &String;
    setRandonString(*sPtr);
    sortString(String*Array);
    */
    char string[N][] = {0};
    srand( time(NULL) );
    int length = rand() % 35 + 1;
    int diff = 'z' - 'a';
    int i;
    for (i = 0; i < length; i++){
        string[i] = rand() % diff + 'a';
    }
    string[length] = '\0';//set a random string

    //sort string
      int j;
    int  isSwapped;
    char hold[length] = {0};
    for(i = 0; i < size; i++){
        isSwapped = 0;
        for(j = 0; j < (size - i); j++){
            if(string[0][i] > string[0][i+1]){
                hold = string[i][0];
                string[0][i]= string[0][i+1];
                string[0][i+1] = hold;
                ++isSwapped;
            }
        }//end of inner for loop
        if( isSwapped == 0){
            break;
        }
    }//end of outer for loop




    return 0;
}
