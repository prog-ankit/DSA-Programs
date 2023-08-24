//Implement a program to convert infix notation to postfix notation using stack.
//Operators --> (),^,/,*,+,-,  A+ (B*C-(D/E^F)*G)*H

/*
Trial Expressions are:
	(A+B^(X*Y+Z))/(C+D)-(D*E)
	(a+b/(c-d))*f^e
	a-b+c*d/f/g*h-s+k
	a+b*(c^d-e)^(f+g*h)-i
	(R/(I-T+K))-M*X+(P*Y/Q^S)^D^E-F
	(a+b/(c-d*(x+y/(p+q))))*f^e
*/

#include<stdio.h> 
#include<string.h>
#include<ctype.h>
#include <stdlib.h>
#define N 50
char stack[N];
int TOP = -1;

void push(char opr){	
	if(TOP==N-1)
		printf("Stack Overflow");	
	else{
		TOP = TOP+1;
		stack[TOP] = opr;	
	}
}
int pop(){
	if(TOP==-1) 
		printf("Stack Underflow");	
	else
		return stack[TOP--];
}
int priority(char opr){
//	printf("Operator --> %c\n",opr);
	if(opr==NULL)
		return -1;
		
	else if(opr=='+' || opr=='-')
		return 0;
	
	else if(opr=='*' || opr=='/')
		return 1;
		
	else if(opr=='^')
        return 2;
    
    else if(opr==')'|| opr=='(')
        return 3;
	else
		printf("Invalid operator\n");
}

int main(){
	char expr[100];
	char result[100]={'\0'};

	printf("Enter the infix expression to convert: ");
	scanf("%s",expr); 
	
	char* recieve = strrev(expr);
	for(int j=0;recieve[j]!='\0';j++){
		if(recieve[j] == '(')
			recieve[j] = ')';		
		else if(recieve[j] == ')')
			recieve[j] = '(';	
	}

	for(int i=0,j=0;expr[i]!='\0';i++){
	if(isdigit(expr[i]) || isalpha(expr[i]) )
			    result[j++]=expr[i];            
		else{	
			if(expr[i]==')'){
				while(stack[TOP]!='('){
					result[j++] = pop();
				}
				pop();	
			}
			else{
				while(priority(stack[TOP])>=priority(expr[i])){
						if(stack[TOP]=='(') break;
						else result[j++] = pop();		
				}	
				push(expr[i]);	
			}		
		}		
	}

	//Printing the Stack Elements
	int l = strlen(result);
	for(int i=TOP;i>=0;i--){
		result[l++] = pop();
	}
	printf("Prefix Expression is: ");
	puts(strrev(result));					
}	
