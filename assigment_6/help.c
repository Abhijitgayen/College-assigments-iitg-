#include<stdio.h>
#include<limits.h>
 
/*
This is code for linear probing in open addressing. If you want to do quadratic probing and double hashing which are also
open addressing methods in this code when I used hash function that (pos+1)%hFn in that place just replace with another function.
*/
 
void insert(int ary[], int hFn,int element, int size){
    int pos,n=0;
	pos = element%hFn;
 
	while(ary[pos]!= INT_MIN) {  // INT_MIN and INT_MAX indicates that cell is empty. So if cell is empty loop will break and goto bottom of the loop to insert element
		if(ary[pos]== INT_MAX)
            break;
		pos = (pos+1)%hFn;
		n++;
		if(n==size)
		break;      // If table is full we should break, if not check this, loop will go to infinite loop.
	}
 
	if(n==size)
        printf("Hash table was full of elements\nNo Place to insert this element\n\n");
	else
        ary[pos] = element;    //Inserting element
}
 
void delete(int ary[],int hFn,int size){
	/*
	very careful observation required while deleting. To understand code of this delete function see the note at end of the program
	*/
	int element,n=0,pos;
 
	printf("Enter element to delete\n");
	scanf("%d",&element);
 
	pos = element%hFn;
 
	while(n++ != size){
		if(ary[pos]==INT_MIN){
			printf("Element not found in hash table\n");
			break;
		}
		else if(ary[pos]==element){
			ary[pos]=INT_MAX;
			printf("Element deleted\n\n");
			break;
		}
		else{
			pos = (pos+1) % hFn;
		}
	}
	if(--n==size)
        printf("Element not found in hash table\n");
}
 
void search(int ary[],int hFn,int size){
	int element,pos,n=0;
 
	printf("Enter element you want to search\n");
	scanf("%d",&element);
 
	pos = element%hFn;
 
	while(n++ != size){
		if(ary[pos]==element){
			printf("Element found at index %d\n",pos);
			break;
		}
		else
            if(ary[pos]==INT_MAX ||ary[pos]!=INT_MIN)
                pos = (pos+1) %hFn;
	}
	if(--n==size) printf("Element not found in hash table\n");
}
 
void display(int ary[],int size){
	int i;
 
	printf("Index\tValue\n");
 
	for(i=0;i<size;i++)
        printf("%d\t%d\n",i,ary[i]);
}
int main(){
	int size,hFn,i;
FILE *fptr;
    /*char name[10];
    printf("Enter the file name:");
    scanf(" %s",name);*/
    fptr=fopen("test.txt", "r"); 
    if (fptr == NULL) {
    printf("\n\n\tError....I am not able to read this file\n\n");
    return 0;
    }
    else{
        int DAta;
    	 size=0;
    	while (!feof(fptr)){
		 fscanf(fptr, "%d", &DAta);
          size++;
			 }
        rewind(fptr);
        printf("\n\n size is %d",size);
        long long int i=0;
        int ary[size] ;
        for(i=0;i<size;i++)
        ary[i]=INT_MIN; //Assigning INT_MIN indicates that cell is empty
 
	  
         int num;
         hFn=size;
		 while (!feof(fptr)){
		 fscanf(fptr, "%d", &num);
    		insert(ary,hFn,num,size);
			 }
        fclose(fptr);
        display(ary,size);
        search(ary,hFn,size);
 
	return 0;}
    .
}
