#include<iostream>
using namespace std;

void sumSubarray(int arr[],int n){
	int currentSum=0,maxSum=0;
    int leftIndex=-1,rightIndex=-1;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			currentSum=0;
			for(int k=i;k<=j;k++){
				currentSum+=arr[k];
			}
			cout<<currentSum<<",";
			if(maxSum<=currentSum){
				maxSum=currentSum;
				leftIndex=i;
				rightIndex=j;
			}
		}

	}
	cout<<endl<<"Maximum Subarray sum is:"<<maxSum<<endl;
	cout<<"For subarray:";
	for(int k=leftIndex;k<=rightIndex;k++)
		cout<<arr[k]<<",";
}

int main()
{
	/* code */
	int arr[]={-4,1,3,-2,6,2,-8,-9,4};
	int n=sizeof(arr)/sizeof(int);
	suSmubarray(arr,n);
	return 0;
}
