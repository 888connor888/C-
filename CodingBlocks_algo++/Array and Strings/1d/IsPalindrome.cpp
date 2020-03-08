#include<iostream>
using namespace std;

bool isPalindrome(int *a,int n,int i,int j){
	// Base Case
	if(i>=j){
		return true;
	}

	// Recursive Case
	if(a[i]==a[j]){
		isPalindrome(a,n,i+1,j-1);
	}
	else{
		return false;
	}
	
}


int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
    bool val = isPalindrome(a,n,0,n-1);
	if(val == 1){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }

	return 0;
}