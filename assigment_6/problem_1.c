#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define null INT_MIN
//linear probing key creat function
int probing(int table[], int i, int index)
{
    if (table[index + i] == null)
        return (index + i);
    else
        return -1;
}
int seach_hash_table(int table[], int data, int size)
{
    int i, key, index;
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

void insert_In_table(int table[], int size, int data)
{
    int i, key, index;
    index = data % size;
    index = (index >= 0) ? index : (index + size);
    for (i = 0; i < size; i++)
    {
        key = probing(table, i, index);
        // printf("\n\t for %d key is%d",data ,key);
        if (key != -1)
        {
            table[key % size] = data;
            break;
        }
    }
}
int main()
{

    FILE *fptr;
    fptr = fopen("test.txt", "r");
    if (fptr == NULL)
    {
        printf("\n\n\tError....I am not able to read this file\n\n");
        return 0;
    }
    else
    {
        int DAta;
        int size = 0;
        while (!feof(fptr))
        {
            fscanf(fptr, "%d", &DAta);
            size++;
        }
        printf("\n\n size is %d", size - 1);
        rewind(fptr);
        size += 10;
        int hash_table[size];
        int j; //initialize the hash table
        for (j = 0; j < size; j++)
        {
            hash_table[j] = null;
        }
        long long int i = 0;
        int val[size];
        int num;
        int size_arry = size - 10;
        int arr[size_arry];
        while (!feof(fptr))
        {
            fscanf(fptr, "%d", &num);
            arr[i] = num;
            i++;
            insert_In_table(hash_table, size, num);
        }

        fclose(fptr);
        int t, s = 0;
        for (t = 3; t <= 10; t++)
        {
            for (i = 0; i < size_arry; i++)
            {
                int y = t - arr[i];
                if (seach_hash_table(hash_table, y, size))
                {
                	printf("\n\t pair is (%d %d)",arr[i],y);
                    s++;
                    break;
                }
            }
        }
        printf("\n\ttotal No of such possible is :%d\n\n", s);
    }
    /*int size=10;
    int hash_table[size];
    int j;//initialize the hash table
        for(j=0;j<size;j++){
            hash_table[j]=null;
        }
    insert_In_table(hash_table, size, -12);
    insert_In_table(hash_table, size, -2);
    insert_In_table(hash_table, size, -82);
   	insert_In_table(hash_table, size, 22);
     print_hash_table(hash_table,size);*/
    return 0;
}
