#include<iostream>
using namespace std;

void printSubarray(int arr[],int n){
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int k=i;k<=j;k++){
				cout<<arr[k]<<",";
			}
			cout<<"\t";
		}
		cout<<endl;
	}
} 

int main()
{
	/* code */
	int arr[]={1,2,3,4};
	int n=sizeof(arr)/sizeof(int);
	printSubarray(arr,n);
	return 0;
}