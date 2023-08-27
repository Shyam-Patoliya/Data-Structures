#include<stdio.h>

void selectionSort(int arr[],int size){
    int i,j,minpos;
    for(i=0;i<size-1;i++){
        minpos=i;
        for(j=i+1;j<size;j++){
            if(arr[j]<arr[minpos]){
                minpos=j;
            }
        }
        if(minpos!=i){
            int temp=arr[i];
            arr[i]=arr[minpos];
            arr[minpos]=temp;
        }
    }
}

void main(){
    int i,size;
    printf("Enter size of array: ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter elements of array: ");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    selectionSort(arr,size);
    printf("Sorted array: ");
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

