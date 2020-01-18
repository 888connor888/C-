#include<iostream>
using namespace std;

int LinearSearch(int *a,int i,int n,int Key){
	// Base Cases
	if(i==n){
		return -1;
	}
	if(a[i]==Key){
		return i;
	}
	// Recursive call
	return LinearSearch(a,i+1,n,Key);
}

int main(){
	int a[]={1,3,2,5,6,9};
	int n=sizeof(a)/sizeof(int);
	int Key;
	cin>>Key;
	cout<<LinearSearch(a,0,n,Key)<<endl;
	return 0;
}