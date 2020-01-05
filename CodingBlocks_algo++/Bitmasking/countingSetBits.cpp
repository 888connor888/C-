#include<iostream>
using namespace std;

// Approach One
int countBits(int n){
	int ans=0;
	while(n>0){
		int last_bit=n&1;
		ans+=last_bit;
		n=n>>1;     
	}
    return ans;
}

// Approach Two
int countBitsFast(int n){
	int ans=0;
	while(n>0){
		n=n&(n-1);
		ans++;
	}
	return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<"The number of bits in n is:"<<countBits(n)<<endl;
    cout<<"The number of bits in n is(faster):"<<countBitsFast(n)<<endl;
    cout<<"The number of bits in n is(built in):"<<__builtin_popcount(n)<<endl;
	return 0;
}