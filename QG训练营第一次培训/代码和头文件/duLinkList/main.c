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
		printf("\n\n*****************************************************************************************\n\n请输入指令：");
		con = scanf("%d",&type);
		if(con != 1){
			printf("请输入\n");
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
					printf("链表已存在\n");
					break;
				}
				ans = InitList_DuL(&L);
				if(ans == 1)
				{
					printf("创建链表成功\n");
				}else
				{
					printf("创建错误\n");
				}
				break;
			case 3:
				if(!L)
				{
					printf("链表不存在\n");
				}else
				{
					DestroyList_DuL(&L);
					printf("释放成功\n");
				}
				break;
			case 4:
				if(!L)
				{
					printf("链表不存在\n");
					continue;
				}
				printf("输入结点序号：\n");
				ans = scanf("%d",&num);
				if(ans != 1){
					printf("输入异常\n");
					while (getchar() != '\n');
					continue;
				}
				if(num < 0){
					printf("请输入正数\n");
					continue;
				}
				num--;
				if(!confirm(L,num)){
					printf("链表长度不足\n");
					continue;
				}
				b = numNode(L,num);
				printf("输入待插入结点值：\n");
				ans = scanf("%d",&thisdata);
				if(ans != 1){
					printf("输入异常\n");
					while (getchar() != '\n');
					continue;
				}else
				{
					ans = InsertBeforeList_DuL(b, creatDuLNode(thisdata));
					if(ans == 1)
					{
						printf("插入成功\n");
					}else
					{
						printf("插入错误\n");
					}
				}
				break;
			case 5:
				if(!L)
				{
					printf("链表不存在\n");
					continue;
				}
				printf("输入结点序号：\n");
				ans = scanf("%d",&num);
				if(ans != 1){
					printf("输入异常\n");
					while (getchar() != '\n');
					continue;
				}
				if(num < 1){
					printf("请输入正数\n");
					continue;
				}
				if(!(L->next)){
					num--;
				}
				if(!confirm(L,num)){
					printf("链表长度不足\n");
					continue;
				}
				b = numNode(L,num);
				printf("输入待插入结点值：\n");
				ans = scanf("%d",&thisdata);
				if(ans != 1){
					printf("输入异常\n");
					while (getchar() != '\n');
					continue;
				}else
				{
					ans = InsertAfterList_DuL(b, creatDuLNode(thisdata));
					if(ans == 1)
					{
						printf("插入成功\n");
					}else
					{
						printf("插入错误\n");
					}
				}
				break;
			case 6:
				if(!L)
				{
					printf("链表不存在\n");
					continue;
				}
				if(!(L->next)){
					printf("链表无值\n");
					continue;
				}
				printf("输入序号：\n");
				ans = scanf("%d",&num);
				if(ans != 1){
					printf("输入异常\n");
					while (getchar() != '\n');
					continue;
				}
				if(num < 1){
					printf("请输入正数\n");
					continue;
				}
				num--;
				if(!confirm(L,num)){
					printf("链表长度不足\n");
					continue;
				}
				b = numNode(L,num);
				ans = DeleteList_DuL(b,&E);
				if(ans == 1){
					printf("该节点值为%d，删除成功\n",E);
				}else{
					printf("删除失败\n");
				}
				break;
			case 7:
				if(!L)
				{
					printf("链表不存在\n");
				}else
				{
					TraverseList_DuL(L,visit);
					printf("遍历成功\n");
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
	printf("\t*|                      0. 退出                      |*\n");
	printf("\t*|                      1. 帮助                      |*\n");
	printf("\t*|                   2 . 创建链表                    |*\n");
	printf("\t*|                   3 . 释放链表                    |*\n");
	printf("\t*|              4 . 在某节点前插入结点               |*\n");
	printf("\t*|              5 . 在某节点后插入结点               |*\n");
	printf("\t*|                   6 . 删除结点                    |*\n");
	printf("\t*|                   7 . 遍历结点                    |*\n");
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


