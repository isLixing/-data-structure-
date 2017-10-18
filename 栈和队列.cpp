#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"
#include "math.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define maxSize 200
#define STACKINCREMENT 10

typedef int sElemType;
typedef int Status;

typedef struct Stack{
	sElemType data;
	sElemType  *top;
	sElemType  *base;
	int stacksize;
}Stack;
//清空栈
Status clearStack(Stack &S) {
	S.top= S.base;
	return OK;
}
//销毁栈
Status Destroy(Stack &S){
	free(S.base);
	S.top=NULL;
	S.base=NULL;
	S.stacksize=0;
	return OK; 
} 
//判断栈是否为空、
Status StackEmpty(Stack S){
	if(S.top==S.base)//栈空 
		return FALSE;
	else 
		return TRUE;
} 
//初始化一个空栈 
Status InitStack(Stack &S)  {
	S.base=(sElemType*)malloc(maxSize*sizeof(sElemType));//分配存储空间 
	if(!S.base) return ERROR;
	S.top=S.base;//栈空
	S.stacksize=maxSize;
	return OK; 
}

//获取栈顶元素
Status getTop(Stack S,sElemType &e){
	if(S.base==S.top) return ERROR;//栈空
	e =*(S.top-1);
	return OK;
} 
//插入新元素为栈顶、
Status Push(Stack &S,sElemType e){
	if(S.top-S.base>=S.stacksize){
		S.base =(sElemType*)realloc(S.base,STACKINCREMENT*sizeof(sElemType)) ;
		if(!S.base) exit(OVERFLOW);//存储分配失败
		S.top=S.stacksize+S.base;
		S.stacksize+=STACKINCREMENT; 
	} 
	*S.top++=e;
} 
//删除栈顶元素
Status Pop(Stack &S,sElemType &e){
	if(S.top==S.base) return ERROR;//栈空
//	e=*(S.top-1);
//	S.top--;
	e=*--S.top;
	return OK; 
} 
//输出单个元素
Status visit(sElemType e){
	printf("%d  ",e);
	return OK;
} 
//遍历栈
Status StackTraverse(Stack S ) {
  sElemType *b=S.base;
  sElemType *t=S.top;
  if(b==t) return ERROR;
  while(t>b){//栈不为空 
  	visit(*b);
	  b++;	 
  }
  printf("\n");
  return OK;
}

int main(){
	Stack s;
	sElemType e;
	InitStack(s);
	int n;
	printf("选择要进栈的个数：");
	scanf("%d",&n);
	while(n--){
		int m;
		scanf("%d",&m);
		Push(s,m);
	} 
	printf("初始化栈后： "); 
	StackTraverse(s);
	getTop(s,e);
	printf("栈顶为：%d\n",e);
	Pop(s,e);
	printf("出栈的元素是: %d\n",e);
	if(StackEmpty(s)==FALSE){
		printf("栈已经为空");
	}else{
		StackTraverse(s);
	}
	Destroy(s);	
} 

