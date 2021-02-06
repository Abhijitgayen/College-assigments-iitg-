/*this is work for only 4 digits and two digits*/
#include<stdio.h>
#include<math.h>

long int mul(long int num_1,long int num_2,int n){
	if(n=1){
		return num_1*num_2 ;
	}
	else{
		long int x=pow(10,(n/2));
		long int b=num_1%x;
		long int a=(num_1-b)/pow(10,(n/2));
		long int c=num_2%x;
		long int d=(num_2-b)/pow(10,(n/2));
		long int p=a+b;
		long int q=c+d;
		long int ac=mul(a,c,n/2);
		long int bd=mul(b,d,n/2);
		long int pq=mul(p,q,n/2);
		return( pow(10,n)*ac+pow(10,(n/2))*(pq-bd-ac)+bd);
		
	}
}
int main(void){
	long int num_1=1245,num_2=1455;//change here
/*	printf("Enter first number");
	scanf("%d",&num_1);
	printf("Enter  number");
	scanf("%d",&num_2);*/
	printf("Multiplication of those two number is:%ld",mul(num_1,num_2,4));//change here
	
	return 0;}
