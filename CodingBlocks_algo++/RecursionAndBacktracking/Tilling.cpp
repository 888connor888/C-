#include<iostream>
using namespace std;

int tilling(int n){
	if(n==0){
		return 1;
	}

	return (f(n-1)+f(n-4));
}

int main(){
	int n;
	cin>>n;
	cout<<tilling(n)<<endl;
	return 0;
}