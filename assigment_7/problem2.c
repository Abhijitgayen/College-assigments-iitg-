
#include<stdio.h>
#include<stdlib.h>
#define tal 10
struct Node {
	int key;
	struct Node *left;
	struct Node *right;
}; 

void printTree(struct Node *root, int space) 
{ 
 
    if (root == NULL) 
        return;  
    space +=tal; 
    printTree(root->left, space); 
    printf("\n");
	int i; 
    for ( i =tal; i < space; i++) 
        printf(" "); 
    printf("%d\n", root->key); 
  
    // Process left child 
    printTree(root->right, space); 
} 

// Wrapper over printTree() 
 

//creatn new node
struct Node* creat(int data){
	struct Node* new;
		new =(struct Node*)malloc(sizeof(struct Node));
		new->key =data;
		new->left =NULL;
		new->right = NULL;
		return new;
	
}
// Function for Insert Node in a BST
struct Node* Insert( struct Node *root,int key) {
	if(root == NULL) {
		 root=creat(key);
	}
	else {
	if(key < root->key)
		root->left = Insert(root->left,key);
	else 
		root->right = Insert(root->right,key);
		}
	return root;
}

int main() {
	
	int ba ;
	printf("how many key you want to add :");
	scanf("%d",&ba);
	int val;
	int i;
	struct Node* root = NULL;
	for (i=0;i<ba;i++){
		printf("enter the key:");
		scanf("%d",&val);	
		root = Insert(root,val);
	}
	 printTree(root, 0); 
}
