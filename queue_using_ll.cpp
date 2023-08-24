#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int info;
	struct Node *link;	
	
}Node;
Node *rear=NULL,*front=NULL,*newnode,*ptr;

void enqueue(){
	newnode=(Node *)malloc(sizeof(Node));
	printf("Enter the data to insert into queue: ");
	scanf("%d",&newnode->info);
	
	newnode->link = NULL;
	if(front == NULL){
		front = rear = newnode;
	}
	else{
		rear->link = newnode;
		rear = newnode;
	}
	printf("%d is inserted into queue.\n\n",newnode->info);
}
void dequeue(){
	if(rear == NULL || front == NULL)
		printf("Queue Underflow.\n\n");
	else{
		ptr = front;
		printf("%d is deleted from queue.\n\n",ptr->info);
		front = front->link;
//		if(front == rear)
//			rear = rear->link;
		free(ptr);
	}
	

}
void display(){
	if(rear == NULL || front == NULL)
		printf("Queue is Empty.\n\n");
	else{
		printf("Elements of Queue are: \n");
		ptr = front;
		while(ptr!=NULL){
			printf("%d\n",ptr->info);
			ptr = ptr->link;
		}
	}
}
int main(){
	int ch;
	printf("\nWhat would you like to perform? \n");
	printf("1. Enqueue.\n");
	printf("2. Dequeue.\n");
	printf("3. Display\n");
	printf("4. Exit\n");

	printf("Your choice is: ");
	scanf("%d",&ch);
	while(ch!=4){
		switch(ch){
			case 1: 
					enqueue();
					break;
			case 2: dequeue();
					break;
			case 3: display();
					break;				

			default: printf("Wrong Choice!!");
					break;
		}	
		printf("\nWhat would you like to perform? \n");
		printf("1. Enqueue.\n");
		printf("2. Dequeue.\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("Your choice is: ");
		scanf("%d",&ch);
	}
	return 0;	
}
