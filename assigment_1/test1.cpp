 #include<stdio.h>
 #include<string.h>
 #include<stdlib.h>
 #define max_digits 100

 void sum(char a[],char b[],char c[]){
		int i,j,k,l1,l2,s,d=0;
		l1=strlen(a);
		l2=strlen(b);
		i=l1-1;
		j=l2-1;
		k=l1 > l2?l1:l2;
		c[k]='\0';
		k--;
		while(i>=0&&j>=0){
			s=(a[i]-48)+(b[j]-48)+d;
			c[k]=s%10 +48;
			d=s/10;
			i--;
			j--;
			k--;
		}
		if(i>=0){
			while(i>=0){
			s=(a[i]-48)+d;
			c[k]=s%10 +48;
			d=s/10;
			i--;
			k--;
			}
			}
			else if(j>=0){
				while(j>=0){
				s=(b[j]-48)+d;
				c[k]=s%10 +48;
				d=s/10;
				j--;
				k--;
			}
		}
		if(d>0){
			c[k]=d+48;
		}

	}
void sub(char a[], char b[], char c[]) {
	int l1 = strlen(a);
	int l2 = strlen(b);
	//assume(l1 >= l2);
	int toSub = 0,i,j;
	for (i = l1 - 1, j = l2 - 1; i >= 0; --i, --j)
	{
		int x = a[i] - 48;
		int y = j >= 0 ? b[j] - 48 : 0;

		if (toSub == 1)
		{
		x--;
		}
		int cur;
		if (x < y)
		{
		cur = x + 10 - y;
		toSub = 1;
		}
	else
	{
		cur = x - y;
		toSub = 0;
	}
	c[i] = cur + 48;
	}
	}
void mult10(char* a, int n) {
		int l1 = strlen(a);
		if (l1 == 1 && a[0] == 48)
		{
			return ;
		}
		for (int i = l1; i < l1 + n; ++i)
		{
			a[i] = 48;
		}
		a[l1 + n] = 0;
}
void karatsuba_mult(char a[],char b[], char c[]){
		int i, n=strlen(a);
		if (n == 1)
		{
		int res = (a[0] - 48) * (b[0] - 48);
		if (res < 10) {
			c[0] = res + 48;
			}
		else
			{
			c[0] = (res / 10) + 48;
			c[1] = (res % 10) + 48;
			}
		}
	else{

		char* p,*q,*r,*s,*h,*k,*hr,*pq,*ks,*hkrs,*l,*t;
		p=(char*)malloc(max_digits *(sizeof(char)));
		l=(char*)malloc(max_digits *(sizeof(char)));
		q=(char*)malloc(max_digits *(sizeof(char)));
		k=(char*)malloc(max_digits *(sizeof(char)));
		h=(char*)malloc(max_digits *(sizeof(char)));
		r=(char*)malloc(max_digits *(sizeof(char)));
		ks=(char*)malloc(max_digits *(sizeof(char)));
		s=(char*)malloc(max_digits *(sizeof(char)));
		hr=(char*)malloc(max_digits *(sizeof(char)));
		hkrs=(char*)malloc(max_digits *(sizeof(char)));
		pq=(char*)malloc(max_digits *(sizeof(char)));
		for(i=0;i<(n/2);i++){
			h[i]=a[i];
			k[i]=a[(n/2) + i];
			r[i]=b[i];
			s[i]=b[(n/2) + i];
		}h[(n/2)]='\0';
		k[(n/2)]='\0';
		r[(n/2)]='\0';
		s[(n/2)]='\0';
		printf( "%s %s %s %s\n",h,k,r,s);
		sum(h,k,p);
		printf("%s",p);
		sum(r,s,q);
		printf("%s",q);
		karatsuba_mult(h,r,hr);
		printf("%s",hr);
		karatsuba_mult(k,s,ks);
		printf("%s",ks);
		sum(hr,ks,l);
		printf("%s",l);
		karatsuba_mult(p,q,pq);
		printf("%s",pq);
		sub(pq,l,hkrs);
		printf("%s",hkrs);
		mult10(hr,n);
		printf("%s",hr);
		mult10(hkrs,(n/2));
		printf("%s",hkrs);
		sum(hr,hkrs,c);
		printf("%s",c);
		sum(c,ks,c);
		printf("%s",c);
		free(h);
		free(k);
		free(r);
		free(s);
		free(hkrs);
		free(p);
		free(q);
		free(pq);
		free(ks);
		free(hr);
		free(l);

	}


}
 int main(){
 	char num_1[max_digits],num_2[max_digits],result[max_digits];
	printf("Enter 1st number:");
	scanf(" %s",num_1);
	printf("Enter 2nd number:");
	scanf(" %s",num_2);
	/*sum(num_1,num_2,result);
	printf("%s\n",result);
	sub(num_1,num_2,result);
	printf("%s\n",result);
	mult10(num_1,40);
	printf("%s\n",num_1);*/
	karatsuba_mult(num_1,num_2,result);
	printf(" \t So multiplication of %s and %s is : %s\n\n",num_1,num_2,result);
 	return 0;

 }


