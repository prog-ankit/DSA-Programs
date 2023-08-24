#include<stdio.h>
#include<conio.h>
int main(){
	int a[100],n,i,ser;
	printf("Enter the number of elements to be added in the array: ");
	scanf("%d",&n);
	
	printf("Enter the elements: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Enter the number to search in the array: ");
	scanf("%d",&ser);
	int flag = 0;
	for(i=0;i<n;i++){
		if(ser == a[i]){
			flag = 1;
			break;
		}
	}
	if(flag==1){
		printf("Element Found at %d position",(i+1));
	}
	else{
		printf("Element not found!!");
	}
	return 0;
}
