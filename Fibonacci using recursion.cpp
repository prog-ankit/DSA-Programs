#include<stdio.h>
int fibo(int n)
{
	if(n == 0 || n == 1)
		return n;
	else
		return(fibo(n-1) + fibo(n-2));
}
int main()
{
	int n, m= 0;
	printf("Enter number of terms to be seen from fibonacci: ");
	scanf("%d", &n);
	printf("Fibonacci series terms are:\n");
	for(int i = 1; i <= n; i++){
		printf("%d\n", fibo(m++));
	}
	return 0;
}

