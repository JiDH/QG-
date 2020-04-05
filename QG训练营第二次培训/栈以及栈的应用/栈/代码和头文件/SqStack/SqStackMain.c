#include "SqStack.c"
#include <stdio.h>
#include <stdlib.h>


void help();


int main(void){
	SqStack s;
	help();
	int flag = 0;
	while(1){
		int type, con, ans,length;
		ElemType thisdata;
		printf("\n\n*****************************************************************************************\n\n������ָ�");
		con = scanf("%d",&type);
		if(con != 1){
			printf("��������ȷָ��\n");
			while (getchar() != '\n');
			continue;
		}
		if(type == 0)
		{
			break;
		}
		switch(type)
		{
			case 1:
				help();
				break;
			case 2:
				if(flag)
				{
					printf("ջ�ѳ�ʼ��\n");
					continue;
				}
				flag = 1;
				int sizes;
				printf("������ջ��С��");
				con = scanf("%d",&sizes);
				if(con != 1){
					printf("��������ȷֵ\n");
					while (getchar() != '\n');
					continue;
				}
				ans = initStack(&s,sizes);
				if(ans == 1)
				{
					printf("��ʼ���ɹ�\n");
				}else
				{
					printf("��ʼ������\n");
				}
				break;
			case 3:
				if(!flag)
				{
					printf("ջδ��ʼ��\n");
					continue;
				}else
				{
					ans = isEmptyStack(&s);
					if(ans == 1)
					{
						printf("ջΪ��\n");
					}else
					{
						printf("ջ�ǿ�\n");
					}

				}
				break;
			case 4:
				if(!flag)
				{
					printf("ջδ��ʼ��\n");
					continue;
				}
				ans = getTopStack(&s,&thisdata);
				if(ans == 1)
				{
					printf("��ȡ�ɹ���Ԫ��Ϊ��%d\n",thisdata);
				}else
				{
					printf("��ȡʧ��\n");
				}
				break;
			case 5:
				if(!flag)
				{
					printf("ջδ��ʼ��\n");
					continue;
				}
				ans = clearStack(&s);
				if(ans == 1){
					printf("��ճɹ�\n");
				}else{
					printf("���ʧ��\n");
				}
				break;
			case 6:
				if(!flag)
				{
					printf("ջδ��ʼ��\n");
					continue;
				}
				flag = 0;
				ans = destroyStack(&s);
				if(ans == 1){
					printf("���ٳɹ�\n");
				}else{
					printf("����ʧ��\n");
				}
				break;
			case 7:
				if(!flag)
				{
					printf("ջδ��ʼ��\n");
					continue;
				}
				ans = stackLength(&s,&length);
				if(ans == 1){
					printf("���ɹ���ջ��Ϊ��%d\n",length);
				}else{
					printf("���ʧ��\n");
				}
				break;
			case 8:
				if(!flag)
				{
					printf("ջδ��ʼ��\n");
					continue;
				}
				printf("���������ֵ��");
				con = scanf("%d",&thisdata);
				if(con != 1){
					printf("��������ȷֵ\n");
					while (getchar() != '\n');
					continue;
				}
				ans = pushStack(&s,thisdata);
				if(ans == 1)
				{
					printf("��ջ�ɹ�\n");
				}else
				{
					printf("��ջʧ��\n");
				}
				break;
			case 9:
				if(!flag)
				{
					printf("ջδ��ʼ��\n");
					continue;
				}
				ans = popStack(&s,&thisdata);
				if(ans == 1)
				{
					printf("��ջ�ɹ���ֵΪ��%d\n",thisdata);
				}else
				{
					printf("��ջʧ��\n");
				}
				break;
			default:
				printf("��������ȷָ��\n");
		}
	}
	return 0;
}


void help(){
	printf("\t\t\t**********************************\n");
	printf("\t\t\t*|------------------------------|*\n");
	printf("\t\t\t*|                              |*\n");
	printf("\t\t\t*|            SqStack           |*\n");
	printf("\t\t\t*|                              |*\n");
	printf("\t\t\t*|                              |*\n");
	printf("\t\t\t*|           0 . �˳�           |*\n");
	printf("\t\t\t*|           1 . ����           |*\n");
	printf("\t\t\t*|         2 . ��ʼ��ջ         |*\n");
	printf("\t\t\t*|      3 . �ж�ջ�Ƿ�Ϊ��      |*\n");
	printf("\t\t\t*|       4 . ��ȡջ��Ԫ��       |*\n");
	printf("\t\t\t*|          5 . ���ջ          |*\n");
	printf("\t\t\t*|          6 . ����ջ          |*\n");
	printf("\t\t\t*|         7 . ���ջ��         |*\n");
	printf("\t\t\t*|           8 . ��ջ           |*\n");
	printf("\t\t\t*|           9 . ��ջ           |*\n");
	printf("\t\t\t*|                              |*\n");
	printf("\t\t\t*|------------------------------|*\n");
	printf("\t\t\t**********************************\n");
}

