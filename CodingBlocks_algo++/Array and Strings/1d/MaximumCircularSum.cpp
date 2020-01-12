#include<iostream>
using namespace std;
#define ll long long

int Kadane(ll *a,int n){
	int current_sum=0,max_sum=0;
	for(int i=0;i<n;i++){
		current_sum += a[i];
		if(current_sum<0){
			current_sum=0;
		}
		max_sum=max(max_sum,current_sum);
	}
	return max_sum;
}

int main(){
	ll a[1000];
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int max_Kaden=Kadane(a,n);
		int array_sum=0;
		for(int i=0;i<n;i++){
			array_sum += a[i];
			a[i]=-a[i];
		}
		int max_inverse = array_sum - Kadane(a,n);
		cout<<max_Kaden<<" "<<max_inverse;
	}
	return 0;
}