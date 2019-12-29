#include<iostream>
using namespace std;

void insertionSort(int arr[],int n){
	for(int i=1;i<n;i++){
		int j=i-1,num=arr[i];
		for( ;j>=0 && arr[j]>num ;j--){
            arr[j+1]=arr[j];
		}
		arr[j+1]=num;
	}
}

int main(){
	int arr[]={4,1,2,0,3};
	int n= sizeof(arr)/sizeof(int);
	insertionSort(arr,n);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}