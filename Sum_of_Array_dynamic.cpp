//Program to add the n numbers enter by user.
#include<stdio.h>
int main(){
	int arr[50],sum=0,n;
	printf("Enter the number of elements in an array: ");
	scanf("%d",&n);
	
	printf("Enter the array elements: \n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	for(int i=0;i<n;i++){
		sum +=arr[i];
	}
	printf("Sum of all Array elements: %d",sum);
}
