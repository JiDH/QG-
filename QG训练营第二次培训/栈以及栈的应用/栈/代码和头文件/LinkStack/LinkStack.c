#include "../head/LinkStack.h"
#include <stdio.h>
#include <stdlib.h>

//Á´Õ»

//³õÊ¼»¯Õ»
Status initLStack(LinkStack *s){
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!s->top)
	{
		return ERROR;
	}
	s->count = 0;
	return SUCCESS;
}
//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
Status isEmptyLStack(LinkStack *s){
	if(s->count == 0){
		return SUCCESS;
	}
	return ERROR;

}
//µÃµ½Õ»¶¥ÔªËØ
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
//Çå¿ÕÕ»
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
//Ïú»ÙÕ»
Status destroyLStack(LinkStack *s){
	if(!(s->top))
	{
		return ERROR;
	}
	clearLStack(s);
	free(s->top);
	return SUCCESS;
}
//¼ì²âÕ»³¤¶È
Status LStackLength(LinkStack *s,int *length){
	if(!s)
	{
		return ERROR;
	}
	*length = s->count;
	return SUCCESS;
}
//ÈëÕ»
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
//³öÕ»
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


