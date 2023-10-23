#include<stdio.h>

int main()
{  
   int flag=0;
	int n;
	printf("Enter the no. of elements");
	scanf("%d",&n);
	int a[n];
   for(int i=0;i<n;i++)
	{
		printf("Enter array element:");
		scanf("%d",&a[i]);
	}
	int data;
	printf("Enter the element to be searched:");
	scanf("%d",&data);
	for(int i=0;i<n;i++)
	{
		if(a[i]==data)
		{
			flag=1;
			printf("Element found at %d index",i);
		}
	}
	if(flag==0)
	{
		printf("Element not found");
	}
	return 0;
}
