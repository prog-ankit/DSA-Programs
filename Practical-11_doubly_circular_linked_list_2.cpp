#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
   int info;
   struct Node *link;
   struct Node *pre;		
	
}Node;
Node *first=NULL,*newnode,*ptr,*tmp, *pretrav;

void insert_node_begin(int data){
	newnode = (Node *)malloc(sizeof(Node));
	newnode->info = data;

	if(first == NULL){
		newnode->pre = first;
		first = newnode;
		newnode->link = first;
	}
	else{	
		ptr = first;
		while(ptr->link != first){
			ptr = ptr->link;
		}
		newnode->pre = ptr;
		newnode->link = first;
		first->pre = newnode;
		first = newnode;
		ptr->link = first;	
	}
	
	printf("Node Inserted.\n");
}

void insert_node_after(int data, int pos){
	int i=0;
	newnode = (Node *)malloc(sizeof(Node));
	newnode->info = data;

	if(first == NULL)
		printf("Empty Linked List");
	else{
		ptr = first;
		
		do{
			i++;
			if(i == pos){
				ptr->link->pre = newnode;
				newnode->link = ptr->link;
				newnode->pre = ptr;
				ptr->link = newnode;
				printf("Node inserted success.\n\n");
				break;
			}
			ptr = ptr->link;
		}while(ptr->link != first);
		
		if(i != pos)
			printf("Node number not found.\n\n");
	}
}


void insert_value_after(int data, int value){
	
	newnode = (Node *)malloc(sizeof(Node));
	newnode->info = data;
	int flag = 0;
	if(first == NULL)
		printf("Linked List is Empty.\n\n");
	else{
		ptr = first;		
		while(ptr->link != first){
			if(ptr->info == value){
				newnode->link = ptr->link;
				newnode->pre = ptr;
				
				ptr->link = newnode;
				ptr->link->pre = newnode;
				flag = 1;
				break;
			}
			ptr = ptr->link;
		}
		if(flag == 1)
			printf("Node Inserted Success.\n\n");
		else
			printf("Node Inserted Failed.\n\n");
	}
}


void insert_node_before(int data, int pos){
	int i=0;
	newnode = (Node *)malloc(sizeof(Node));
	newnode->info = data;

	if(first == NULL)
		printf("Empty Linked List");
	else if(pos ==1)
		printf("Node Insertion not possible.\n\n");
	else{
		ptr = first;
		do{
			i++;
			if(i==pos){
				newnode->link = ptr;
				newnode->pre = ptr->pre;
				newnode->pre->link = newnode;
				ptr->pre = newnode;
				printf("Node Insert Success.\n\n");
				break;
				
			}
			
			ptr = ptr->link;
		}while(ptr != first);
		
		
		if(i != pos)
			printf("Node number not found.\n\n");
	}
}




void insert_value_before(int data, int value){
	
	newnode = (Node *)malloc(sizeof(Node));
	newnode->info = data;
	int flag = 0;
	if(first == NULL)
		printf("Linked List is Empty.\n\n");
	else{
		ptr = first;		
		do{
			if(ptr->info==value){
				newnode->link = ptr;
				newnode->pre = ptr->pre;
				newnode->pre->link = newnode;
				ptr->pre = newnode;
				flag = 1;
				break;
				
			}
			
			ptr = ptr->link;
		}while(ptr != first);
		
		
		if(flag == 1)
			printf("Node Inserted Success.\n\n");
		else
			printf("Node Inserted Failed.\n\n");
	}
}

