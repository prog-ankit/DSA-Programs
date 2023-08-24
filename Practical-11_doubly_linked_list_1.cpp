#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
   int info;
   struct Node *link;
   struct Node *pre;		
	
}Node;
Node *first=NULL,*newnode,*ptr,*tmp, *pretrav;

void insert_node_begin(int value){
	newnode = (Node *)malloc(sizeof(Node));
	newnode->info = value;
	newnode->pre = NULL;
	newnode->link = first;
	if(first != NULL)
		first->pre = newnode; 
	first = newnode;
	
	printf("Node Inserted.\n\n");
}
void insert_node_end(int value){
	newnode = (Node *)malloc(sizeof(Node));
	newnode->info = value;	
	newnode->link = NULL;
	
	if(first == NULL){
		newnode->pre = NULL;
		first = newnode;
	}
	else{		
		ptr = first;
		while(ptr->link != NULL){
			ptr = ptr->link;
		}
		ptr->link = newnode;
		newnode->pre = ptr;	
	}
	printf("Node Inserted.\n\n");		
}

void delete_node_last(){
	if(first == NULL)
		printf("Linked list is Emplty.\n\n");
	else{
		ptr = first;
		while(ptr->link != NULL){
			ptr = ptr->link;
		}
		tmp = ptr;
		ptr = ptr->pre;
		if(first->link == NULL)
			first = NULL;
		else
			ptr->link = NULL;
		free(tmp);
		printf("Node deleted Success.\n\n");
	}
}

void delete_node_before(int position){
	int i=0;
	if(first == NULL)
		printf("Empty Linked list.\n\n");
	else if(position == 1 || position == 2)
		printf("Cannot delete the node.\n\n");
	else{
		ptr = first;
		while(ptr != NULL){
			if(++i == position){
				tmp = ptr->pre;
				ptr->pre->pre->link = ptr;
				ptr->pre = tmp->pre;
				tmp->link = NULL;
				tmp->pre = NULL;
				free(tmp);
				printf("Node Deleted Success.\n\n");
				break;		
			}
			
		
			ptr = ptr->link;
		}
		if(i != position)
			printf("Node number not found.\n\n");
	}
}
void display(){
	if(first==NULL)
		printf("Empty Linked list.\n\n");
	
	else
	{		
		ptr=first;
		while(ptr!=NULL) 
   		{
			printf("Node data: %d\n",ptr->info);
			printf("Node previous link: %d\n",ptr->pre);
			printf("Node next link: %d\n",ptr->link);
			printf("Node Address: %u\n\n",ptr);
			ptr=ptr->link;	
		}	
	}
}
int main(){
	int ch,data,pos;

	do {
		printf("Enter Choice:\n");
		printf("1. Insert node at Front.\n");
		printf("2. Insert node at End\n");
		printf("3. Delete last Node.\n");
		printf("4. Delete node before specified position.\n");
		printf("5. Display Linked List.\n");
		printf("6. Exit.\n");
		
		scanf("%d",&ch);
		
		switch(ch){
			case 1:	printf("Enter the value you want to insert: ");
					scanf("%d",&data);
					insert_node_begin(data); 
					break;
			case 2:	printf("Enter the value you want to insert: ");
					scanf("%d",&data);
					insert_node_end(data);
					break;
			case 3:	delete_node_last();
					break;
			case 4:	printf("Enter the position before which you want to delete: ");
					scanf("%d",&pos);
					delete_node_before(pos);
					break;
			case 5:	display();
				
		}
		
		
	}while(ch != 7);
	return 0;
}

