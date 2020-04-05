#include "../head/SqStack.h"
#include <stdio.h>
#include <stdlib.h>




//���������˳��ջ
//��ʼ��ջ
Status initStack(SqStack *s,int sizes){
	s->elem = (ElemType*)malloc(sizes * sizeof(ElemType));
	if (!(s->elem))
	{
		return ERROR;
	}
	s->top = -1;
	s->size = sizes;
	return SUCCESS;
}
//�ж�ջ�Ƿ�Ϊ��
Status isEmptyStack(SqStack *s){
	if(s->top == -1){
		return SUCCESS;
	}
	return ERROR;

}
//�õ�ջ��Ԫ��
Status getTopStack(SqStack *s,ElemType *e){
	if(s->top == -1){
		return ERROR;
	}
	*e = (s->elem)[s->top];
	if(*e != (s->elem)[s->top]){
		return ERROR;
	}
	return SUCCESS;

}
//���ջ
Status clearStack(SqStack *s){
	if(!s)
	{
		return ERROR;
	}
	s->top = -1;
	return SUCCESS;

}
//����ջ
Status destroyStack(SqStack *s){
	if(!s)
	{
		return ERROR;
	}
	free(s->elem);
	return SUCCESS;
}
//���ջ����
Status stackLength(SqStack *s,int *length){
	if(!s){
		return ERROR;
	}
	*length = (s->top)+1;
	return SUCCESS;
}
//��ջ
Status pushStack(SqStack *s,ElemType data){
	if(!s || ((s->top) == ((s->size)-1)))
	{
		return ERROR;
	}
	s->top ++;
	s->elem[s->top] = data;
	return SUCCESS;
}
//��ջ
Status popStack(SqStack *s,ElemType *data){
	if(isEmptyStack(s)){
		return ERROR;
	}
	*data = (s->elem)[s->top];
	s->top--;
	return SUCCESS;
}
