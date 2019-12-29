// Cumulative Sum approach

#include<iostream>
using namespace std;
void sumSubarray(int arr[],int cs[],int n){
	int currentSum=0,maxSum=0;
    int leftIndex=-1,rightIndex=-1;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			currentSum=0;
			currentSum=cs[j]-cs[i-1];
			//cout<<currentSum<<",";
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
	int n;
	cin>>n;
	int arr[1000],cs[1000]={0};
	// For cumulative sum array the first element is initialized separately. 
	cin>>arr[0];
	cs[0]=arr[0];
	// Then the rest of the elements are inserted.
	for(int i=1;i<n;i++){
		cin>>arr[i];
		cs[i]=cs[i-1]+arr[i];
	}
	//int n=sizeof(arr)/sizeof(int);
	sumSubarray(arr,cs,n);
	return 0;
}
