#include <stdio.h>
#include <stdlib.h>

int isNarcissistic(int x);
//�����жϲ���x�Ƿ�Ϊˮ�ɻ��������򷵻�1���񷵻�0
void displayNarcissisti(int x);
//���������ˮ�ɻ������ӡ��ֽ�ʽ�����������ӡ"It is not a narcissistic number."
int main()
{
    printf("we are going to find the narcissistic number between 200 and 1000\n");
    int i;
    int test = 0;//��������
    for(i = 200; i<= 1000;i++){
        if(isNarcissistic(i)==1){
            displayNarcissisti(i);
            test++;
        }
    }//�������е����֣��ж��Ƿ���Ҫ��ӡ��������Ҫ��ӡ������ִ�д�ӡ������
    if(test==0){
        printf("Not found");
    }//δ�ҵ�ʱ�ı������
    else{
        printf("We found %d narcissistic number",test);
    }
    return 0;
}

int isNarcissistic(int x){
    int x1 = x;//����һ��x��ֵ�����ں����ļ���
    int length;//������¼x�ж���λ��
    int i = 0;//���ڼ�¼ѭ�������ı���
    int cmp = 1;
    while(1){
        if(x>=cmp){
            cmp = cmp*10;
            i++;
        }
        else{
            break;
        }
    }//������1��10��100��x���бȽ�void displayNarcissisti(int x);���ó���λ��
    cmp = cmp/10;
    length = i;
    int eachNum[length];//�����������μ�¼ÿһλ�����֣�
    for(i = 0;i<length;i++){
        eachNum[i] = x/cmp;
        x = x%cmp;
        cmp = cmp/10;

    }
    int sum = 0;//�����������λ��������
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
        int x1 = x;//����һ��x��ֵ�����ں����ļ���
        int length;//������¼x�ж���λ��
        int i = 0;//���ڼ�¼ѭ�������ı���
        int cmp = 1;
        while(1){
            if(x>=cmp){
                cmp = cmp*10;
                i++;
            }
            else{
                break;
            }
        }//������1��10��100��x���бȽ�void displayNarcissisti(int x);���ó���λ��
        cmp = cmp/10;
        length = i;
        int eachNum[length];//�����������μ�¼ÿһλ�����֣�
        for(i = 0;i<length;i++){
            eachNum[i] = x/cmp;
            x = x%cmp;
            cmp = cmp/10;
        }//��������λ��������ȡ����
        printf("%d = ",x1);
        for(i = 0; i < length-1;i++){
            printf("%d*%d*%d + ",eachNum[i],eachNum[i],eachNum[i]);

        }
        printf("%d*%d*%d\n",eachNum[i],eachNum[i],eachNum[i]);
    }


}


