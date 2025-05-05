#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define real_width 25 // the width of real number includes the point/dot
#define point_position 12 

// generate a random long real number 
void generatelongreal( char longreal[] );
// 基于引用的传递，由该函数为字符数组 longint[]每个数位产生随机数

// sum two long real numbers
int addtwolongreals( char longreal1[], char longreal2[], char longrealsum[]);
//基于引用的传递，由longlnt1[]和longlnt2[]为加数，longsum[]存放求和结果，返回值int标记是否计算溢出

// display the long integer in a single line
void displaylongreal( char longreal[] );

int main( void )
{
	srand(time(NULL));
	char longreal1[ real_width ] = { 0 };
	generatelongreal( longreal1 ); 
	char longreal2[real_width] = { 0 };
	generatelongreal( longreal2 );

	
	char longrealsum[real_width] = { 0 };
	//该函数返回值表达是否计算溢出
	int isoverflow = addtwolongreals(longreal1, longreal2, longrealsum);

	//如果不溢出，则由main函数控制输出竖式计算过程
	if (isoverflow == 0)
	{
		printf("\n  ");
		displaylongreal(longreal1);
		printf("+ ");
		displaylongreal(longreal2);
		printf("= ");
		displaylongreal(longrealsum);
	}
	//如果溢出，则显示报错信息
	else if (isoverflow == 1)
	{
		printf("\nerror! addition overflow!\n");
	}

	printf("\n");
	return 0;

}
void generatelongreal( char longreal[] )
{
	int i;
	longreal[0] = '1' + rand() % 9;
	for (i = 1; i < real_width; i++)
	{
		longreal[i] = '0' + rand() % 10;
	}
	longreal[point_position - 1] = '.';
	printf("generated (%d.%d): ", real_width, real_width - point_position);
	displaylongreal( longreal );

	return;
}

int addtwolongreals(char longreal1[], char longreal2[], char longrealsum[])
{
	int add = 0;
	for (int i = real_width - 1; i >= 0; i--)
	{

		if (i == point_position - 1)
		{
			longrealsum[i] = '.';
		}
		else
		{
			int dig1 = longreal1[i] - '0';
			int dig2 = longreal2[i] - '0';
			int sum = dig1 + dig2 + add;
			if (sum > 9)
			{
				add = 1;
				sum -= 10;
			}
			else
			{
				add = 0;
			}
			longrealsum[i] = sum + '0';
		}
	}
	return add;
}

void displaylongreal(char longreal[])
{
	int i;
	for (i = 0; i < real_width; i++)
	{
		printf("%c", longreal[i]);
	}
	printf("\n");

	return;

}
