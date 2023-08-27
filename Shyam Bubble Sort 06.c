#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[],int size) {
	int i,j,flag=0;
	for(i=0;i<size-1;i++){
	    flag=0;
	    for(j=0;j<size-i-1;j++){
	        if(arr[j]>arr[j+1]){
	            int temp=arr[j];
	            arr[j]=arr[j+1];
	            arr[j+1]=temp;
	            flag=1;
	        }
	    }
	    if(flag==0){
	        break;
	    }
	}
}

void main(){
    int size,i;
    printf("Enter size of array: ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter elements of array: ");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nSorting the array!");
	bubbleSort(arr,5);
	printf("\nSorted array below!\n");
    for(i=0;i<5;i++){
    	printf("%d ",arr[i]);
    }
}

