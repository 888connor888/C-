#include<iostream>
using namespace std;

int Power(int a, int n){
    if(n==0){
    	return 1;
    }

    return a*Power(a,n-1);
}

int fastPower(int a,int n){
	if(n==0){
		return 1;
	}
	int smallAns=fastPower(a,n/2);
	smallAns*=smallAns;
	// if n is odd
	if(n&1){
		return a*smallAns;
	}
	else{
		return smallAns;
	}
}

int main(){
	int a,n;
	cin>>a>>n;
	cout<<Power(a,n)<<endl;
    cout<<fastPower(a,n)<<endl;
	return 0;
}