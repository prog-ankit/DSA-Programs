#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
char *queue[100];
int front=-1;
int rear=-1;	
void dequeue(){
		if(front==rear){
			front = -1;
			rear = -1;
		}
		else if(front==N-1)
			front = 0;
		else
			front = front+1;	
}
void enqueue(){
	char *val= (char *)malloc(sizeof(char));
	printf("\nEnter the website to surf: ");
	scanf("%s",val);
	if(rear>=N-1){
		dequeue();
		rear=0;
	}
	else if(rear==front-1){
		dequeue();
		rear = rear+1;
	}
	else
		rear = rear+1;
	queue[rear] = val;
	if(front==-1)
		front=0;
		
		
}

void display(){
	if(rear==-1 || front==-1)
		printf("You have not surfed any website yet.\n");
	else{
		printf("\nThe pages you have visited are \n");
		if(rear<front){
			for(int i=front;i<=N-1;i++){
				printf("%s\n",queue[i]);
			}	
			for(int i=0;i<=rear;i++){
				printf("%s\n",queue[i]);
			}
		}
		else{
			for(int i=front;i<=rear;i++){
				printf("%s\n",queue[i]);
			}	
		}	
	}
}
int main(){
	int op;
	char ch;
	do{
		printf("\nSelect from below: \n");
		printf("1. Add Page of visit.\n");
		printf("2. Display visited pages.\n");
		printf("Your choice is: ");
		scanf("%d",&op);	
		switch(op){
			case 1: 
					enqueue();	
					break;
			case 2: display();
					break;				

			default: printf("Wrong Choice!!");
					break;
		}
		printf("\nDo you want to continue? ");
		scanf(" %c", &ch);
	}while(ch!='N');
	return 0;	
}
