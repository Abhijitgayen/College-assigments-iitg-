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
char* CreateArray(int len)
{
  char* res = (char*)malloc(len *(sizeof(char)));
  return res;
}


void karatsuba(char* x, char* y, char* res)
{
  make_equal_length(x, y);
  int len = strlen(x);
  if (len == 1)
    {
    int val = (x[0] - '0') * (y[0] - '0');
    if (val < 10) {
      res[0] = val + '0';
    }
  else
    {
      res[0] = (val / 10) + '0';
      res[1] = (val % 10) + '0';
    }
  }
  else
  {
    char* xl = CreateArray(len);
    char* xr = CreateArray(len);
    char* yl = CreateArray(len);
    char* yr = CreateArray(len);

    int rightSize = len / 2;
    int leftSize = len - rightSize;

    strncpy(xl, x, leftSize);
    strncpy(xr, x + leftSize);
    strncpy(yl, y, leftSize);
    strncpy(yr, y + leftSize);
    int maxl = 3 * len;
    char* P1 = CreateArray(maxl);
    char* P2 = CreateArray(maxl);
    char* P3 = CreateArray(maxl);

    karatsuba(xl, yl, P1);
    karatsuba(xr, yr, P2);

    char* tmp1 = CreateArray(maxl);
    char* tmp2 = CreateArray(maxl);
    sum(xl, xr, tmp1);
    sum(yl, yr, tmp2);
    karatsuba(tmp1, tmp2, P3);
    sub(P3, P1, P3);
    sub(P3, P2, P3);
    mult10(P3, rightSize);
    mult10(P1, 2 * rightSize);
    sum(P1, P2, res);
    sum(res, P3, res);
   // remove_zeros(res);

    free( xl);
    free( xr);
    free( yl);
    free( yr);
    free( tmp1);
    free( tmp2);
    free( P1);
    free( P2);
    free( P3);
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


