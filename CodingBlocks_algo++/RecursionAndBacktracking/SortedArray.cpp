#include<iostream>
using namespace std;
#define ll long long


bool isSorted(ll *a,int n){
	if(n==1){
		return true;
	}
	if(a[0]<=a[1] && isSorted(a+1,n-1)){
		return true;
	}

	return false;
}

int main(){
    int n;
	ll a[1000]={0};
	cin>>n;
	for(int i=0;i<n;i++){
        cin>>a[i];
	}
	if(isSorted(a,n)){
		
		cout<<"true"<<endl;
	}
	else{
		cout<<"false"<<endl;
	}
	return 0;
}