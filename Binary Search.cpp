//Binary Searching
#include<stdio.h>
#include<conio.h>
int main(){
	int a[100],i,n,ser;
	int l=0,h,mid;
	printf("Enter the number of elements to be added in the array: ");
	scanf("%d",&n);
	
	printf("Enter the elements: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Enter the number to search in the array: ");
	scanf("%d",&ser);
	h = n-1;
	int deb = 1;
	while(l<=h){
		mid = (l+h)/2;
		if(a[mid] == ser){
			printf("Element Found");
			break;
		}
		else if(a[mid]<ser)
			l = mid+1;	
		else if(a[mid]>ser)
			h = mid-1;		
	}

	return 0;
}
