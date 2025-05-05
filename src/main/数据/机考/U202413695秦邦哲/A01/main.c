#include <stdio.h>
#include <stdlib.h>
int isNarcissistic(int x);
void displayNarcissistic(int x);

int main()
{
int i=200;
for(i=200;i<=1000;i++)
{
int j=isNarcissistic(i);
if(j==1){
displayNarcissistic(i);}
}
return 0;
}

int isNarcissistic(int x)//判断这个数是否为水仙花数
{
    int ge=x%10;
    int shi=(x/10)%10;
    int bai=(x/100)%10;
    if(x==((ge*ge*ge)+(shi*shi*shi)+(bai*bai*bai)))
       {
           return 1;
       }
       else
        {
            return 0;
        }
}

void displayNarcissistic(int x)//打印这个水仙花数
{
    int ge=x%10;
    int shi=(x/10)%10;
    int bai=(x/100)%10;
int i=isNarcissistic(x);
if(i==0)
{
    printf("It is not a Narcissistic number.\n");
}
if(i==1)
{
    printf("%d = %d^3 + %d^3 +%d^3\n",x,bai,shi,ge);
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
