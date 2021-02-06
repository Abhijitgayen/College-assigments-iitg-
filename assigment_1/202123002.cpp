/*here i use string of numbers because we are not able to operate the operation add ,subtract, multiple with respect to too large number*/
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <cstdio>
#define MAX 1000
using namespace std;


//for addition and make equal length srting (for Karastasuba multipilication)
void add_zreo(char* a, int n){
        int length_a = strlen(a);
        for (int i = length_a - 1 + n; i >= n; --i)
        {
            a[i] = a[i - n];
        }
        a[length_a + n] = 0;
        for (int i = 0; i < n; ++i)
        {
            a[i] = 48;
        }
}
void sum(char* a, char* b, char* c){
        int length_a = strlen(a);
        int length_b = strlen(b);

        if (length_a < length_b)
        {
            swap(a, b);
            swap(length_a, length_b);
        }

        int add = 0;
        for (int i = length_a - 1,j = length_b - 1; i >= 0; --i, --j)
            {
                int x = a[i] - 48;
                int y =j >= 0 ? b[j] - 48 : 0;

                int cur = x + y + add;

                if (cur >= 10)
                {
                add = 1;
                cur -= 10;
                }
                else
                {
                add = 0;
                }

                c[i] = cur + 48;
            }

        if (add == 1)
        {
            add_zreo(c, 1);
            c[0] = '1';
        }
}

// assume that a > b/*By Abhijit Gayen (Roll NO-202123002*/
void sub(char* a, char* b, char* c){
        int length_a = strlen(a);
        int length_b = strlen(b);


        int s = 0;
        for (int i = length_a - 1,j = length_b - 1; i >= 0; --i, --j)
        {
            int x = a[i] - 48;
            int y =j >= 0 ? b[j] - 48 : 0;

            if (s == 1)
            {
            x--;
            }
            int cur;
            if (x < y)
            {
            cur = x + 10 - y;
            s = 1;
            }
        else
        {
            cur = x - y;
            s = 0;
        }

            c[i] = cur + 48;
        }
}

// this returns a * 10^n
void multiplie_of_10(char* a, int n){
        int length_a = strlen(a);
        for (int i = length_a; i < length_a + n; ++i)
        {
            a[i] = 48;
        }
        a[length_a + n] = 0;
}

char* Create_array(int l){
        char* c = new char[l];// creat adynamic array
        memset(c, 0, l);
        return c;
}
//make equal lenth for currect multiplication
void make_equal_length(char* a, char* b)
{
        int length_a = strlen(a);
        int length_b = strlen(b);
        int n = max(length_a, length_b);
        add_zreo(a, n - length_a);
        add_zreo(b, n - length_b);
}
//removes zreo befor the numbres
void remove_zeros(char* a){
        int length_a = strlen(a);
        int ind = 0;
        while (ind < length_a && a[ind] == 48)
        {
            ++ind;
        }
        for (int i = ind; i < length_a; ++i)
        {
            a[i - ind] = a[i];
        }
        a[length_a - ind] = 0;
}

void karatsuba_multipile(char* x, char* y, char* c)
{
        make_equal_length(x, y);
        int len = strlen(x);
        if (len == 1)
            {
            int val = (x[0] - 48) * (y[0] - 48);
            if (val < 10) {
            c[0] = val + 48;
            }
        else
            {
            c[0] = (val / 10) + 48;
            c[1] = (val % 10) + 48;
            }
        }
        else
        {
            char* xl = Create_array(len);
            char* xr = Create_array(len);
            char* yl = Create_array(len);
            char* yr = Create_array(len);

            int rs = len / 2;
            int ls = len - rs;

            strncpy(xl, x, ls);
            strcpy(xr, x + ls);
            strncpy(yl, y, ls);
            strcpy(yr, y + ls);
            int maxl = 3 * len;
            char* P1 = Create_array(maxl);
            char* P2 = Create_array(maxl);
            char* P3 = Create_array(maxl);

            karatsuba_multipile(xl, yl, P1);
            karatsuba_multipile(xr, yr, P2);

            char* temp_1 = Create_array(maxl);
            char* temp_2 = Create_array(maxl);
            sum(xl, xr, temp_1);
            sum(yl, yr, temp_2);
            karatsuba_multipile(temp_1, temp_2, P3);
            sub(P3, P1, P3);
            sub(P3, P2, P3);
            multiplie_of_10(P3, rs);
            multiplie_of_10(P1, 2 * rs);
            sum(P1, P2, c);
            sum(c, P3, c);
            remove_zeros(c);

            delete[] xl;
            delete[] xr;
            delete[] yl;
            delete[] yr;
            delete[] temp_1;
            delete[] temp_2;
            delete[] P1;
            delete[] P2;
            delete[] P3;
        }
}

int main(void){
        char num_1[MAX], num_2[MAX];
        cout<<"Enter the 1st  numbers: ";
        cin>>num_1;
        cout<<"Enter the 2nd numbers: ";
        cin>>num_2;
        cout<<"\n";

        char* cult = Create_array(MAX);
        karatsuba_multipile(num_1, num_2, cult);
        cout<<"The product of the entered "<<num_1<<" and  "<<num_2<<" is: \n\t"<<cult<<"\n";
        return 0;
}
