#include<iostream>
using namespace std;

int main(){
	char a[10][100];
	// You want to take input n strings
	int n;
	cin>>n;
	cin.ignore(); // to ignore the \n
	for(int i=0;i<n;i++){
		cin.getline(a[i],100); // Each row of the charater will be filled	
	}
	// You can also print it
	for(int i=0;i<n;i++){
		cout<<a[i]<<endl; 
	}
	// to check if word is in array
	char key[100];
	cin>>Key;
	for(int i=0;i<n;i++){
		// to compare two arrays use a loop or strcmp() function
		if(strcmp(key,a[i]==0)){
			cout<<"Found at Index"<<i<<endl;
			break;
	}
	if(i==n){
		cout<<"Not found!";
	}
}