#include<iostream>
# define ll long long
using namespace std;

void countingSort(ll arr[],ll n){
	ll freq[n+1]={0};
	// creating the freq array
	for(ll i=0;i<n;i++){
		freq[arr[i]]+=1;
	}
	// using the freq array
	ll count=0;
	for(ll i=0;i<n;i++){
		if(freq[arr[i]]>0){
		  for(ll j=0;j<freq[i];j++){
			 arr[count++]=i;
		    }
	    }
	}
}

int main(){
	ll n, a[1000000];
	cin>>n;
	for(ll i=0;i<n;i++)
		cin>>a[i];
	countingSort(a,n);
	for(ll i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}