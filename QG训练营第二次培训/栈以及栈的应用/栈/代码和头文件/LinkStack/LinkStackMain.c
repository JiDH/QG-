#include "LinkStack.c"
#include <stdio.h>
#include <stdlib.h>


void help();


int main(void){
	LinkStack s;
	help();
	int flag = 0;
	while(1){
		int type, con, ans,length;
		ElemType thisdata;
		printf("\n\n*****************************************************************************************\n\n请输入指令：");
		con = scanf("%d",&type);
		if(con != 1){
			printf("请输入正确指令\n");
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
				if(flag)
				{
					printf("栈已初始化\n");
					continue;
				}
				ans = initLStack(&s);
				if(ans == 1)
				{
					printf("初始化成功\n");
					flag = 1;
				}else
				{
					printf("初始化错误\n");
				}
				break;
			case 3:
				if(!flag)
				{
					printf("栈未初始化\n");
					continue;
				}else
				{
					ans = isEmptyLStack(&s);
					if(ans == 1)
					{
						printf("栈为空\n");
					}else
					{
						printf("栈非空\n");
					}

				}
				break;
			case 4:
				if(!flag)
				{
					printf("栈未初始化\n");
					continue;
				}
				ans = getTopLStack(&s,&thisdata);
				if(ans == 1)
				{
					printf("读取成功，元素为：%d\n",thisdata);
				}else
				{
					printf("读取失败\n");
				}
				break;
			case 5:
				if(!flag)
				{
					printf("栈未初始化\n");
					continue;
				}
				ans = clearLStack(&s);
				if(ans == 1){
					printf("清空成功\n");
				}else{
					printf("清空失败\n");
				}
				break;
			case 6:
				if(!flag)
				{
					printf("栈未初始化\n");
					continue;
				}
				ans = destroyLStack(&s);
				if(ans == 1){
					printf("销毁成功\n");
					flag = 0;
				}else{
					printf("销毁失败\n");
				}
				break;
			case 7:
				if(!flag)
				{
					printf("栈未初始化\n");
					continue;
				}
				ans = LStackLength(&s,&length);
				if(ans == 1){
					printf("检测成功，栈长为：%d\n",length);
				}else{
					printf("检测失败\n");
				}
				break;
			case 8:
				if(!flag)
				{
					printf("栈未初始化\n");
					continue;
				}
				printf("请输入插入值：");
				con = scanf("%d",&thisdata);
				if(con != 1){
					printf("请输入正确值\n");
					while (getchar() != '\n');
					continue;
				}
				ans = pushLStack(&s,thisdata);
				if(ans == 1)
				{
					printf("入栈成功\n");
				}else
				{
					printf("入栈失败\n");
				}
				break;
			case 9:
				if(!flag)
				{
					printf("栈未初始化\n");
					continue;
				}
				ans = popLStack(&s,&thisdata);
				if(ans == 1)
				{
					printf("出栈成功，值为：%d\n",thisdata);
				}else
				{
					printf("出栈失败\n");
				}
				break;
			default:
				printf("请输入正确指令\n");
		}
	}
	return 0;
}


void help(){
	printf("\t\t\t**********************************\n");
	printf("\t\t\t*|------------------------------|*\n");
	printf("\t\t\t*|                              |*\n");
	printf("\t\t\t*|           LinkStack          |*\n");
	printf("\t\t\t*|                              |*\n");
	printf("\t\t\t*|                              |*\n");
	printf("\t\t\t*|           0 . 退出           |*\n");
	printf("\t\t\t*|           1 . 帮助           |*\n");
	printf("\t\t\t*|         2 . 初始化栈         |*\n");
	printf("\t\t\t*|      3 . 判断栈是否为空      |*\n");
	printf("\t\t\t*|       4 . 读取栈顶元素       |*\n");
	printf("\t\t\t*|          5 . 清空栈          |*\n");
	printf("\t\t\t*|          6 . 销毁栈          |*\n");
	printf("\t\t\t*|         7 . 检测栈长         |*\n");
	printf("\t\t\t*|           8 . 入栈           |*\n");
	printf("\t\t\t*|           9 . 出栈           |*\n");
	printf("\t\t\t*|                              |*\n");
	printf("\t\t\t*|------------------------------|*\n");
	printf("\t\t\t**********************************\n");
}

