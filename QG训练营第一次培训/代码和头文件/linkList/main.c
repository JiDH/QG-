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
					continue;
				}
				ans = InitList(&L);
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
					DestroyList(&L);
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

				printf("输入待插入结点值：\n");
				ans = scanf("%d",&thisdata);
				if(ans != 1){
					printf("输入异常\n");
					while (getchar() != '\n');
					continue;
				}else
				{
					ans = InsertList(b, creatNode(thisdata));
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
				if(!(L->next))
				{
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
				ans = DeleteList(b,&E);
				if(ans == 1){
					printf("该节点值为%d，删除成功\n",E);
				}else{
					printf("删除失败\n");
				}
				break;
			case 6:
				if(!L)
				{
					printf("链表不存在\n");
				}else
				{
					TraverseList(L,visit);
					printf("遍历成功\n");
				}
				break;
			case 7:
				if(!L)
				{
					printf("链表不存在\n");
					continue;
				}
				printf("输入待搜索值：\n");
				ans = scanf("%d",&thisdata);
				if(ans != 1){
					printf("输入异常\n");
					while (getchar() != '\n');
					continue;
				}else
				{
					ans = SearchList(L,thisdata);
					if(ans == 1)
					{
						printf("搜索成功\n");
					}else
					{
						printf("未找到\n");
					}
				}
				break;
			case 8:
				if(!L)
				{
					printf("链表不存在\n");
					continue;
				}
				if(!(L->next))
				{
					printf("链表无值\n");
					continue;
				}
				ans = ReverseList(&L);
				if(ans == 1)
				{
					printf("反转成功\n");
				}else
				{
					printf("反转失败\n");
				}
				break;
			case 9:
				if(!L)
				{
					printf("链表不存在\n");
					continue;
				}
				ans = IsLoopList(L);
				if(ans == 1)
				{
					printf("该链表成环\n");
				}else
				{
					printf("链表未成环\n");
				}
				break;
			case 10:
				if(!L)
				{
					printf("链表不存在\n");
					continue;
				}
				if(!(L->next))
				{
					printf("链表无值\n");
					continue;
				}
				ReverseEvenList(&L);
				printf("反转成功\n");
				break;
			case 11:
				if(!L)
				{
					printf("链表不存在\n");
					continue;
				}
				if(!(L->next))
				{
					printf("链表无值\n");
					continue;
				}
				b = FindMidNode(&L);
				printf("中点值为%d",b->data);
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
	printf("\t*|                               0. 退出                               |*\n");
	printf("\t*|                               1. 帮助                               |*\n");
	printf("\t*|                            2 . 创建链表                             |*\n");
	printf("\t*|                            3 . 释放链表                             |*\n");
	printf("\t*|                       4 . 在某节点前插入结点                        |*\n");
	printf("\t*|                            5 . 删除结点                             |*\n");
	printf("\t*|                            6 . 遍历结点                             |*\n");
	printf("\t*|                            7 . 搜索结点                             |*\n");
	printf("\t*|                            8 . 反转链表                             |*\n");
	printf("\t*|                            9 . 判断环表                             |*\n");
	printf("\t*|                           10 . 奇偶调转                             |*\n");
	printf("\t*|                           11 . 寻找中点                             |*\n");
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
