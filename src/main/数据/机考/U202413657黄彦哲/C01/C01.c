//Authored by huang yan zhe U202413657
#include <stdio.h>
#include <stdlib.h>
#define M 10
#define N 35

typedef struct {
    char content[N];
    int length;
}String;

//set random char string in range a - z and a random length in range 0 - N
void setRandomString(String *s);
//sort the string according to first letter and length
void sortString(String *sArray);
//function to display the content and length of string
void displayString( String *s );

int main()
{
    srand(time(NULL));
    String sArray[M];
    int i;

    for( i = 0 ; i < M ; i ++)//get random string
    {
        setRandomString( sArray + i );
    }

    sortString( sArray );//sort the string

    return 0;
}

void setRandomString( String *s )
{
    int i;
    s->length = rand() % (N + 1);//get the length
    for( i = 0 ; i < s->length ; i ++)
    {
       s->content[i] = 'a' + rand() % 26;//get letters in effective length
    }
    for( i = s->length ; i < N ; i ++)
    {
        s->content[i] = '0';//fill the empty string with 0
    }
    printf("Set string:");
    displayString( s );

    return;
}

void sortString( String *sArray )
{
    int i,j;
    int isSorted;
    String hold;
    for( i = 1 ; i < N ; i ++)//Bubble Sort the strings
    {
        isSorted = 0;
        for( j = 0 ; j < M - 1 ; j ++)
        {
            if( sArray[j].content[0] > sArray[j + 1].content[0])//compare the first letter
            {
                hold = sArray[j];
                sArray[j] = sArray[j + 1];
                sArray[j + 1] = hold;
                isSorted ++;
            }
            else if( sArray[j].content[0] == sArray[j + 1].content[0] )//if the first letter is same compare their length
            {
                if(sArray[j].length > sArray[j + 1].length)
                {
                    hold = sArray[j];
                    sArray[j] = sArray[j + 1];
                    sArray[j + 1] = hold;
                    isSorted ++;
                }
            }
        }
        if( isSorted == 0 )
        {
            break;
        }
    }

    printf("\nSorted the string:\n");//display the sorted string
    for( i = 0 ; i < M ; i ++)
    {
        printf("[%d]",i+1);
        displayString( sArray + i );
    }
    return;
}

void displayString( String *s )
{
    int i;
    for( i = 0 ; i < N ; i ++)
    {
        if( s->content[i] == '0')
        {
            printf(" ");
        }
        else
        {
            printf("%c",s->content[i]);
        }
    }
    printf("(length = %d)",s->length);
    printf("\n");

    return;
}
