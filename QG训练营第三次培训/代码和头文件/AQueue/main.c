#include "../head/AQueue.h"
#include "AQueue.c"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void menu()
{
	printf("\t\t\t\t*************************************************\n");
	printf("\t\t\t\t*\t\t0------- �� �� \t\t\t*\n");
	printf("\t\t\t\t*\t\t1-------��������\t\t*\n");
	printf("\t\t\t\t*\t\t2-------���ٶ���\t\t*\n");
	printf("\t\t\t\t*\t\t3-------��������\t\t*\n");
	printf("\t\t\t\t*\t\t4-------�пն���\t\t*\n");
	printf("\t\t\t\t*\t\t5-------��ͷԪ��\t\t*\n");
	printf("\t\t\t\t*\t\t6-------���г���\t\t*\n");
	printf("\t\t\t\t*\t\t7-------�������\t\t*\n");
	printf("\t\t\t\t*\t\t8-------���ݳ���\t\t*\n");
	printf("\t\t\t\t*\t\t9-------��ն���\t\t*\n");
	printf("\t\t\t\t*\t\t10------��������\t\t*\n");
	printf("\t\t\t\t*\t\t11------�����Ļ\t\t*\n");
	printf("\t\t\t\t*\t\t12------ �� �� \t\t\t*\n");
	printf("\t\t\t\t*************************************************\n");
}
int judge()//�ж��Ƿ�Ϊ������
{

	double a = 0;
	int c;
	char b[1000];
	do {
		c = 0;
		printf("��������������\n");
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
int conJud() {//�ж��Ƿ�Ϊ1��12������
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
	} while (cc != 0 || aa < 0 || aa >12 || aa != (int)aa);
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
char judge5() {//�ų��ո���س��������ַ�
	char aa;
	int cc;
	char bb[1000];
	do {
		cc = 0;
		printf("(����ǿո�ǻس��������ַ�)\n");
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
Status enter(AQueue *Q,int t)//ѡ������
{
	int cc;
	char a;
	int b;
	double c;
	char d[101];//�ַ�����󳤶�Ϊ100
	printf("������������ӵ�����:\n");
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
			printf("(�������ⳤ�Ȳ�����100���ַ���)\n");
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
			printf("�����ɹ�\n");
			printf("��������\n");
			menu();
			z = conJud();
		}
		if (z == 12)
		{
			printf("�˳�����\n");
			exit(0);
		}
		if (z == 1)
		{
			sign = 1;
		}
		if (sign == 0 && z != 0)
		{
			printf("���Ƚ��г�ʼ������\n");
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
			printf("��������\n");
			z = conJud();
			break;
		case 2:DestoryAQueue(&Q);
			sign = 0;
			printf("��������\n");
			z = conJud();
			break;
		case 3:
			IsFullAQueue(&Q);
			printf("��������\n");
			z = conJud();
			break;
		case 4:
			IsEmptyAQueue(&Q);
			printf("��������\n");
			z = conJud();
			break;
		case 5:
			GetHeadAQueue(&Q, &e);
			printf("��������\n");
			z = conJud();
			break;
		case 6:
			LengthAQueue(&Q);
			printf("��������\n");
			z = conJud();
			break;
		case 7:
			printf("���������������:\n");
			printf("1.�ַ���2.���� 3.������4.�ַ�����\n");
			t = judge3();
			enter(&Q, t);
			printf("��������\n");
			z = conJud();
			break;
		case 8:
			DeAQueue(&Q);
			printf("��������\n");
			z = conJud();
			break;
		case 9:
			ClearAQueue(&Q);
			printf("��������\n");
			z = conJud();
			break;
		case 10:
			TraverseAQueue(&Q, APrint);//�Ҳ��־��Ǵ�������ַ��ȥ��ֵ����Ϊ�βεĺ���ָ��
			printf("��������\n");
			z = conJud();
			break;
		case 11:
			system("cls");
			printf("�����ɹ�\n");
			printf("��������\n");
			menu();
			z = conJud();
			break;
		case 12:
			printf("�˳�����\n");
			exit(0);
		default:break;
		}
	}
}
