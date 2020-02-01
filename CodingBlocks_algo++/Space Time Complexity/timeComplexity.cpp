#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std;

int a[100000000];

void bubbleSort(int *a,int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-2;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
}

int main(){
	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		a[i] = n-i;
	}
	clock_t startTime=clock();
	sort(a,a+n);
	clock_t endTime=clock();
	cout<<"For Inbuilt Sort:"<<(endTime-startTime)<<endl; // In mili seconds 
	startTime=endTime=0;
	startTime = clock();
	bubbleSort(a,n);
	endTime = clock();
	cout<<"For Bubble Sort:"<<(endTime-startTime)<<endl;
	/*	
    for(int i=0;i<n;i++)
	   cout<<a[i]<<" ";
	   */
	return 0;
}