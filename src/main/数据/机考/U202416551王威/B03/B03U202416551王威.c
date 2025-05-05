#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void setRandomArray ( int *x, const int size );//��ȡ��������飬Ԫ��ȡֵ��Χ1��99
void sortArraySelect ( int *x, const int size );//������Ԫ����������,����ѡ������
void displaySumRelation( int *x, const int size, int *foundNum );//��ӡ���з���һԪ��Ϊ������Ԫ�غ͵�����������ظ���

int main()
{
    const int size = 16;
    int *x[size] ;
    srand( time( NULL));
    setRandomArray ( *x, size );
    sortArraySelect ( *x, size );
    int num = 0;
    int *irr = &num;
    displaySumRelation( *x, size, *irr );
}

void setRandomArray ( int *x, const int size )
{
    int integer1 = 0;//����ѭ�����ӵı���
    for ( ; integer1 < size; integer1 ++ )
    {
        *(x + integer1) = rand() % 100;
    }
}

void sortArraySelect ( int *x, const int size )//ѡ������
{
    int index1;//ÿ��ѭ��ȷ������СֵӦ���������λ��
    int index2;//ѭ��ɸѡ����Сֵ
    int insertIndex;//ȷ����Сֵ���ڵ�����λ��
    int value;//������������λ��

    for ( index1 = 0; index1 < size; index1 ++ )
    {
        insertIndex = index1;
        for ( index2 = index1 + 1; index2 < size; index2 ++ )
        {
            if ( *(x + index2) < *(x + insertIndex) )
            {
                insertIndex = index2;
            }
        }
        if ( insertIndex != index1 )
        {
            value = *(x + index1);
            *(x + index1) = *(x + insertIndex);
            *(x + insertIndex) = value;
        }
    }
}

void displaySumRelation( int *x, const int size, int *foundNum )
{
    int change1;
    int change2;
    int change3;
    for ( change1 = 0; change1 < size; change1 ++ )
    {
        for ( change2 = change1 + 1; change2 < size; change2 ++ )
        {
            for ( change3 = change2 + 1; change3 < size; change3 ++ )
            {
                if ( *(x + change1) + *(x + change2) == *(x + change3))
                {
                    *foundNum ++;
                    printf ("{%d,%d,%d}\n", *(x + change1), *(x + change1), *(x + change1));
                }
            }
        }
    }
    printf ("һ����%d��", *foundNum );
}
