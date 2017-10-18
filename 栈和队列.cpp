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
//���ջ
Status clearStack(Stack &S) {
	S.top= S.base;
	return OK;
}
//����ջ
Status Destroy(Stack &S){
	free(S.base);
	S.top=NULL;
	S.base=NULL;
	S.stacksize=0;
	return OK; 
} 
//�ж�ջ�Ƿ�Ϊ�ա�
Status StackEmpty(Stack S){
	if(S.top==S.base)//ջ�� 
		return FALSE;
	else 
		return TRUE;
} 
//��ʼ��һ����ջ 
Status InitStack(Stack &S)  {
	S.base=(sElemType*)malloc(maxSize*sizeof(sElemType));//����洢�ռ� 
	if(!S.base) return ERROR;
	S.top=S.base;//ջ��
	S.stacksize=maxSize;
	return OK; 
}

//��ȡջ��Ԫ��
Status getTop(Stack S,sElemType &e){
	if(S.base==S.top) return ERROR;//ջ��
	e =*(S.top-1);
	return OK;
} 
//������Ԫ��Ϊջ����
Status Push(Stack &S,sElemType e){
	if(S.top-S.base>=S.stacksize){
		S.base =(sElemType*)realloc(S.base,STACKINCREMENT*sizeof(sElemType)) ;
		if(!S.base) exit(OVERFLOW);//�洢����ʧ��
		S.top=S.stacksize+S.base;
		S.stacksize+=STACKINCREMENT; 
	} 
	*S.top++=e;
} 
//ɾ��ջ��Ԫ��
Status Pop(Stack &S,sElemType &e){
	if(S.top==S.base) return ERROR;//ջ��
//	e=*(S.top-1);
//	S.top--;
	e=*--S.top;
	return OK; 
} 
//�������Ԫ��
Status visit(sElemType e){
	printf("%d  ",e);
	return OK;
} 
//����ջ
Status StackTraverse(Stack S ) {
  sElemType *b=S.base;
  sElemType *t=S.top;
  if(b==t) return ERROR;
  while(t>b){//ջ��Ϊ�� 
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
	printf("ѡ��Ҫ��ջ�ĸ�����");
	scanf("%d",&n);
	while(n--){
		int m;
		scanf("%d",&m);
		Push(s,m);
	} 
	printf("��ʼ��ջ�� "); 
	StackTraverse(s);
	getTop(s,e);
	printf("ջ��Ϊ��%d\n",e);
	Pop(s,e);
	printf("��ջ��Ԫ����: %d\n",e);
	if(StackEmpty(s)==FALSE){
		printf("ջ�Ѿ�Ϊ��");
	}else{
		StackTraverse(s);
	}
	Destroy(s);	
} 

