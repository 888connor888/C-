#include<iostream>
using namespace std;

int main(){
	int a[1000]={0};
	int n,m;
	cin>>n;
	for(int i=0;i<n;i++){
		int no;
		cin>>no;
		a[i]=no;
	}
	cin>>m;
	for(int i=0;i<m;i++){
		int n1;
		cin>>n1;
		a[i]+=n1;
	}
	int c= (n>m)?n:m;
	for(int i=0;i<c;i++){
         cout<<a[i]<<", ";
	}
    cout<<"END";
    return 0;
}