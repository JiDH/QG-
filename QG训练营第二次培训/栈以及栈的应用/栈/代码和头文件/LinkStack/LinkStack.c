#include "../head/LinkStack.h"
#include <stdio.h>
#include <stdlib.h>

//��ջ

//��ʼ��ջ
Status initLStack(LinkStack *s){
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!s->top)
	{
		return ERROR;
	}
	s->count = 0;
	return SUCCESS;
}
//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s){
	if(s->count == 0){
		return SUCCESS;
	}
	return ERROR;

}
//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e){
	if(s->count == 0 || !(s->top)){
		return ERROR;
	}
	*e = s->top->next->data;
	if(*e != s->top->next->data){
		return ERROR;
	}
	return SUCCESS;

}
//���ջ
Status clearLStack(LinkStack *s){
	LinkStackPtr temp;
	if(!(s->top)){
		return ERROR;
	}
	while(s->count){
		LinkStackPtr temp = s->top->next;
		s->top->next = temp->next;
		free(temp);
		s->count --;
	}
	return SUCCESS;
}
//����ջ
Status destroyLStack(LinkStack *s){
	if(!(s->top))
	{
		return ERROR;
	}
	clearLStack(s);
	free(s->top);
	return SUCCESS;
}
//���ջ����
Status LStackLength(LinkStack *s,int *length){
	if(!s)
	{
		return ERROR;
	}
	*length = s->count;
	return SUCCESS;
}
//��ջ
Status pushLStack(LinkStack *s,ElemType data){
	StackNode *newNode;
	if(!(s->top))
	{
		return ERROR;
	}
	newNode = (StackNode*)malloc(sizeof(StackNode));
	newNode->data = data;
	newNode->next = s->top->next;
	s->top->next = newNode;
	s->count++;
	return SUCCESS;
}
//��ջ
Status popLStack(LinkStack *s,ElemType *data){
	if(isEmptyLStack(s)){
		return ERROR;
	}
	*data = s->top->next->data;
	LinkStackPtr temp = s->top->next;
	s->top->next = temp->next;
	free(temp);
	s->count --;
	return SUCCESS;
}


