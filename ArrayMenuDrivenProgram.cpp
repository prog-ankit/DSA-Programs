#include<stdio.h>

void display(int a[], int n){
	printf("Elements are as follows: \n");
	for(int i=0;i<n;i++)
		printf("%d\n",a[i]);
}
int main(){
	int arr[100],n,ch;
	
	printf("\nWhat would you like to perform? \n");
	printf("1. Initialize Array.\n");
	printf("2. Insert into Array.\n");
	printf("3. Remove Element\n");
	printf("4. Clear Array\n");
	printf("5. Count Elements\n");
	printf("6. Search Element in array.\n");
	printf("7. Display Array.\n");
	printf("8. Sorting.\n");
	printf("9. Find Duplicate Elements	\n");
	printf("10. Modify Element\n");
	printf("11. Replace values in array\n");
	printf("12. Exit.\n");
	
	scanf("%d",&ch);
	while(ch!=12){
		switch(ch){
			case 1: initialize_array(a,n);
					break;
			case 7: display_array(a,&n);
					break;
		/*	case 3: sort(a,&n);
					break;				
			case 4: search(a,&n);
					break;
			case 5: display(a,&n);
					break;	*/		
			default: printf("Wrong Choice!!");
					break;
		}
		printf("\nWhat would you like to perform? \n");
		printf("1. Initialize Array.\n");
		printf("2. Insert into Array.\n");
		printf("3. Remove Element\n");
		printf("4. Clear Array\n");
		printf("5. Count Elements\n");
		printf("6. Search Element in array.\n");
		printf("7. Display Array.\n");
		printf("8. Sorting.\n");
		printf("9. Find Duplicate Elements	\n");
		printf("10. Modify Element\n");
		printf("11. Replace values in array\n");
		printf("12. Exit.\n");
	
	scanf("%d",&ch);	
	}
}
