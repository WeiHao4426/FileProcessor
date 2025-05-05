#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_REAL_WIDTH 25
#define POINT_POSITION 12

typedef struct{
    char digits[ MAX_REAL_WIDTH ];
    int length;
} Real;

// Generate a random long real number
//修改生成函数的设计，将结构体作为返回值带回
Real generateLongReal( void);

// Sum two long real numbers
//修改计算函数的设计，将计算结果结构体作为返回值带回
Real addTwoLongReals( Real r1,Real r2);

// Display the real number in a single line
//新增一个函数，支持对空闲数位的打印显示
void displayLongReal( Real r);

// Display the number in a fixed width
void displayFixedwidthNumber( char number[], const int width );

int main( void )
{
    srand( time(NULL));
    Real real1 = generateLongReal();
    Real real2= generateLongReal();
    Real realSum=addTwoLongReals( real1,real2 );

    //判断结构体变量是否有效
    if( realSum.length > 0 )
    {   //如果不溢出，输出竖式计算过程
        printf("\n  ");
        displayLongReal( real1 );
        printf("+ ");
        displayLongReal( real2 );
        printf("= ");
        displayLongReal( realSum );
    }
    else
    {   //如果溢出，则显示报错信息
        printf("\nError! addition overflow!\n");
    }
    printf("\n");
    return 0;
}

Real generateLongReal( void )
{
    Real r;
    int fractionLength = rand() % ( MAX_REAL_WIDTH - POINT_POSITION + 1 );
    r.length = POINT_POSITION + fractionLength;

    int i;
    r.digits[0] = '1' + rand() % 9;
    for( i = 1; i < r.length - 1; i++ )
    {
        r.digits[i] = '0' + rand() % 10;
    }
    r.digits[ r.length - 1 ] = '1' + rand() % 9;
    r.digits[ POINT_POSITION - 1 ] = '.';
    for( i = r.length; i < MAX_REAL_WIDTH; i++ )
    {   // clear the rest of the memory
        //生成随机数时，没有用到的数位填充'\0';
        //显示正常数值时，无需打印；显示全部数宽的时候，空闲数位用字符'_'代替
        r.digits[i] = '\0';
    }
    r.digits[ MAX_REAL_WIDTH - 1 ] = '\0';
    printf("Generated (%2d.%02d):", r.length, r.length - POINT_POSITION );
    displayFixedwidthNumber( r.digits, MAX_REAL_WIDTH );

    return r;
}

void displayLongReal( Real r)
{
    int i;
    for(i=0; i<r.length; i ++ )
    {
        printf("%c", r.digits[i]);
    }
    printf("\n");
    return;
}

void displayFixedwidthNumber( char number[], const int width )
{
    int i;
    for(i=0; i< width; i ++ )
    {
        if( number[i] == '\0' )
        {   
            printf("_");
        }
        else
        {
            printf("%c", number[i]);
        }
    }
    printf("\n");
    return;
}

Real addTwoLongReals( Real r1,Real r2)
{
    Real r;
    int i;
    int carry = 0;
    int sum = 0;
    int maxLen = ( r1.length > r2.length ) ? r1.length : r2.length ;

    //判断是否溢出
    if( maxLen >= MAX_REAL_WIDTH )
    {
        r.length = 0;
        return r;
    }

    for(i = maxLen - 1 ; i >= 0; i--)
    {
        if( r1.digits[i] == '.' )
        {
            r.digits[i] = '.';
            continue;
        }
        else
        {
            sum = carry;
            if(r1.digits[i] != '\0' )
            {
                sum += r1.digits[i] - '0';
            }
            if( r2.digits[i] != '\0' )
            {
                sum += r2.digits[i] - '0';
            }
        }
        carry = sum / 10;
        r.digits[i] = '0' + sum % 10;
        
    }

    if( carry > 0 )
    {
        //溢出判断
        r.length = 0 ;
        return r;
    }
    else
    {
        r.length = maxLen;
    }

    for( i=r.length; i < MAX_REAL_WIDTH ; i++ )
    {   // clear the rest of the memory
        //生成随机数时，没有用到的数位填充'\0';
        //显示正常数值时，无需打印；显示全部数宽的时候，空闲数位用字符'_'代替
        r.digits[i] = '\0';
    }
    r.digits[ MAX_REAL_WIDTH - 1 ] = '\0';
    printf("Sum Result(%2d.%02d):", r.length, r.length - POINT_POSITION );
    displayFixedwidthNumber( r.digits, MAX_REAL_WIDTH );
    return r;
}