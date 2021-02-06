#include<stdio.h>
#include<stdlib.h>
unsigned long long int count_com=0;
void swap(int arr[], int c, int d){
    int temp=arr[c];
    arr[c]=arr[d];
    arr[d]=temp;
}
int partition_last( int arr[], int a , int b){
	swap(arr,a,b);
	int x=arr[a];//frist element as pivot
    int j,i=a;
    for(j=a+1;j<=b;j++){
    	count_com++;//1 st comparison
        if(arr[j]<x){
            i++;
            swap(arr,i,j);
        }
    }swap(arr,a,i);
	
   /* int x=arr[b];//last element as pivot
    int j,i=a;
    for(j=a;j<=b-1;j++){
    	count_com++;//1 st comparison
        if(arr[j]<x){
            swap(arr,i,j);
            i++;
        }
    }swap(arr,i,b);*/
    
    return i;
}
void quckSort_last( int arr[],int l, int r){
    if(l<r){
        int q=partition_last( arr, l, r);
        quckSort_last(arr,l,q-1);
        quckSort_last(arr,q+1,r);


    }
}
int main(void){
     FILE *fptr;
    fptr = fopen("a3test1.txt", "r");
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
    printf("\n\n\tno of element=%d\n",i);
    int n=i;
    quckSort_last(arr,0,n-1);
    printf("\nafter sorting the array is:\n");
    for(i=0;i<n;i++){
        printf("\n\t%d",arr[i]);
    }
    printf("\n no of comparison is as last element as pivot : %llu",count_com);
    printf("\n\n");
    return 0;
}
}
