#include<iostream>
using namespace std;

void countingSort(int arr[],int n){
	int freq[n+1]={0};
	// creating the freq array
	for(int i=0;i<n;i++){
		freq[arr[i]]+=1;
	}
	// using the freq array
	int count=0;
	for(int i=0;i<n;i++){
		if(freq[arr[i]]>0){
		  for(int j=0;j<freq[i];j++){
			 arr[count++]=i;
		    }
	    }
	}

}

int main(){
	int arr[]={3,5,2,6,1,4,3};
	int n=sizeof(arr)/sizeof(int);
	countingSort(arr,n);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}