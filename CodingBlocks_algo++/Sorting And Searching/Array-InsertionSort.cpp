#include<iostream>
using namespace std;
# define ll long long

void insertionSort(ll arr[],ll n){
	for(ll i=1;i<n;i++){
		ll j=i-1,num=arr[i];
		for( ;j>=0 && arr[j]>num ;j--){
            arr[j+1]=arr[j];
		}
		arr[j+1]=num;
	}
}

int main(){
	ll n;
	ll a[100000];
	cin>>n;
	for(ll i=0;i<n;i++)
		cin>>a[i];
	insertionSort(a,n);
	for(ll i=0;i<n;i++)
		cout<<a[i]<<endl;
	return 0;
}