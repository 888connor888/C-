#include<iostream>
using namespace std;

int main(){
	// array of fixed size O(1) space
	int count[64]={0};

	int n,no;
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>no;
		int j=0;
		while(no>0){
            int last_bit=(no&1);
            count[j] += last_bit;
            j++;
            no=(no>>1);
		}
	}

	// Reduce the count array by factor of 3
	for(int i=0;i<64;i++){
		count[i] %= 3;
	}

	// Now print the number
	int p=1,num=0;
	for(int i=0;i<64;i++){
		num += p*count[i];
		p=p*2;
	}
	cout<<num;
}