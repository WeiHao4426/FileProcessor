#include <stdio.h>
#include <stdlib.h>

//���ߣ���Դ


//�ж������Ƿ�Ϊˮ�ɻ���
int isNarcissistic (int x);

//��ӡ�ֽ�ʽ
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
    int m=0;//m���ڼ�¼���ֵ�λ��

    int number2=1;

    int i=0;//ѭ���������

    int sum=0;//����ͳ�Ƹ�λ�������η��ĺ�

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

 int m=0;//m���ڼ�¼���ֵ�λ��

    int number2=1;

    int i=0;//ѭ���������


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









