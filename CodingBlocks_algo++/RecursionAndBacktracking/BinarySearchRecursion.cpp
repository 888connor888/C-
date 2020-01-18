#include<iostream>
using namespace std;

int BinarySearch(int *a,int s,int e,int mid,int Key){
    //Base Cases
	if(s>e){
		return -1;
	}
	if(a[mid]==Key){
		return mid;
	}

	//Recursive Cases
	if(a[mid]>Key){
		return BinarySearch(a,s,mid-1,(s+mid-1)/2,Key);
	}
	else{
		return BinarySearch(a,mid+1,e,(e+mid+1)/2,Key);
	}
}

int main(){
	int a[]={1,3,2,5,6,9};
	int e=sizeof(a)/sizeof(int);
	int Key;
	cin>>Key;
	cout<<BinarySearch(a,0,e,e/2,Key)<<endl;
	return 0;
}