
#include<iostream>
using namespace std;

void waveSort(int arr[],int n){
	for(int i=0;i<n;i+=2){

		// check for left element
		if(i >0 && arr[i-1]>arr[i]){
			swap(arr[i],arr[i-1]);
		}

		// check for left element  
		if(i<=n-2 && arr[i+1]>arr[i]){
			swap(arr[i],arr[i+1]);
		}
	}
}

int main(){
	int arr[]={1,3,4,2,7,8,6,4,1};
	int n=sizeof(arr)/sizeof(int);
	waveSort(arr,n);

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}