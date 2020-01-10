#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int L[n],R[n];
	int max=a[0];
	for(int i=0;i<n;i++){
		
		
		if(a[i]>max){
			max=a[i];
			L[i]=max;
		}
		L[i]=max;
	}
	int max1=a[n-1];
	for(int i=n-1;i>=0;i--){
		
		
		if(a[i]>max1){
			max1=a[i];
			R[i]=max1;
		}
		R[i]=max1;
	}
	int accumuation=0;
	for(int i=0;i<n;i++){
		accumuation += min(L[i],R[i]) - a[i];
	}
	cout<<accumuation<<endl;
	return 0;


}