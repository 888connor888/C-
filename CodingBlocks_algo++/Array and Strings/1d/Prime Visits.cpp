#include<iostream>
using namespace std;
#define max_size 1000000
#define ll long long


int main(){
	//Generate Prime Sieve
	ll a[max_size]={0};
	a[0]=a[1]=0;
	a[2]=1;
	for(ll i=3;i<max_size;i+=2){
		a[i]=1;
	}
	for(ll i=3;i<max_size;i+=2){
		for(ll j=i*i;j<max_size;j+=2*i){
				a[j]=0;
		}
	}

	int t;
	cin>>t;
	while(t--){
		ll A,b;
	    cin>>A>>b;
	    ll count=0;
	    for(ll i=A;i<=b;i++){
	    	if(a[i]){
	    		count++;
	    	}
	    }
	    cout<<count<<endl;
	}
	return 0;
}