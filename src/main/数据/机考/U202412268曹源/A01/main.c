#include <stdio.h>
#include <stdlib.h>

//作者：曹源


//判断数字是否为水仙花数
int isNarcissistic (int x);

//打印分解式
void displayNarcissistic(int x);


int main()
{int x;

int begin=200;

scanf("%d",&x);

displayNarcissistic(x);

for(begin=200;begin<1000;begin++)
{
    if(isNarcissistic(begin)==1)
    {
        displayNarcissistic(begin);


    }
}

}

int isNarcissistic (int x)
{
    int m=0;//m用于记录数字的位数

    int number2=1;

    int i=0;//循环标记数字

    int sum=0;//用于统计各位数字三次方的和

  if(x>0)
  {
   while(x/number2>0)
     {
         m++;

         number2=number2*10;
     }
     number2=number2/10;

     while(i<m)
     {
         sum=sum+((x/number2)%10)*((x/number2)%10)*((x/number2)%10);

         i++;
         number2=number2/10;
     }
     if(sum==x)
     {
         return 1;
     }
     else
     {
         return 0;
     }
  }
  else{
    return 0;
  }

}

void displayNarcissistic(int x)
{
    if(isNarcissistic(x)==1)
    {
        printf("%d=",x);

 int m=0;//m用于记录数字的位数

    int number2=1;

    int i=0;//循环标记数字


  if(x>0)
  {
   while(x/number2>0)
     {
         m++;

         number2=number2*10;
     }
     number2=number2/10;

 while(i<m)
     {if(i!=0)
     {
         printf("+");
     }
        printf("%d^3",((x/number2)%10));
         i++;
         number2=number2/10;
     }
    }
    printf("\n");
    }
else
    {
        printf("It is not a narcissistic number.\n");
    }
}









