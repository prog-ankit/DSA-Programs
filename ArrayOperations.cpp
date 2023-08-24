//Array Operations
#include<stdio.h>
void insert(int a[],int *n){
	int pos, value;

	printf("Enter the position: ");
	scanf("%d",&pos);
	pos = pos-1;
	if(pos>*n)
		printf("Value cannot be inserted in this position!!");
	else{
		printf("Enter the value for the position: ");
		scanf("%d",&value);
		for(int i=*n-1;i>=pos;i--)
			a[i+1] = a[i];
		a[pos] = value;
		*n = *n + 1;
		
		printf("%d inserted success.\n",value);
	}
}
void del(int a[],int *n){
	int pos,tem = *n-1;
	printf("Enter the position: ");
	scanf("%d",&pos);
	pos = pos-1;
	if(pos>*n || *n<=0)
		printf("Deletion failed!!");
	else{
		for(int i=pos;i<=tem;i++)
			a[i] = a[i+1];
		*n = *n - 1;
		
		
		printf("Value on %d deleted success.\n",pos);
	}
	
}

void sort(int a[],int *n){
	int store,tmp;
	for(int i=0;i<*n-1;i++){
		tmp = i;
		for(int j=i+1;j<*n;j++){
			if(a[tmp]>a[j])
				tmp = j;
		}
		store = a[tmp];
		a[tmp] = a[i];
		a[i] = store;
	}
	printf("Array is Sorted!!");
}
void search(int a[],int *n){
	int search,flag=0;
	printf("Enter the element to search in the array: ");
	scanf("%d",&search);
	for(int i=0;i<*n;i++){
		if(a[i]==search){
			printf("Element found on position %d",i+1);
			flag=1;
			break;
		}
	}
	if(flag==0)
		printf("Element not found!!");
}
void display(int a[], int *n){
	printf("Elements are as follows: \n");
	for(int i=0;i<*n;i++)
		printf("%d\n",a[i]);
}
int main(){
	int a[100],n,i,ch;
	printf("Enter the size of an array: ");
	scanf("%d",&n);
	printf("Enter the elements of an array: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
	printf("\nWhat would you like to perform? \n");
	printf("1. Insertion.\n");
	printf("2. Deletion.\n");
	printf("3. Sorting\n");
	printf("4. Searching\n");
	printf("5. Display\n");
	printf("6. Exit.\n");
	scanf("%d",&ch);
	while(ch!=6){
		switch(ch){
			case 1: insert(a,&n);
					break;
			case 2: del(a,&n);
					break;
			case 3: sort(a,&n);
					break;				
			case 4: search(a,&n);
					break;
			case 5: display(a,&n);
					break;			
			default: printf("Wrong Choice!!");
					break;
		}
		printf("\nWhat would you like to perform? \n");
		printf("1. Insertion.\n");
		printf("2. Deletion.\n");
		printf("3. Sorting\n");
		printf("4. Searching\n");
		printf("5. Display\n");
		printf("6. Exit.\n");
		scanf("%d",&ch);		
	}
}
