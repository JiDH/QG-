#include "../head/AQueue.h"
#include "AQueue.c"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void menu()
{
	printf("\t\t\t\t*************************************************\n");
	printf("\t\t\t\t*\t\t0------- 帮 助 \t\t\t*\n");
	printf("\t\t\t\t*\t\t1-------创建队列\t\t*\n");
	printf("\t\t\t\t*\t\t2-------销毁队列\t\t*\n");
	printf("\t\t\t\t*\t\t3-------判满队列\t\t*\n");
	printf("\t\t\t\t*\t\t4-------判空队列\t\t*\n");
	printf("\t\t\t\t*\t\t5-------队头元素\t\t*\n");
	printf("\t\t\t\t*\t\t6-------队列长度\t\t*\n");
	printf("\t\t\t\t*\t\t7-------数据入队\t\t*\n");
	printf("\t\t\t\t*\t\t8-------数据出队\t\t*\n");
	printf("\t\t\t\t*\t\t9-------清空队列\t\t*\n");
	printf("\t\t\t\t*\t\t10------遍历队列\t\t*\n");
	printf("\t\t\t\t*\t\t11------清除屏幕\t\t*\n");
	printf("\t\t\t\t*\t\t12------ 退 出 \t\t\t*\n");
	printf("\t\t\t\t*************************************************\n");
}
int judge()//判断是否为正整数
{

	double a = 0;
	int c;
	char b[1000];
	do {
		c = 0;
		printf("请输入正整数：\n");
		scanf_s("%lf", &a);
		gets(b);
		if (strlen(b) > 0)
		{
			c = 1;
		}
	} while (c != 0 || a <= 0 || a != (int)a);
	a = (int)a;
	fflush(stdout);
	return a;
}
int conJud() {//判断是否为1到12的整数
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
	} while (cc != 0 || aa < 0 || aa >12 || aa != (int)aa);
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
char judge5() {//排除空格与回车与中文字符
	char aa;
	int cc;
	char bb[1000];
	do {
		cc = 0;
		printf("(输入非空格非回车非中文字符)\n");
		aa = getchar();
		if (aa == '\n'||aa==' ')
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
Status enter(AQueue *Q,int t)//选择类型
{
	int cc;
	char a;
	int b;
	double c;
	char d[101];//字符串最大长度为100
	printf("请输入你想入队的数据:\n");
	switch (t)
	{
	case 1:
		datatype[Q->rear] = 1;
		a = judge5();
		EnAQueue(Q, &a);
		break;
	case 2:
		datatype[Q->rear] = 4;
		b = judge2();
		EnAQueue(Q, &b);
		break;
	case 3:
		datatype[Q->rear]= 8;
		c = judge4();
		EnAQueue(Q, &c);
		break;
	case 4:
		datatype[Q->rear] = -1;
		do {
			cc = 0;
			printf("(输入任意长度不大于100的字符串)\n");
			gets(d);
			if (strlen(d) > 100 || strlen(d) == 0)
			{
				cc = 1;
			}
		} while (cc != 0);
		EnAQueue(Q, d);
		break;
	defaut:;
	}
}

int main()
{

	menu();
	int z = 0, i = 0, e = 0, sign = 0,t=0;
	z = conJud();
	AQueue Q;
	while (1)
	{
		if (z == 11)
		{
			system("cls");
			printf("操作成功\n");
			printf("操作结束\n");
			menu();
			z = conJud();
		}
		if (z == 12)
		{
			printf("退出程序\n");
			exit(0);
		}
		if (z == 1)
		{
			sign = 1;
		}
		if (sign == 0 && z != 0)
		{
			printf("请先进行初始化操作\n");
			z = conJud();
			if (z != 1)
			{
				continue;
			}
		}
		switch (z)
		{
		case 0:
			menu();
			z = conJud();
			break;
		case 1:
			InitAQueue(&Q);
			sign = 1;
			printf("操作结束\n");
			z = conJud();
			break;
		case 2:DestoryAQueue(&Q);
			sign = 0;
			printf("操作结束\n");
			z = conJud();
			break;
		case 3:
			IsFullAQueue(&Q);
			printf("操作结束\n");
			z = conJud();
			break;
		case 4:
			IsEmptyAQueue(&Q);
			printf("操作结束\n");
			z = conJud();
			break;
		case 5:
			GetHeadAQueue(&Q, &e);
			printf("操作结束\n");
			z = conJud();
			break;
		case 6:
			LengthAQueue(&Q);
			printf("操作结束\n");
			z = conJud();
			break;
		case 7:
			printf("你想入队哪种类型:\n");
			printf("1.字符型2.整型 3.浮点型4.字符串型\n");
			t = judge3();
			enter(&Q, t);
			printf("操作结束\n");
			z = conJud();
			break;
		case 8:
			DeAQueue(&Q);
			printf("操作结束\n");
			z = conJud();
			break;
		case 9:
			ClearAQueue(&Q);
			printf("操作结束\n");
			z = conJud();
			break;
		case 10:
			TraverseAQueue(&Q, APrint);//右部分就是传函数地址进去赋值给作为形参的函数指针
			printf("操作结束\n");
			z = conJud();
			break;
		case 11:
			system("cls");
			printf("操作成功\n");
			printf("操作结束\n");
			menu();
			z = conJud();
			break;
		case 12:
			printf("退出程序\n");
			exit(0);
		default:break;
		}
	}
}
