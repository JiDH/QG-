#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//����ж�
typedef enum Status {
	ERROR = 0, SUCCESS = 1
} Status;

//������ջ���
typedef  struct StackNode {
	char data;
	struct StackNode *next;
} StackNode, *LinkStackPtr;

//������ջ
typedef  struct  LinkStack {
	LinkStackPtr top;
	int	count;
} LinkStack;

//��ֵջ
typedef struct SqStack {
	float *elem;
	int top;
} SqStack;

//������׺���ʽ
void getit(char *a) {
	printf("���룺\n>");
	gets(a);
}

//������ջ��ʼ��
Status initLStack(LinkStack *s) {
	s->count=-1;
	s->top=NULL;
	return SUCCESS;
}

//��������ջ
Status pushLStack(LinkStack *s,char data) {
	LinkStackPtr nod=(LinkStackPtr)malloc(sizeof(StackNode));
	nod->next=s->top;
	nod->data=data;
	s->top=nod;
	s->count++;
	return SUCCESS;
}

//��������ջ
Status popLStack(LinkStack *s,char *data) {
	if(!s->top)return ERROR;
	LinkStackPtr poi=s->top;
	*data=s->top->data;
	s->top=s->top->next;
	free(poi);
	s->count--;
	return SUCCESS;
}

//�õ�������ջ��Ԫ��
Status getTopLStack(LinkStack *s,char *e) {
	if(!s->top)return ERROR;
	*e=s->top->data;
	return SUCCESS;
}

//�жϲ�����ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s) {
	if(!s->top)
	return SUCCESS;
	return ERROR;
}

//��׺���ʽת���ɺ�׺���ʽ
int change(char *a,char *b) {
 	LinkStack im;
 	initLStack(&im);   //������ջ��ʼ��
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
				pushLStack(&im,ch);  //��ջ
				break;
			case ')':
				while(getTopLStack(&im,&e)&&e!='(')//һֱ����ֱ������������
				{
					popLStack(&im,&e);
					b[j]=e;
					j++;
				}
				popLStack(&im,&e);   //�����ŵ���������������ʽ
				break;
			case '+':
				if(!isEmptyLStack(&im)&&getTopLStack(&im,&e)&&e!='(')
				{

					popLStack(&im,&e);       //����ջ��
					b[j]=e;j++;

				}
				pushLStack(&im,ch);  //��ǰ�������ջ
				break;
			case '-':
				if(head=='-'){      //��һ��Ϊ����
					b[j]='0';
					j++;
					b[j]=' ';
					j++;

				}
				else if(!isEmptyLStack(&im)&&getTopLStack(&im,&e)&&e!='(')
				{
					popLStack(&im,&e);       //����ջ��
					b[j]=e;j++;
				}
				else if(!isEmptyLStack(&im)&&getTopLStack(&im,&e)&&e=='('){  //����
					b[j]='0';
					j++;
					b[j]=' ';
					j++;
				}
				pushLStack(&im,ch);  //��ǰ�������ջ
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
				while(ch>='0'&&ch<='9'||ch=='.')     //����ֱ���ۼ�
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
					printf("�����ʽ����\n");
					return 0;
				}
		}
		ch=a[i];
		i++;
	}
	while(!isEmptyLStack(&im)){    //����ջ��ʣ��Ĳ�����
		popLStack(&im,&e);
		b[j]=e;
		j++;
	}
	b[j]='\0';
	return 1;
}

//��ʼ����ֵջ
Status initStack(SqStack *s,int sizes) {
	s->elem=(float*)malloc(sizes*sizeof(float));
	if(!s->elem)return ERROR;
	s->top=-1;
	return SUCCESS;
}

//�ж���ֵջ�Ƿ�Ϊ��
Status isEmptyStack(SqStack *s) {
	if(s->top==-1)return SUCCESS;
	return ERROR;
}

//��ֵ��ջ
Status pushStack(SqStack *s,float data) {
	s->top++;
	s->elem[s->top]=data;
	return SUCCESS;
}

//��ֵ��ջ
Status popStack(SqStack *s,float *data) {
	if(s->top==-1)
	{
		printf("��ջ\n");
		return ERROR;
	}
	*data=s->elem[s->top];
	s->top-=1;
	return SUCCESS;
}

//��׺���ʽ����
float caculate(char *arr) {
 	int i=0,j;
 	SqStack ym;
 	float x1,x2,result,value;
 	initStack(&ym,100);
 	while(arr[i]){
 		if(arr[i]!=' '&&arr[i]<='9'&&arr[i]>='0')//   ���ַ�������
 		{
 			value=0;
			while(arr[i]!=' ')
 			{
 				if(arr[i]=='.'){            //С�����ּ���
				 j=i;i++;
				 while(arr[i]!=' '){
 					value=(value+(arr[i]-'0')/pow(10,i-j));
 					i++;}
				 }
				else
				  {
				value=value*10+arr[i]-'0';   //��ԭ����
 				i++;}
			}
			pushStack(&ym,value);       //�õ��Ľ����ջ
		}
		else
		{
		 	switch (arr[i])           //������
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
			printf("���ʽ����");
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
 	initLStack(&im);   //�����洢�������ջ
 	while(1){
		getit(cal);                 //������ʽ
		int con = change(cal,cal2);            //ת���ɺ�׺���ʽ
		if(!con){
			continue;			//��������
		}
		printf("��׺���ʽΪ:%s\n",cal2);            //�鿴��׺���ʽ
		final=caculate(cal2);         //��׺���ʽ��ֵ
		printf("�����: %f\n",final);
		printf("**********************************************************************************************\n");
 	}
	printf("����������˳�");
	getchar();
	return 0;
 }
