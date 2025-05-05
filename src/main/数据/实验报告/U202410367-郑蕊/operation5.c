#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
  
#define MAX_REAL_WIDTH 25  
  
typedef struct{  
    char digits[ MAX_REAL_WIDTH ];  
    int pointPos;  
    int length;  
} Real;  
  
//需要用指针法改写的函数，通过指针操作数组元素
// Generate a random long real number  
Real generateLongReal( void);  
  
// Sum two long real numbers  
Real addTwoLongReals( Real r1,Real r2);  
  
//需要用指针法改写的函数，通过指针操作数组元素
// Display the real number in a single line  
void displayAssignedLongReal( int pointPos,Real r);  
  
// Shift the digits to right direction  
void shiftDigitsToRight( char number[],int shiftLength);  
  
// Shift the digits to left direction  
void shiftDigitsToLeft( char number[],int shiftLength);  
  
// Display the number in a fixed width  
void displayFixedwidthNumber( char number[], const int width );  
  
int main( void )  
{  
    srand( time(NULL));  
    Real real1 = generateLongReal();  
    Real real2 = generateLongReal();  
    Real realSum = addTwoLongReals( real1,real2 );  
  
    //判断结构体变量是否有效  
    if( realSum.length > 0 )  
    {   //如果不溢出，输出竖式计算过程  
        printf("\n  ");  
        displayAssignedLongReal( realSum.pointPos,real1 );  
        printf("+ ");  
        displayAssignedLongReal( realSum.pointPos,real2 );  
        printf("= ");  
        displayAssignedLongReal( realSum.pointPos,realSum );  
    }  
    else  
    {   //如果溢出，则显示报错信息  
        printf("\nError! addition overflow!\n");  
    }  
    printf("\n");  
    return 0;  
}  
  
void displayAssignedLongReal(int pointPos,Real r)  
{  
    int i;  
    for( i=0 ; i < pointPos-r.pointPos ; i++ )  
    {  
        printf(" ");  
    }  
    char *cPtr = NULL ;
    for( cPtr = r.digits ; cPtr < r.digits + r.length ; cPtr ++ )  
    {  
        printf("%c",*cPtr);  
    }  
    printf("\n");  
  
    return;  
}  
  
void shiftDigitsToRight( char number[],int shiftLength)  
{  
    char *end = number + MAX_REAL_WIDTH - 1;
    char *start = number + MAX_REAL_WIDTH - 1 - shiftLength;
    while( start >= number )  
    {  
        *end = *start;  
        end--;  
        start--;  
    }
    while( end >= number )  
    {  
        *end = '\0';  
        end--;  
    }

    printf("shiftRight  (%02d)  :",shiftLength);  
    displayFixedwidthNumber( number, MAX_REAL_WIDTH );  
    return;  
}  
  
void shiftDigitsToLeft( char number[],int shiftLength)  
{  
    char *start = number;
    char *end = number + shiftLength;
    while( end < number + MAX_REAL_WIDTH )  
    {  
        *start = *end;  
        start++;  
        end++;  
    }
    while( start < number + MAX_REAL_WIDTH )  
    {  
        *start = '\0';  
        start++;  
    }

    printf("shiftLeft   (%02d)  :",shiftLength);  
    displayFixedwidthNumber( number, MAX_REAL_WIDTH );  
    return;  
}  
  
