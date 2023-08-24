//Find GCD of two numbers
#include<stdio.h>
int gcd(int m,int n){
	if(m % n == 0)
		return n;
	else if(m<n)
		return gcd(n,m);
	else 
		return gcd(n,m%n);
		
}
int main(){
	int x,y;
	printf("Enter any two numbers to find their gcd: ");
	scanf("%d %d",&x,&y);
	int ans = gcd(x,y);
	printf("GCD of %d and %d is %d",x,y,ans);
}
