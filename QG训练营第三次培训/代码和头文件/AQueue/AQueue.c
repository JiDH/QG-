#include "../head/AQueue.h"
#include <stdio.h>

void InitAQueue(AQueue *Q)
{
	//遍历赋值
	for (int i = 0; i < MAXQUEUE; i++)
	{
		//分别分配空间，不知道类型，所以制定了足够大的空间
		Q->data[i] = (void *)malloc(100 * MAXQUEUE);
	}
	//长度，头指针，尾指针均为0
	Q->front = Q->rear = Q->length = 0;
}

void DestoryAQueue(AQueue *Q)
{
	//逐个释放
	for (int i = 0; i < MAXQUEUE; i++)
	{
		free(Q->data[i]);
	}
	//头指针、尾指针、长度归零
	Q->front = Q->rear = Q->length = 0;
}

Status IsFullAQueue(const AQueue *Q)
{
	//长度等于最大值
	if (Q->length == MAXQUEUE)
	{
		return TRUE;
	}
	return FALSE;
}

Status IsEmptyAQueue(const AQueue *Q)
{
	//长度为空
	if (Q->length == 0)
	{
		return TRUE;
	}
	return FALSE;
}

Status GetHeadAQueue(AQueue *Q, void *e)
{
	//长度为零则为空
	if (Q->length == 0)
	{
		return FALSE;
	}
	// 将Q->data[Q->front]复制到e地址
	memcpy(e, Q->data[Q->front], 100);
	return TRUE;
}

int LengthAQueue(AQueue *Q)
{
	return Q->length;
}

Status EnAQueue(AQueue *Q, void *data)
{
	//判断是否队列满
	if (Q->length == MAXQUEUE)
	{
		return FALSE;
	}
	//将data拷贝到数组对应地址
	memcpy(Q->data[Q->rear], data, 100);
	//循环队列
	Q->rear = (Q->rear + 1) % MAXQUEUE;
	//长度增加
	Q->length++;
	return TRUE;
}

Status DeAQueue(AQueue *Q)
{
	//判断是否队空
	if (Q->length == 0)
	{
		return FALSE;
	}
	//头指针后移
	Q->front = (Q->front + 1) % MAXQUEUE;
	//队长-1
	Q->length--;
	return TRUE;
}

void ClearAQueue(AQueue *Q)
{
	//指针，长度全归零
	Q->front = Q->rear = Q->length = 0;
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q, int i))
{
	//判断是否为空
	if (Q->length == 0)
	{
		return FALSE;
	}
	//遍历数组
	for (int i = 0; i < Q->length; i++)
	{
		foo(Q->data[(Q->front + i) % MAXQUEUE], (Q->front + i) % MAXQUEUE); 
	}
	return TRUE;
}

void APrint(void *q, int i)
{
	//判断类型
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