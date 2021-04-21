/* Assigment-9 --By Abhijit Gayen Roll No- 202123002*/
/*Subject- Edit Distance*/
#include <bits/stdc++.h>
using namespace std;
#define SIZE 100

#define BIGNUM 10000
#define copCos 0 /*cost to copy*/
#define inserCos 1  /*cost to insert*/
#define replacCos 1  /*cost to replace*/
#define deletCos 1  /*cost to delete*/
#define twiddlCos 1   /*cost to twiddle*/
#define kilCos 1 /*cost to kill rest part of str1*/

int EditDis(char *s1, char *s2)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    // creating minheap for easly find the minimum element
    int d, c;
    int m = strlen(s1);
    int n = strlen(s2);
    int mainTable[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        mainTable[i][0] = i;
    }
    for (int j = 0; j <= n; j++)
    {
        mainTable[0][j] = j;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                d = mainTable[i - 1][j - 1] + copCos; /*copy cost*/
            else
                d = BIGNUM; /*replace cost */
            if ((i >1 ) && (j > 1) && (s1[i-1] == s2[j-2]) && (s1[i-2] == s2[j-1]))
            {   
                c = mainTable[i-2][j-2] + twiddlCos;
            }
            else
            {
                c = BIGNUM;
            }
            pq.push(d);
            pq.push(c);
            pq.push(mainTable[i - 1][j - 1] + replacCos);/*for replace cost*/
            pq.push(mainTable[i - 1][j] + inserCos); /* for insert cost*/
            pq.push(mainTable[i][j - 1] + deletCos); /*for delete cost*/
            mainTable[i][j] = pq.top();
            // getting the top element form this minHeap
            while (!pq.empty())
            // make empty the piority queue
            {
                pq.pop();
            }
        }
    }
     /*for( int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                     printf("  %d",mainTable[i][j]);
             }printf("\n");
        }*/
    for(int i=0;i<=m-1;i++){
            if(mainTable[i][n]+ kilCos < mainTable[m][n]){
                mainTable[m][n]= mainTable[i][n]+ kilCos;
            // need to see here
            }
        }
     /*  printf("----\n");
    for( int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
                printf("  %d",mainTable[i][j]);
            }printf("\n");
        }*/
        return mainTable[m][n];
}
 
int main()
{
    int test;

    scanf("%d", &test);

    while (test--)
    {
        char stra[SIZE];
        char strb[SIZE];

        scanf("%s", stra);
        scanf("%s", strb);
        printf("\tTest %d\n", test);
        printf("-------------\n");
        printf("Minimum cost to convert '%s' into '%s' is %d\n\n", stra, strb, EditDis(stra, strb));
    }

    return 0;
}