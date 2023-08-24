#include<stdio.h>
#include<conio.h>
int main(){
	int arr[100],n,tmp,store;
	int j;
	printf("Enter the size of Array: ");
	scanf("%d",&n);
	printf("Enter the elements: \n");
	
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	for(int i=0;i<n-1;i++){
		tmp = i;
		for(j=i+1;j<n;j++){
			if(arr[tmp]>arr[j]){
				tmp = j;
			}
		}
		store = arr[tmp];
		arr[tmp] = arr[i];
		arr[i] = store;
		
	}
	for(int i=0;i<n;i++){
		printf("%d\n",arr[i]);
	}	
}
