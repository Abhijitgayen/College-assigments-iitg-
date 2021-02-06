//  ASSIGMENT-2 by Abhijit Gayen (Roll no -202123002)
#include<stdio.h>
#include<stdlib.h>
/* marge two subarray and calculating inversion */
unsigned long long int marge(int arr[], int dy_array[], long long int a, long long int mid, long long int b){
    long long int i=a;
    long long int j=mid+1;
    long long int k=a;
	unsigned long long int count=0;
    while((i<=mid)&&(j<=b)){
        if(arr[i]>arr[j]){
            dy_array[k++]=arr[j++];
            count=count+((mid-i)+1);
        }
        else
        {
            dy_array[k++]=arr[i++];
        }
        
    }
    while(i<=mid){
        dy_array[k++]=arr[i++];
    }
    while(j<=b){
        dy_array[k++]=arr[j++];
    }
    for(i=a;i<=b;i++){
        arr[i]=dy_array[i];
    }
    return count;
}
 /*marge sorting and calculating inversion*/
unsigned long long int margeSort( int arr[], int dy_array[], long long int a,long long int b ){
	if(a==b){
		return 0;
	}
	else{
    unsigned long long int count = 0;
    if(a<b){
        long long int mid=(a+b)/2;
        count += margeSort(arr,dy_array,a,mid);
        count += margeSort(arr,dy_array,mid+1,b);
        count += marge(arr,dy_array,a,mid,b);
        }
        return count ;
    }
}
/*print the array*/
void print(int arr[],long long int n){
    long long int i;
    for(i=0;i<n;i++){
        printf("\n\t%d",arr[i]);
    }
    printf("\n\n");

}

void tstcase1(){
	FILE *fptr;
    fptr = fopen("tstcase1.txt", "r");
    if (fptr == NULL) {
    printf("\n\n\tError....I am not able to read this file\n\n");
    }
    else{
    	int data;
    	long long int total=0;
    	while (!feof(fptr)){
		 fscanf(fptr, "%d", &data);
   		  total++;
			 }
        int arr[total];
        rewind(fptr);
        long long int i=0;
         while (!feof(fptr)){
		 fscanf(fptr, "%d", &arr[i]);
   		  i++;
			 }

    fclose(fptr); 
	long long int n=i;
	//printf("\n\nArray that is store in this file is:");
	//print(arr,n);
	printf("\nLenght of this array is:%d\n",n);
  	int* dy_array=(int*)malloc(n*sizeof(int));
    unsigned long long int count=margeSort(arr,dy_array,0,n-1);
    printf("\n\tinversion of this array is : %llu\n\n",count);

    }
     
    
}
void tstcase3(void){
	FILE *fptr;
    fptr = fopen("tstcase3.txt", "r");
    if (fptr == NULL) {
    printf("\n\n\tError....I am not able to read this file\n\n");
    }
    else{
    	int data;
    	long long int total=0;
    	while (!feof(fptr)){
		 fscanf(fptr, "%d", &data);
   		  total++;
			 }
        int arr[total];
        rewind(fptr);
        long long int i=0;
         while (!feof(fptr)){
		 fscanf(fptr, "%d", &arr[i]);
   		  i++;
			 }

    fclose(fptr); 
	long long int n=i;
	//printf("\n\nArray that is store in this file is:");
	//print(arr,n);
	printf("\nLenght of this array is:%d\n",n);
  	int* dy_array=(int*)malloc(n*sizeof(int));
    unsigned long long int count=margeSort(arr,dy_array,0,n-1);
    printf("\n\tinversion of this array is : %llu\n\n",count);

    }
     
    
}
void tstcase2(void){
	FILE *fptr;
    fptr = fopen("tstcase2.txt", "r");
    if (fptr == NULL) {
    printf("\n\n\tError....I am not able to read this file\n\n");
    }
    else{
    	int data;
    	long long int total=0;
    	while (!feof(fptr)){
		 fscanf(fptr, "%d", &data);
   		  total++;
			 }
        int arr[total];
        rewind(fptr);
        long long int i=0;
         while (!feof(fptr)){
		 fscanf(fptr, "%d", &arr[i]);
   		  i++;
			 }

    fclose(fptr); 
	long long int n=i;
	//printf("\n\nArray that is store in this file is:");
	//print(arr,n);
	printf("\nLenght of this array is:%d\n",n);
  	int* dy_array=(int*)malloc(n*sizeof(int));
    unsigned long long int count=margeSort(arr,dy_array,0,n-1);
    printf("\n\tinversion of this array is : %llu\n\n",count);

    }
     
    
}
void problem1a(void){
     int n;
     printf("\nEnter the no of element:");
     scanf(" %d",&n);
    int arr_1[n], arr_2[n];
   // printf("Sorted array fron 1 to %d is",n);
    int i;
    for(i=0;i<n;i++){
        arr_1[i]=i+1;
    }
    //print(arr_1,n);
    int* dy_array=(int*)malloc(n*sizeof(int));
    int count_1=margeSort(arr_1,dy_array,0,n-1);
    printf("inversion of sorted array is : %d\n\n",count_1);
   // printf("Reverse sorted array fron 1 to %d is",n);
    for(i=0;i<n;i++){
        arr_2[i]=n-i;
    }
   // print(arr_2,n);
    int count_2=margeSort(arr_2,dy_array,0,n-1);
    printf("inversion of Reverse sorted array is : %d\n\n",count_2);
}
int main(void){
	int i;
	do{
		printf("\nchoose\n\t1.Problem 1a)\n\t2.Problem 1 b)\n\t3.Problem 1 c)\n\t4.lab test\n\t5.exist");
		printf("\nchoose:");
		scanf("%d",&i);
		switch(i){
			case 1:
				problem1a();
				break;
			case 2:
				tstcase1();
				break;
			case 3:
				tstcase2();
				break;
			case 4:
				tstcase3();
				break;
			case 5:
				printf("\n\t\t teminating.....");
				break;
			default:
				printf("\n\tEnter currect choices....\n");
				break;				
		}
		
	}while(i!=5);
		
}



