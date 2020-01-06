#include<iostream>
using namespace std;

int generatePrime(int n){
  int x=1;
	if(n!=1){
		for(int i=2;i<n;i++){
			if(n%i==0){
				x=0;
        break;
			}
			else{
				x=1;
			}
		}
	}
  return x;
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		for(int j=a;j<=b;j++){
			if(generatePrime(j)){
			cout<<j<<" ";
		}
		}
		cout<<endl;
	}
	return 0;
}