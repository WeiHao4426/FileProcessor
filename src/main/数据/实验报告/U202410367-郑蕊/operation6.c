#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_REAL_WIDTH 25

typedef struct {
	char digits[MAX_REAL_WIDTH];
	int pointPos;
	int length;
} Real;

//通过指针实现基于引用的函数传递，修改相应的函数

//原来返回结构体的函数改为，通过结构体指针的基于引用的函数传递
void generateLongReal( Real* rPtr );

void addTwoLongReals( const Real* rPtr1, const Real* rPtr2, Real* rPtrSum );

void displayAssignedLongReal( int pointPos, Real* rPtr );

//原来通过数组名实现基于引用传递的函数，改为通过指针实现
void shiftDigitsToRight(const char* longNumber, int shiftLength);

void shiftDigitsToLeft(const char* longNumber, int shiftLength);

void displayFixedWidthNumber(const char* number, const int width);

int main(void)
{
	srand(time(NULL));
	Real r1, r2, sum;
	Real* rPtr1 = &r1, * rPtr2 = &r2, * rPtrSum = &sum;

	//通过结构体指针rPtrSum实现基于引用的传递，相应的内存区sum对象被函数直接改写，无需通过函数返回值带回，节省了内存复制过程
	generateLongReal(rPtr1);
	generateLongReal(rPtr2);
	addTwoLongReals(rPtr1, rPtr2, rPtrSum);

	if (rPtrSum->length > 0)
	{
		printf("\n  ");
		displayAssignedLongReal(rPtrSum->pointPos, rPtr1);
		printf("+ ");
		displayAssignedLongReal(rPtrSum->pointPos, rPtr2);
		printf("= ");
		displayAssignedLongReal(rPtrSum->pointPos, rPtrSum);
	}
	else
	{
		printf("\nError! addition overflow!\n");
	}
	printf("\n");
}

//通过结构体指针来操作结构体变量的成员
void generateLongReal(Real* rPtr)
{
	rPtr->length = 2 + rand() % (MAX_REAL_WIDTH - 1);
	rPtr->pointPos = 1 + rand() % (rPtr->length);

	char* cPtr = rPtr->digits;
	*cPtr = '1' + rand() % 9;
	for (cPtr++; cPtr < rPtr->digits + rPtr->length - 1; cPtr++)
	{
		*cPtr = '0' + rand() % 10;
	}
	for (; cPtr < rPtr->digits + MAX_REAL_WIDTH; cPtr++)
	{
		// clear the rest of the memory
		*cPtr = '\0';
	}

	rPtr->digits[rPtr->length - 1] = '1' + rand() % 9;
	rPtr->digits[rPtr->pointPos - 1] = '.';

	printf("Generated(%2d.%02d): ", rPtr->length, rPtr->length - rPtr->pointPos);
	displayFixedWidthNumber(rPtr->digits, MAX_REAL_WIDTH);
	return;
}

