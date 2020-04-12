#include "../head/LQueue.h"
#include "LQueue.c"
#include<stdio.h>
#include <string.h>
void menu()
{
	printf("\t\t\t\t*************************************************\n");
	printf("\t\t\t\t*\t\t1-------创建队列\t\t*\n");
	printf("\t\t\t\t*\t\t2-------销毁队列\t\t*\n");
	printf("\t\t\t\t*\t\t3-------判空队列\t\t*\n");
	printf("\t\t\t\t*\t\t4-------队头元素\t\t*\n");
	printf("\t\t\t\t*\t\t5-------队列长度\t\t*\n");
	printf("\t\t\t\t*\t\t6-------进入队列\t\t*\n");
	printf("\t\t\t\t*\t\t7-------移出队列\t\t*\n");
	printf("\t\t\t\t*\t\t8-------清空队列\t\t*\n");
	printf("\t\t\t\t*\t\t9-------遍历队列\t\t*\n");
	printf("\t\t\t\t*\t\t10------清除屏幕\t\t*\n");
	printf("\t\t\t\t*\t\t11------退出程序\t\t*\n");
	printf("\t\t\t\t*************************************************\n");
}
int judge1() {//判断是否为1到11的整数
	double aa = 0;
	int cc;
	char bb[1000];
	do {
		cc = 0;
		printf("请输入功能数字：\n");
		scanf_s("%lf", &aa);
		gets(bb);
		if (strlen(bb) > 0)
		{
			cc = 1;
		}
	} while (cc != 0 || aa < 1 || aa >11 || aa != (int)aa);
	fflush(stdout);
	aa = (int)aa;
	return aa;
}
int judge2() {//判断是否是任意整数
	double aa = 0;
	int cc;
	char bb[1000];
	do {
		cc = 0;
		printf("请输入任意整数：\n");
		scanf_s("%lf", &aa);
		gets(bb);
		if (strlen(bb) > 0)
		{
			cc = 1;
		}
	} while (cc != 0 || aa != (int)aa);
	aa = (int)aa;
	fflush(stdout);
	return aa;
}
int judge3() {//判断是否为1到4的整数
	double aa = 0;
	int cc;
	char bb[1000];
	do {
		cc = 0;
		printf("请输入1到4的数字：\n");
		scanf_s("%lf", &aa);
		gets(bb);
		if (strlen(bb) > 0)
		{
			cc = 1;
		}
	} while (cc != 0 || aa < 1 || aa >4 || aa != (int)aa);
	fflush(stdout);
	aa = (int)aa;
	return aa;
}
double judge4() {//判断是否是浮点数
	double aa = 0;
	int cc;
	char bb[1000];
	do {
		cc = 0;
		printf("(输入任意浮点数)\n");
		scanf_s("%lf", &aa);
		gets(bb);
		if (strlen(bb) > 0)
		{
			cc = 1;
		}
	} while (cc != 0);
	fflush(stdout);
	return aa;
}
char judge5() {//排除回车与空格与中文字符
	char aa;
	int cc;
	char bb[1000];
	do {
		cc = 0;
		printf("(输入非空格非回车非中文字符)\n");
		aa = getchar();
		if (aa == '\n' || aa == ' ')
		{
			cc = 1;
		}
		gets(bb);
		if (strlen(bb) > 0)
		{
			cc = 1;
		}
	} while (cc != 0);
	fflush(stdout);
	return aa;
}

Status enter(LQueue* Q, int t)//选择类型
{
	int cc = 0;
	char a;
	int b;
	double c;
	char d[101];//最大为100字节的字符串
	printf("请输入你想入队的数据:\n");
	switch (t)
	{
	case 1:
		datatype[type+Q->length] = 1;
		a = judge5();
		EnLQueue(Q, &a);
		break;
	case 2:
		datatype[type + Q->length] = 4;
		b = judge2();
		EnLQueue(Q, &b);
		break;
	case 3:
		datatype[type + Q->length] = 8;
		c = judge4();
		EnLQueue(Q, &c);
		break;
	case 4:
		datatype[type + Q->length ] = -1;
		do {
			cc = 0;
			printf("(输入任意长度不大于100的字符串)\n");
			gets(d);
			if (strlen(d) > 100|| strlen(d)==0)
			{
				cc = 1;
			}
		} while (cc != 0);
		EnLQueue(Q, d);
		break;
	defaut:;
	}
}

int main()
{

	menu();
	int z = 0, i = 0, e = 0, sign = 0, t = 0;
	z = judge1();
	LQueue Q;
	while (1)
	{
		if (z == 10)
		{
			system("cls");
			printf("操作成功\n");
			printf("操作结束\n");
			menu();
			z = judge1();
		}
		if (z == 11)
		{
			printf("退出程序\n");
			exit(0);
		}
		if (z == 1)
		{
			sign = 1;
		}
		if (sign == 0)
		{
			printf("请先进行初始化操作\n");
			z = judge1();
			if (z != 1)
			{
				continue;
			}
		}
		switch (z)
		{
		case 1:
			InitLQueue(&Q);
			sign = 1;
			printf("操作结束\n");
			z = judge1();
			break;
		case 2:DestoryLQueue(&Q);
			sign = 0;
			printf("操作结束\n");
			z = judge1();
			break;
		case 3:
			IsEmptyLQueue(&Q);
			printf("操作结束\n");
			z = judge1();
			break;
		case 4:
			GetHeadLQueue(&Q, &e);
			printf("操作结束\n");
			z = judge1();
			break;
		case 5:
			LengthLQueue(&Q);
			printf("操作结束\n");
			z = judge1();
			break;
		case 6:
			printf("你想入队哪种类型:\n");
			printf("1.字符型 2.整型 3.浮点型4.字符串型 \n");
			t = judge3();
			enter(&Q, t);
			printf("操作结束\n");
			z = judge1();
			break;
		case 7:
			DeLQueue(&Q);
			printf("操作结束\n");
			z = judge1();
			break;
		case 8:
			ClearLQueue(&Q);
			printf("操作结束\n");
			z = judge1();
			break;
		case 9:
			TraverseLQueue(&Q, LPrint);
			printf("操作结束\n");
			z = judge1();
			break;
		case 10:
			system("cls");
			printf("操作成功\n");
			printf("操作结束\n");
			menu();
			z = judge1();
			break;
		case 11:
			printf("退出程序\n");
			exit(0);
		default:break;
		}
	}
}
