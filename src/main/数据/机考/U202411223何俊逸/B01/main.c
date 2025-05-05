//�ο���U202411223
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20
void setRandomArray(int *x,const int size);
//�����������
void sortArrayBubble(int *x,const int size);
//ʹ��ð��������������
void displayResults(int *x,const int size,int *foundNum);
//��������������в��ң��ж�Ԫ��֮���Ƿ���ڵȲ����еĹ�ϵ��
//�ҵ����ӡ���з���Ҫ�������
int isInTheArray(int *x,const int size,int a);
//�ж�a�Ƿ�������x�У����򷵻�1�������򷵻�0
int main()
{
    int x[N];//׼��һ�������¼���
    setRandomArray(x,N);//��int isInTheArray(int *x,int a);�ɸ�����
    int i;
    sortArrayBubble(x,N);//����
    for( i = 0 ; i < N ; i++){
        printf("x[%d] = %d\n",i,x[i]);
    }//չʾ
    int num;//��¼�ҵ��˼�����
    int *foundNum;
    foundNum = &num;
    printf("get the result:\n");
    displayResults( x , N , *foundNum );//��Ȳ����в�չʾ��
    printf("there are %d wanted result here", *foundNum );
    return 0;
}

void setRandomArray( int *x , const int size ){
    srand( time(NULL) );
    int i;
    for( i = 0; i < size ; i++){
        x[i] = 1 + rand() % 99;
    }
}

void sortArrayBubble(int *x,const int size){
    int i,j;
    int help = 0 ;
    for( i = 0; i < size ; i++){
        for( j = 1 ; j < size ; j++ ){
            if( x[j-1] > x[j] ){
                help = x[j-1];
                x[j-1] = x[j];
                x[j] = help;
            }


        }
    }

}

void displayResults( int *x , const int size , int *foundNum ){
    int i;
    int x1[N];
    for( i = 0 ; i < size; i++){
        x1[i] = x[i];

    }
    int j = 1;
    for(j = 1; j < 35 ; j++){//�������1��ʼ�����ж�
        for(i = 0; i < size ; i++){
            if( isInTheArray( x1, N, x1[i]+j ) && isInTheArray( x1, N, x1[i]+2*j ) && isInTheArray(x1,N,x1[i]-j)==0){//��������������Ҫ��������ɸѡ�����ҷ�ֹ�ظ�
                int many = 1;
                printf("%d ",x1[i]);
                while( isInTheArray( x1 , N , x1[i] + many * j ) ){//��whileѭ�����Ѱ�ҿ��ܵĵ��ĸ��������Ԫ�أ������д�ӡ
                    printf("%d ", x1[i] + many * j );
                    many++;

                }
                printf("\n");
            }


        }


    }



}


int isInTheArray(int *x,const int size,int a){
    int i;
    for( i = 0 ; i < size ; i++){
        if( x[i] == a ){
            return 1;
        }
    }
    return 0;

}
