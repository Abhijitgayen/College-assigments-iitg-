#include<stdio.h>
#include<stdlib.h>
unsigned long long int count_com;

void insertionSort(int arr[], int a,int b){
    int i;
    for (i=a+1;i<=b;i++){
       int key=arr[i];
       int j=i-1;
       while((j>=0)&&(arr[j]>key)){
       		count_com++;
           arr[j+1]=arr[j];
           j--;
       }
       if(key >= arr[j+1]){
       	count_com++;
	   }
	  arr[j+1]=key;
    }
}
void swap(int arr[], int c, int d){
    int temp=arr[c];
    arr[c]=arr[d];
    arr[d]=temp;
}
int median_index(int arr[],int a, int b, int mid){
	if((arr[a]-arr[mid])*(arr[mid]-arr[b])>0)
	return mid;
	if((arr[b]-arr[a])*(arr[a]-arr[mid])>0)
	return a;
	else
	return b;
}
int middle( int a, int b){
	int mid;
	if((a+b)%2==0) 
	mid=((a+b)/2)-1;
	else
	mid=(a+b)/2;
	return mid;
}
int partition( int arr[], int a , int b){
    int k=middle(a,b);
	swap(arr,a,median_index(arr,a,b,k));
	int x=arr[a];//median-of-3-element as pivot
    int j,i=a;
    for(j=a+1;j<=b;j++){
    	count_com++;//1 st comparison
        if(arr[j]<x){
            i++;
            swap(arr,i,j);
        }
    }swap(arr,a,i);
    
    return i;
}
void quickSort( int arr[],int l, int r){
	if(l<r){
		if((r-l)<=5){
			 insertionSort( arr,l,r);	
		}
	else{
	
        int q=partition( arr, l, r);
        quickSort(arr,l,q-1);
        quickSort(arr,q+1,r);}
}
    }

int main(void){
	count_com=0;
     FILE *fptr;
    fptr = fopen("a3test2.txt", "r");
    if (fptr == NULL) {
    printf("\n\n\tError....I am not able to read this file\n\n");
    }
    else{
    	int data;
    	long long int total=1;
    	while (!feof(fptr)){
		 fscanf(fptr, "%d", &data);
          total++;
			 }
        int arr[total];
        rewind(fptr);
         int i=0;
        int key;
         while (!feof(fptr)){
		 fscanf(fptr, "%d", &arr[i]);
             i++;
			 }
			 i--;

    fclose(fptr); 
    printf("no of element=%d",i);
    int n=i;
    quickSort(arr,0,n-1);
    printf("after sorting the array is:");
    for(i=0;i<n;i++){
        printf("\n\t%d",arr[i]);
    }
    printf("\n no of comparison is as median as pivot and insertion : %llu",count_com);
    printf("\n\n");
    return 0;
}
}
