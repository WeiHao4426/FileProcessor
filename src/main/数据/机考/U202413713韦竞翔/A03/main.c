//by Τ����

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getGCD(int x,int y);
void displayGCD(int x,int y);

int main()
{
    int k;
    int i,j,t = 0;
    int iarr[30] = {0};//���ڴ洢��һ��������ʼ��Ϊ0
    int jarr[30] = {0};//���ڴ洢�ڶ���������ʼ��Ϊ0
    printf("�����뷶ΧΪ��3-30����������");
    scanf("%d",&k);
    if(k >= 3 && k <= 30){
        for(i = 3;i <= 30;i ++){
            for(j = i + 1;j <= 30;j ++){
                //�������飬Ѱ�ҷ��������������洢
                if(getGCD(i,j) == k){
                    iarr[t] = i;
                    jarr[t] = j;
                    t ++;
                }
            }
        }
        //�ж�������ǲ��Ǳ�����Ĺ������������һλΪ0��ʾδ�洢������������
        if(iarr[0] != 0){
            for(i = 0;i < t;i ++){
                displayGCD(iarr[i],jarr[i]);
            }
        }else{
            printf("There is no integer pair with their GCD is k.");
        }
    }else{
        printf("input error.");
    }
    return 0;
}

int getGCD(int x,int y){
    int t;
    if(x > y){
        t = y;
    }else{
        t = x;
    }
    while(!(x % t == 0 && y % t == 0)){
        t --;
    }
    return t;
}

void displayGCD(int x,int y){
    printf("GCD(%d,%d)=%d,because %d = %d * %d;%d = %d * %d\n",x,y,getGCD(x,y),x,getGCD(x,y),x/getGCD(x,y),y,getGCD(x,y),y/getGCD(x,y));
}
