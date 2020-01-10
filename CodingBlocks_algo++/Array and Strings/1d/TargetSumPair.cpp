#include<iostream>
#include<algorithm>
using namespace std;

bool mycompare(int a,int b){
	return a<b;
}

 
int main(){
	int n,target;
	int  a[1000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>target;
	sort(a,a+n);
	int l=0,r=n-1;
	while(l<r){
		int sum=a[l]+a[r];
		if(sum==target){
			cout<<a[l]<<" and "<<a[r]<<endl;
			l++;
			r--;
		}
		if(sum>target){
			r--;
		}
		if(sum<target){
			l++;
		}	
	}
	return 0;
}