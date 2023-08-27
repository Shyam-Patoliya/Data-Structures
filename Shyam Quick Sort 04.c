#include<stdio.h>

int partition(int arr[],int low,int high){
    int start=low,pivot=arr[start],end=high,temp;
    while(start<end){
        while(arr[start]<=pivot){
            start++;
        }
        while(arr[end]>pivot){
            end--;
        }
        if(start<end){
            temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
        }
    }
     temp = arr[low];
     arr[low] = arr[end];
     arr[end] = temp;
     return end;
}

void quickSort(int arr[],int low,int high){
    int loc;
    if(low<high){
        loc = partition(arr,low,high);
        quickSort(arr,low,loc-1);
        quickSort(arr,loc+1,high);
    }
}

void main(){
int i,arr[]={89,65,44,55,11};
quickSort(arr,0,5);
for(i=0;i<5;i++){
    printf("%d ",arr[i]);
}
}
