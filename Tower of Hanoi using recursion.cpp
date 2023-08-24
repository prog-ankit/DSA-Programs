//Tower of Hanoi 

#include<stdio.h>
void TOH(int n,char rod_1,char rod_2,char rod_3){
	if(n>0){
		TOH(n-1,rod_1,rod_3,rod_2);
		printf("Moved %dth disk %c to %c\n",n,rod_1,rod_3);
		TOH(n-1,rod_2,rod_1,rod_3);
	}
}
int main(){
	int n;
	printf("Enter the number of disks to transfer from rod 1 to rod 3: ");
	scanf("%d",&n);
	TOH(n,'rod1','rod2','rod3');
}
