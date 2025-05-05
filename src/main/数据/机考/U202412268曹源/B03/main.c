#include <stdio.h>
#include <stdlib.h>
#include<time.h>

//作者：曹源
//学号：U202412268
//题目：B03

//设置数组为随机整数
void setRandomArray(int *x,const int size);

//升序排列数组，使用选择排序
void softArraySelect(int *x,const int size);

//找出两数之和的个数并打印每组解
void displaySumRelation(int *x,const int size,int *foundNum);


int main()
{
  int array[16]={0};

  int number;//循环计数

  int foundNum=0;

  setRandomArray(array,16);

  for(number=0;number<16;number++)
  {
      printf("%d  ",array[number]);
  }
softArraySelect(array,16);

printf("\n");

for(number=0;number<16;number++)
  {
      printf("%d  ",array[number]);
  }

  displaySumRelation(array,16, &foundNum);

printf("\n两数之和关系的个数为%d",foundNum);
}

void setRandomArray(int *x,const int size)
{
    int i;

    srand(time(NULL));//保证随机不重复

   for(i=0;i<size;i++)
    {
        *(x+i)=rand()%99+1;

    }

}

void softArraySelect(int *x,const int size)
{
    int i,j,m;

    for(i=0;i<size-1;i++)
    {
    m=i;

    for(j=i+1;j<=size-1;j++)
        {
            if(x[j]<x[m])
            {
              m=j;
            }

        }
        int n=0;

              n=x[m];

              x[m]=x[i];

              x[i]=n;
    }


}

void displaySumRelation(int *x,const int size,int *foundNum)
{
    int i,j,m=0;

    for(i=0;i<=13;i++)
    {
      for(j=i+1;j<=14;j++)
        {
           for(m=j+1;m<=15;m++)
            {
                if(x[i]+x[j]==x[m])
                {*foundNum=*foundNum+1;

                printf("\n%d+%d=%d",x[i],x[j],x[m]);


                }

            if(x[m]==x[m+1])
            {
                m++;
            }
            }

            if(x[j]==x[j+1])
            {
                j++;
            }


        }
        if(x[i]==x[i+1])
            {
               i++;
            }
    }
}



