//Menu Driven Stack Operations
#include<stdio.h>
int TOP=-1;
int count=0;
int stack[100];
void push(int n){
	int value;
	if(TOP==n-1)
		printf("Stack Overflow.\n");
	else{
		printf("Enter the value to insert into stack: ");
		scanf("%d",&value);
		TOP = TOP+1;
		stack[TOP] = value;	
		count++;
		printf("%d is pushed into Stack.\n",value);	
	}
}
void pop(){
	if(TOP==-1)
		printf("Stack Underflow.\n");	
	else{
		printf("Popped element from the stack is %d",stack[TOP]);
		TOP = TOP-1;
		count--;
	}
}
void display(){
	if(TOP == -1)
		printf("Stack is Empty.\n");
	else{
		printf("Present Stack elements are as follows: \n");
		for(int i=TOP;i>=0;i--){
			printf("%d\n",stack[i]);
		}	
	}
}
void peek(){
	if(TOP == -1)
		printf("Stack is Empty.\n");
	else
		printf("Peek Element is %d\n",stack[TOP]);
}

void peep(){
 	int s;
	printf("\nEnter position to peep:->");
	scanf("%d",&s);
	if(TOP-s<=-1)
	   	printf("\nThe Stack is Overflow...\n");
   else
     printf("\nThe Element is:->%d",stack[TOP-s]);
   
}
void modify(){
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
			stack[pos] = value;
			printf("Value is Modified.\n");
		}	
	}	
}
void count_stack(){
	printf("\nNumber of Elements in stack are %d\n",count);
}
int main(){
	int n,ch;
	printf("Enter the size of stack: ");
	scanf("%d",&n);
	printf("\nWhat would you like to perform? \n");
	printf("1. PUSH.\n");
	printf("2. POP.\n");
	printf("3. DISPLAY\n");
	printf("4. PEEK\n");
	printf("5. PEEP.\n");
	printf("6. Change.\n");
	printf("7. Count.\n");
	printf("8. Exit.\n");
	printf("Your choice is: ");
	scanf("%d",&ch);
	while(ch!=8){
		switch(ch){
			case 1: push(n);
					break;
			case 2: pop();
					break;
			case 3: display();
					break;				
			case 4: peek();
					break;	
			case 5: peep();
					break; 
			case 6: modify();
					break;
			case 7: count_stack();
					break;
			default: printf("Wrong Choice!!");
					break;
		}	
		printf("\nWhat would you like to perform? \n");
		printf("1. PUSH.\n");
		printf("2. POP.\n");
		printf("3. DISPLAY\n");
		printf("4. PEEK\n");
		printf("5. PEEP.\n");
		printf("6. Change.\n");
		printf("7. Count.\n");
		printf("8. Exit.\n");
		printf("Your choice is: ");
		scanf("%d",&ch);
	}
}
