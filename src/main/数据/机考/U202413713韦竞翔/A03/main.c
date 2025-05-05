//by 韦竞翔

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getGCD(int x,int y);
void displayGCD(int x,int y);

int main()
{
    int k;
    int i,j,t = 0;
    int iarr[30] = {0};//用于存储第一个数，初始化为0
    int jarr[30] = {0};//用于存储第二个数，初始化为0
    printf("请输入范围为【3-30】的整数：");
    scanf("%d",&k);
    if(k >= 3 && k <= 30){
        for(i = 3;i <= 30;i ++){
            for(j = i + 1;j <= 30;j ++){
                //遍历数组，寻找符合条件的数并存储
                if(getGCD(i,j) == k){
                    iarr[t] = i;
                    jarr[t] = j;
                    t ++;
                }
            }
        }
        //判断这个数是不是别的数的公因数，数组第一位为0表示未存储符合条件的数
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
