#include<iostream>
using namespace std;
# define ll long long

void selectionSort(ll a[],ll n){
	for(ll i=0;i<n-1;i++){
		ll minIndex=i;
		for(ll j=i+1;j<n;j++){
			if(a[j]<a[minIndex]){
				minIndex=j;
			}
		}
		swap(a[i],a[minIndex]);
	}
}

int main(){
	ll n;
	ll a[100000];
	cin>> n;
	for(ll i=0;i<n;i++)
		cin>>a[i];
	selectionSort(a,n);
	for(ll i=0;i<n;i++)
		cout<<a[i]<<endl;
	return 0;
}