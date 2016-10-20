#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"string.h"
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define STACK_INIT_SIZE 100
#define STACKINCREMENT  10
typedef int Status;
typedef struct{
	char *base;
	char *top;
	int stacksize;
}SqStack;
Status InitStack(SqStack *S){
	(*S).base=(char*)malloc(STACK_INIT_SIZE*sizeof(char));
	if(!(*S).base) exit(OVERFLOW);
	(*S).top=(*S).base;
	(*S).stacksize=STACK_INIT_SIZE;
	return OK;
}
Status Push(SqStack *S,char e){
	if((*S).top-(*S).base>=(*S).stacksize){
		(*S).base=(char*)realloc((*S).base,
			((*S).stacksize+STACKINCREMENT)*sizeof(char));
		if(!(*S).base)exit(OVERFLOW);
		(*S).top=(*S).base+(*S).stacksize;
		(*S).stacksize+=STACKINCREMENT;
	}
	*((*S).top)=e;
	printf("the top of S is %d\n",e);
	(*S).top++;
	return OK;
}
Status Pop(SqStack *S,char *e){
	printf("the top of S in push is %d\n",*((*S).top));
	if((*S).top==(*S).base) return ERROR;
	*e=*((*S).top-1);
	((*S).top)--;
	
	return OK;
}
Status StackEmpty(SqStack S){
	if(S.top==S.base) return TRUE;
	else return ERROR;
}
int main()
{
	int i;
	char l[100];
	SqStack S;
	InitStack(&S);
	scanf("%s",l);
	for(i=0;l[i]!='\0';i++)
	{
		char e1=l[i];
		char e2;
		printf("at first e2:%d",e2);
		if((e1=='(')||(e1=='[')||(e1=='{')){
		
			Push(&S,e1);
			printf("top:%d,base:%d",S.top,S.base);
		}
		else if((e1==')')||(e1==']')||(e1=='}'))
			if((Pop(&S,&e2)==ERROR)||(e1==')'&&e2!='(')||(e1==']'&&e2!='[')||(e1=='}'&&e2!='{')){
				printf("¿®∫≈≤ª∆•≈‰\n");
				printf("e2:%d",e2);
				return 0;
			}
	}
	if(StackEmpty(S))
		printf("¿®∫≈∆•≈‰£¨’Êµƒ∆•≈‰¡À\n");
	else printf("¿®∫≈≤ª∆•≈‰\n");
	return 0;
}