void addTwoLongReals(const Real* rPtr1, const Real* rPtr2, Real* rPtrSum)
{  
    int i;  
    int carry = 0;  
    int sum = 0;  
  
    //向右对齐  
    int r1right = MAX_REAL_WIDTH - rPtr1->length ;  
    int r2right = MAX_REAL_WIDTH - rPtr2->length ;  
    int shiftLength = (r1right < r2right) ? r1right : r2right ;  
      
    //将两个数的小数点向右移动对齐并求和  
    if( r1right < r2right )  
    {    //判断表达精度的数位是否足够  
			//是否在移动过程中向右溢出
        if(rPtr2->length+shiftLength + rPtr1->pointPos-rPtr2->pointPos > MAX_REAL_WIDTH
           ||rPtr2->pointPos - rPtr1->pointPos > shiftLength )  
        {  
            rPtrSum->length = 0;  
            return;  
        }  
        else  
        {  
            shiftDigitsToRight( rPtr1->digits, shiftLength );  
            shiftDigitsToRight( rPtr2->digits, shiftLength + rPtr1->pointPos-rPtr2->pointPos );  
        }  
    }  
    else if( r1right > r2right )  
    {  
        if(rPtr1->length+shiftLength + rPtr2->pointPos-rPtr1->pointPos > MAX_REAL_WIDTH
           || rPtr1->pointPos - rPtr2->pointPos > shiftLength )  
        {  
            rPtrSum->length = 0;  
            return ;  
        }  
        else  
        {  
            shiftDigitsToRight( rPtr1->digits, shiftLength + rPtr2->pointPos-rPtr1->pointPos );  
            shiftDigitsToRight( rPtr2->digits, shiftLength  );  
        }  
    }  
    else if( r1right == r2right )  
    {  
        if(rPtr1->pointPos!=rPtr2->pointPos)  
        {  
            rPtrSum->length = 0;  
            return ;  
        }  
        else  
        {  
            shiftDigitsToRight( rPtr1->digits, r1right  );  
            shiftDigitsToRight( rPtr2->digits, r2right  );  
        }  
    }  
      
  
    //判断是否溢出  
    if( rPtr1->length > MAX_REAL_WIDTH || rPtr2->length > MAX_REAL_WIDTH )  
    {  
        rPtrSum->length = 0;  
        return ;  
    }  
  
    //求向右对齐后长实数  
    int r1left = 0,r2left = 0;  
    while(rPtr1->digits[r1left] =='\0')  
    {  
        r1left++;  
    }  
    while(rPtr2->digits[r2left] =='\0')  
    {  
        r2left++;  
    }  
    int rleft = (r1left < r2left) ? r1left : r2left ;  
    rPtrSum->length = MAX_REAL_WIDTH - rleft ;  
  
    //求和  
    for(i = MAX_REAL_WIDTH - 1 ; i >= 0 ; i--)  
    {  
        if( rPtr1->digits[i] == '.' )  
        {  
            rPtrSum->digits[i] = '.';  
            rPtrSum->pointPos = rPtrSum->length - (MAX_REAL_WIDTH - ( i + 1 ) );  
            continue;  
        }  
        else  
        {  
            sum = carry;  
            if(rPtr1->digits[i] != '\0' )  
            {  
                sum += rPtr1->digits[i] - '0';  
            }  
            if( rPtr2->digits[i] != '\0' )  
            {  
                sum += rPtr2->digits[i] - '0';  
            }  
        }  
        carry = sum / 10;  
        rPtrSum->digits[i] = '0' + sum % 10;  
    }  
    if( carry > 0 )  
    {  
        //加法运算有进位，计算溢出  
        rPtrSum->length = 0 ;  
        return ;  
    }  
  
    for( i = MAX_REAL_WIDTH - rPtrSum->length - 1; i >=0 ; i-- )  
    {   // clear the rest of the memory  
        //生成随机数时，没有用到的数位填充'\0';  
        //显示正常数值时，无需打印；显示全部数宽的时候，空闲数位用字符'_'代替  
        rPtrSum->digits[i] = '\0';  
    }  
      
    printf("Sum Result (%2d.%02d):", rPtrSum->length, rPtrSum->length - rPtrSum->pointPos );  
    displayFixedWidthNumber( rPtrSum->digits, MAX_REAL_WIDTH );  
  
    //最后将三个数的小数点向左移动，去除前置的0  
    shiftDigitsToLeft( rPtr1->digits, r1left  );  
    shiftDigitsToLeft( rPtr2->digits, r2left );  
    shiftDigitsToLeft( rPtrSum->digits, rleft );  
  
    return 	;  
}

void displayAssignedLongReal(int pointPos, Real* rPtr)
{
	int i;
	for (i = 0; i < pointPos - rPtr->pointPos; i++)
	{
		printf(" ");
	}
	for (i = 0; i < rPtr->length; i++)
	{
		printf("%c", rPtr->digits[i]);
	}
	printf("\n");

	return;
}

void shiftDigitsToRight(const char* longNumber, int shiftLength)
{
	char *end = longNumber + MAX_REAL_WIDTH - 1;
	char *start = longNumber + MAX_REAL_WIDTH - 1 - shiftLength;
	while (start >= longNumber)
	{
		*end = *start;
		end--;
		start--;
	}
	while (end >= longNumber)
	{
		*end = '\0';
		end--;
	}

	printf("shiftRight  (%02d)  :", shiftLength);
	displayFixedWidthNumber(longNumber, MAX_REAL_WIDTH);
	return ;
}

void shiftDigitsToLeft(const char* longNumber, int shiftLength)
{
    char *start = longNumber;
    char *end = longNumber + shiftLength;
    while( end < longNumber + MAX_REAL_WIDTH )  
    {  
        *start = *end;  
        start++;  
        end++;  
    }
    while( start < longNumber + MAX_REAL_WIDTH )  
    {  
        *start = '\0';  
        start++;  
    }

    printf("shiftLeft   (%02d)  :",shiftLength);  
    displayFixedWidthNumber( longNumber, MAX_REAL_WIDTH );  
    return;
}

void displayFixedWidthNumber(const char* number, const int width)
{
	int i;
	for (i = 0; i < width; i++)
	{
		if (number[i] == '\0')
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
		