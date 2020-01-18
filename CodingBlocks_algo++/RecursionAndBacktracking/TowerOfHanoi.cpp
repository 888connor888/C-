#include<iostream>
using namespace std;

void TowerOfHanoi(int n,char source,char Destination,char Helper){
	// Base Case
	if(n==0){
		return;
	}
	// Recursive Case
	TowerOfHanoi(n-1,source,Helper,Destination);
	cout<<"Move "<<n<<" disk from "<<source<<" to "<<Destination<<endl;
	TowerOfHanoi(n-1,Helper,Destination,source);
}

int main(){
	int n;
	cin>>n;
	TowerOfHanoi(n,'A','C','B');
	return 0;
}