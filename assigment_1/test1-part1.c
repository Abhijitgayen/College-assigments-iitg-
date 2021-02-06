 #include<stdio.h>
 #include<string.h>
 #include<stdlib.h>
 #define max_digits 100
void swap_str(char *a, char *b){
    char *temp= a;
    a=b;
    b=temp;
}
void add_zeros(char* a, int n)
{
  int lena = strlen(a),i;
  for ( i = lena - 1 + n; i >= n; --i)
  {
    a[i] = a[i - n];
  }
  a[lena + n] = 0;
  for (i = 0; i < n; ++i)
  {
    a[i] = '0';
  }
} 
void make_equal_length(char* a, char* b)
{
  int lena = strlen(a);
  int lenb = strlen(b);
  int n;
  n= lena>lenb? lena:lenb;
  add_zeros(a, n - lena);
  add_zeros(b, n - lenb);
}
 void sum(char* a, char* b, char* res)
{
  int lena = strlen(a);
  int lenb = strlen(b);

  if (lena < lenb)
  {
    swap_str(a, b);
     int temp=lena;
     lena=lenb;
     lenb=temp;
  }

  int toAdd = 0,inda,indb;
  for ( inda = lena - 1, indb = lenb - 1; inda >= 0; --inda, --indb)
    {
        int x = a[inda] - '0';
        int y = indb >= 0 ? b[indb] - '0' : 0;

        int cur = x + y + toAdd;

        if (cur >= 10)
        {
          toAdd = 1;
          cur -= 10;
        }
        else
        {
          toAdd = 0;
        }

        res[inda] = cur + '0';
    }
    res[lena]='\0';

  if (toAdd == 1)
  {
	 char * str=(char*)malloc(max_digits*(sizeof(char)) );
	 int i,j;
	 str[i]='1';
	 for(i=0;res[i]!='\0';i++){
	 	
	 	str[i+1]=res[i];
	 }
	 for(j=0;str[j]!='\0';j++){
	 	res[j]=str[j];
	 }
	 res[strlen(res)]='\0';
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
	}c[l1]='\0';
	}
void mult10(char* a, int n) {
		int l1 = strlen(a),i;
		/*if (l1 == 1 && a[0] == 48)
		{
			return ;
		}*/
		for ( i = l1; i < l1 + n; ++i)
		{
			a[i] = 48;
		}
		a[l1 + n] = '\0';
}
void karatsuba_mult(char a[],char b[], char c[]){
	make_equal_length(a, b);
		int i, n=strlen(a);
		if (n == 1)
		{
		int res = (a[0] - 48) * (b[0] - 48);
		if (res < 10) {
			c[0] = res + 48;
			c[1]='\0';
			}
		else
			{
			c[0] = (res / 10) + 48;
			c[1] = (res % 10) + 48;
			}
			c[2]='\0';
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
		printf("%s\n",p);
		sum(r,s,q);
		printf("%s\n",q);
		karatsuba_mult(h,r,hr);
		printf("%s\n",hr);
		karatsuba_mult(k,s,ks);
		printf("%s\n",ks);
		sum(hr,ks,l);
		printf("%s\n",l);
		karatsuba_mult(p,q,pq);
		printf("%s\n",pq);
		sub(pq,l,hkrs);
		printf("%s\n",hkrs);
		mult10(hr,n);
		printf("%s\n",hr);
		mult10(hkrs,(n/2));
		printf("%s\n",hkrs);
		sum(hr,hkrs,c);
		printf("%s\n",c);
		sum(c,ks,c);
		printf("%s",c);
		/*free(h);
		free(k);
		free(r);
		free(s);
		free(hkrs);
		free(p);
		free(q);
		free(pq);
		free(ks);
		free(hr);
		free(l);*/

	}


}
 int main(){
 	char num_1[max_digits],num_2[max_digits],result[max_digits];
	printf("Enter 1st number:");
	scanf(" %s",num_1);
	printf("Enter 2nd number:");
	scanf(" %s",num_2);
	sum(num_1,num_2,result);
	printf("%s\n",result);
	sub(num_1,num_2,result);
	printf("%s\n",result);
	mult10(num_1,40);
	printf("%s\n",num_1);
//	karatsuba_mult(num_1,num_2,result);
//	printf(" \t So multiplication of %s and %s is : %s\n\n",num_1,num_2,result);
 	return 0;

 }


