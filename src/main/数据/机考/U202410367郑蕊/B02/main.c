//÷£»Ô
//U202410367

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void setRandomArray(int *x,const int size);

void sortArrayInsert(int *x,const int size);

void diaplayResults(int *x,const int size,int *foundNum);

int main()
{
    const int size=20;
    srand(time(NULL));

    printf("Gerenate array:");
    int qarray[20]={0};
    setRandomArray(qarray,size);
    int i=0;
    for( i=0;i<size;i++)
    {
        printf("%d ",qarray[i]);
    }

    printf("\nAfter sorted:");
    sortArrayInsert(qarray,size);
    i=0;
    for( i=0;i<size;i++)
    {
        printf("%d ",qarray[i]);
    }

    printf("\nFound:\n");
    int x=0;
    int *foundNum=&x;
    diaplayResults(qarray,size,foundNum);
    printf("\nThe number is %d",*foundNum);
    return 0;
}

void setRandomArray(int *x,const int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        x[i]=rand()%99+1;
    }
}

//≤Â»Î≈≈–Ú…˝–Ú≈≈¡– ˝◊È
void sortArrayInsert(int *x,const int size)
{
    int i,j,insert_value;
    for( i=0 ; i<size-1 ; i++ )
    {

        for( j=0 ; j<size-1;j++)
        {
            if( x[j]>x[j+1] )
            {
                int temp=x[j+1];
                x[j+1]=x[j];
                x[j]=temp;
            }
        }
    }
}

void diaplayResults(int *x,const int size,int *foundNum)
{

    int i , j ;
    for( i=0 ; i<size ; i++ )
    {
        int temp[20]={0};
        temp[0]=x[i];

        int num=0;
        for( j=i+1 ; j<size ; j++)
        {
            if( x[j]%x[i] == 0 )
            {
                num++;
                temp[num]=x[j];
            }
        }

        if(num>=3)
        {
            *foundNum+=1;
            printf(" {");
            int m;
            for(m=0;m<num;m++)
            {
                printf("%d ",temp[m]);
            }
            printf("} \n");
        }
    }
}
