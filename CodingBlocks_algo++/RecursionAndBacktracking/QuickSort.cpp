#include<iostream>
using namespace std;


int  partition(int *a,int s,int e){
	int i=s-1;
	int j=s;
	int pivot=a[e];
	for(;j<e;j++){
		if(a[j]<=pivot){
			i++;
			swap(a[i],a[j]);
		}
	}

	// Bring the pivot element to its sorted position
	swap(a[i+1],a[e]);
    return i+1;
}

void QuickSort(int a[],int s,int e){
	// Base Case
	if(s>=e){
		return;
	}

	// Select Pivot
	int p = partition(a,s,e);

	// Now call quicksort left and right 
	QuickSort(a,s,p-1);
	QuickSort(a,p+1,e); 
}

int main(){
	int a[]={2,1,5,6,7,5,8};
	int n=sizeof(a)/sizeof(int);
	QuickSort(a,0,n-1);

	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}