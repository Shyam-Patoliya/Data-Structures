#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *next; 
};

struct node *head= NULL;
void printlist(){
    struct node *temp=head;
    printf("\n[ ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("]\n");
}
void insertatbegin(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=head;
    head=newnode;
}
void insertatend(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next=NULL;
    struct node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}
void insertafter(int pos,int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    struct node *temp = head;
    while(temp->data!=pos){
        if(temp->next==NULL){
            printf("\nElement position for insertion not found!");
            return;
        }
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
void deleteatbegin(){
    struct node *temp = head;
    head=head->next;
    free(temp);
}
void deleteatend(){
    struct node *temp = head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    struct node *loc = temp->next;
    temp->next=NULL;
    free(loc);
}
void deletenode(int data){
    struct node *temp=head,*prev;

    if(temp!=NULL && temp->data==data){
        head=head->next;
        free(temp);
        return;
    }
    while(temp!=NULL && temp->data!=data){
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    free(temp);
}
void search(int data){
    struct node *temp=head;
    int count=0; //starting counting from 0
     while(temp!=NULL){
        temp=temp->next;
        count++;
        if(temp!=NULL && temp->data==data){
            printf("\nElement found at %d position",count);
            return;
        }
    }
    printf("\nElement not found!\n");   
}
void sort(){
    struct node *p=head,*q;
    int temp;
    while(p->next!=NULL){
        q=p->next;
        while(q!=NULL){
            if(p->data > q->data){
                temp = p->data;
                p->data=q->data;
                q->data = temp;
            }
            q=q->next;
        }
        p=p->next;
    }

}   
void reverse(){
    struct node *temp=NULL,*temp1;
    while(head!=NULL){
        temp1=head;
        head=head->next;
        temp1->next=temp;
        temp=temp1;
    }
    head=temp1;
}
void concatenate(struct node *ptr, struct node *ptr1){
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=ptr1;
}
struct node *intersection(struct node *ptr, struct node *ptr1) {
    struct node *result = NULL; 
    struct node *p = ptr; 
    while (p != NULL) {
        struct node *q = ptr1;
        while (q != NULL) {
            if (p->data == q->data) {
                struct node *newNode = (struct node *)malloc(sizeof(struct node));
                newNode->data = p->data;
                newNode->next = result;
                result = newNode;
                break; 
            }
            q = q->next;
        }
        p = p->next;
    }
    return result; 
}


int main(){
    insertatbegin(55);
    insertatend(56);
    insertatend(57);
    insertatbegin(54);
    insertafter(57,78);
    insertatend(64);
    printlist();
    sort();
    printlist();
    reverse();
    printlist();
    struct node *head1 = NULL;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = 55;
    newnode->next=head1;
    head1=newnode;
    struct node *newnode1 = (struct node*)malloc(sizeof(struct node));
    newnode1->data = 56;
    newnode1->next=head1;
    head1=newnode1;
    head = intersection(head,head1);
    printlist();
    return 0;
}
