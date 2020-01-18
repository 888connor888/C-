#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

void BubbleSort(int *a,int n){
	// Base Case
	if(n==1){
		return;
	}

	//Sort 1 element then call for the rest
	for(int i=0;i<=n-2;i++){
		if(a[i]>a[i+1]){
			swap(a[i],a[i+1]);
		}
	}
	BubbleSort(a,n-1);    
}

// Using only recursion
void BubbleSort2(int *a,int j,int n){
	// Base Cases
	if(n==1){
		return;
	}
	if(j==n-1){
		return BubbleSort2(a,0,n-1);
	}

	//Recursive Case
	if(a[j]>a[j+1]){
		swap(a[j],a[j+1]);
	}
	BubbleSort2(a,j+1,n);
	return;
}


int main(){
	int a[]={5,4,3,2,1};
	int n=5;
	BubbleSort(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}