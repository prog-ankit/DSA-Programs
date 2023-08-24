#include<stdio.h>
#include<conio.h>
int main(){
	int arr[100],n,tmp;
	printf("Enter the size of Array: ");
	scanf("%d",&n);
	printf("Enter the elements: \n");
	
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i;j++){
			if(arr[j]>arr[j+1]){
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp; 
			}
		}
	}
	for(int i=0;i<n;i++){
		printf("%d\n",arr[i]);
	}
	return 0;
}
