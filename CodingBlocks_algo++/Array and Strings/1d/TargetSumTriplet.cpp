#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int a[1000];
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int target;
	cin>>target;
	for(int i=0;i<n;i++){
		int l=i+1,r=n-1;
		while(l<r){
			int sum= a[i] + a[l] + a[r];
			if(sum<target){
				l++;
			}
			if(sum>target){
				r--;
			}
			if(sum==target){
				cout<<a[i]<<", "<<a[l]<<" and "<<a[r]<<endl;
				l++;
				r--;
			}

		}
	}
	return 0;
}