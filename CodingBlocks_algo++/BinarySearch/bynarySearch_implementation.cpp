#include<iostream>
using namespace std;

int binarySearch(int arr[],int n,int Key){
	int s=0,e=n-1;
	int mid;
	while(s<=e){
		mid=(s+e)/2;
		if(arr[mid]==Key){
			// Found
			return mid;
		}

		// the element may be in the left of mid
		else if(arr[mid]>Key){
			e=mid-1;
		}
		// the element may be in the right of mid
		else{
			s=mid+1;
		}
	}
	return -1;

}

int main(){
	int arr[]={1,3,5,10,12,15,17};
	int n=sizeof(arr)/sizeof(int);
	int Key;
	cin>>Key;
	int searchIndex=binarySearch(arr,n,Key);
	if(searchIndex==-1){
		cout<<Key<<" is not present!"<<endl;
	}
	else{
		cout<<" The index of the element is:"<<searchIndex<<endl;
	}
}