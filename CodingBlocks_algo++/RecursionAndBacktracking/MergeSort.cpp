#include<iostream>
using namespace std;

void Merge(int *a,int s,int e){
	int mid=(s+e)/2;

	int i=s;
	int j=mid+1;
	int k=s;
	int temp[100];

	while(i<=mid && j<=e){
		if(a[i]<a[j]){
			temp[k++]=a[i++];
		}
		else{
			temp[k++]=a[j++];
		}

	}
	// Now if some elements of any of the two array is left over 
	while(i<=mid){
		temp[k++]=a[i++];
	}
	while(j<=e){
		temp[k++]=a[j++];
	}

	// Now we need to copy all elements to the original array
	for(int i=s;i<=e;i++)
		a[i]=temp[i];

}

void MergeSort(int a[],int s,int e){
	// Base Case : If there is 1 or 0 elements then we do not need to sort them
    if(s>=e){
    	return;
    }
    // Follow 3 steps 
    // 1.Divide
    int mid=(s+e)/2;
    
    //Recursively sort the two arrays: 1.(s to mid) 2.(mid+1 to e)
    // call merge sort over the two parts
    MergeSort(a,s,mid);
    MergeSort(a,mid+1,e);
    
    // Now merge the two parts
    Merge(a,s,e);
}



int main(){
	int a[1000];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	MergeSort(a,0,n-1);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}