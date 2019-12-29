#include<iostream>
using namespace std;

int main(){
	int arr[1000];
    int n,currentSum=0,maxSum=0;
    cin>>n;
    for(int i=0;i<n;i++)
       cin>>arr[i];
    // Kadane's Algorithm for finding the maximum subarray sum.
    for(int i=0;i<n;i++){
    	currentSum+=arr[i];
    	if(currentSum<0){
    		currentSum=0;
    	}
    	maxSum=max(currentSum,maxSum);
    }
    cout<<"The Maximum sum is:"<<maxSum<<endl;
    }