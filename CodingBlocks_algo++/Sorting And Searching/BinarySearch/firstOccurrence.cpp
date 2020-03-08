#include<iostream>
using namespace std;

int firstOccurrence(int arr[],int n,int Key){
	int s=0,e=n-1;
	int mid,ans=-1;// initialize ans by 1 just in case the element is not present in the array
	while(s<=e){
        mid=(s+e)/2;
        // sligth change from binary search (e=mid-1) because we want to find in the left part
        if(arr[mid]==Key){
          ans=mid;
          e=mid-1;
          // and to find last occurrence we will do(s=mid+1)in place of (e=mid-1)
        }
        else if(arr[mid]>Key){
        	e=mid-1;
        }
        else{
        	s=mid+1;
        }
	}
	return ans;
}

int main(){
	int arr[]={1,2,2,2,2,4,4};
	int n=sizeof(arr)/sizeof(int);
	int first_occurrence=firstOccurrence(arr,n,2);
	cout<<"The first occurrence is:"<<first_occurrence<<endl;
}