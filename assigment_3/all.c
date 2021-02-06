//Assigment-3 Name-Abhijit Gayen Roll no-202123002
#include<stdio.h>
#include<stdlib.h>//use for dynamic array
unsigned long long int count_com;

void insertionSort(int arr[],int a,int b){
    int i;
    for (i=a+1;i<=b;i++){
       int keyELe=arr[i];
       int j=i-1;
       while((j>=0)&&(arr[j] > keyELe)){
       		count_com++;//2nd counting
           arr[j+1]=arr[j];
           j--;
       }
       if(keyELe >= arr[j+1]){
       	count_com++;//3rd counting
	   }
	  arr[j+1]=keyELe;
    }
}
void swapTwoEle(int arr[], long long int c,long long int d){
    int tempEle=arr[c];
    arr[c]=arr[d];
    arr[d]=tempEle;
}
int IndexOfmedian(int arr[],long long int a,long long int b,long long int mid){
	if((arr[a]-arr[mid])*(arr[mid]-arr[b])>0)
	return mid;
	if((arr[b]-arr[a])*(arr[a]-arr[mid])>0)
	return a;
	else
	return b;
}
int IndexOfMid( long long int a,long long int b){
	int mid;
	if((a+b)%2==0) 
	mid=((a+b)/2)-1;
	else
	mid=(a+b)/2;
	return mid;
}
int partition_median_insertion( int arr[],long long int a ,long long int b){
    long long int k=IndexOfMid(a,b);
	swapTwoEle(arr,a,IndexOfmedian(arr,a,b,k));//here i just swap between 1st and privot Element
	int x=arr[a];//median-of-3-element as pivot
    long long int j,i=a;
    for(j=a+1;j<=b;j++){
    	count_com++;//1 st comparison
        if(arr[j]<x){
            i++;
            swapTwoEle(arr,i,j);
        }
    }swapTwoEle(arr,a,i);
    
    return i;
}

void qucikSort_median_insertion( int arr[],long long int l,long long int r){
	if(l<r){
		if((r-l)<=5){
			 insertionSort( arr,l,r);	
		}
	else{
	
        int q=partition_median_insertion( arr, l, r);
        qucikSort_median_insertion(arr,l,q-1);
        qucikSort_median_insertion(arr,q+1,r);}
}
    }
int partition_median( int arr[],long long int a ,long long int b){
    long long int k=IndexOfMid(a,b);
	swapTwoEle(arr,a,IndexOfmedian(arr,a,b,k));
	int x=arr[a];//median-of-3-element as pivot
    long long int j,i=a;
    for(j=a+1;j<=b;j++){
    	count_com++;//1 st comparison
        if(arr[j]<x){
            i++;
            swapTwoEle(arr,i,j);
        }
    }swapTwoEle(arr,a,i);
    
    return i;
}

void qucikSort_median( int arr[],long long int l,long long int r){

	if(l<r){
        int q=partition_median( arr, l, r);
        qucikSort_median(arr,l,q-1);
        qucikSort_median(arr,q+1,r);
    }    
}
    
