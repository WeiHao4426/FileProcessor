#include <stdio.h>
#include <stdlib.h>
#include<time.h>

//���ߣ���Դ
//ѧ�ţ�U202412268
//��Ŀ��B03

//��������Ϊ�������
void setRandomArray(int *x,const int size);

//�����������飬ʹ��ѡ������
void softArraySelect(int *x,const int size);

//�ҳ�����֮�͵ĸ�������ӡÿ���
void displaySumRelation(int *x,const int size,int *foundNum);


int main()
{
  int array[16]={0};

  int number;//ѭ������

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

printf("\n����֮�͹�ϵ�ĸ���Ϊ%d",foundNum);
}

void setRandomArray(int *x,const int size)
{
    int i;

    srand(time(NULL));//��֤������ظ�

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



