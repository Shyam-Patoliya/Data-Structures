#include <stdio.h>
#include <stdlib.h>

struct bt{
    int data;
    struct bt *left;
    struct bt *right;
};

struct bt *create(){
    struct bt *newnode = malloc(sizeof(struct bt));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
void insert(struct bt *root,struct bt *node){
    if(root==NULL){
        root=node;
    }
    else{
        if(node->data < root->data){
            if(root->left!=NULL){
                insert(root->left,node);
            }
            else{
                root->left = node;
            }
        }
        if(node->data > root->data){
            if(root->right!=NULL){
                insert(root->right,node);
            }
            else{
                root->right=node;
            }
        }
    }
}

void preorder(struct bt *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct bt *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void postorder(struct bt *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
void main(){
    int num;
    struct bt *root=NULL,*node,*current;
    printf("Enter the number of nodes you want: ");
    scanf("%d",&num);
    printf("Enter the nodes data: \n");
    while(num!=0){
        node=create();
        if(root==NULL){
            root=node;
        }
        else{
            insert(root,node);
        }
        num--;
    }
    printf("\nPreorder traversal: ");
    preorder(root);

    printf("\nInorder traversal: ");
    inorder(root);

    printf("\nPostorder traversal: ");
    postorder(root);

    printf("\n");
}
