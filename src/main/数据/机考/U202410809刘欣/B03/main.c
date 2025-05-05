// ����
// U202410809
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 16 // �������鳤��

// ��������Ϊ������� , Ԫ��ȡֵ��ΧΪ1-99
void setRandomArray(int *x , const int size ) ;
// ��������������ѡ������
void sortArraySelect(int *x , const int size ) ;
// �����Ƿ���������͵Ĺ�ϵ �� �ҵ����ӡ ��ָ�뷵���ҵ��ĸ���
void displaySumRelation(int *x , const int size , int *foundNum ) ;
// ����ɾ��
void disPlay( int array[ ] , int size ) ;

int main()
{
    // ��������Ϊ������� , Ԫ��ȡֵ��ΧΪ1-99
    printf("Set random array : \n") ;
    srand(time(NULL)) ; // �������
    int array[SIZE] ; // ��������
    setRandomArray(array , SIZE) ; // �����������
    disPlay(array , SIZE ) ; // չʾ��ʼδ��������
    printf("\n") ;
    // ��������������ѡ������
    printf("Display the sorted array : \n") ;
    sortArraySelect(array , SIZE) ;
    disPlay(array , SIZE ) ; // չʾ��������
    printf("\n") ;
    // �����Ƿ���������͵Ĺ�ϵ �� �ҵ����ӡ ��ָ�뷵���ҵ��ĸ���
    printf("Display the sum relation :\n");
    int foundNum = 0 ;
    displaySumRelation(array , SIZE , &foundNum ) ;
    printf("\n%d relations in sum\n",foundNum) ;
    return 0;
}
// ��������Ϊ������� , Ԫ��ȡֵ��ΧΪ1-99
void setRandomArray(int *x , const int size )
{
    int i ;
    for (i = 0 ; i < size ; i ++ )
    {
        x[i] = rand( ) % 99 + 1 ;
    }
}

// ��������������ѡ������
void sortArraySelect(int *x , const int size )
{
    int i , j , min_index , min_value ;
    for ( i = 0 ; i < size - 1 ; i ++ )
    {
        min_index = i ;
        for ( j = i + 1 ; j < size ; j ++ )
        {
            if ( x[j] < x[min_index])
            {
                min_index = j ;
            }
        }
        if (min_index != i)
        {
            min_value = x[min_index] ;
            x[min_index] = x[i] ;
            x[i] = min_value ;
        }
    }
}

// �����Ƿ���������͵Ĺ�ϵ �� �ҵ����ӡ ��ָ�뷵���ҵ��ĸ���
void displaySumRelation(int *x , const int size , int *foundNum )
{
    int i , j , k ;
    for ( i = 0 ; i < size ; i ++ )
    {
        for ( j = 0 ; j < size  ; j ++ )
        {
            if ( j < i )
            {
                 break ; // ���ټ�������㣬���Ч��
            }
            for ( k = 0 ; k < size  ; k ++)
            {
                if ( x[i] + x[j] == x[k] )
                {
                    printf("%d + %d = %d \n",x[i] , x[j] , x[k] ) ;
                    (*foundNum) ++ ;
                }
            }
        }
    }
}

void disPlay( int array[ ] , int size )
{
    int i ;
    for ( i = 0 ; i < size ; i ++ )
    {
        printf("%2d  " , array[i]);
        if ( ( i + 1) % 4 == 0 )
        {
            printf("\n") ;
        }
    }
}
