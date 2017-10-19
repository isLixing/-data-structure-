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
	QuerePtr front;//��ͷָ��  
	QuerePtr rear;//��βָ�� 
}LinkQuere;

//��ʼ������
Status InitQuere(LinkQuere &Q) {
	Q.rear=Q.front=(QuerePtr)malloc(sizeof(QNode));
	if(!Q.rear) return ERROR;//�洢�ռ����ʧ��
	Q.front->next=NULL;
	return OK; 
}

//����Ԫ��eΪ�µĶ�βԪ��
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
//ɾ����ͷԪ��e 
Status DeleteQuere(LinkQuere &Q,QElemType &e){
	if(Q.front==Q.rear) return ERROR;//���п� 
	QuerePtr p;
	p=Q.front->next;
	e=p->data; 
	Q.front->next=p->next;
	if(Q.rear==p) Q.rear=Q.front;
	free(p);
	return OK;
}
//�������Ԫ��
Status visit(QElemType e){
	printf("%d  ",e);
	return OK;
} 

//�������� ����ӡ�������� 
Status QuereTraverse(LinkQuere Q){
	QuerePtr f=Q.front->next;//��ͷ 
	if(Q.front==Q.rear) return ERROR;
	while(f){
		int e=f->data;
		visit(e);
		f=f->next;
	}
	printf("\n");
	return OK;
}

//���ٶ���
Status destroyQuere(LinkQuere &Q){
	while(Q.front){
		Q.rear=Q.front->next;
		free(Q.front);
		Q.front=Q.rear;
	}
	return OK;
} 
//��ն���
Status ClearQuere(LinkQuere &Q) {
	QuerePtr p,q;
	Q.rear=Q.front;
	p=Q.front->next;//����ͷ��� 
	Q.front->next=NULL;//
	while(p){
		q=p;
		p=p->next;
		free(q);
	}	
	return OK;
}
//��ȡ��ͷԪ��
Status getTop(LinkQuere Q,QElemType &e) {
	e=Q.front->next->data;
	return OK;
}

int main(){
	LinkQuere q;
	QElemType e;
	InitQuere(q); 
	int n;
	printf("ѡ��Ҫ��ӵĸ�����");
	scanf("%d",&n);
	while(n--){
		int m;
		scanf("%d",&m);
		InsertQuere(q,m);
	}
	printf("��ʼ��ջ��");
	QuereTraverse(q);
	
	DeleteQuere(q,e);
	printf("��ͷ���Ӻ�"); 
	if(q.front==q.rear){
		printf("����Ϊ��"); 
	}else{
		QuereTraverse(q); 
	}
	
	getTop(q,e);
	printf("��ȡ��ͷԪ�أ�%d\n",e);
} 
