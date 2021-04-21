#include<stdio.h>
#include<stdlib.h>
struct twoThreeNode{
	int d1,d2; // Two data fields

    // The three child nodes
    struct twoThreeNode *first, *second, *third;

    // This next one is quite useful. It aids
    // moving around the tree. It is a pointer
    // to the parent of the current node.
    struct twoThreeNode *parent;
} ; 
int middel(int a, int b,int c){
	if((a<b && b<c)||(c<b && b<a)) return b;
	else if((b<a && a<c )||( c<a &&a<b)) return a;
	else
		return c;
}
int minimum(int a, int b, int c){
	int min=a;
	if(b<min) min=b;
	if(c<min) min=c;
	return min;
}
int maximum( int a, int b , int c){
	int max=a;
	if(b>max)max=b;
	if(c>max)max=c;
	return max;
}
struct twoThreeNode * CreatNode( int data ){
	struct twoThreeNode * temp=(struct twoThreeNode*)malloc(sizeof(struct twoThreeNode));
		temp->d2=NULL;
		temp->first=NULL;
		temp->d1=data;
		temp->second=NULL;
		temp->third=NULL;
		temp->parent=NULL;	
		return temp;

}

struct twoThreeNode * Insert( struct twoThreeNode * root, int data ){
	if(root==NULL){
		root=CreatNode(data);
	}
	else{
		// case 1 root.d2=null
		if(root->d1 !=NULL && root->d2==NULL){
			if(data > root->d1)
		    root->third= Insert(root->third,data);
			else root->first= Insert(root->first,data);
		}
		else if(root->d1 !=NULL && root->d2!=NULL){
			if(data >root->d2)
		    root->third= Insert(root->third,data);
			else if(data < root->d1) root->first= Insert(root->first,data);
			else if(data > root->d1 && data < root->d2)
			root->second=Insert(root->second, data);


		}

		//for after finding the position
		if(root->d2==NULL){
			int data2=data;
			int data1=root->d1;
			if(data1<data2){
				root->d1=data1;
				root->d2=data2;
			}
			else {
				root->d1=data2;
				root->d2=data1;
			}
		}
		else{
			int data1=root->d1;
			int data2=root->d2;
			int data3=data;
			int mid=middel(data1,data2,data3);
			int min=minimum(data1,data2,data3);
			int max=maximum(data1,data2,data3);
			struct twoThreeNode *temp1,*temp2,*temp3;
			temp1=CreatNode(mid);
			temp2=CreatNode(min);
			temp3=CreatNode(max);
			temp2->parent=temp1;
			temp3->parent=temp1;
			temp1->first=temp2;
			temp1->third=temp3;
			if(temp1->parent!=NULL){
				//add programming
			}
    } 
	}
	return root;
}
int main(){
    struct twoThreeNode* root = NULL;
	int a ;
	printf("how many data you want to add :");
	scanf("%d",&a);
	int data;
	int i;
	for ( i=0;i<a;i++){
		printf("enter the data:");
		scanf("%d",&data);	
		root = Insert(root,data);
	}
	int sear;
    return 0;
}