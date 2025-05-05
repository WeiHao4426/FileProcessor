//U202413452 ������
//A03
#include <stdio.h>
#include <stdlib.h>

int getGCD(int x, int y);
void displayGCD(int x, int y);

int main()
{
    int k;
    printf("�����뷶Χ[3,30]��������k\n");
    scanf("%d", &k);

    if(k < 3 || k > 30)
    {
        printf("�������");
        return 0;
    }//�ж��쳣����

    int i, j;
    int counter = 0;
    for(i = 3; i < 30; i ++)
    {
        for(j = i + 1; j < 31; j ++)
        {
            if(getGCD(i, j) == k)
            {
                displayGCD(i, j);
                counter ++;
            }
        }
    }
    //û�н��ʱ�����
    if (counter == 0)
    {
        printf("û�������Ե����Լ����k");
    }

    return 0;
}
//���������Լ��
int getGCD(int x, int y)
{
    while(y != 0){
        int tem = y;
        y = x % y;
        x = tem;
    }
    return x;
}
//��ӡ���Լ����Ϣ
void displayGCD(int x, int y)
{
    printf("GCD(%d,%d)=%d\n", x, y, getGCD(x, y));
    return;
}


