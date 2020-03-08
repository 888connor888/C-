#include<iostream>
using namespace std;

void selectionSort(int a[],int n){
	for(int i=0;i<n-1;i++){
		int minIndex=i;
		for(int j=i+1;j<n;j++){
			if(a[j]<a[minIndex]){
				minIndex=j;
			}
		}
		swap(a[i],a[minIndex]);
	}
}

int main(){
	int a[]={5,4,1,2,3};
	int n= sizeof(a)/sizeof(int);
	selectionSort(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
}