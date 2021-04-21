#include <stdio.h>
#include <stdlib.h>
typedef struct twoThreeNode
{
    int d1;                               // the value of this node that is maximum value with respect to all it's leaf
    struct twoThreeNode *fis, *sec, *thi; // this is pointer of three node first , second ,third
    struct twoThreeNode *par;             // this is the pointer of the parent of the node
} node;
// this is search function to seartch data in 2-3 tree
node *search(node *head, int data)
{
    if (head == NULL || head->d1 == data)
        {return head;}
    // this is for cheack the leaf   
    else if ((head->fis == NULL) || (head->sec == NULL) || (head->thi == NULL))
    {
        printf("%d",head->d1);
        if (head->d1 == data)
            return head;
    }
    // the recurssion retation for search case is T(n)=3*T(n/3)+O(1)
    else
    {	if (data <= head->sec->d1)
            return search(head->sec, data);
        else if (data <= head->fis->d1)
            return search(head->fis, data);
        else
            return search(head->thi, data);
    }
    return NULL;
}
//function for creat new node
node *creatNode(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->d1 = data;
    temp->fis = NULL;
    temp->sec = NULL;
    temp->thi = NULL;
    temp->par = NULL;
    return temp;
}
int numLeaf(node *root)
{
    int i = 0;
    if (root->fis != NULL){
        i++;
        }
    if (root->sec != NULL){
    	i++;
	}
        
    if (root->thi != NULL){
    	i++;
	}
        
    return i;
}
void shortArry(int arr[], int n)
{
    int a, i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n-i; ++j)
        { if(arr[j]>arr[j+1]){
            int a = arr[j];
            arr[j] = arr[i];
            arr[i] = a;}
        }
    }
}
//arrangment all element
void arrangmentAll(node *root, int data)
{
    node *temp = root;
    int d = data;
    while (temp != NULL)
    {
        if (temp->d1 < d)
        {
            temp->d1 = d;
            temp = temp->par;
        }
        else
            break;
    }
}
node *splitAll(node* head, node *main, node* part){
    node* temp=main;
    int array[4];
    array[0]=part->d1;
    array[1]=temp->fis->d1;
    array[2]=temp->sec->d1;
    array[3]=temp->thi->d1;
    shortArry(array,4);
    part->d1=array[0];
    
    temp->fis->d1=array[1];
    temp->sec->d1=array[2];
    temp->thi->d1=array[3];
    node* nodey1,*nodey2;
    nodey1=(node*)malloc(sizeof(node));
    nodey2=(node*)malloc(sizeof(node));
    nodey1->d1=array[1];
    nodey1->par=temp->par;
    nodey1->thi=temp->fis;
    nodey1->sec=part;
    nodey1->fis=NULL;
    nodey2->par=temp->par;
    nodey2->d1=array[3];
    nodey2->thi=temp->thi;
    nodey2->sec=temp->sec;
    nodey2->fis=NULL;
    if(temp->par==NULL){
    	node* temp2= head;
    	head=creatNode(array[4]);
        head->thi=nodey2;
        head->sec=nodey1;
        temp2->fis=NULL;
        temp2->sec=NULL;
        temp2->thi=NULL;
        free(temp2);
        return head;
	}
    if(temp->par->fis!=NULL){
    	if(temp->par->fis==main){
        temp->par->fis=NULL;
        free(main);}
        printf("ok fis");
    }
    else if(temp->par->sec!=NULL){
    	if(temp->par->sec==main){
        temp->par->sec=NULL;
        free(main);}
        printf("ok sec");
    }
    else{
    	if(temp->par->thi==main){
        temp->par->thi= NULL;
        free(main);}
        printf("ok thi");
    }
    printf("it is ok");
    if(temp->par->thi==NULL && temp->par->sec==NULL){
        temp->par->thi=nodey2;
        temp->par->sec=nodey1;
        arrangmentAll(temp->par, array[3]);
    }
    else if(temp->par->sec==NULL && temp->par->fis==NULL){
        temp->par->sec=nodey2;
        temp->par->fis=nodey1;
        arrangmentAll(temp->par, array[3]);
    }
   else if(temp->par->thi==NULL && temp->par->fis==NULL){
        temp->par->thi=nodey2;
        temp->par->fis=nodey1;
        arrangmentAll(temp->par, array[3]);
    }
    else{
         temp->par->fis=nodey2;
          arrangmentAll(temp->par, array[3]);
         return head =splitAll(head,temp->par,nodey1);
    }
   

    return head;
}
// function to insert data in thew 2-3 tree
node *insert(node *head, int data)
{
    if (head == NULL)
    {
        head = creatNode(data);
        head->thi=creatNode(head->d1);
        head->thi->par=head;
        return head;
    }
	else if(search(head,data)) {
	printf("\n\t Error......Data is threre in this Tree");
	return head;}
    else
    {   
        int array[3];
        node *temp = head;
       while (temp != NULL)
        {
           if ((temp->fis == NULL) || (temp->sec == NULL) || (temp->thi == NULL))
            {
                break;
            }
            else if((temp->fis != NULL) && (temp->sec != NULL) && (temp->thi != NULL)){
                if(temp->thi->thi==NULL)break;
                else continue;

            }
          else if (temp->fis!=NULL && data < temp->fis->d1)
            {
                temp = temp->fis;
            }
            else if (temp->sec !=NULL && data < temp->sec->d1)
            {
                temp = temp->sec;
            }
            else
                temp = temp->thi;
        }
         if (temp->thi == NULL)
        {
            temp->thi = creatNode(temp->d1);
            temp->thi->par = temp;
        }
        if (numLeaf(temp) < 3)
        {
            if ((temp->fis == NULL) && (temp->sec != NULL))
            {
                array[1] = temp->sec->d1;
                array[2] = data;
                array[0] = temp->thi->d1;
                free(temp->sec);
                free(temp->thi);
                shortArry(array, 3);
                temp->fis = creatNode(array[0]);
                temp->fis->par = temp;
                temp->sec = creatNode(array[1]);
                temp->sec->par = temp;
                temp->thi = creatNode(array[2]);
                temp->thi->par = temp;
                //printf("\n %d %d %d",temp->fis->d1,temp->sec->d1,temp->thi->d1);
                //need arrangment
              // 	printf("\n case -2 %d",numLeaf(temp));
                arrangmentAll(temp, array[2]);
                //printf("\n %d %d %d",temp->fis->d1,temp->sec->d1,temp->thi->d1);
            }
            else
            {
                array[0] = data;
                array[1] = temp->thi->d1;
                free(temp->thi);
                shortArry(array, 2);
                temp->sec = creatNode(array[0]);
                temp->sec->par = temp;
                temp->thi = creatNode(array[1]);
                temp->thi->par = temp;
                //need to arrangment
                //printf("case-1");
                //printf("\n %d  %d",temp->sec->d1,temp->thi->d1);
                arrangmentAll(temp, array[1]);
            }
        }
        else if(numLeaf(temp)>=3)
        {
          //printf("need to complete it\n"); 
          node* part=creatNode(data);
          head=splitAll(head,temp,part);
		  return head;   
        }
        return head;
    }
}
node *delete (node *head, int data)
{
}

