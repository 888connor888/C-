#include<iostream>
using namespace std;
# define ll long long
# define max_size 1000000




int main(){
	ll p[max_size]={0};
	ll a[max_size]={0};
	//ll n;
	//cin>>n;
    
    a[1]=2;
    int count=2;
    p[0]=p[1]=0;
    p[2]=1;

    for(ll i=3;i<max_size;i+=2){
    	p[i]=1;
    }
    for(ll i=3;i<max_size;i+=2){
    	if(p[i]){
    		a[count]=i;
    		for(ll j=i*i;j<max_size;j+=2*i){
    			p[j]=0;
    		}
    		count++;
    	}
    }
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<a[n]<<endl;
    }
    //cout<<a[n]<<endl;
    return 0;
}