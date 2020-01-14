/*
#include<iostream>
using namespace std;

#define ll long long

ll mod(ll a,ll b,ll c ){
    // Base Case
	if(b==0){
		return 1;
	}

	// Odd case
	if(a&1){
		return (a%c)* mod(a,b-1,c)%c;

	}

	// Even Case
	else{
		ll forEven= mod(a,b/2,c);
		return forEven*forEven%c;
	}


}

int main(){
	
	ll a,b,c;
	cin>>a>>b>>c;
	cout<<mod(a,b,c)<<endl;
	return 0;
}

*/

#include<iostream>
using namespace std;

#define ll long long

int mod(ll a,ll b,ll c ){
    // Base Case
	if(b==0){
		return 1%c; // Here
	}

	// Odd case
	if(b&1){ // Here
		return ((a%c)* mod(a,b-1,c))%c; // Here
	}

	// Even Case
	else{
		ll forEven= mod(a,b/2,c);
		return (forEven*forEven)%c; // Here
	}

}

int main(){
	/* code */
	ll a,b,c;
	cin>>a>>b>>c;
	cout<<mod(a,b,c)<<endl;
	return 0;
}