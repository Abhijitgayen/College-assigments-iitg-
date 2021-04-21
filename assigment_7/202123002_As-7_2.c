#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	int val;
	struct Node *lefsi;
	struct Node *righsi;
} Data;
int HIght(Data *node)
{
	if (node == NULL)
	{
		return 0;
	}
	int lefsiMaxHight = 1 + HIght(node->lefsi);
	int righsiMaxHight = 1 + HIght(node->righsi);
	return (lefsiMaxHight > righsiMaxHight) ? lefsiMaxHight : righsiMaxHight;
}
void printNode(Data *node, int level)
{
	if (node != NULL && level == 0)
	{
		printf("%d", node->val);
	}

	else if (node != NULL)
	{
		printNode(node->lefsi, level - 1);
		printf("   ");
		printNode(node->righsi, level - 1);
	}
}
void preOderTrEEPrint(Data *node)
{
	int i;
	int levCou = HIght(node);
	for (i = 0; i < levCou; i++)
	{
		int j;
		for (j = 0; j < levCou - i; j++)
		{
			printf("   ");
		}
		printNode(node, i);
		for (j = levCou - i; j < 2 * (levCou - i); j++)
		{
			printf("   ");
		}
		printf("\n\n\n");
	}
}
Data *Insert(Data *head, int data)
{
	if (head == NULL)
	{
		Data *temp;
		temp = (Data *)malloc(sizeof(Data));
		temp->val = data;
		temp->lefsi = NULL;
		temp->righsi = NULL;
		head = temp;
	}
	else
	{
		if (data < head->val)
			head->lefsi = Insert(head->lefsi, data);
		else if (data == head->val)
			printf("\t Error data already exist in this tree\n");
		else
			head->righsi = Insert(head->righsi, data);
	}
	return head;
}
int main()
{
	Data *head = NULL;
	/*int a,i,data;
	printf("how many data you want to add :");
	scanf("%d",&a);
	for (  i=0;i<a;i++){
		printf("enter the data:");
		scanf("%d",&data);	
		head = Insert(head,data);
	}*/
	FILE *Filepoint;
	Filepoint = fopen("test.txt", "r");
	if (Filepoint == NULL)
	{
		printf("\n\n\tError....I am not able to read this file\n\n");
	}
	else
	{
		int DAta;
		while (!feof(Filepoint))
		{
			fscanf(Filepoint, "%d", &DAta);
			head = Insert(head, DAta);
		}
	}
	printf("\n\nthe Tree is :\n");
	preOderTrEEPrint(head);
	printf("\n\n");
}
