#include "../head/SqStack.h"
#include <stdio.h>
#include <stdlib.h>




//基于数组的顺序栈
//初始化栈
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
//判断栈是否为空
Status isEmptyStack(SqStack *s){
	if(s->top == -1){
		return SUCCESS;
	}
	return ERROR;

}
//得到栈顶元素
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
//清空栈
Status clearStack(SqStack *s){
	if(!s)
	{
		return ERROR;
	}
	s->top = -1;
	return SUCCESS;

}
//销毁栈
Status destroyStack(SqStack *s){
	if(!s)
	{
		return ERROR;
	}
	free(s->elem);
	return SUCCESS;
}
//检测栈长度
Status stackLength(SqStack *s,int *length){
	if(!s){
		return ERROR;
	}
	*length = (s->top)+1;
	return SUCCESS;
}
//入栈
Status pushStack(SqStack *s,ElemType data){
	if(!s || ((s->top) == ((s->size)-1)))
	{
		return ERROR;
	}
	s->top ++;
	s->elem[s->top] = data;
	return SUCCESS;
}
//出栈
Status popStack(SqStack *s,ElemType *data){
	if(isEmptyStack(s)){
		return ERROR;
	}
	*data = (s->elem)[s->top];
	s->top--;
	return SUCCESS;
}
