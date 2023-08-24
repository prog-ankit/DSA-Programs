//Program to add n numbers entered by user by Dynamic Memory allocation
#include<stdio.h>
#include<stdlib.h>
int main(){
	int *ptr,n,sum=0;
	
	printf("Enter the number of elements to add: ");
	scanf("%d",&n);
	
	ptr = (int *) calloc(n,sizeof(int));
	
	if(ptr == NULL)
		printf("Memory is not allocated.");	
	else{
		printf("Enter the elements to add: \n");
		for(int i=0;i<n;i++){
			scanf("%d",&ptr[i]);
		}
		for(int i=0;i<n;i++){
			sum+=ptr[i];
		}
		printf("The sum of entered elements are: %d",sum);	
	}	
}
