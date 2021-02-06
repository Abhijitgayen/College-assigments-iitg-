//Assigment - 4 (promblem - 1) By Abhijit Gayen (Roll-202123002)
#include<stdio.h>
#include<stdlib.h>//for dynamic array
#define maxS 1000

char* StaCk;//Creat a Stract As a dynamic Array
int StaCk_Top = -1;//Top Of this stack
//PUsh Function of Stact
void push_StaCk_Data(char x){
    StaCk[++StaCk_Top] = x;
}
//POp FuNction of Stact
char pop_stact(){
    if(StaCk_Top == -1)
        return -1;
    else
        return StaCk[StaCk_Top--];
}
//this function help to compare the pioritiy of the operater
int priOpera(char x){
    if(x == '(')
        return -1;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/'||x=='%'||x=='^')
        return 2;
    else
   		return 0;
}
//this function help us to alphabates and Numbers
int cheakAlph(char c){
    if((c>='a'&& c<='z')||(c>='a'&& c<='z')||(c>='0'&& c<='9'))
    return 1;
    else return 0;
}
//this is the main Function
int main(){   
    StaCk=(char*)malloc(maxS*sizeof(char));
    char *expERi;
    expERi=(char*)malloc(maxS*sizeof(char));
    printf("Note: The Given infex Expression need not be fully paranthesized\n");
    printf("Enter the infix : ");
    scanf("%s",expERi);
    printf("\n\tthe postfix expration is : ");
    int i=0;
    while(expERi[i]!='\0')
    {
        if(cheakAlph(expERi[i]))
            printf("%c ",expERi[i]);
            //49-56 use for the peranthisis "()"
        else if(expERi[i] == '(')
            push_StaCk_Data(expERi[i]);
        else if(expERi[i] == ')'){
            char  chR;
            while((chR = pop_stact()) != '(')
                printf("%c ", chR);
        }
        else{
            while(priOpera(StaCk[StaCk_Top]) >= priOpera(expERi[i]))
                printf("%c ",pop_stact());
            push_StaCk_Data(expERi[i]);
        }
        i++;
    }
    //print All operaters that is store in the stack
    while(StaCk_Top != -1)
    {
        printf("%c ",pop_stact());
    }
	printf("\n\n\n");
	return 0;
}
