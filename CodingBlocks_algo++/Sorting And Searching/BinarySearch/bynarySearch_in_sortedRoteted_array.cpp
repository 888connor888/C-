#include<iostream>
using namespace std;

int searchIn(int a[],int s,int e,int Key){
	// Base case
	if(e<s){
		return -1;
	}

	//Rec cases
	int mid=(e+s)/2;
	if(a[mid]==Key){
		return mid;
	}

	//if mid lies in the first line
	if(a[s]<=a[mid]){
		if(Key>=a[s] && Key<=a[mid]){
			return searchIn(a,s,mid-1,Key);
		}
		else{
			return searchIn(a,mid+1,e,Key);
		}
	}

	// mid lies in the second line
	if(Key>=a[mid]&&Key<=a[e]){
		return searchIn(a,mid+1,e,Key);
	}
	return searchIn(a,s,mid-1,Key);
}

int main(){
	int a[]={5,6,7,1,2,3,4};
	int Key;
	cin>>Key;
	cout<<"Element found at index :"<<searchIn(a,0,6,Key);
}
