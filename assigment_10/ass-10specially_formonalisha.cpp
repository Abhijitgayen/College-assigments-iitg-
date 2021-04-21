#include<iostream>
#include<cstdio>
using namespace std;
typedef struct node {
    char key;
    node* left;
    node* right;
} node;

node* creatNode(char key)
{	
    node* temp = new node();
    temp->key = key;
    temp->left = NULL;
	temp->right = NULL;
    return temp;
}
int j;
void uncompress( string str,node *root)
{
    int i=0;
    node* temp = root;
    do{
        if(temp->right==NULL && temp->left == NULL){
            j++;

            printf("%c",temp->key);
            if(j % 76==0){
                printf("\n");
            }
            temp=root;
        }
        if(str[i]=='0'){
            temp=temp->left;
        }
        else if(str[i]=='1'){
            temp=temp->right;
        }
        i++;
    }while(str[i-1]!='\0');
}
int ix=0;
node *binaryTree(string v,int low,int high,int size)
{
     if(ix>size){
     	return NULL;
	 }
     node *head = creatNode(v[ix]);
     ix=ix+1;
     if(head->key!='*')
     {
     return head;
     }
     int i= low+1;
     while(v[i]=='*')
     i++;
     head->left = binaryTree(v,ix,i,size);
     head->right = binaryTree(v,i,high+1,size);
     return head;
}
void printTree(node* root, int space , int height)
{
    if (root == NULL) {
        return;
    }
    space += height;
    printTree(root->right,space,height);
    cout << endl;
    for (int i = height; i < space; i++) {
        cout << ' ';
    }
    cout << root->key;
    cout << endl;
    printTree(root->left,space,height);
}
int main()
{       
      string preO,comp;
      //printf("\nEnter  preorder traversal of the binary tree:");
      getline(cin,preO);
      node *head=binaryTree(preO,0,preO.size(),preO.size());
      //printf("\t The table is");
      //printTree(head,0 ,5);
      //printf("\nEnter the compressed message:");
      getline(cin,comp);
      printf("\n>>>>>The massege is:>>>>>\n\n");
      uncompress(comp,head);
      printf("\n");
    return 0;
}