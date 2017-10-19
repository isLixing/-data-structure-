#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#include "math.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int QElemType;
typedef int Status;
typedef struct QNode{
	QElemType data;
	struct QNode *next;
}QNode;
typedef  struct QNode *QuerePtr;

typedef struct {
	QuerePtr front;//队头指针  
	QuerePtr rear;//队尾指针 
}LinkQuere;

//初始化队列
Status InitQuere(LinkQuere &Q) {
	Q.rear=Q.front=(QuerePtr)malloc(sizeof(QNode));
	if(!Q.rear) return ERROR;//存储空间分配失败
	Q.front->next=NULL;
	return OK; 
}

//插入元素e为新的队尾元素
Status InsertQuere(LinkQuere &Q,QElemType e){
	QuerePtr p;
	p=(QuerePtr)malloc(sizeof(QNode));
	if(!p) return ERROR;
	p->data=e;
	p->next=NULL;

	Q.rear->next=p;
	Q.rear=p;
	return OK; 
} 
//删除队头元素e 
Status DeleteQuere(LinkQuere &Q,QElemType &e){
	if(Q.front==Q.rear) return ERROR;//队列空 
	QuerePtr p;
	p=Q.front->next;
	e=p->data; 
	Q.front->next=p->next;
	if(Q.rear==p) Q.rear=Q.front;
	free(p);
	return OK;
}
//输出单个元素
Status visit(QElemType e){
	printf("%d  ",e);
	return OK;
} 

//遍历队列 ，打印队列数据 
Status QuereTraverse(LinkQuere Q){
	QuerePtr f=Q.front->next;//队头 
	if(Q.front==Q.rear) return ERROR;
	while(f){
		int e=f->data;
		visit(e);
		f=f->next;
	}
	printf("\n");
	return OK;
}

//销毁队列
Status destroyQuere(LinkQuere &Q){
	while(Q.front){
		Q.rear=Q.front->next;
		free(Q.front);
		Q.front=Q.rear;
	}
	return OK;
} 
//清空队列
Status ClearQuere(LinkQuere &Q) {
	QuerePtr p,q;
	Q.rear=Q.front;
	p=Q.front->next;//留下头结点 
	Q.front->next=NULL;//
	while(p){
		q=p;
		p=p->next;
		free(q);
	}	
	return OK;
}
//获取队头元素
Status getTop(LinkQuere Q,QElemType &e) {
	e=Q.front->next->data;
	return OK;
}

int main(){
	LinkQuere q;
	QElemType e;
	InitQuere(q); 
	int n;
	printf("选择要入队的个数：");
	scanf("%d",&n);
	while(n--){
		int m;
		scanf("%d",&m);
		InsertQuere(q,m);
	}
	printf("初始化栈后：");
	QuereTraverse(q);
	
	DeleteQuere(q,e);
	printf("队头出队后："); 
	if(q.front==q.rear){
		printf("队列为空"); 
	}else{
		QuereTraverse(q); 
	}
	
	getTop(q,e);
	printf("获取队头元素：%d\n",e);
} 
