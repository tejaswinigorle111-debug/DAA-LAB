
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node{
    char ch;
    int freq;
    Node *left,*right;
    Node(char c,int f){
        ch=c;
        freq=f;
        left=right=NULL;
    }
    struct compare{
        bool operator()(Node* a,Node* b){
            return a->freq>b->freq;
        }
    };
};
void printthecode(Node* root,string code){
        if(root==NULL){
            return;
        }
        if(root->left==NULL&&root->right==NULL){
            cout<<root->ch<<"-"<<code<<endl;
            return;
        }
    
        printthecode(root->left,code+"0");
        printthecode(root->right,code+"1");
}

int main(){
    int n;
    cout<<"enter the no.of chars:";
    cin>>n;
    char ch[50];
    int freq[50];
    for(int i=0;i<n;i++){
        cout<<"enter the character and its frequency:";
        cin>>ch[i]>>freq[i];
    }
    priority_queue<Node*,vector<Node*>,Node::compare> minq;
    for(int i=0;i<n;i++){
        Node* newNode=new Node(ch[i],freq[i]);
        minq.push(newNode);
    }
    while(minq.size()>1){
        Node* left=minq.top();
        minq.pop();
        Node* right=minq.top();
        minq.pop();
        Node* parent=new Node('\0',left->freq+right->freq);
        parent->left=left;
        parent->right=right;
        minq.push(parent);
    }
    printthecode(minq.top(), "");
    
}















