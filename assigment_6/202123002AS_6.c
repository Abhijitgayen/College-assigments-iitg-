// Assigment - 6 BY Abhijit Gayen Roll NO-202123002
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define null LLONG_MIN
long long int probing(long long int table[], long long int i, long long int index)
{
    if (table[index + i] == null)
        return (index + i);
    else
        return -1;
}
//Search data in the heash file
int searCHhashTableMain(long long int table[], long long int data, long long int size)
{
    long long int i, key, index;
    index = data % size;
    index = (index >= 0) ? index : (index + size);
    for (i = 0; i < size; i++)
    {
        key = (index + i) % size;
        //printf("\n\tfor %d search key is%d",data,key);
        if (key != -1)
        {
            if (table[key % size] == data)
            {
                return 1;
                break;
            }
        }
    }
    return 0;
}
//insert data in the Hash TAble
void insert_In_table(long long int table[], long long int size, long long int data)
{
    long long int i, key, index;
    index = data % size;
    index = (index >= 0) ? index : (index + size);
    for (i = 0; i < size;)
    {
        key = probing(table, i, index);
        // printf("\n\t for %d key is%d",data ,key);
        if (key != -1)
        {
            table[key % size] = data;
            break;
        }
        i = i + 1;
    }
}
main()
{
    FILE *FliPt;
    //FliPt=fopen("test.txt", "r");
    FliPt = fopen("test.txt", "r");
    if (FliPt == NULL)
    {
        printf("\n\n\tError....I am not able to read this file\n\n");
        return 0;
    }
    else
    {
        long long int DAta;
        long long int size = 0;
        while (!feof(FliPt))
        {
            fscanf(FliPt, "%d", &DAta);
            size++;
        }
        printf("\n\n size is %d\n", size - 1);
        rewind(FliPt);
        long long int ARrySize = size;
        long long int HAshsize = 10 * size; //for challane.txt We need to choose big multiple you choose small it take more time to search
        printf("\n\n size is hash table %d\n", HAshsize);
        long long int *hashTableMain = (long long int *)malloc(HAshsize * sizeof(long long int));
        long long int j;
        //initialize the hash table
        for (j = 0; j < HAshsize; j++)
        {
            hashTableMain[j] = null;
        }
        long long int i = 0;
        long long int num;
        long long int *arr = (long long int *)malloc(ARrySize * sizeof(long long int));
        //here insert data form file to array and hash table
        while (!feof(FliPt))
        {
            fscanf(FliPt, "%lld", &num);
            arr[i] = num;
            i++;
            insert_In_table(hashTableMain, size, num);
        }

        fclose(FliPt);
        long long int t;
        long long int s = 0;
        for (t = -100; t <= 100; t++)
        {
            for (i = 0; i < ARrySize; i++)
            {
                long long int y = t - arr[i];
                if (searCHhashTableMain(hashTableMain, y, size))
                {
                    printf("\n\tfor %d pair is (%d , %d)", t, arr[i], y);
                    s++;
                    break;
                }
            }
        }

        printf("\n\ttotal No of such posible is :%lld\n\n", s);
    }
    return 0;
}
