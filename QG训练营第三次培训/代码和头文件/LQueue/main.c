#include "../head/LQueue.h"
#include "LQueue.c"
#include<stdio.h>
#include <string.h>
void menu()
{
	printf("\t\t\t\t*************************************************\n");
	printf("\t\t\t\t*\t\t1-------��������\t\t*\n");
	printf("\t\t\t\t*\t\t2-------���ٶ���\t\t*\n");
	printf("\t\t\t\t*\t\t3-------�пն���\t\t*\n");
	printf("\t\t\t\t*\t\t4-------��ͷԪ��\t\t*\n");
	printf("\t\t\t\t*\t\t5-------���г���\t\t*\n");
	printf("\t\t\t\t*\t\t6-------�������\t\t*\n");
	printf("\t\t\t\t*\t\t7-------�Ƴ�����\t\t*\n");
	printf("\t\t\t\t*\t\t8-------��ն���\t\t*\n");
	printf("\t\t\t\t*\t\t9-------��������\t\t*\n");
	printf("\t\t\t\t*\t\t10------�����Ļ\t\t*\n");
	printf("\t\t\t\t*\t\t11------�˳�����\t\t*\n");
	printf("\t\t\t\t*************************************************\n");
}
int judge1() {//�ж��Ƿ�Ϊ1��11������
	double aa = 0;
	int cc;
	char bb[1000];
	do {
		cc = 0;
		printf("�����빦�����֣�\n");
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
int judge2() {//�ж��Ƿ�����������
	double aa = 0;
	int cc;
	char bb[1000];
	do {
		cc = 0;
		printf("����������������\n");
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
int judge3() {//�ж��Ƿ�Ϊ1��4������
	double aa = 0;
	int cc;
	char bb[1000];
	do {
		cc = 0;
		printf("������1��4�����֣�\n");
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
double judge4() {//�ж��Ƿ��Ǹ�����
	double aa = 0;
	int cc;
	char bb[1000];
	do {
		cc = 0;
		printf("(�������⸡����)\n");
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
char judge5() {//�ų��س���ո��������ַ�
	char aa;
	int cc;
	char bb[1000];
	do {
		cc = 0;
		printf("(����ǿո�ǻس��������ַ�)\n");
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

Status enter(LQueue* Q, int t)//ѡ������
{
	int cc = 0;
	char a;
	int b;
	double c;
	char d[101];//���Ϊ100�ֽڵ��ַ���
	printf("������������ӵ�����:\n");
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
			printf("(�������ⳤ�Ȳ�����100���ַ���)\n");
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
			printf("�����ɹ�\n");
			printf("��������\n");
			menu();
			z = judge1();
		}
		if (z == 11)
		{
			printf("�˳�����\n");
			exit(0);
		}
		if (z == 1)
		{
			sign = 1;
		}
		if (sign == 0)
		{
			printf("���Ƚ��г�ʼ������\n");
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
			printf("��������\n");
			z = judge1();
			break;
		case 2:DestoryLQueue(&Q);
			sign = 0;
			printf("��������\n");
			z = judge1();
			break;
		case 3:
			IsEmptyLQueue(&Q);
			printf("��������\n");
			z = judge1();
			break;
		case 4:
			GetHeadLQueue(&Q, &e);
			printf("��������\n");
			z = judge1();
			break;
		case 5:
			LengthLQueue(&Q);
			printf("��������\n");
			z = judge1();
			break;
		case 6:
			printf("���������������:\n");
			printf("1.�ַ��� 2.���� 3.������4.�ַ����� \n");
			t = judge3();
			enter(&Q, t);
			printf("��������\n");
			z = judge1();
			break;
		case 7:
			DeLQueue(&Q);
			printf("��������\n");
			z = judge1();
			break;
		case 8:
			ClearLQueue(&Q);
			printf("��������\n");
			z = judge1();
			break;
		case 9:
			TraverseLQueue(&Q, LPrint);
			printf("��������\n");
			z = judge1();
			break;
		case 10:
			system("cls");
			printf("�����ɹ�\n");
			printf("��������\n");
			menu();
			z = judge1();
			break;
		case 11:
			printf("�˳�����\n");
			exit(0);
		default:break;
		}
	}
}
