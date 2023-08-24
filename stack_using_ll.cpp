//implement stack using linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int info;
	struct Node *link;	
	
}Node;
Node *top=NULL,*newnode,*ptr;

void push(int data){
	newnode=(Node *)malloc(sizeof(Node));
	newnode->info = data;
 	
	if(top == NULL){
		newnode->link = top;
		top = newnode;	
	}
	else{
		
		newnode->link = top;
		top = newnode;
	}
	printf("Data pushed.\n\n");
}
void pop(){
	if(top == NULL)
		printf("Stack Underflow.\n\n");
	else{
		ptr = top;
		top = top->link;
		free(ptr);
		printf("Data popped.\n\n");
	}
}
void traverse(){
	if(top== NULL)
		printf("Stack is Empty.\n\n");
	else{
		printf("Data in Stack: \n");
		ptr = top;
		while(ptr != NULL){
			printf("%d\n",ptr->info);
			ptr = ptr->link;
		}
	}
}
int main(){
	int data,ch;
	printf("\nWhat would you like to perform? \n");
	printf("1. PUSH.\n");
	printf("2. POP.\n");
	printf("3. TRAVERSE\n");
	printf("4. Exit.\n");
	scanf("%d",&ch);
	while(ch!=4){
		switch(ch){
			case 1: 
					printf("Enter the data to push into stack: ");
					scanf("%d",&data);
					push(data);
					break;
			case 2: pop();
					break;
			case 3: traverse();
					break;				
			default: printf("Wrong Choice!!");
					break;
		}	
		printf("\nWhat would you like to perform? \n");
		printf("1. PUSH.\n");
		printf("2. POP.\n");
		printf("3. TRAVERSE\n");
		printf("4. Exit.\n");
		scanf("%d",&ch);
	}
}


