//  problem 1 a) by Abhijit Gayen (Roll no -202123002)
#include<stdio.h>
#include<stdlib.h>
#define max 10000
/* marge two subarray and calculating inversion */
int marge(int arr[],int dy_array[], int a, int mid, int b){
    int i=a;
    int j=mid+1;
    int k=a,count=0;
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
int margeSort( int arr[], int dy_array[],int a, int b ){
    int count = 0;
    if(a<b){
        int mid=(a+b)/2;
        count += margeSort(arr,dy_array,a,mid);
        count += margeSort(arr,dy_array,mid+1,b);
        count += marge(arr,dy_array,a,mid,b);
        }
        return count ;
}
/*print array*/
void print(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("\n\t%d",arr[i]);
    }
    printf("\n\n");

}

int main (void){
     int n;
     printf("\nEnter the no of element:");
     scanf(" %d",&n);
    int arr_1[n], arr_2[n];
    printf("Sorted array fron 1 to %d is",n);
    int i;
    for(i=0;i<n;i++){
        arr_1[i]=i+1;
    }
    print(arr_1,n);
    int* dy_array=(int*)malloc(n*sizeof(int));
    int count_1=margeSort(arr_1,dy_array,0,n-1);
    printf("inversion of sorted array is : %d\n\n",count_1);
    printf("Reverse sorted array fron 1 to %d is",n);
    for(i=0;i<n;i++){
        arr_2[i]=n-i;
    }
    print(arr_2,n);
    int count_2=margeSort(arr_2,dy_array,0,n-1);
    printf("inversion of Reverse sorted array is : %d\n\n",count_2);
    return 0;
}