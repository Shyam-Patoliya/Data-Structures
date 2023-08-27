#include<stdio.h>




int recursive_BS(int arr[],int low, int high, int key)
{
	
	while(low<=high){
		int mid=(low+high)/2;
		if(arr[mid]==key){
			return mid;
		}
		else if(key>arr[mid]){
			return recursive_BS(arr,mid+1,high,key);
		}
		else{
			return recursive_BS(arr,low,mid-1,key);
		}
	}


}

void main(){
	int arr[5],low,high,key,i,mid;
	printf("Enter the elements:\n");
	for(i=0;i<5;i++){
		scanf("%d",&arr[i]);
	}
	low=0;
	high=4;
	printf("Enter the key to find:");
	scanf("%d",&key);
	
	int position = recursive_BS(arr,low,high,key);
	printf("Key found at index:%d",position);
	
}
