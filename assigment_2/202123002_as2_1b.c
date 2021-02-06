/* problem 1.b by Abhijit Gayen(202123002) */
#include<stdio.h>
#include<stdlib.h>
#define max 1000

unsigned long long int marge(int arr[],int dy_array[], int a, int mid, int b){
    int i=a;
    int j=mid+1;
    int k=a;
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
 
unsigned long long int margeSort( int arr[], int dy_array[],int a, int b ){
    unsigned long long int count = 0;
    if(a<b){
        int mid=(a+b)/2;
        count += margeSort(arr,dy_array,a,mid);
        count += margeSort(arr,dy_array,mid+1,b);
        count += marge(arr,dy_array,a,mid,b);
        }
        return count ;
}
void print(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("\n\t%d",arr[i]);
    }
    printf("\n\n");

}

int main (void){
	FILE *fptr;
    int arr[max];
    fptr = fopen("tstcase1.txt", "r");
    if (fptr == NULL) {
        printf("I am not able to read this file");
        return 0;
    }
    else{
        int i=0;
        while (!feof(fptr)){
		fscanf(fptr, "%d", &arr[i]);
   		i++;
        }
    fclose(fptr); 
	int n=i-1;
	printf("\n\nArray that is store in this file is:");
	print(arr,n);
	printf("\nLenght of this array is:%d\n",n);
  	int* dy_array=(int*)malloc(n*sizeof(int));
    unsigned long long int count=margeSort(arr,dy_array,0,n-1);
    printf("\n\tinversion of this array is : %d\n\n",count);
    //print(arr,n);
    return 0;

    }
     
    
}

