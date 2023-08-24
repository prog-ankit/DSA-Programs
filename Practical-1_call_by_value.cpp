/*Program to swap the value of two variables using user defined function
and Call by Value.*/
#include<stdio.h>
void call_by_value(int m,int n){
	int tmp;
	printf("Before Swapping- \n");
	printf("Value of a: %d\n",m);
	printf("Value of b: %d\n\n",n);	
	tmp = m;
	m = n;
	n = tmp;
	printf("After Swapping- \n");
	printf("Value of a: %d\n",m);
	printf("Value of b: %d\n\n",n);	
}
int main() {
	int a,b;
	printf("Enter any two number: \n");
	scanf("%d %d",&a,&b);
	call_by_value(a,b);	
	return 0;
}

