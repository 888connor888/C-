// given a sorted rotated array find the highest element in array using binary search

#include<iostream>
using namespace std;


int main(){
   int a[]={6,7,1,2,3,4,5};
   int n=sizeof(a)/sizeof(int);
   int s=0;
   int e=n-1;
   while(s<=e){
   	int mid=(s+e)/2;
   	if(a[mid]>a[mid+1]){
   		cout<<mid<<" ";
   		break;
   	}
   	if(mid<e && a[mid]<a[mid-1]){
   	    cout<<mid-1<<" ";
   	    break;
   	}
   	if(mid>s && a[s]>=a[mid]){
   		e=mid-1;
   	}
   	else{
   		s=mid+1;
   	}
   }
   if(s>e){
   	cout<<"Pivot element does'nt exist!"<<endl;
   }	
}