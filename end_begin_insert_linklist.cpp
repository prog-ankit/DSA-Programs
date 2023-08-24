//program to implement linked list

#include<stdio.h>
#include<malloc.h>
void insert_beg(int);
void insert_end(int);
void display();
typedef struct node {
	int info;
	struct node *link;
} node;
node *first=NULL;
int main() {
	int ch,data;

	do {
		printf("\nEnter Choice:\n");
		printf("1. Insert at Begin\n");
		printf("2. Insert at End\n");
		printf("3. Display Linked List\n");
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
				display();
				break;
		}
	} while(ch!=4);
	
	return 0;
}
void insert_beg(int x)
{
	node *tmp;
	tmp=(node *)malloc(sizeof(node));
	tmp->info=x;
	tmp->link=first;
	first=tmp;
	
   printf("Insert Begin.\n");
}

void insert_end(int k) {
	node *ptr,*ext;

	ptr=(node *)malloc(sizeof(node));
	ptr->info=k;

	if(first== NULL){
		ptr->link = NULL;
		first = ptr;
	}
	else{
		ext=first;
		while(ext->link!=NULL) 
	  	{
			ext=ext->link;
		}
		ptr->link=NULL;
		ext->link=ptr;
	
		printf("Insert End.\n");
	}

}
void display() {
	node *temp=first;
	while(temp!=NULL) 
   {
		printf("%d\t",temp->info);
		temp=temp->link;
	}

