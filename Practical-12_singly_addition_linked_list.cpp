#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int info;
	struct node *link;
}Node;
Node *firstA= NULL,*firstB= NULL,*firstC= NULL, *newnode, *ptrA, *ptrB, *ptrC, *tmpA, *tmpB, *tmpC;
int countA=0,countB=0;
void insertintoA(int data){	
	newnode = (Node *) malloc(sizeof(Node));
	newnode->info = data;
	newnode->link = NULL;
	
	countA++;
	if(firstA == NULL)
		firstA = tmpA = newnode;
	else{
		tmpA->link = newnode;
		tmpA = newnode;
	}
}

void insertintoB(int data){	
	newnode = (Node *) malloc(sizeof(Node));
	newnode->info = data;
	newnode->link = NULL;
	
	countB++;
	if(firstB == NULL)
		firstB = tmpB = newnode;
	else{
		tmpB->link = newnode;
		tmpB = newnode;
	}
}

void add(){
	int count=0;

	tmpC = NULL;
	firstC = NULL;

	newnode->link = NULL;
	if(countA != countB)
		printf("Addition Not possible.\n\n");
	else{
		ptrA = firstA;
		ptrB = firstB;
		while(count != countA){
		
			newnode = (Node *) malloc(sizeof(Node));
			newnode->info = ptrA->info + ptrB->info;
			newnode->link = NULL;
		
			if(firstC == NULL)
				firstC = tmpC = newnode;	
			else{
				tmpC->link = newnode;
				tmpC = tmpC->link;		
			}
			
			
		
			count++;
			ptrA = ptrA->link;
			ptrB = ptrB->link;
		}
	}	
}


void display_result(){
	ptrC = firstC;

	if(firstC == NULL)
		printf("No elements to add.\n\n");
	else{	
		while(ptrC != NULL){
			printf("%d -> ",ptrC->info);	
			ptrC = ptrC->link;
		}
		printf("\n");
	}	
}


int main(){
	int choice, data;
	
	do{		
		printf("Enter your choice: \n");
		printf("1. Insert value in 1st linked list.\n");
		printf("2. Insert value in 2nd linked list.\n");
		printf("3. Perform addition.\n");
		printf("4. Display the result.\n");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
					printf("Enter the element to insert: ");
					scanf("%d",&data);
					insertintoA(data);
					break;
			case 2:
					printf("Enter the element to insert: ");
					scanf("%d",&data);
					insertintoB(data);
					break;
					
			case 3:
					add();
					break;
			case 4:
					display_result();
					break;
		}
	
	
	}while(choice<5);
	
}
