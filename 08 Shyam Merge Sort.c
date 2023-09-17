#include <stdio.h>

void merge(int arr[],int low,int mid,int high){
   int i=low,j=mid+1,k=low,b[high+1];
   while(i<=mid && j<=high){
    if(arr[i]<=arr[j]){
       b[k]=arr[i];
       i++;
    }
    else{
        b[k]=arr[j];
        j++;
    }
    k++;
   }
   if(i>mid){
    while(j<=high){
        b[k]=arr[j];
        j++;
        k++;
    }
   }
   else{
    while(i<=mid){
        b[k]=arr[i];
        i++;
        k++;
    }
   }
   for(k=low;k<=high;k++){
    arr[k]=b[k];
   }
}

void MS(int arr[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        MS(arr,low,mid);
        MS(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
int main(){
    int i,arr[]={5,78,64,12,3};
    MS(arr,0,4);
    for(i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