int main()
{
    node *root = NULL;
    int b,a,sear,del;
    system("COLOR 6");
    printf("chooses:\n\t 1. Insert\n\t 2. Search \n\t 3. Delete\n\t 4. Exist\n");
    do
    {
        printf("choose: ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("how many data you want to add :");
            scanf("%d", &b);
            int data;
            int i;
            for (i = 0; i < b; i++)
            {
                printf("\tenter the data:");
                scanf("%d", &data);
                root = insert(root, data);
            }
            break;
        case 2:
            
            printf("Enter the data to search:");
            scanf("%d", &sear);
            //if(sear > root->d1) printf("\n\t data is not there..");
            if (search(root, sear))
                printf("\n\tdata is there in this 2-3 tree\n");
            else
                printf("\n\t data is not there in this 2-3 tree....\n");
            break;
        case 3:
            printf("\n\t enter data to delete form 2-3 tree :");
            scanf("%d", &del);
            root = delete (root, del);
        case 4:
            printf("\t\t terminating......");
            break;
        default:
            printf("\t\tError Enter the Right chooses....\n");
            break;
        }
    } while (a != 4);
    // printf("how many data you want to add :");
    //     scanf("%d", &a);
    //     int data;
    //     int i;
    //     for (i = 0; i < a; i++)
    //     {
    //         printf("enter the data:");
    //         scanf("%d", &data);
    //         root = insert(root, data);
    //     }
    //     int sear;
    //     printf("Enter the data to search:");
    //     scanf("%d", &sear);
    //    if( search(root, sear)) printf("\n\tdata is there in this 2-3 tree");
    //    else printf("\n\t data is not there in this 2-3 tree....");
    // int del;
    // printf("\n\t enter data to delete form 2-3 tree :");
    // scanf("%d",&del);
    // root=delete(root,del);
    return 0;
}
