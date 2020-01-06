#include<iostream>
using namespace std;

# define ll long long

int main(){
	ll t;
	cin>>t;
	// list of primes lessthan 20
	ll primes[]={2,3,5,7,11,13,17,19};

	while(t--){
		ll n;
		
		cin>>n;


		ll subsets =(1<<8) -1;
		ll ans=0;

        for(ll i=1;i<=subsets;i++){
        	ll denominator= 1ll;
        	ll setBits=__builtin_popcount(i);
            
            // iterating in setbits to obtain denominator
        	for(ll j=0;j<=7;j++){
        		if(i&(1<<j)){
        			denominator=denominator*primes[j];
        		}
        	}

        	// Based on odd or even pairing
        	if(setBits&1){
        		ans += n/denominator;
        	}
        	else{
        		ans -= n/denominator;
        	}
        }
        cout<<ans<<endl;
	}
	return 0;
}