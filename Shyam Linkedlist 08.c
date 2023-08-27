#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
struct node *head=NULL;
struct node *next=NULL;

void insertatbegin(int data){
	struct node *lk=(struct node*)malloc(sizeof(struct node));
	lk->data=data;
	lk->next=head;
	head=lk;
}
void insertatend(int data){
	struct node *lk=(struct node*)malloc(sizeof(struct node));
	lk->data=data;
	struct node *linklist=head;
	while(linklist->next !=NULL){
		linklist=linklist->next;
	
	}
	linklist->next=lk;
}
void printlist(){
	struct node *p=head;
	printf("\n[");
	
	while(p!= NULL){
		printf("%d ",p->data);
		printf("%d ",&p->data);
		p=p->next;
	}
	printf("]");
}

void main(){
	int k=0;
	insertatbegin(10);
	insertatend(12);
	insertatend(22);
	insertatend(30);
	insertatend(44);
	insertatend(50);
	printf("linked list:");
	printlist();
}





