/*(1) Insert a node into beginning 
(2) Insert before a node (Node can be a node number or a value)
 (3) Insert after a node (Node can be a node number or a value)
(4)Insert at the end of the list.
(5)Insert into sorted list.
(6)  Delete a node from beginning 
(7) Delete before a node (Node can be a node number or a value)
(8) Delete after a node (Node can be a node number or a value)
 (9)Reverse the list 
(10) Search the given value from the list
 (11) Display.
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int info;
	struct Node *link;	
	
}Node;
Node *first=NULL,*newnode,*ptr, *pretrav;

void insert_afternode(int data, int num){
	Node *trav = first;
	newnode=(Node *)malloc(sizeof(Node));
	newnode->info = data;
	int counter = 0,flag=0;
	while(trav != NULL){
		counter++;
		if(num == counter){
			newnode->link = trav->link;
			trav->link = newnode;
			break;
		}
		trav = trav->link;	
	}

	if(counter != num)
		printf("No such Node number exist.\n");	
	else	
		printf("Insert Success.\n");
	
}
void insert_afterval(int data,int val_choice){
	newnode=(Node *)malloc(sizeof(Node));
	newnode->info=data;
	Node *trav = first;
	int flag = 0;
	if(first== NULL){
		printf("No such value exists.\n");
	}
	else{
		while(trav!=NULL){
			if(trav->info == val_choice){
				newnode->link = trav->link;
				trav->link = newnode;
				flag = 1;
				break;
			}
			trav= trav->link;
		}
		if(flag == 0)
			printf("No such value exists.");		
		else
			printf("Insertion after value Success.\n");	
	}
}

void insert_beforenode(int data, int num){
	Node *trav =first;
	newnode=(Node *)malloc(sizeof(Node));
	newnode->info = data;
	int i = 0;
	if(first==NULL)
		printf("No such value exists.\n");	
	else{	
		while(trav != NULL){
			i++;		
			if(num == 1){
				newnode->link = first;
				first = newnode;
				break;
			}
			else if(i==num){
				newnode->link = pretrav->link;
				pretrav->link = newnode;
				break;	
			}
			pretrav = trav;
			trav= trav->link;	
		}
		if(i != num){
			printf("No node number exists.\n");
		}	
		else{
			printf("Insertion before value success.\n");
		}
	}

	
}
void insert_beforeval(int data,int val_choice){
	newnode=(Node *)malloc(sizeof(Node));
	newnode->info=data;
	int flag=0;
	Node *trav = first;
	
	if(first== NULL){
		printf("No such value exists.\n");
	}
	else{
		while(trav != NULL){
			if(trav->info == val_choice){
				newnode->link = pretrav->link;
				pretrav->link = newnode;
				flag = 1;
				break;
			}
			pretrav = trav;
			trav = trav->link;
		}
	}
			
	if(flag == 1)
		printf("Insertion before value success.\n");
	else
		printf("No such value exists.\n");
	
	
}


void insert_beg(int x){	
	newnode=(Node *)malloc(sizeof(Node));
	newnode->info=x;
	newnode->link=first;
	first = newnode;
	
   printf("Insert Begin.\n");
}
void insert_end(int k) {
	
	newnode=(Node *)malloc(sizeof(Node));
	newnode->info=k;
	newnode->link = NULL;
	if(first== NULL)
		first = newnode;
	
	else{
		ptr = first;
		while(ptr->link !=NULL){
			ptr = ptr->link;
		}
		ptr->link = newnode;
		ptr = newnode;
		printf("Insert End.\n");
	}

}


void display() {
	if(first==NULL){
		printf("Empty Linked list.\n");
	}
	else
	{		
		Node *traverse=first;
		while(traverse!=NULL) 
   		{
			printf("Node data: %d\n",traverse->info);
			printf("Node link: %d\n",traverse->link);
			printf("Node Address: %u\n\n",traverse);
			traverse=traverse->link;	
		}	
	}
}



int main(){
	int ch,data,nodenum,value;

	do {
		printf("\nEnter Choice:\n");
		printf("1. Insert at Begin\n");
		printf("2. Insert at End\n");
		printf("3. Insert After Node number.\n");
		printf("4. Insert After value.\n");
		printf("5. Insert Before Node number.\n");
		printf("6. Insert Before value.\n");
		printf("7. Insertion into sorted list.\n");
		printf("8. Display Linked List\n");
		
		
		printf("9. Exit\n");
		scanf("%d",&ch);

		switch(ch) {
			case 1:
				printf("Enter the data for node: ");
				scanf("%d",&data);
				insert_beg(data);
				break;

			case 2:
				printf("Enter the data for node: ");
				scanf("%d",&data);
				insert_end(data);
				break;
			
			case 3:
				printf("Enter the data for node: ");
				scanf("%d",&data);
				printf("Enter the node number after which you want to insert: ");
				scanf("%d",&nodenum);
				insert_afternode(data,nodenum);
				break;
			case 4:
				printf("Enter the data for node: ");
				scanf("%d",&data);
				printf("Enter the node value after which you want to insert: ");
				scanf("%d",&value);
				insert_afterval(data,value);
				break;
			case 5:
				printf("Enter the data for node: ");
				scanf("%d",&data);
				printf("Enter the node number before which you want to insert: ");
				scanf("%d",&nodenum);
				insert_beforenode(data,nodenum);
				break;
			case 6:
				printf("Enter the data for node: ");
				scanf("%d",&data);
				printf("Enter the node value before which you want to insert: ");
				scanf("%d",&value);
				insert_beforeval(data,value);
				break;
			case 8:
				display();
				break;
		}
	} while(ch!=9);
	return 0;	
}

