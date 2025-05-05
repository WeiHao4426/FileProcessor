#include <stdio.h>
#include <stdlib.h>

int isNarcissistic(int x);
//用来判断参数x是否为水仙花数，是则返回1，否返回0
void displayNarcissisti(int x);
//如果输入是水仙花数则打印其分解式，若不是则打印"It is not a narcissistic number."
int main()
{
    printf("we are going to find the narcissistic number between 200 and 1000\n");
    int i;
    int test = 0;//用来记数
    for(i = 200; i<= 1000;i++){
        if(isNarcissistic(i)==1){
            displayNarcissisti(i);
            test++;
        }
    }//遍历所有的数字，判断是否需要打印，并对需要打印的数字执行打印函数。
    if(test==0){
        printf("Not found");
    }//未找到时的报错机制
    else{
        printf("We found %d narcissistic number",test);
    }
    return 0;
}

int isNarcissistic(int x){
    int x1 = x;//复制一个x的值，便于后续的计算
    int length;//用来记录x有多少位；
    int i = 0;//用于记录循环次数的变量
    int cmp = 1;
    while(1){
        if(x>=cmp){
            cmp = cmp*10;
            i++;
        }
        else{
            break;
        }
    }//依次用1、10、100跟x进行比较void displayNarcissisti(int x);，得出数位。
    cmp = cmp/10;
    length = i;
    int eachNum[length];//创建数组依次记录每一位的数字；
    for(i = 0;i<length;i++){
        eachNum[i] = x/cmp;
        x = x%cmp;
        cmp = cmp/10;

    }
    int sum = 0;//用来计算各数位的立方和
    for(i = 0;i<length;i++){
        sum += eachNum[i]*eachNum[i]*eachNum[i];
    }
    if(sum == x1){
        return 1;
    }
    else{
        return 0;
    }

}

void displayNarcissisti(int x){
    if(isNarcissistic(x)==0){
        printf("It is not a narcissistic number.");
    }
    else{
        int x1 = x;//复制一个x的值，便于后续的计算
        int length;//用来记录x有多少位；
        int i = 0;//用于记录循环次数的变量
        int cmp = 1;
        while(1){
            if(x>=cmp){
                cmp = cmp*10;
                i++;
            }
            else{
                break;
            }
        }//依次用1、10、100跟x进行比较void displayNarcissisti(int x);，得出数位。
        cmp = cmp/10;
        length = i;
        int eachNum[length];//创建数组依次记录每一位的数字；
        for(i = 0;i<length;i++){
            eachNum[i] = x/cmp;
            x = x%cmp;
            cmp = cmp/10;
        }//将各个数位的数字提取出来
        printf("%d = ",x1);
        for(i = 0; i < length-1;i++){
            printf("%d*%d*%d + ",eachNum[i],eachNum[i],eachNum[i]);

        }
        printf("%d*%d*%d\n",eachNum[i],eachNum[i],eachNum[i]);
    }


}


