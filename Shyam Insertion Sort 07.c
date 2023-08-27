#include<stdio.h>

void insertionSort(int arr[],int size){
	int i,key,j;
	for(i=1;i<size;i++){
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}

int main(){
	int i,arr[10];
	printf("Enter elements of array: ");
	for(i=0;i<10;i++){
		scanf("%d",&arr[i]);
	}
	printf("Sorting!\n");
	insertionSort(arr,10);
	for(i=0;i<10;i++){
		printf("%d ",arr[i]);
	}
	
	return 0;
}

