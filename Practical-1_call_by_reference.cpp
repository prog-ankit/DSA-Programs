//Call by reference 
#include<stdio.h>
void swap(int& first, int& second){
	int tmp = first;
	first = second;
	second = tmp;
}
int main(){
	int a,b;

	printf("Enter any two number: \n");
	scanf("%d %d",&a,&b);
	
		
	printf("Before Swapping- \n");
	printf("Value of a: %d\n",a);
	printf("Value of b: %d\n\n",b);	
	swap(a,b);
	printf("After Swapping- \n");
	printf("Value of a: %d\n",a);
	printf("Value of b: %d\n\n",b);	
}