Real addTwoLongReals( Real r1,Real r2)  
{  
    Real r;  
    int i;  
    int carry = 0;  
    int sum = 0;  
  
    //向右对齐  
    int r1right = MAX_REAL_WIDTH - r1.length ;  
    int r2right = MAX_REAL_WIDTH - r2.length ;  
    int shiftLength = (r1right < r2right) ? r1right : r2right ;  
  
    //将两个数的小数点向右移动对齐并求和  
    if( r1right < r2right )  
    {    //判断表达精度的数位是否足够  
            //是否在移动过程中向右溢出
        if(r2.length+shiftLength + r1.pointPos-r2.pointPos > MAX_REAL_WIDTH
              //是否向左溢出
           ||r2.length-r1.length > shiftLength )  
        {  
            r.length = 0;  
            return r;  
        }  
        else  
        {  
            shiftDigitsToRight( r1.digits, shiftLength );  
            shiftDigitsToRight( r2.digits, shiftLength + r1.pointPos-r2.pointPos );  
        }  
    }  
    else if( r1right > r2right )  
    {  
        if(r1.length+shiftLength + r2.pointPos-r1.pointPos > MAX_REAL_WIDTH
           || r1.length-r2.length > shiftLength )  
        {  
            r.length = 0;  
            return r;  
        }  
        else  
        {  
            shiftDigitsToRight( r1.digits, shiftLength + r2.pointPos-r1.pointPos );  
            shiftDigitsToRight( r2.digits, shiftLength  );  
        }  
    }  
    else if( r1right == r2right )  
    {  
        if(r1.pointPos!=r2.pointPos)  
        {  
            r.length = 0;  
            return r;  
        }  
        else  
        {  
            shiftDigitsToRight( r1.digits, r1right + abs(r2.pointPos-r1.pointPos) );  
            shiftDigitsToRight( r2.digits, r2right + abs(r2.pointPos-r1.pointPos) );  
        }  
    }  
      
  
    //判断是否溢出  
    if( r1.length > MAX_REAL_WIDTH || r2.length > MAX_REAL_WIDTH )  
    {  
        r.length = 0;  
        return r;  
    }  
  
    //求向右对齐后长实数  
    int r1left = 0,r2left = 0;  
    while(r1.digits[r1left] =='\0')  
    {  
        r1left++;  
    }  
    while(r2.digits[r2left] =='\0')  
    {  
        r2left++;  
    }  
    int rleft = (r1left < r2left) ? r1left : r2left ;  
    r.length = MAX_REAL_WIDTH - rleft ;  
  
    //求和  
    for(i = MAX_REAL_WIDTH - 1 ; i >= 0 ; i--)  
    {  
        if( r1.digits[i] == '.' )  
        {  
            r.digits[i] = '.';  
            r.pointPos = r.length - (MAX_REAL_WIDTH - ( i + 1 ) );  
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
        //加法运算有进位，计算溢出  
        r.length = 0 ;  
        return r;  
    }  
  
    for( i = MAX_REAL_WIDTH - r.length - 1; i >=0 ; i-- )  
    {   // clear the rest of the memory  
        //生成随机数时，没有用到的数位填充'\0';  
        //显示正常数值时，无需打印；显示全部数宽的时候，空闲数位用字符'_'代替  
        r.digits[i] = '\0';  
    }  
      
    printf("Sum Result (%2d.%02d):", r.length, r.length - r.pointPos );  
    displayFixedwidthNumber( r.digits, MAX_REAL_WIDTH );  
  
    //最后将三个数的小数点向左移动，去除前置的0  
    shiftDigitsToLeft( r1.digits, r1left  );  
    shiftDigitsToLeft( r2.digits, r2left );  
    shiftDigitsToLeft( r.digits, rleft );  
  
    return r;  
}  
  
void displayFixedwidthNumber( char number[], const int width )  
{  
    char *cPtr = number;
    int i;  
    for( i = 0; i < width; i++ )  
    {  
        if( *(cPtr + i) == '\0' )  
        {     
            printf("_");  
        }  
        else  
        {  
            printf("%c", *(cPtr + i) );   
        }  
    }  
    printf("\n");  
    return;  
}  
  
Real generateLongReal( void )  
{  
    Real r;  
    int i;  
    int len = rand() % ( MAX_REAL_WIDTH + 1 );  
    r.pointPos = rand() % len  + 1 ;  
    r.length = len;  
    
    char *cPtr = r.digits;
    for( i = 0; i < len ; i++ )  
    {  
        char digit = rand() % 10;  
        if( i == r.pointPos-1 )  
        {  
            *(cPtr + i) = '.';  
        }  
        else  
        {  
            *(cPtr + i) = '0' + digit;  
        }  
    }  
    *(cPtr + 0) = '1' + rand() % 9;  
    *(cPtr + r.length - 1 ) = '1' + rand() % 9; 

    if( r.pointPos == 1 )  
    {  
        *(cPtr + 0) = '.';  
    }  
  
    if( r.pointPos == r.length )  
    {  
        *(cPtr + r.length - 1 ) = '.';  
    }  
    
    for( i = len; i < MAX_REAL_WIDTH; i++ )  
    {  
        *(cPtr + i) = '\0';  
    }  
  
    *(cPtr + MAX_REAL_WIDTH - 1 ) = '\0';  
    printf("Generated  (%2d.%02d):", r.length, r.length - r.pointPos );  
    displayFixedwidthNumber( r.digits, MAX_REAL_WIDTH );  
  
    return r;  
}  