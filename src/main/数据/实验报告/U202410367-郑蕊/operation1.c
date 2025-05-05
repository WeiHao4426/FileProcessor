#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define INT_WIDTH 20 
// Generate a random long integer 
void generateLongInt( char longInt[ ] );
//基于引用的传递，由该函数为字符数组longInt[]每个数位产生随机数

// Sum two long integers
int addTwoLongInts( char longInt1[ ], char longInt2[ ], char longIntSum[ ] );
//基于引用的传递，由longInt1[]和longInt2[]为加数，longSum[]存放求和结果，返回值int标记是否计算溢出

// Display the long integer in a single line 
void displayLongInt( char longInt[ ] );

int main(void)
{
	srand( time(NULL) );
	char longInt1[ INT_WIDTH ] = { 0 };
	generateLongInt(longInt1);
	char longInt2[ INT_WIDTH ] = { 0 };
	generateLongInt(longInt2);

	char longIntSum[ INT_WIDTH ] = { 0 };
	int isOverflow = addTwoLongInts( longInt1, longInt2, longIntSum );
	//该函数返回值表达是否计算溢出

	if ( isOverflow == 0 )
	{
		printf("\n  ");
		displayLongInt( longInt1 );
		printf("+ ");
		displayLongInt( longInt2 ); 
		printf("= ");
		displayLongInt( longIntSum );
	}
	//如果不溢出，则由main函数控制输出竖式计算过程

	else if ( isOverflow == 1 )
	{
		printf("\nError! addition overflow!\n");
	}
	//如果溢出，则显示报错信息

	printf("\n"); 
	return 0;
}

void generateLongInt( char longInt[] )
{
	int i;
	longInt[0] = '1' + rand() % 9;
	for ( i = 1; i < INT_WIDTH; i++ )
	{
		longInt[i] += '0' + rand() % 10;
	}

	printf( "Generated (%d digit): ", INT_WIDTH);
	displayLongInt( longInt );

	return;
}

int addTwoLongInts( char longInt1[], char longInt2[], char longIntSum[] )
{
	int add = 0;
	int i;
	for (i = INT_WIDTH - 1; i >= 0; i--)
	{
		int digit_1 = longInt1[i] - '0';
		int digit_2 = longInt2[i] - '0';
		int sum = digit_1 + digit_2 + add;
		if (sum > 9)
		{
			add = 1;
			sum -= 10;
		}
		else
		{
			add = 0;
		}
		longIntSum[i] = sum + '0';
	}
	
	return add;
}

void displayLongInt( char longInt[] )
{
	int i;
	for ( i = 0; i < INT_WIDTH; i++ )
	{
		printf( "%c", longInt[i] );
	}
	printf("\n");

	return;
}
