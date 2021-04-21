#include <stdio.h>
#include <stdlib.h>
int prime_number( int n){
    int i,fact =0;
    for(i=1; i<= n ;i++){
        if(n % i == 0){
            fact++;
        }
    }
    if(fact == 2)
    return 1;
    else
    return 0;
}
int prime( int p){
    int num;
    long long int i=2*p;
    while(i >= 2*p){
        if(prime_number(i) == 1){
            num = i;
            break;
        }
        i++;
    }
    return num;
}
main()
{	printf("hello");
	printf(" %d",prime(15));
	return 0;
}
