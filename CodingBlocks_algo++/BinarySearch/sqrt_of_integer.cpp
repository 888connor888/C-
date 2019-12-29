#include<iostream>
using namespace std;

float sqrt(int n,int p){
	// Binary Search
	int s=0,e=n;
	int mid;
	double ans;
	while(s<e){
		mid=(s+e)/2;
        if(mid*mid==n){
        	ans=mid;
        	break;
        }
		else if(mid*mid>n){
			e=mid-1;
		}
		 else{
			s=mid+1;
			ans=mid;
		}
	}
	// Fractional Part
	float increment=0.1;
	for(int i=0;i<p;i++){
		
		while(ans*ans<n){
             ans+=increment;
		}
        ans-= increment;// as incrementation has already taken place before checking condition
		increment=increment/10;
	}
	return ans;
}

int main(){
	int n=10;
	cout<<sqrt(n,3)<<endl;
}