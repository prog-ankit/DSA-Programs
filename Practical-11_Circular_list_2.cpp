#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int info;
	struct Node *link;	
	
}Node;
Node *first=NULL,*newnode,*ptr, *trav,*pretrav,*tmp;

void insert_beforenode(int data, int num){
	Node *trav =first;
	newnode=(Node *)malloc(sizeof(Node));
	newnode->info = data;
	int i = 0;
	if(first==NULL)
		printf("No such value exists.\n");	
	else{	
		do{
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
			}while(trav!=first);
			
			if(i != num){
				printf("No node number exists.\n");
			}	
			else{
				printf("Insertion before value success.\n");
			}	
		}
}
void insert_end(int k) {
	newnode=(Node *)malloc(sizeof(Node));
	newnode->info=k;
	newnode->link = first;
	if(first== NULL){
		first = newnode;
		newnode->link = first;
	}
		
	else{
		ptr = first;//11  22 33
		while(ptr->link != first){
			ptr = ptr->link;
		}
		ptr->link = newnode;
	}
	
	printf("Insert End.\n\n");
	

}


//Deletion Starts
void delete_begin(){
	if(first == NULL)
		printf("Linked list does not exist.\n\n");
	else if(first->link == first){
		ptr = first;
		first = NULL;
		free(ptr);

		printf("Node Deleted.\n\n");
	}
	else{
		ptr = trav = first;	
		while(trav->link != first){
			trav = trav->link;
		}
		
		first = first->link;
		trav->link = first;
		free(ptr);
		printf("Node Deleted.\n\n");
	}	
}

void delete_afternode(int nodenum){
	int i=0;
	if(first == NULL)
		printf("Linked list does not exist.\n\n");
	else{
	
		ptr = first;
		
		while(ptr != NULL){
			i++;
			if(i==nodenum){
				if(ptr->link == first){
					printf("No node on %d\n\n",i+1);
					break;	
				}
				else{
					tmp = ptr->link;
					ptr->link = tmp->link;
					free(tmp);
					printf("Node Deleted.\n\n");
					break;
				}
			
			}
			ptr = ptr->link;
		}
	}
	if(i!=nodenum){
		printf("Node Number doesn't Exist.\n\n");
	}
}
//Deletion Ends
void display() {
	if(first==NULL){
		printf("Empty Linked list.\n");
	}
	else
	{		
		Node *traverse=first;
		do{
			printf("Node data: %d\n",traverse->info);
			printf("Node link: %d\n",traverse->link);
			printf("Node Address: %u\n\n",traverse);
			traverse=traverse->link;
		}while(traverse!=first);
	}

}



int main(){
	int ch,data,nodenum,value;

	do {
		printf("Enter Choice:\n");
		printf("1. Insert at End\n");
		printf("2. Insert Before Node number.\n");
		printf("3. Delete from begin\n");
		printf("4. Delete After Node number.\n");
		
		printf("5. Display Linked List\n");
		printf("6. Exit\n\n");
		printf("Your Choice is: ");
		scanf("%d",&ch);

		switch(ch) {
		
			case 1:
				printf("Enter the data for node: ");
				scanf("%d",&data);
				insert_end(data);
				break;
			
			case 2:
				printf("Enter the data for node: ");
				scanf("%d",&data);
				printf("Enter the node number before which you want to insert: ");
				scanf("%d",&nodenum);
				insert_beforenode(data,nodenum);
				break;
			
			case 3:
				delete_begin();
				break;
				
			case 4:
				printf("Enter the node number after which you want to delete: ");
				scanf("%d",&nodenum);
				delete_afternode(nodenum);
				break;
			case 5:
				display();
				break;
		}
	} while(ch<6);
	return 0;	
}

