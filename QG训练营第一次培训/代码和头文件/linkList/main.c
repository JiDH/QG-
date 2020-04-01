#include "linkedList.c"
#include <stdio.h>
#include <stdlib.h>


void visit(ElemType e);
void help();
LNode* creatNode(ElemType data);
LNode* numNode(LinkedList L,int n);
int confirm(LinkedList L, int n);

int main(void){
	LinkedList L;
	LNode a, *b;
	ElemType  E;
	int num;
	help();
	InitList(&L);
	DestroyList(&L);
	while(1){
		int type, con, ans;
		ElemType thisdata;
		printf("\n\n*****************************************************************************************\n\n������ָ�");
		con = scanf("%d",&type);
		if(con != 1){
			printf("������\n");
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
				if(L)
				{
					printf("�����Ѵ���\n");
					continue;
				}
				ans = InitList(&L);
				if(ans == 1)
				{
					printf("��������ɹ�\n");
				}else
				{
					printf("��������\n");
				}
				break;
			case 3:
				if(!L)
				{
					printf("��������\n");
				}else
				{
					DestroyList(&L);
					printf("�ͷųɹ�\n");
				}
				break;
			case 4:
				if(!L)
				{
					printf("��������\n");
					continue;
				}
				printf("��������ţ�\n");
				ans = scanf("%d",&num);
				if(ans != 1){
					printf("�����쳣\n");
					while (getchar() != '\n');
					continue;
				}
				if(num < 1){
					printf("����������\n");
					continue;
				}
				num--;
				if(!confirm(L,num)){
					printf("�����Ȳ���\n");
					continue;
				}
				b = numNode(L,num);

				printf("�����������ֵ��\n");
				ans = scanf("%d",&thisdata);
				if(ans != 1){
					printf("�����쳣\n");
					while (getchar() != '\n');
					continue;
				}else
				{
					ans = InsertList(b, creatNode(thisdata));
					if(ans == 1)
					{
						printf("����ɹ�\n");
					}else
					{
						printf("�������\n");
					}
				}
				break;
			case 5:
				if(!L)
				{
					printf("��������\n");
					continue;
				}
				if(!(L->next))
				{
					printf("������ֵ\n");
					continue;
				}
				printf("������ţ�\n");
				ans = scanf("%d",&num);
				if(ans != 1){
					printf("�����쳣\n");
					while (getchar() != '\n');
					continue;
				}
				if(num < 1){
					printf("����������\n");
					continue;
				}
				num--;
				if(!confirm(L,num)){
					printf("�����Ȳ���\n");
					continue;
				}
				b = numNode(L,num);
				ans = DeleteList(b,&E);
				if(ans == 1){
					printf("�ýڵ�ֵΪ%d��ɾ���ɹ�\n",E);
				}else{
					printf("ɾ��ʧ��\n");
				}
				break;
			case 6:
				if(!L)
				{
					printf("��������\n");
				}else
				{
					TraverseList(L,visit);
					printf("�����ɹ�\n");
				}
				break;
			case 7:
				if(!L)
				{
					printf("��������\n");
					continue;
				}
				printf("���������ֵ��\n");
				ans = scanf("%d",&thisdata);
				if(ans != 1){
					printf("�����쳣\n");
					while (getchar() != '\n');
					continue;
				}else
				{
					ans = SearchList(L,thisdata);
					if(ans == 1)
					{
						printf("�����ɹ�\n");
					}else
					{
						printf("δ�ҵ�\n");
					}
				}
				break;
			case 8:
				if(!L)
				{
					printf("��������\n");
					continue;
				}
				if(!(L->next))
				{
					printf("������ֵ\n");
					continue;
				}
				ans = ReverseList(&L);
				if(ans == 1)
				{
					printf("��ת�ɹ�\n");
				}else
				{
					printf("��תʧ��\n");
				}
				break;
			case 9:
				if(!L)
				{
					printf("��������\n");
					continue;
				}
				ans = IsLoopList(L);
				if(ans == 1)
				{
					printf("������ɻ�\n");
				}else
				{
					printf("����δ�ɻ�\n");
				}
				break;
			case 10:
				if(!L)
				{
					printf("��������\n");
					continue;
				}
				if(!(L->next))
				{
					printf("������ֵ\n");
					continue;
				}
				ReverseEvenList(&L);
				printf("��ת�ɹ�\n");
				break;
			case 11:
				if(!L)
				{
					printf("��������\n");
					continue;
				}
				if(!(L->next))
				{
					printf("������ֵ\n");
					continue;
				}
				b = FindMidNode(&L);
				printf("�е�ֵΪ%d",b->data);
				break;
		}
	}
	return 0;
}

LNode* creatNode(ElemType data){
	LNode* newNode = (LNode*)malloc(sizeof(LNode*));
	newNode->data  = data;
	newNode->next  = NULL;
	return newNode;
}

void help(){
	printf("\t*************************************************************************\n");
	printf("\t*|---------------------------------------------------------------------|*\n");
	printf("\t*|                                                                     |*\n");
	printf("\t*|                              LinkedList                             |*\n");
	printf("\t*|                                                                     |*\n");
	printf("\t*|                                                                     |*\n");
	printf("\t*|                               0. �˳�                               |*\n");
	printf("\t*|                               1. ����                               |*\n");
	printf("\t*|                            2 . ��������                             |*\n");
	printf("\t*|                            3 . �ͷ�����                             |*\n");
	printf("\t*|                       4 . ��ĳ�ڵ�ǰ������                        |*\n");
	printf("\t*|                            5 . ɾ�����                             |*\n");
	printf("\t*|                            6 . �������                             |*\n");
	printf("\t*|                            7 . �������                             |*\n");
	printf("\t*|                            8 . ��ת����                             |*\n");
	printf("\t*|                            9 . �жϻ���                             |*\n");
	printf("\t*|                           10 . ��ż��ת                             |*\n");
	printf("\t*|                           11 . Ѱ���е�                             |*\n");
	printf("\t*|                                                                     |*\n");
	printf("\t*|                                                                     |*\n");
	printf("\t*|                                                                     |*\n");
	printf("\t*|---------------------------------------------------------------------|*\n");
	printf("\t*************************************************************************\n");
}

int confirm(LinkedList L, int n){
	LinkedList p = L;
	for(int i = 0; i < n; i++)
	{
		if(!p->next){
			return 0;
		}
		p = p->next;
	}
	return 1;
}

LNode* numNode(LinkedList L,int n){
	LinkedList p = L;
	for(int i = 0; i < n; i++)
	{
		p = p->next;
	}
	return p;
}

void visit(ElemType e){
	printf("%d\t",e);
	return;
}
