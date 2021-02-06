// Assigment-4 (problem-2) By Abhijit Gayen (Roll No-202123002) Using Stact(using array)
#include <stdio.h> 
#include<stdlib.h>//for Dynamic Array
#define maxS 1000 //Here i define the of the lenght of Stack 

char*StaCk;
int StaCk_top = -1;//Stack Pointer
//push function of stact
void Push_StaCk_DatA(char x){
    StaCk[++StaCk_top] = x;
}
//pop function of stact
char Pop_StaCk_DatA(){
    if(StaCk_top == -1)
        return -1;
    else
        return StaCk[StaCk_top--];
}
//here i fix the pionter to the end element of the file 
//and for each line i call a stack data stracture and store all element from  right to left
// and end of the line i print this stack
void tailDataOfFile(FILE* file_pt, int nup){ 
	int counum = 0;
	char chR; 
	unsigned long long pos; 
	fseek(file_pt, 0, SEEK_END);//make a pointer to the last element of the file
	pos=ftell(file_pt);
	printf("\n\t\t no of character in this file is : %d \n\n",pos);
	//fseek(file_pt,pos,SEEK_SET);
	printf("%d lines From last line to %d'th line are :\n",nup,nup);
	do{
	fseek(file_pt,--pos,SEEK_SET);
	chR=fgetc(file_pt);
	if(chR=='\n'){//this the position of line break
	if(StaCk_top!=-1){
	printf("\tline %d : ",counum+1);
	while(StaCk_top != -1)
    {
        printf("%c",Pop_StaCk_DatA());
    }
    printf("\n");
    counum++;
	}}
	else{
		Push_StaCk_DatA(chR);	
	}

	}while(counum!=nup && chR!=EOF);
	
	
	
	fclose(file_pt);
	
}
int main() 
{ 
	StaCk=(char*)malloc(maxS*sizeof(char));
	FILE* Fp_Test;
	int nu;
	char st[16] ;
	printf("Enter the file name :");
	scanf(" %s",st);
	printf("Enter the value of k:");
	scanf("%d",&nu);
	Fp_Test = fopen(st, "r"); 
	if (Fp_Test == NULL) 
	{ 
		printf("Error while opening file");  
	} 
	else{
		tailDataOfFile(Fp_Test, nu);
		fclose(Fp_Test); }

	return 0; 
} 

