#include<iostream>
using namespace std;

int Product(int a,int b){
	int sum=0;
	if(a<b){
      return Product(b,a) ;
	}
	else if(b==0){
		return 0;
	}
	return (a+Product(a,b-1));
}

int main(){
	int a,b;
	cin>>a>>b;
	cout<<Product(a,b)<<endl;
	return 0;
}