#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define SIZE 16
void setRandomArray(int arr[] );
void sortArraySelect(int arr[]);
void displaySumSelect(int arr[]);
int main()
{
   int i=0;
   int Arr[SIZE]={0};
   setRandomArray(Arr);//生成随机数组
   sortArraySelect(Arr);//将其升序排列
   for(i=0;i<SIZE;i++)//打印排列好的数组
   {
       printf("%4d",Arr[i]);
   }
   printf("\n");
   displaySumSelect(Arr);//获得该数组中有和关系的集合并打印
    return 0;
}
void  setRandomArray(int arr[])//生成随机数组
{
    srand(time(NULL));
    int i=0;
    for(i=0;i<SIZE;i++)
    {
        arr[i]=rand()%99+1;
    }
}
void sortArraySelect(int arr[])//利用选择排序使数组升序排列
{
    int i=0;
    int j=0;
    for(i=0;i<SIZE;i++)
{
    for(j=i+1;j<SIZE;j++)
    {
        int temp=arr[j];
        if(arr[j]<arr[i])
        {
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
}
}
void displaySumSelect(int arr[])//打印存在两数之和等于第三个数关系的集合
{
    int i=0;int j=1;int k=2;
    for(i=0;i<SIZE-2;i++)
    {
        for(j=i+1;j<SIZE-1;j++)
        {
            for(k=j+1;k<SIZE;k++)
            {
                if(arr[i]+arr[j]==arr[k])
                {
                    printf("{%d,%d,%d}\n",arr[i],arr[j],arr[k]);
                }
            }
        }
    }
}






































//bubble
/*int i=0;
int j=0;
int arr[SIZE]={3,1,4,2,5};
for(i=0;i<SIZE-1;i++)
{
    for(j=0;j<SIZE-i-1;j++)
    {
        int temp=arr[j];
        if(arr[j]>arr[j+1])
        {
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
}*/
//select
/*int i=0;
int j=0;
int arr[SIZE]={3,1,4,2,5};
for(i=0;i<SIZE-1;i++)
{
    for(j=i+1;j<SIZE-1;j++)
    {
        int temp=arr[j];
        if(arr[j]<arr[i])
        {
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
}*/
//insert
/*int i=0;
int j=0;
int arr[SIZE]={3,1,4,2,5};
for(i=0;i<SIZE-1;i++)
{
    for(j=i+1;j>-1;j--)
    {
        int temp=arr[j];
        if(arr[j]>arr[i])
        {
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }*/
