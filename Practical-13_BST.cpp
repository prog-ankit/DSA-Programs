#include <stdio.h>
#include <stdlib.h>
typedef struct node {
  int data;
  struct node *next, *prev;
}Node; 
Node *root= NULL,*newnode,*ptr;
Node *insert(){
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("\nEnter value for node: ");
		scanf("%d",&newnode->data);
		newnode->prev=NULL;
		newnode->next=NULL;  
		
		int flag = 0;
		ptr = root;
		if(root == NULL)
			root = newnode;
		else{
			while(flag == 0){
				if(newnode->data < ptr->data){//10 = root = ptr, 6=new, 8=latest
					//8<6
					if(ptr->prev == NULL){
						ptr->prev = newnode;
						flag = 1;
					}
					else
						ptr = ptr->prev;
				}
				else{
					if(ptr->next == NULL){
						ptr->next = newnode;
						flag = 1;
					}
					else
						ptr = ptr->next;
				}				
			}		
		}
		printf("%d is inserted in tree.\n\n",newnode->data);
}
void preOrder(Node *ptr){

    if (ptr == NULL)
        return;
 
    printf("%d ", ptr->data);//10, 8, 5,
    preOrder(ptr->prev);
	preOrder(ptr->next);

}
void postOrder(Node *ptr){
    if (ptr == NULL)
        return;
 
    postOrder(ptr->next);
    postOrder(ptr->prev);
    printf("%d ", ptr->data);
}

void inOrder(Node *ptr){
    if (ptr =	= NULL)
        return;
 	inOrder(ptr->prev);
 	printf("%d ", ptr->data);
    inOrder(ptr->next);
}

int main(){
	int ch,data;
	do{
		printf("Enter your choice: \n");
		printf("1. Insert.\n");
		printf("2. Display in Preorder.\n");
		printf("3. Display in Inorder.\n");
		printf("4. Display in Postorder.\n");
		
		scanf("%d",&ch);
		
		switch(ch){
			case 1:
					insert();
					break;
			case 2:
					printf("Pre-order traversal: \n");
					preOrder(root);
					break;
			case 3:
					printf("In-order traversal: \n");
					inOrder(root);
					break;		
			case 4:
					printf("Post-order traversal: \n");
					postOrder(root);
					break;
		}
	}while(ch != 5);
}
