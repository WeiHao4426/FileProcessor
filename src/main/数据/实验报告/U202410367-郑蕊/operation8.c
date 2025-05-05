#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_REAL_WIDTH 25

typedef struct {
    //数据结构有变化，结构体成员char* digits是只想动态内存区的指针
	char* digits;
	int pointPos;
	int length;
} Real;

Real* generateLongReal(void);

void destoryLongReal(Real* rPtr);

Real* addTwoLongReals(Real* rPtr1,Real* rPtr2);

//左移和右移的函数不再是对固定内存区不同数位的操作，但是直接调整动态内存区的大小和内容
void shiftDigitsToRight(Real *rPtr, int shiftLength);

void shiftDigitsToLeft(Real *rPtr, int shiftLength);

void displayAssignedLongReal(int assignedLength, const Real* rPtr);


int main(void)
{
	srand(time(NULL));
	Real* rPtr1 = generateLongReal( );
	Real* rPtr2 = generateLongReal( );
	Real* rPtrSum = addTwoLongReals(rPtr1, rPtr2);

	//结构体可以动态调整所需的字符数组区域大小，无需再判断是否溢出
	printf("\n  ") ;
	displayAssignedLongReal(rPtrSum->pointPos-rPtr1->pointPos, rPtr1);
	printf("+ ");
	displayAssignedLongReal(rPtrSum->pointPos-rPtr2->pointPos, rPtr2);
	printf("= ");
	displayAssignedLongReal(0, rPtrSum);


	destoryLongReal(rPtr1);
	destoryLongReal(rPtr2);
	destoryLongReal(rPtrSum);
}

Real *generateLongReal(void)
{
    //当前情况，结构体对象被创建时，指针类型的成员被一起创建，但是并未为其分配内存，还需要再操作
	Real* rPtr = (Real*)malloc(sizeof(Real));

	rPtr->length = 2 + rand() % (MAX_REAL_WIDTH - 1);
	rPtr->pointPos = 1 + rand() % (rPtr->length);

    //allocate memory for rPtr->digits array
	rPtr->digits = (char*)calloc(rPtr->length , sizeof(char));
    rPtr->digits[0] = '1' + rand() % 9;

    int i;
    for( i = 1; i < rPtr->length - 1; i++ )
    {
        rPtr->digits[i] = '0' + rand() % 10;
    }
	rPtr->digits[rPtr->length - 1] = '1' + rand() % 9;
	rPtr->digits[rPtr->pointPos - 1] = '.';

	printf("Randomize (%2d.%02d):", rPtr->length, rPtr->length - rPtr->pointPos);
	displayAssignedLongReal(0, rPtr);

	return rPtr;
}

void destoryLongReal(Real* rPtr)
{
    if( rPtr->digits != NULL )
    {
        free(rPtr->digits);
    }
    free(rPtr);

    return;
}

Real* addTwoLongReals(Real* rPtr1, Real* rPtr2)
{
    Real* rPtrSum = (Real*)malloc(sizeof(Real));

	int i;
    int carry = 0;
    int sum = 0;

    //向右对齐小数点
    if( rPtr1->pointPos > rPtr2->pointPos )
    {
        shiftDigitsToRight( rPtr2, rPtr1->pointPos - rPtr2->pointPos );
        rPtrSum->pointPos = rPtr1->pointPos;
    }
    else if( rPtr1->pointPos < rPtr2->pointPos )
    {
        shiftDigitsToRight( rPtr1, rPtr2->pointPos - rPtr1->pointPos );
        rPtrSum->pointPos = rPtr2->pointPos;
    }
    else if( rPtr1->pointPos == rPtr2->pointPos )
    {
        rPtrSum->pointPos = rPtr1->pointPos;
    }

    //结果长度
    rPtrSum->length = (rPtr1->length > rPtr2->length) ? rPtr1->length : rPtr2->length;
    rPtrSum->digits = (char*)calloc(rPtrSum->length , sizeof(char));
    rPtrSum->digits[rPtrSum->length] = '\0';

    //从后向前逐位相加
    for(i = rPtrSum->length - 1 ; i >= 0 ; i--)
    {
        if( i== rPtrSum->pointPos - 1 )
        {
            rPtrSum->digits[i] = '.';
            continue;
        }
        else
        {
            sum = carry;
            if( rPtr1->digits[i] >= '0' && rPtr1->digits[i] <= '9' )
            {
                sum += rPtr1->digits[i] - '0';
            }
            if( rPtr2->digits[i] >= '0' && rPtr2->digits[i] <= '9' )
            {
                sum += rPtr2->digits[i] - '0';
            }
        }
        carry = sum / 10;
        rPtrSum->digits[i] = '0' + sum % 10;
    }
    if( carry > 0 )
    {
        ;
        //存储数位不足时向右移动申请新内存，支持拓展数位，不再存在溢出的问题
        rPtrSum->length++;
        rPtrSum->digits = (char*)realloc(rPtrSum->digits, rPtrSum->length * sizeof(char));
        shiftDigitsToRight( rPtrSum, 1 );
        rPtrSum->digits[0] = '0' + carry;
    }

    printf("Sum Result(%2d.%02d):", rPtrSum->length, rPtrSum->length - rPtrSum->pointPos );
    displayAssignedLongReal(0, rPtrSum);

    if(rPtr1->pointPos > rPtr2->pointPos)
    {
        shiftDigitsToLeft( rPtr2, rPtr1->pointPos - rPtr2->pointPos );
    }
    else if(rPtr1->pointPos < rPtr2->pointPos)
    {
        shiftDigitsToLeft( rPtr1, rPtr2->pointPos - rPtr1->pointPos );
    }

    return rPtrSum;
}

void shiftDigitsToRight(Real *rPtr, int shiftLength)
{
    rPtr->digits = (char*)realloc(rPtr->digits, (rPtr->length+shiftLength+1) * sizeof(char));
    int i;
    for ( i = rPtr->length - 1; i >= 0; i--)
    {
        rPtr->digits[i + shiftLength] = rPtr->digits[i];
    }
    for ( i = 0; i < shiftLength; i++)
    {
        rPtr->digits[i] = ' ';
    }
    rPtr->length += shiftLength;
    rPtr->digits[rPtr->length] = '\0';

    printf("shiftRight (%02d)  :",shiftLength);
    displayAssignedLongReal( 0,rPtr);
    return;
}

void shiftDigitsToLeft(Real *rPtr, int shiftLength)
{
    int i;
    for ( i = 0; i < rPtr->length - shiftLength; i++)
    {
        rPtr->digits[i] = rPtr->digits[i + shiftLength];
    }
    rPtr->length -= shiftLength;
    rPtr->digits = (char*)realloc(rPtr->digits, (rPtr->length + 1) * sizeof(char));
    rPtr->digits[rPtr->length] = '\0';

    printf("shiftLeft  (%02d)  :",shiftLength);
    displayAssignedLongReal( 0, rPtr );
    return;
}

void displayAssignedLongReal(int assignedLength, const Real* rPtr)
{
    int i;
	for (i = 0; i < assignedLength  ; i++)
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