void delete_node_last(){
	if(first == NULL)
		printf("Linked list is Emplty");
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

//Deletion Starts
void delete_node_begin(){
	if(first == NULL)
		printf("Linked list is Empty");
	else if(first->link == first){
		ptr = first;
		first = NULL;
		free(ptr);
		printf("Node Deleted Success.\n\n");
	}
	else{
		ptr = tmp =first;
		while(ptr->link != first){
			ptr = ptr->link;
		}
		ptr->link = first->link;
		first->link->pre = first->pre;
		first = first->link;
		free(tmp);

		printf("Node Deleted Success.\n\n");
	}
}
void delete_node_before(int position){
	int i=0;
	if(first == NULL)
		printf("Empty Linked list.\n\n");
	else if(position == 1 or position == 2)
		printf("Cannot delete the node.\n\n");
	else{
		ptr = first;
		do{
			if(++i == position){
				tmp = ptr->pre;
				ptr->pre = tmp->pre;
				tmp->pre->link = ptr;
				free(tmp);
				printf("Node Deleted Success.\n\n");
				break;
			}
			ptr = ptr->link;
		}while(ptr != first);
		
		if(i != position)
			printf("Node number not found.\n\n");
	}
}

void delete_value_before(int val_choice){
	int flag=0;
	if(first == NULL)
		printf("Empty Linked list.\n\n");
	else{
		ptr = first;
		do{
			if(ptr->info == val_choice){
				tmp = ptr->pre;
				ptr->pre = tmp->pre;
				tmp->pre->link = ptr;
				free(tmp);
				flag = 1;
				printf("Node Deleted Success.\n\n");
				
				break;
			}
			ptr = ptr->link;
		}while(ptr != first);
		
		if(flag == 0)
			printf("Node value not found.\n\n");
	}
}

void delete_node_after(int position){
	int i=0;
	if(first == NULL)
		printf("Empty Linked list.\n\n");
	
	else{
		ptr = first;
		do{
			if(++i == position){
				if(ptr->link == first || ptr->link->link == first){
					printf("Node Deletion Failed.\n\n");
				}
				else{
					tmp = ptr->link;
					ptr->link = tmp->link;
					tmp->link->pre = ptr;
					free(tmp);
					printf("Node Deleted Success.\n\n");
					break;	
				}
			}
			ptr = ptr->link;
		}while(ptr != first);
		
		if(i != position)
			printf("Node number not found.\n\n");
	}
}

void delete_value_after(int val_choice){
	int flag=0;
	if(first == NULL)
		printf("Empty Linked list.\n\n");
	else{
		ptr = first;
		do{
			if(ptr->info == val_choice){
				flag = 1;
					
				if(ptr->link == first || ptr->link->link == first){
					printf("Node Deletion Failed.\n\n");
				}
				else{					
					tmp = ptr->link;
					ptr->link = tmp->link;
					tmp->link->pre = ptr;
					free(tmp);
					printf("Node Deleted Success.\n\n");	
				}
				break;	
				
			}
			ptr = ptr->link;
		}while(ptr != first);
		
		if(flag == 0)
			printf("Node Value not found.\n\n");
	}
}

void search_list(int value){
	int i=0;
	if(first == NULL)
		printf("Linked list is empty.\n\n");
	else{
		ptr =first;
		do{
			i++;
			if(ptr->info == value){
				printf("Value found at position=%d.\n\n",i);
				break;
			}
			
			ptr = ptr->link;
		}while(ptr != first);
		
		if(ptr == first)
			printf("Value not found in linked list.\n\n");
	}	
	
}


void display(){
	if(first==NULL)
		printf("Empty Linked list.\n");
	
	else
	{		
		ptr=first;
		do{
			printf("Node data: %d\n",ptr->info);
			printf("Node link: %d\n",ptr->link);
			printf("Node Address: %u\n\n",ptr);
			ptr=ptr->link;
		}while(ptr!=first);
	}
}
int main(){
	int ch,data,pos, value;

	do {
		printf("Enter Choice:\n");
		printf("1. Insert node at Front.\n");
		printf("2. Insert after specified node.\n");
		printf("3. Insert after specified node value.\n");
		printf("4. Insert before specified node.\n");
		printf("5. Insert before specified node value.\n");
	
		printf("6. Delete node from beginning.\n");		
		printf("7. Delete node before specified node position.\n");
		printf("8. Delete node before specified node value.\n");
		printf("9. Delete node after specified node position.\n");
		printf("10. Delete node after specified node value.\n");
		
		printf("11. Search a value in linked list.\n");
		printf("12. Display Linked List.\n");
		printf("13. Exit.\n");
		
		scanf("%d",&ch);
		
		switch(ch){
			case 1:	printf("Enter the value you want to insert: ");
					scanf("%d",&data);
					insert_node_begin(data); 
					break;
			case 2:	printf("Enter the value you want to insert: ");
					scanf("%d",&data);
					printf("Enter the node number after which you want to insert: ");
					scanf("%d",&pos);
					insert_node_after(data, pos);
					break;
			case 3:	printf("Enter the value you want to insert: ");
					scanf("%d",&data);
					printf("Enter the node value after which you want to insert: ");
					scanf("%d",&value);
					insert_value_after(data, value);
					break;
			
			case 4:	printf("Enter the value you want to insert: ");
					scanf("%d",&data);
					printf("Enter the node number before which you want to insert: ");
					scanf("%d",&pos);
					insert_node_before(data, pos);
					break;
			case 5:	printf("Enter the value you want to insert: ");
					scanf("%d",&data);
					printf("Enter the node value before which you want to insert: ");
					scanf("%d",&value);
					insert_value_before(data, value);
					break;
					
					
					
			case 6:	delete_node_begin();
					break;
			case 7:	printf("Enter the position before which you want to delete: ");
					scanf("%d",&pos);
					delete_node_before(pos);
					break;
			case 8:	printf("Enter the node value before which you want to delete: ");
					scanf("%d",&value);
					delete_value_before(value);
					break;
					
			case 9:	printf("Enter the position after which you want to delete: ");
					scanf("%d",&pos);
					delete_node_after(pos);
					break;
			case 10:printf("Enter the node value after which you want to delete: ");
					scanf("%d",&value);
					delete_value_after(value);
					break;
					
			case 11:printf("Enter the value to search in linked list: ");
					scanf("%d",&value);
					search_list(value);
					break;
					 
			case 12: 	display();
						break;
		}
		
		
	}while(ch != 14);
	return 0;
}

