//Assigment-10
//by _Abhijit Gayen
//Roll No-202123002
#include <iostream>
#include<string>
#include <cstdio>
using namespace std;
//creat node for the binary tree
// every node has two leaf right and left
typedef struct node
{
    char keyData;
    node *leftSide;
    node *rightSide;
} node;
//add data in the node
node *nodeCreat(char ckey)
{
    node *temp = new node();
    temp->keyData = ckey;
    temp->leftSide = NULL;
    temp->rightSide = NULL;
    return temp;
}
// this fuction is use to uncopress this binary data
void uncompress(string str, node *root)
{
    int i = 0;
    node *temp = root;
    do
    {
        if (temp->rightSide == NULL && temp->leftSide == NULL)
        {
            cout << temp->keyData;
            temp = root;
        }
        if (str[i] == '0')
        {
            temp = temp->leftSide;
        }
        else if (str[i] == '1')
        {
            temp = temp->rightSide;
        }
        i++;
    } while (str[i - 1] != '\0');
}
// this function to  creat this binary tree
int ix = 0;
node *binaryTReeCreat(string v, int below, int up, int s)
{
    if (ix > s)
    {
        return NULL;
    }
    node *head = nodeCreat(v[ix++]);
    if (head->keyData != '*')
    {
        return head;
    }
    int i = below + 1;
    while (v[i] == '*')
    {
        i++;
    }
    head->leftSide = binaryTReeCreat(v, ix, i, s);
    head->rightSide = binaryTReeCreat(v, i, up + 1, s);
    return head;
}
int main()
{
    string preO, comp;
    //cout<<"\nEnter  preorder traversal of the binary tree:";
    getline(cin, preO);
    node *head = binaryTReeCreat(preO, 0, preO.size(), preO.size());
    //cout<<"\t The table is";
    //printTree(head,0 ,5);
    //cout<<"\nEnter the compressed message:";
    getline(cin, comp);
    cout << "\n>>>>>The massege is:>>>>>\n\n";
    uncompress(comp, head);
    cout << "\n";
    return 0;
}