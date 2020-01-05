#include<iostream>
using namespace std;

// Unique Number 2


int main(){
	int n;
	cin>>n;
	int a[100005];
	int Xor=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		Xor=Xor^a[i];
	}
	int temp=Xor;
    int pos=0;
	while((temp&1)!=0){
          pos++;
          temp=temp>>1;
    }
    // first bit of xor at pos
    int mask=(1<<pos);
    // find the nos containg set bits at those positions
    int x=0,y=0;
    for(int i=0;i<n;i++){
    	if(a[i]&mask>0){
    		x=x^a[i];
    	}
    }
    y=Xor^x;
    cout<<min(x,y)<<" "<<max(x,y);
    return 0;
}
