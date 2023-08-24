#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *right;
	struct node *left;
}Node;
Node root;
int main(){
	int data;
	
	printf("Enter the data to store in the graph: ");
	scanf("%d",&data);
	
	root = (struct node*)malloc(sizeof(struct node));
	
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	
	printf("Data part is %d",root->data);
	
}




