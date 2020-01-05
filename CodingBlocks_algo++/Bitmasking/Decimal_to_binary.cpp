#include<iostream>
using namespace std;

int decimal_ToBinary(int n){
	int ans=0,p=1;
	while(n>0){
		int last_bit=(n&1);
		ans=p*last_bit;
		p=p*10;
		n=n>>1;
	}
    return ans;
}

int main(){
	int n;
	cin>>n;
    cout<<"The Binary Format of the number is:"<<decimal_ToBinary(n)<<endl;
	return 0;
}