int partition_first( int arr[],long long int a ,long long int b){
    int x=arr[a];//frist element as pivot
    long long int j,i=a;
    for(j=a+1;j<=b;j++){
    	count_com++;//1 st comparison
        if(arr[j]<x){
            i++;
            swapTwoEle(arr,i,j);
        }
    }swapTwoEle(arr,a,i);
    
    return i;
}
void quickSort_first( int arr[],long long int l,long long int r){
    if(l<r){
        long long int q=partition_first( arr, l, r);
        quickSort_first(arr,l,q-1);
        quickSort_first(arr,q+1,r);
    }
}
int partition_last( int arr[],long long int a ,long long int b){
	/* int x=arr[b];//last element as pivot
    int j,i=a;
    for(j=a;j<=b-1;j++){
    	count_com++;//1 st comparison
        if(arr[j]<x){
            swap(arr,i,j);
            i++;
        }
    }swap(arr,i,b);*/
	swapTwoEle(arr,a,b);//here i swap 1st element to last element
    int x=arr[a];//last element as pivot
    long long int j,i=a;
    for(j=a+1;j<=b;j++){
    	count_com++;//1 st comparison
        if(arr[j]<x){
            i++;
            swapTwoEle(arr,i,j);
        }
    }swapTwoEle(arr,a,i);
    
    return i;
}
void quckSort_last( int arr[],long long int l,long long int r){
    if(l<r){
        long long int q=partition_last( arr, l, r);
        quckSort_last(arr,l,q-1);
  	    quckSort_last(arr,q+1,r);
    }
}
void test1(void){
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
        int arr1[total],arr2[total];
        rewind(fptr);
        long long int i=0;
        int keyELe;
         while (!feof(fptr)){
		 fscanf(fptr, "%d", &arr1[i]);
             i++;
			 }
			 i--;

    fclose(fptr); 
    printf("\n\tno of element=%d",i);
    long long int n=i;
    // pivot as a first element
    count_com=0;
     for(i=0;i<n;i++){
    	arr2[i]=arr1[i];
	}
    quickSort_first(arr2,0,n-1);
    // printf("after sorting the array is:");
    // for(i=0;i<n;i++){
    //     printf("\n\t%d",arr2[i]);
    // }
    printf("\nno of comparison is as fist element as pivot : %llu",count_com);
    //printf("\n\n");
    /*pivot as last element*/
   count_com=0;
     for(i=0;i<n;i++){
    	arr2[i]=arr1[i];
	}
    quckSort_last(arr2,0,n-1);
    // printf("after sorting the array is:");
    // for(i=0;i<n;i++){
    //     printf("\n\t%d",arr2[i]);
    // }
    printf("\nno of comparison is as last element as pivot : %llu",count_com);
    //pivot as median
    for(i=0;i<n;i++){
    	arr2[i]=arr1[i];
	}
    count_com=0;
    qucikSort_median(arr2,0,n-1);
    // printf("after sorting the array is:");
    // for(i=0;i<n;i++){
    //     printf("\n\t%d",arr2[i]);
    // }
    printf("\nno of comparison is as midean-of-three as pivot : %llu",count_com);
    // pivot as median and insertion 
    for(i=0;i<n;i++){
    	arr2[i]=arr1[i];
	}
    count_com=0;
    qucikSort_median_insertion(arr2,0,n-1);
    // printf("after sorting the array is:");
    // for(i=0;i<n;i++){
    //     printf("\n\t%d",arr2[i]);
    // }
    printf("\nno of comparison is as midean-of-three as pivot and insertion : %llu",count_com);
    

}
}
void test2(void){
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
        int arr1[total],arr2[total];
        rewind(fptr);
        long long int i=0;
        int keyELe;
         while (!feof(fptr)){
		 fscanf(fptr, "%d", &arr1[i]);
             i++;
			 }
			 i--;

    fclose(fptr); 
    printf("\n\tno of element=%d",i);
    long long int n=i;
    // pivot as a first element
    count_com=0;
     for(i=0;i<n;i++){
    	arr2[i]=arr1[i];
	}
    quickSort_first(arr2,0,n-1);
    // printf("after sorting the array is:");
    // for(i=0;i<n;i++){
    //     printf("\n\t%d",arr2[i]);
    // }
    printf("\nno of comparison is as fist element as pivot : %llu",count_com);
    //printf("\n\n");
    /*pivot as last element*/
   count_com=0;
     for(i=0;i<n;i++){
    	arr2[i]=arr1[i];
	}
    quckSort_last(arr2,0,n-1);
    // printf("after sorting the array is:");
    // for(i=0;i<n;i++){
    //     printf("\n\t%d",arr2[i]);
    // }
    printf("\nno of comparison is as last element as pivot : %llu",count_com);
    // pivot as median 
    for(i=0;i<n;i++){
    	arr2[i]=arr1[i];
	}
    count_com=0;
    qucikSort_median(arr2,0,n-1);
    // printf("after sorting the array is:");
    // for(i=0;i<n;i++){
    //     printf("\n\t%d",arr2[i]);
    // }
    printf("\nno of comparison is as midean-of-three as pivot : %llu",count_com);
    // pivot as median and insertion 
    for(i=0;i<n;i++){
    	arr2[i]=arr1[i];
	}
    count_com=0;
    qucikSort_median_insertion(arr2,0,n-1);
    // printf("after sorting the array is:");
    // for(i=0;i<n;i++){
    //     printf("\n\t%d",arr2[i]);
    // }
    printf("\nno of comparison is as midean-of-three as pivot and insertion : %llu",count_com);

}
}
void test3(void){
    FILE *fptr;
    fptr = fopen("a3challenge.txt", "r");
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
        //int arr1[total],arr2[total];
        int* arr1=(int*)malloc(total*sizeof(int));
        int* arr2=(int*)malloc(total*sizeof(int));
        rewind(fptr);
        long long int i=0;
        int keyELe;
         while (!feof(fptr)){
		 fscanf(fptr, "%d", &arr1[i]);
             i++;
			 }
			 i--;

    fclose(fptr); 
    printf("\n\tno of element=%d",i);
    long long int n=i;
    // pivot as a first element
    count_com=0;
     for(i=0;i<n;i++){
    	arr2[i]=arr1[i];
	}
    quickSort_first(arr2,0,n-1);
    // printf("after sorting the array is:");
    // for(i=0;i<n;i++){
    //     printf("\n\t%d",arr2[i]);
    // }
    printf("\nno of comparison is as fist element as pivot : %llu",count_com);
    //printf("\n\n");
    /*pivot as last element*/
   count_com=0;
     for(i=0;i<n;i++){
    	arr2[i]=arr1[i];
	}
    quckSort_last(arr2,0,n-1);
    // printf("after sorting the array is:");
    // for(i=0;i<n;i++){
    //     printf("\n\t%d",arr2[i]);
    // }
    printf("\nno of comparison is as last element as pivot : %llu",count_com);
    // pivot as median 
    for(i=0;i<n;i++){
    	arr2[i]=arr1[i];
	}
    count_com=0;
    qucikSort_median(arr2,0,n-1);
    // printf("after sorting the array is:");
    // for(i=0;i<n;i++){
    //     printf("\n\t%d",arr2[i]);
    // }
    printf("\nno of comparison is as midean-of-three as pivot : %llu",count_com);
    // pivot as median and insertion 
    for(i=0;i<n;i++){
    	arr2[i]=arr1[i];
	}
    count_com=0;
    qucikSort_median_insertion(arr2,0,n-1);
    // printf("after sorting the array is:");
    // for(i=0;i<n;i++){
    //     printf("\n\t%d",arr2[i]);
    // }
    printf("\nno of comparison is as midean-of-three as pivot and insertion : %llu",count_com);

}
}
int main(void){
	printf("\tfor file a3test1.txt\n");
	test1();
	printf("\n\n\tfor file a3test2.txt\n");
	test2();
	printf("\n\n\tfor file a3challange.txt\n\n");
	test3();
	printf("\n\n\n");
	return 0;
}
