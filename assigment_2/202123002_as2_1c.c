//  problem 1 a) by Abhijit Gayen (Roll no -202123002)
#include<stdio.h>
#include<stdlib.h>
#define max 518999
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
    unsigned long long int count = 0;
    if(a<b){
        long long int mid=(a+b)/2;
        count += margeSort(arr,dy_array,a,mid);
        count += margeSort(arr,dy_array,mid+1,b);
        count += marge(arr,dy_array,a,mid,b);
        }
        return count ;
}
/*print the array*/
void print(int arr[],long long int n){
    long long int i;
    for(i=0;i<n;i++){
        printf("\n\t%d",arr[i]);
    }
    printf("\n\n");

}

int main (void){
	FILE *fptr;
    int arr[max];
    fptr = fopen("tstcase2.txt", "r");
    if (fptr == NULL) {
    printf("\n\n\tError....I am not able to read this file\n\n");
    return 0;
    }
    else{
        printf("\n\tif Lenght of this array is less than %d , then this programming ran finely.......\n",max);
        long long int i=0;
         while (!feof(fptr)){
		 fscanf(fptr, "%d", &arr[i]);
   		  i++;
			 }

    fclose(fptr); 
	long long int n=i-1;
	printf("\n\nArray that is store in this file is:");
	print(arr,n);
	printf("\nLenght of this array is:%d\n",n);
  	int* dy_array=(int*)malloc(n*sizeof(int));
    unsigned long long int count=margeSort(arr,dy_array,0,n-1);
    printf("\n\tinversion of this array is : %llu\n\n",count);
    return 0;

    }
     
    
}


