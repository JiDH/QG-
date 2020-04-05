#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//结果判断
typedef enum Status {
	ERROR = 0, SUCCESS = 1
} Status;

//操作符栈结点
typedef  struct StackNode {
	char data;
	struct StackNode *next;
} StackNode, *LinkStackPtr;

//操作符栈
typedef  struct  LinkStack {
	LinkStackPtr top;
	int	count;
} LinkStack;

//数值栈
typedef struct SqStack {
	float *elem;
	int top;
} SqStack;

//输入中缀表达式
void getit(char *a) {
	printf("输入：\n>");
	gets(a);
}

//操作符栈初始化
Status initLStack(LinkStack *s) {
	s->count=-1;
	s->top=NULL;
	return SUCCESS;
}

//操作符入栈
Status pushLStack(LinkStack *s,char data) {
	LinkStackPtr nod=(LinkStackPtr)malloc(sizeof(StackNode));
	nod->next=s->top;
	nod->data=data;
	s->top=nod;
	s->count++;
	return SUCCESS;
}

//操作符出栈
Status popLStack(LinkStack *s,char *data) {
	if(!s->top)return ERROR;
	LinkStackPtr poi=s->top;
	*data=s->top->data;
	s->top=s->top->next;
	free(poi);
	s->count--;
	return SUCCESS;
}

//得到操作符栈顶元素
Status getTopLStack(LinkStack *s,char *e) {
	if(!s->top)return ERROR;
	*e=s->top->data;
	return SUCCESS;
}

//判断操作符栈是否为空
Status isEmptyLStack(LinkStack *s) {
	if(!s->top)
	return SUCCESS;
	return ERROR;
}

//中缀表达式转换成后缀表达式
int change(char *a,char *b) {
 	LinkStack im;
 	initLStack(&im);   //操作符栈初始化
	char head;
	char ch;
	char e;
	int i=0,j=0;
	ch=a[i];head=a[i];
	i++;
	while(ch!='\0'){
		switch(ch)
		{
			case '(':
				pushLStack(&im,ch);  //入栈
				break;
			case ')':
				while(getTopLStack(&im,&e)&&e!='(')//一直弹出直到遇到左括号
				{
					popLStack(&im,&e);
					b[j]=e;
					j++;
				}
				popLStack(&im,&e);   //左括号弹出，但不加入表达式
				break;
			case '+':
				if(!isEmptyLStack(&im)&&getTopLStack(&im,&e)&&e!='(')
				{

					popLStack(&im,&e);       //弹出栈顶
					b[j]=e;j++;

				}
				pushLStack(&im,ch);  //当前运算符入栈
				break;
			case '-':
				if(head=='-'){      //第一个为负数
					b[j]='0';
					j++;
					b[j]=' ';
					j++;

				}
				else if(!isEmptyLStack(&im)&&getTopLStack(&im,&e)&&e!='(')
				{
					popLStack(&im,&e);       //弹出栈顶
					b[j]=e;j++;
				}
				else if(!isEmptyLStack(&im)&&getTopLStack(&im,&e)&&e=='('){  //负数
					b[j]='0';
					j++;
					b[j]=' ';
					j++;
				}
				pushLStack(&im,ch);  //当前运算符入栈
				break;
			case '*':
			case '/':
				if(!isEmptyLStack(&im)&&getTopLStack(&im,&e)&&e=='*'||e=='/')
				{
					popLStack(&im,&e);
					b[j]=e;
					j++;
				}
				pushLStack(&im,ch);
				break;
			case ' ':
				break;
			default :
				if(ch>='0'&&ch<='9'||ch=='.')
				{
				while(ch>='0'&&ch<='9'||ch=='.')     //数字直接累加
				{
					b[j]=ch;
					j++;
					ch=a[i];
					i++;
				}
				b[j]=' ';
				i--;
				j++;}
				else {
					printf("输入格式错误\n");
					return 0;
				}
		}
		ch=a[i];
		i++;
	}
	while(!isEmptyLStack(&im)){    //弹出栈内剩余的操作符
		popLStack(&im,&e);
		b[j]=e;
		j++;
	}
	b[j]='\0';
	return 1;
}

//初始化数值栈
Status initStack(SqStack *s,int sizes) {
	s->elem=(float*)malloc(sizes*sizeof(float));
	if(!s->elem)return ERROR;
	s->top=-1;
	return SUCCESS;
}

//判断数值栈是否为空
Status isEmptyStack(SqStack *s) {
	if(s->top==-1)return SUCCESS;
	return ERROR;
}

//数值入栈
Status pushStack(SqStack *s,float data) {
	s->top++;
	s->elem[s->top]=data;
	return SUCCESS;
}

//数值出栈
Status popStack(SqStack *s,float *data) {
	if(s->top==-1)
	{
		printf("空栈\n");
		return ERROR;
	}
	*data=s->elem[s->top];
	s->top-=1;
	return SUCCESS;
}

//后缀表达式计算
float caculate(char *arr) {
 	int i=0,j;
 	SqStack ym;
 	float x1,x2,result,value;
 	initStack(&ym,100);
 	while(arr[i]){
 		if(arr[i]!=' '&&arr[i]<='9'&&arr[i]>='0')//   该字符是数字
 		{
 			value=0;
			while(arr[i]!=' ')
 			{
 				if(arr[i]=='.'){            //小数部分计算
				 j=i;i++;
				 while(arr[i]!=' '){
 					value=(value+(arr[i]-'0')/pow(10,i-j));
 					i++;}
				 }
				else
				  {
				value=value*10+arr[i]-'0';   //还原数字
 				i++;}
			}
			pushStack(&ym,value);       //得到的结果入栈
		}
		else
		{
		 	switch (arr[i])           //计算结果
		 	{
		 		case '+':
		 			popStack(&ym,&x1);
		 			popStack(&ym,&x2);
		 			result=x1+x2;
					pushStack(&ym,result);
		 			break;
		 		case '-':
		 			popStack(&ym,&x1);
		 			popStack(&ym,&x2);
		 			result=x2-x1;
		 			pushStack(&ym,result);
		 			break;
		 		case '*':
		 			popStack(&ym,&x1);
		 			popStack(&ym,&x2);
		 			result=x2*x1;
		 			pushStack(&ym,result);
		 			break;
		 		case '/':
		 			popStack(&ym,&x1);
		 			popStack(&ym,&x2);
		 			result=x2/x1;
		 			pushStack(&ym,result);
		 			break;
			}
			i++;
		}
	}
	if(ym.top<=0)
	{
	 	popStack(&ym,&result);
	 	if(isEmptyStack(&ym)){
	 		return result;
		 }
		else {
			printf("表达式错误");
			return 0;
		}
	}
	return 0;
 }

 int main()
 {
 	printf("**********************************************************************************************\n");
 	char cal[100],cal2[100];
 	float final;
 	LinkStack im;
 	initLStack(&im);   //用来存储运算符的栈
 	while(1){
		getit(cal);                 //输入表达式
		int con = change(cal,cal2);            //转换成后缀表达式
		if(!con){
			continue;			//错误跳过
		}
		printf("后缀表达式为:%s\n",cal2);            //查看后缀表达式
		final=caculate(cal2);         //后缀表达式求值
		printf("结果是: %f\n",final);
		printf("**********************************************************************************************\n");
 	}
	printf("输入任意键退出");
	getchar();
	return 0;
 }
