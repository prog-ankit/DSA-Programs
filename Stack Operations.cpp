#include<stdio.h>
int TOP=-1;
int stack[100];
//taken as global so that no need to pass in functions

void push(int n){
	int value;
	
	if(TOP==n-1){
		printf("Stack Overflow");
	}
	else{
		printf("Enter the value to insert into stack: ");
		scanf("%d",&value);
		TOP = TOP+1;
		stack[TOP] = value;	
		printf("%d is pushed into stack.\n",value);	
	}
}
void pop(){
	if(TOP==-1)
		printf("Stack Underflow");
	else{
		printf("Popped element from the stack is %d.\n",stack[TOP]);
		TOP = TOP-1;
	}
}
void traverse(){
	if(TOP == -1)
		printf("Stack is Empty");
	else{
		printf("Present Stack elements are as follows: \n");
		for(int i=TOP;i>=0;i--){
			printf("%d\n",stack[i]);
		}	
	}
}
void peep(){
	int element,flag=0;
	int i;
	if(TOP == -1){
		printf("Stack is Empty");
	}
	else{
		printf("Enter the value to search in the stack: ");
		scanf("%d",&element);
		for(i=TOP;i>=0;i--){
			if(stack[i] == element){
				flag=1;
				break;
			}
		}
		if(flag==1)	printf("Element found at %d index",(i+1));	
		else	printf("Element not found!!");
	}
}
void modify(){	
	int x,z;
	if(TOP == -1)
		printf("Stack is Empty.\n");
	else{
		int pos, value;
		printf("Enter the position you want to modify the value: ");
		scanf("%d",&pos);
	
		if(pos>TOP)
			printf("Exceed Position.!\n");
		else{
			printf("Enter the value you want to change: ");
			scanf("%d",&value);
			z=TOP-pos+1;
			stack[z] = value;
			printf("Value is Modified.\n");
		}	
	}	
}

int main(){
	int n,ch;
	
	printf("Enter the size of stack: ");
	scanf("%d",&n);
	
	printf("\nWhat would you like to perform? \n");
	printf("1. PUSH.\n");
	printf("2. POP.\n");
	printf("3. Search.\n");
	printf("4. Change.\n");
	printf("5. TRAVERSE\n");
	printf("6. Exit.\n");
	scanf("%d",&ch);
	while(ch!=6){
		switch(ch){
			case 1: push(n);
					break;
			case 2: pop();
					break;	
			case 3: peep();
					break;	
			case 4: modify();
					break; 
			case 5: traverse();
					break;
			default: printf("Wrong Choice!!");
					break;
		}	
		printf("\nWhat would you like to perform? \n");
		printf("1. PUSH.\n");
		printf("2. POP.\n");
		printf("3. Search.\n");
		printf("4. Change.\n");
		printf("5. TRAVERSE\n");
		printf("6. Exit.\n");
		scanf("%d",&ch);
	}
}
