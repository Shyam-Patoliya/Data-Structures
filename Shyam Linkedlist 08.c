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

void insertafternode(struct node *list, int data){
   struct node *lk = (struct node*) malloc(sizeof(struct node));
   lk->data = data;
   lk->next = list->next;
   list->next = lk;
}

void deleteatbegin(){
     head=head->next;
}

void deleteatend(){
     struct node *linkedlist=head;
     while(linkedlist->next->next!=NULL)
         linkedlist=linkedlist->next;
     linkedlist->next=NULL;
}

void deletenode(int key){
   struct node *temp = head, *prev;
   if (temp != NULL && temp->data == key) {
      head = temp->next;
      return;
   }

   while (temp != NULL && temp->data != key) {
      prev = temp;
      temp = temp->next;
   }

   if (temp == NULL) return;

   prev->next = temp->next;
}

int searchlist(int key){
   struct node *temp = head;
   while(temp != NULL) {
      if (temp->data == key) {
         return 1;
      }
      temp=temp->next;
   }
   return 0;
}

void printlist(){
	struct node *p=head;
	printf("\n[");
	
	while(p!= NULL){
		printf("%d ",p->data);
		//printf("%d ",&p->data);
		p=p->next;
	}
	printf("]");
}

void main(){
	int k=0;
	insertatbegin(10);
	insertatbegin(12);
	insertatend(22);
	insertatend(30);
	insertatend(44);
	insertatend(50);
	insertafternode(head->next->next, 33);
	printf("linked list:");
	printlist();
        deleteatbegin();
        deleteatend();
        deletenode(33);
        printf("\nLinked List after deletion: ");
        printlist();
        k = searchlist(44);
       if (k == 1)
          printf("\nElement found");
       else
          printf("\nElement is not present in the list");
}





