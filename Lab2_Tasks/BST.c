#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* CreateNewnode(int value){
    struct node * newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node* Insert(struct node* root,int value){
    if(root==NULL){
        return CreateNewnode(value);
    }
    if(value<root->data){
        root->left=Insert(root->left,value);
    }
    else if(value>root->data){
        root->right=Insert(root->right,value);
    }
    return root;
}
struct node* FindMin(struct node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
struct node* DeleteNode(struct node* root,int key){
    if(root==NULL){
        return root;
    }

if(key<root->data){
    root->left=DeleteNode(root->left,key);
}
else if(key>root->data){
    root->right=DeleteNode(root->right,key);
}
else{
    //0 chils case deletion
    if(root->left==NULL && root->right==NULL){ 
        free(root);
        return NULL;
    }
    // one child case deletion
    if(root->left==NULL){ 
        struct node* temp =root->right;
        free(root);
        return temp;
    }
    else if(root->right==NULL){
        struct node* temp=root->left;
        free(root);
        return temp;
    }
    //two child case deletion
    struct node*temp=FindMin(root->right);
    root->data=temp->data;
    root->right=DeleteNode(root->right,temp->data);
}  
    return root;
}
void inorder(struct node* root){
    if(root!=NULL){
       inorder(root->left);
       printf(" %d",root->data);
       inorder(root->right);
    }
}
int main(){
    struct node* root=NULL;
    root=Insert(root,60);
    root=Insert(root,25);
    root=Insert(root,75);
    root=Insert(root,35);
    root=Insert(root,95);
    root=Insert(root,15);
    root=Insert(root,65);
    printf("Inorder traversal:");
    inorder(root);
    root=DeleteNode(root,60);
    root=DeleteNode(root,35);
    root=DeleteNode(root,95);
    printf("\nAfter deleting 60 35 95 elements:");
    inorder(root);
    return 0;
}