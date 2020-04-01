#include "duLinkedList.c"
#include <stdio.h>

void help();
DuLNode* creatDuLNode(ElemType data);
DuLNode* numNode(DuLinkedList L,int n);
int confirm(DuLinkedList L, int n);
void visit(ElemType e);


int main(void){
	DuLinkedList L;
	DuLNode a, *b;
	ElemType  E;
	int num;
	help();
	InitList_DuL(&L);
	DestroyList_DuL(&L);
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
					break;
				}
				ans = InitList_DuL(&L);
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
					DestroyList_DuL(&L);
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
				if(num < 0){
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
					ans = InsertBeforeList_DuL(b, creatDuLNode(thisdata));
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
				if(!(L->next)){
					num--;
				}
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
					ans = InsertAfterList_DuL(b, creatDuLNode(thisdata));
					if(ans == 1)
					{
						printf("����ɹ�\n");
					}else
					{
						printf("�������\n");
					}
				}
				break;
			case 6:
				if(!L)
				{
					printf("��������\n");
					continue;
				}
				if(!(L->next)){
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
				ans = DeleteList_DuL(b,&E);
				if(ans == 1){
					printf("�ýڵ�ֵΪ%d��ɾ���ɹ�\n",E);
				}else{
					printf("ɾ��ʧ��\n");
				}
				break;
			case 7:
				if(!L)
				{
					printf("��������\n");
				}else
				{
					TraverseList_DuL(L,visit);
					printf("�����ɹ�\n");
				}
				break;
		}
	}
	return 0;
}

void visit(ElemType e){
	printf("%d\t",e);
	return;
}

DuLNode* creatDuLNode(ElemType data){
	DuLNode* newNode = (DuLNode*)malloc(sizeof(DuLNode*));
	newNode->data = data;
        newNode->prior = NULL;
        newNode->next = NULL;
        return newNode;
}

void help(){
	printf("\t*******************************************************\n");
	printf("\t*|---------------------------------------------------|*\n");
	printf("\t*|                                                   |*\n");
	printf("\t*|                    DuLinkedList                   |*\n");
	printf("\t*|                                                   |*\n");
	printf("\t*|                                                   |*\n");
	printf("\t*|                      0. �˳�                      |*\n");
	printf("\t*|                      1. ����                      |*\n");
	printf("\t*|                   2 . ��������                    |*\n");
	printf("\t*|                   3 . �ͷ�����                    |*\n");
	printf("\t*|              4 . ��ĳ�ڵ�ǰ������               |*\n");
	printf("\t*|              5 . ��ĳ�ڵ�������               |*\n");
	printf("\t*|                   6 . ɾ�����                    |*\n");
	printf("\t*|                   7 . �������                    |*\n");
	printf("\t*|                                                   |*\n");
	printf("\t*|---------------------------------------------------|*\n");
	printf("\t*******************************************************\n");
	return;
}

int confirm(DuLinkedList L, int n){
	DuLinkedList p = L;
	for(int i = 0; i < n; i++)
	{
		if(!p->next){
			return 0;
		}
		p = p->next;
	}
	return 1;
}

DuLNode* numNode(DuLinkedList L,int n){
	DuLinkedList p = L;
	for(int i = 0; i < n; i++)
	{
		p = p->next;
	}
	return p;
}


