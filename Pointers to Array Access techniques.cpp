#include<stdio.h>
int main(){
	int a[5]={6,2,3,4,5},*p;
	p=&a[0];
	for(int i=0;i<5;i++){
		printf("%d\n",p+i);
	}
	
	printf("Having *(i+p)\n");
	for(int i=0;i<5;i++){
		printf("%d\n",*(i+p));
	}
	
	printf("Having *(p+i)\n");
	for(int i=0;i<5;i++){
		printf("%d\n",*(p+i));
	}
	
	printf("Having p[i]\n");
	for(int i=0;i<5;i++){
		printf("%d\n",p[i]);
	}
	printf("Having i[p]\n");
	for(int i=0;i<5;i++){
		printf("%d\n",i[p]);
	}

	return 0;
}
