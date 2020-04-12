#include "../head/LQueue.h"
#include <stdio.h>

void InitLQueue(LQueue *Q)
{
	Node *p;
	//分配头结点
	p = (Node *)malloc(sizeof(Node));
	//指针域初始化
	p->next = NULL;
	Q->front = Q->rear = p;
	Q->length = 0;
	//重置类型数组下标
	type = 0;
}

void DestoryLQueue(LQueue *Q)
{
	//清空队列
	ClearLQueue(Q);
	//释放头节点
	free(Q->front);
	//全部归空
	Q->front = Q->rear = NULL;
	Q->length = 0;
	//重置类型数组下标
	type = 0;
}

Status IsEmptyLQueue(const LQueue *Q)
{
	//长度0则为空
	if (Q->length == 0)
	{
		return TRUE;
	}
	return FALSE;
}

Status GetHeadLQueue(LQueue *Q, void *e)
{
	if (Q->length == 0)
	{
		return FALSE;
	}
	//将值覆写给e
	memcpy(e, Q->front->next->data, 100); 
	return TRUE;
}

int LengthLQueue(LQueue *Q)
{
	return Q->length;
}

Status EnLQueue(LQueue *Q, void *data)
{	
	//建立临时结点
	Node *p;
	//分配内存
	p = (Node *)malloc(sizeof(Node));
	p->data = (void *)malloc(100);
	//数据覆写
	memcpy(p->data, data, 100);
	//连接到链表尾
	Q->rear->next = p;
	//链表尾指针后移
	Q->rear = p;
	p->next = NULL;
	//长度增加
	Q->length++;
	return TRUE;
}

Status DeLQueue(LQueue *Q) 
{
	//判断空队
	if (Q->length == 0)
	{
		return FALSE;
	}

	if (NULL == Q->front->next->next)
	{
		Q->rear = Q->front;
	}
	//建立临时节点
	Node *p;
	//临时节点赋值
	p = Q->front->next;
	//连接
	Q->front->next = p->next;
	//释放结点
	free(p);
	//长度-1
	Q->length--;
	type++; 
	return TRUE;
}

void ClearLQueue(LQueue *Q)
{
	//建立临时结点
	Node *p;
	//首指针下一位不为空
	while (NULL != Q->front->next)
	{
		//将下一位临时赋给p
		p = Q->front->next;
		//连接
		Q->front->next = p->next;
		//释放
		free(p);
	}
	//指针回头，所有属性重置
	Q->rear = Q->front;
	Q->length = 0;
	type = 0; 
}

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q, int i))
{
	//判断是否为空
	if (Q->length == 0)
	{
		return FALSE;
	}
	Node *p;
	p = Q->front->next;
	//遍历
	for (int i = 0; i < Q->length; i++)
	{
		foo(p->data, type + i);
		p = p->next;
	}
	return TRUE;
}

void LPrint(void *q, int i) 
{
	//类型判断
	if (datatype[i] == 1)
	{
		printf("%c\t", *(char *)q);
	}
	else if (datatype[i] == 4)
	{
		printf("%d\t", *(int *)q);
	}
	else if (datatype[i] == 8)
	{
		printf("%lf\t", *(double *)q);
	}
	else if (datatype[i] == -1)
	{
		printf("%s\t", (char *)q);
	}
}