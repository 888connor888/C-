#include<iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int count=0;
		int a,b;
		cin>>a>>b;
		for(int i=a;i<=b;i++){
			int setBits=__builtin_popcount(i);
			count += setBits;
		}
		cout<<count<<endl;
	}
}