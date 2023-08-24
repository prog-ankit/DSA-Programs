#include<stdio.h>
int front=-1;
int rear=-1;
void enqueue(int queue[],int N){
	if(rear>=N-1)
		printf("Queue Overflow");
	else{
		int val;
		printf("Enter the value to insert into queue: ");
		scanf("%d",&val);
		
		rear = rear+1;
		queue[rear] = val;
		
		if(front==-1)
			front=0;
			
		printf("Value Inserted Successfully.\n");
	}
}
void dequeue(int queue[]){
	if(front==-1 && rear==-1)
		printf("Queue Underflow");
	else{
		if(front==rear){
			front = -1;
			rear = -1;
		}
		else{
			front = front+1;
			printf("Value Removed Successfully.\n");
		}
	
	}
}
void display(int queue[]){
	if(rear==-1 || front==-1)
		printf("Queue is Empty.\n");
	else{
		printf("Elements in Queue are: \n");
		for(int i=front;i<=rear;i++){
			printf("%d\n",queue[i]);
		}
	}

}
int main(){
	
	int size_of_queue,ch;
	printf("Enter the size of queue: ");
	scanf("%d",&size_of_queue);
	
	int queue[size_of_queue];
	
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
					enqueue(queue,size_of_queue);
					break;
			case 2: dequeue(queue);
					break;
			case 3: display(queue);
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
