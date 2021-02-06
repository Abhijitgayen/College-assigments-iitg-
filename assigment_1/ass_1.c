#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct myArray{
    int size;
    int *arr;
};
void creat_array(struct myArray * a,int n ){
    a->size = n;
    a->arr =(int *)malloc(n*(sizeof(int)));
    }
void add_element(struct myArray * a){
    int i;
    srand(time(0));
    for(i=0;i< a->size;i++){
        a->arr[i]=rand();
    }
    }
void print_array( struct myArray * a){
    int i;
    for(i=0;i<a->size;i++){
        printf("\telement %d:%d\n",i+1,a->arr[i]);
    }
    }
    //insertion sort function
void insertion_sort_array( struct myArray *a){
	int i;
	for(i=1;i< a->size;i++){
		int key=a->arr[i];
		int j=i-1;
		while(j>=0 && a->arr[j]>key){
			a->arr[j+1]=a->arr[j];
			j=j-1;	
		}
		a->arr[j+1]=key;
	}
	
}
//Bubble sort function
void bubble_sort_array(struct myArray *a){
	int i,j;
	for(i=a->size-2; i>=0;i--){
		for(j=0;j<=i;j++){
			if(a->arr[j]>a->arr[j+1]){
				int temp=a->arr[j];
				a->arr[j]=a->arr[j+1];
				a->arr[j+1]=temp;
			}
		}
	}
}
//selection sort function
void selection_sort_array(struct myArray *a){
	int i,j,p,temp;
	for(i=0;i< a->size-1;i++){
		p=i;
		for(j=i+1;j< a->size;j++){
			if(a->arr[p] > a->arr[j]){
					p=j;
			}
		
			if(p!=i){
				temp=a->arr[i];
				a->arr[p]=a->arr[i];
				a->arr[i]=temp;
			}
		}
	}
}
int main(){
    struct myArray array_1;
    creat_array(&array_1,10000);
    add_element(&array_1);
    print_array(&array_1);
    printf("After insertion sort\n\n ");
    clock_t begin=clock();
    insertion_sort_array(&array_1);
    clock_t  end=clock();
     double time_spent_1=((double)(end-begin)*1000000)/CLOCKS_PER_SEC;
     print_array(&array_1);
     printf("After bubble sort\n\n ");
     begin=clock();
    bubble_sort_array(&array_1);
    end=clock();
     double time_spent_2=((double)(end-begin)*1000000)/CLOCKS_PER_SEC;
     print_array(&array_1);
     printf("After selection sort\n\n ");
     begin=clock();
    selection_sort_array(&array_1);
    end=clock();
     double time_spent_3=((double)(end-begin)*1000000)/CLOCKS_PER_SEC;
     print_array(&array_1);
     printf("it take times in Insert sort:%f microseconds\n",time_spent_1);
     printf("it take times in Bubble sort:%f microseconds\n",time_spent_2);
     printf("it take times in seletion sort:%f microseconds\n",time_spent_3);
     
    
   /* srand(time(0));
    int i;
    for(i=0;i<4;i++){
    printf("random: %d\n",rand());

    }*/


    return 0;
}
